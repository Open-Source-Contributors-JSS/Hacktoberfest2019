''' This project is for hacktoberfest 2019. It is a dice roller for DND and other tabletop RPGs. The user will type
        the dice they want to roll in the form of '2d6', '1d20 3d4', '3d10 + 2', etc. 
    Programmer: Amariah Del Mar / itstheholyginger
 '''
import random
import re


def welcome():
    print("''''' Welcome to DND Dice Roller '''''")


# this function collects user input and splits it in separate sections. '1d6 2d10' = a list with ['1d6', '2d10']
def get_input():
    valid = False

    while valid is False:
        user_input = input("Enter dice to roll in format '1d20' or '3d4 1d6, or type 'exit' to exit program\n\t")

        # check for exit prompt
        if user_input.startswith('ex') or user_input.startswith("Ex") or user_input.startswith("EX"):
            return "exit"

        print(user_input)

        # check for user error in input
        if user_input.startswith("d"):
            user_input = "1" + user_input

        if '+' not in user_input and '-' not in user_input:
            user_input = user_input + " + 0"
        
        separated = user_input.split()
        print("separated: ", separated)

        if separated[-2] is '-' or separated[-2] is '+':
            if separated[-1].isdigit():

                rex = re.compile('(\d+d\d+)')

                first_part = separated[:-2]
                print("first part: ", first_part)

                if all(rex.match(item) for item in first_part):
                    valid = True

        if valid == False:
            print("invalid input. try again.")
    return separated


# calculate a random number between 1 and and max number on the dice
# for each multiplier we need to roll and add them up
def roll(mult, dice):
    roll = 0
    for i in range(0, int(mult)):
        roll = roll + random.randint(1, int(dice))
    return roll

def play():
    # until the user exits, repeat
    while 1:
        temp = get_input()
        dice_list = temp[:-2]
        additive = temp[-2:]
        if dice_list == "exit":
            return
        print(dice_list)
        result = 0
        for item in dice_list:
            mult, dice = item.split('d')
            print("mult= ", mult)
            print("dice= ", dice)
            result = result + roll(mult, dice)
            
            print(result)
        if additive[0] == '+':
            result = result + int(additive[1])
        if additive[0] == '-':
            result = result - int(additive[1])
        print("result: ", result)


if __name__ == '__main__':
    welcome()
    
    play()

    print("Goodbye!")

