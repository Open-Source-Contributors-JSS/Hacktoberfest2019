# Python Script for generate all possible combinations without repetitions
from itertools import combinations

# Combinations will haves numbers from 1 to 60
NUMBERS = 60
# Each possible combination haves 6 numbers
QUANTITY = 6
with open('combinations.txt', 'w') as f:
    for comb in combinations(range(1, NUMBERS + 1), QUANTITY):
        f.write(str(comb) + '\n')
