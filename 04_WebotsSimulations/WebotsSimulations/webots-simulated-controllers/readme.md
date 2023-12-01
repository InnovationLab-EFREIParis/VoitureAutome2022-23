

This repo contains worlds and controllers fully managed by Webots (not ROS). It's a mix of both dterministic and RL-based controllers.

## Controllers
- `car_logic.py`: Not an actual Webots controller. Abstract class containing common driving logic. Used as the bass class for most controllers in this repo.
- `minimalController`: A minimal controller implementation based on the CarLogic class.
- `MTD`        : Mind The Disparity based controller, with AEB.
- [DEPRECATED] `testSensor`:  A simple controllers that print the output of each sensors
- [DEPRECATED] `trajectory_estimator`: Using a simple wall following strategy, map the circuit and save position/orientation to a json file.
- [DEPRECATED]`PPO*`: RL-based approaches
- [DEPRECATED] `Model Evaluator`: Used to run deterministicely a trained RL model.
- `manual` : A controller that let you drive the car.
- `crash_test` : Used to test aeb and make fancy gifs.
- `utils`: Not a controller. Nice code used everywhere
  - `dummy_slam`: A fake SLAM that uses Webots information. Can be used to make path planning.

## Worlds
- `track_waide.wbt`: The correct map


