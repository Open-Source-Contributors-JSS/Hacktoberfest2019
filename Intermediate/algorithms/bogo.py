import random

def is_sorted(liste):
    for i in range(len(liste)-1):
        if liste[i] > liste[i+1]:
            return False
    return True

def bogoSort(liste):
    while not is_sorted(liste):
        random.shuffle(liste)
    return liste
