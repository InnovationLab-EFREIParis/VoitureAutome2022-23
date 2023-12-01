import os
from itertools import product
import time

import pandas as pd
from controller import Supervisor

import datetime
import os.path as osp

TIME_STEP = 8

### CONFIG ###

num_round = 1       # Number of time the car will be reset
num_lap_round = 3   # Number of lap before stopping/reseting

max_step_round = 1500 * num_lap_round # Number of steps before forcing the end of a round.

experiment_name = "experiment1"

t = datetime.datetime.now()
t = t.strftime('-%H%M-%d%m')
experiment_name = experiment_name + t

path_to_experiment_results = r"../../logs/Evaluator/" + experiment_name
path_to_data =  path_to_experiment_results + "/buffer"
os.makedirs(path_to_data)
print(path_to_data)
###




robot = Supervisor()  # create Supervisor instance



root_node = robot.getRoot()
children_field = root_node.getField('children')



def build_controller_string(id,path_to_data,translation,rotation,controller,color,dict_params={"salad toamge":678.879}):
  l = []
  l.append(f'DEF {id} TT02 '+'{')
  l.append(f'translation {" ".join(map(lambda x: str(x),translation))}')
  l.append(f'rotation {" ".join(map(lambda x: str(x),rotation))}')
  l.append(f'controller "{controller}"')
  l.append(f'controllerArgs ["{id}","{path_to_data}","{dict_params}"]')
  l.append(f'color {" ".join(map(lambda x: str(x),color))}')
  l.append("}")
  return '\n'.join(l)

id = "TT02"
translation = [-1.38855, -6.67598, 0.04]
rotation = [0, 0, 1, 2.61799]
controller = "MTD"
color = [0.31, 0.4, 1]



controller_str = build_controller_string(id,path_to_data, translation,rotation,controller,color)

print('====\n',controller_str,'\n-----')

def generate_controllers(dicts):

  controllers = []
  for config in dicts:

    #TODO: here the parameters of build_controller_string should be taken from config
    controller_str = build_controller_string(id, path_to_data, translation, rotation, controller, color,dict_params=config)
    children_field.importMFNodeFromString(-1, controller_str)
    car = robot.getFromDef('TT02') #DEF should be parameterized to handle mutliple cars

    controllers.append(car)

  return controllers


hyperparameters_values = {'speed_profile': [{'ttc_threshold':[0.2,0.9,1.5],'speed':[0.5,1,3,6]},
                                            {'ttc_threshold':[0.2,0.5,0.9,1.5],'speed':[0.5,1,1.8,2.5,9]},
                                            {'ttc_threshold':[0.2,0.4,0.6,0.9,1.5],'speed':[0.5,1,1.5,5,9]}],
                          'aperture_half_angle':[60,75,85],
                          'aperture_tight_front_half_angle_deg':[35,45,55],
                          'safety_bubble_r': [0.023, 0.029,0.035],

}

def get_hyperparameter_grid(hyperparameters_values):
  values = [v for v in hyperparameters_values.values() if v]

  combinations = list(product(*values))

  list_of_dicts = [{k: v[i] for i, k in enumerate(hyperparameters_values.keys())} for v in combinations]

  return list_of_dicts


hyperparameters_config_dicts = get_hyperparameter_grid(hyperparameters_values)
hyperparameters_config_dicts = list(map(lambda x: [x],hyperparameters_config_dicts))
print(hyperparameters_config_dicts)
# hyperparameters_config_dicts = [[dict()],[dict()]] # the format of this variable must be [[dict_car_1,dict_car_2,dict_car_3],[dict_car_1,dict_car_2],...]

df_perfs = pd.DataFrame(columns=['params', 'round', 'steps', 'num_collision', 'num_lap'])

t0 = time.time()
for params in hyperparameters_config_dicts:
  # TODO : In order to do a proper hyperparameter search. we need to modify tgus ctrl_config_dicts

  ctrl_config_dicts = params
  perf_dicts = []

  print(f"Testing parameters: {ctrl_config_dicts}")
  cpt_round = 0
  while True:

    controllers = generate_controllers(ctrl_config_dicts)

    laps_controllers = [0 for i in controllers]
    colls_controllers = [0 for i in controllers]

    cpt_lap = 0
    cpt_step = 0
    #A single Round loop
    while True:
      robot.step()
      has_ended = False

      #Retrieving information for all controllers
      for i, ctrl in enumerate(controllers):




        # Contact point tracking :
        if len(ctrl.getContactPoints()) > 0:
          colls_controllers[i] += 1



        # Lap number tracking
        num_lap_ctrl = ctrl.getField("numlap").getSFInt32()
        if num_lap_ctrl != laps_controllers[i] and num_lap_ctrl !=-1:
          cpt_lap +=1

          laps_controllers[i] = num_lap_ctrl

          print(f"#{cpt_round+1}: Lap {num_lap_ctrl} over")

          if num_lap_ctrl >= num_lap_round:
            has_ended = True

      if has_ended or cpt_step > max_step_round:
        break

      cpt_step+=1

    cpt_round +=1
    print(f"Round {cpt_round} over with {cpt_step} steps")

    for i, ctrl in enumerate(controllers):
      perf_dicts.append({'round':cpt_round,'steps':cpt_step,'num_collision':colls_controllers[i],'num_lap':laps_controllers[i]})

    # At the end of a round all the cars are removed
    [ctrl.remove() for ctrl in controllers]

    if cpt_round >= num_round:
      break

  for perf in perf_dicts:
    df_perfs.loc[len(df_perfs)] = [params] +list(perf.values())

  print(df_perfs)

  df_perfs.to_csv(osp.join(path_to_experiment_results,"res.csv"),index=False)

t1 = time.time()





print(f"Performed all the Experiments successfully in {t1-t0:.1f}s ! Closing")