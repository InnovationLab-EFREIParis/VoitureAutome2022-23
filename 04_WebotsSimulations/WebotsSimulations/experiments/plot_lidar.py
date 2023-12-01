import numpy as np
import matplotlib.pyplot as plt 


lidar = [np.random.randint(30) for i in range(721)]


y = lidar


x = np.linspace(0,360,num=len(lidar))



plt.plot(x,y,linewidth=2, markersize=12)
plt.show()