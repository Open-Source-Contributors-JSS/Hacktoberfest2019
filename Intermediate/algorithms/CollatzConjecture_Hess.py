# THIS IS A PYTHON SCRIPT FOR IMPLEMENTATION OF HESS'S ALGORITHM
# For more information search collatz conjecture or hess's algorithm

def hessalgo(num):
    if num%2 == 0:
        return num/2
    else:
        return 3*num+1

if __name__ == '__main__':
    n = int(input('enter your number: '))
    no_of_steps = 0
    while(n!=1):
        n = hessalgo(n)
        # print(n)
        no_of_steps += 1
    print(f'this algorithm number completed in {no_of_steps} steps')    
