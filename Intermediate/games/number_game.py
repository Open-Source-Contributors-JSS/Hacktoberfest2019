import random
#GET GUESS

def get_guess():
    return list(input("What is your guess?")) #list coz else it would be a string and wkt strings are immutable , whereas list is mutable.

#GENERATE COMPUTER CODE

def generate_code():
    digits = [str(num) for num in range(10)]
    random.shuffle(digits) #to shuffle the digits
    return digits[:3] #slices the string after 3 digits

#GENETRATE THE CLUES
def generate_clues(code,user_guess):

    if code == user_guess:
        return "CODE CRACKED!"

    clues = []
    for ind,num in enumerate(user_guess):
        if num == code[ind]:
            clues.append("Match")
        elif num in code:
            clues.append("Close")

    if clues == []:
        return ["Nope"]
    else:
        return clues

#RUN GAME LOGIC

print("Welcome Code Breaker!Let's see if you can guess my three digit number!")
print("Code has been generated , what's your guess ")

secret_code = generate_code()

clue_report = []

while clue_report != "CODE CRACKED!":
    guess = get_guess()

    clue_report = generate_clues(guess,secret_code)
    print("Here is the result of your guess: ")
    for clue in clue_report:
        print(clue)
