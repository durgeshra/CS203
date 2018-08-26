import numpy as np
import matplotlib.pyplot as plt
text_file = open("test.txt", "r")
lines = text_file.read().split(' ')
x = np.array(lines)
x = np.asfarray(x,float)
plt.plot(x)
plt.show()