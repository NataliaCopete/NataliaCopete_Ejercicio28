import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np
import glob
import re

fnames = sorted(glob.glob('*.txt'))
arrays = [np.loadtxt(f) for f in fnames]
arrays=np.array(arrays)
x=np.arange(2,9,1)
z=10**x
teo=155/6
arrays=np.absolute((arrays-teo)*100/teo)

plt.plot(np.log10(z),arrays)
plt.savefig('int.pdf')


