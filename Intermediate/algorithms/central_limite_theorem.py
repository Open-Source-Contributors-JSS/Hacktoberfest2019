import numpy as np 
import matplotlib.pyplot as plt

#Central limite theorem: The sum of several realizations of one random process converges to a normal distribuiton


n_repetitions = 10000 # repetitions for each realization

realization = []

#for one dice
for _ in range(n_repetitions):

    realization.append(np.random.randint(1,7))

plt.figure()
plt.hist(realization, bins = 6, density=True)
plt.title('One dice')

#for two dices
realization = []
for _ in range(n_repetitions):

    aux = 0
    for _ in range(2):
        aux += np.random.randint(1,7)
    
    realization.append(aux)

plt.figure()
plt.hist(realization, bins = 11, density=True)
plt.title('two dices')

#for four dices
realization = []
for _ in range(n_repetitions):

    aux = 0
    for _ in range(4):
        aux += np.random.randint(1,7)
    
    realization.append(aux)

plt.figure()
plt.hist(realization, bins = 21, density=True)
plt.title('four dices')

#for eight dices
realization = []
for _ in range(n_repetitions):

    aux = 0
    for _ in range(8):
        aux += np.random.randint(1,7)
    
    realization.append(aux)

plt.figure()
plt.hist(realization, bins = 34, density=True)
plt.title('eight dices')


plt.show()

