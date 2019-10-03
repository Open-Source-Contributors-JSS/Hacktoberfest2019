import random # importing random for later

def populate_word_list(filename):
  """
  Opens file with name 'filename' and returns a populated list of words contained in file.
  """

  # opens the file specified in argument
  word_file = open(filename, "r")

  # list comprehension to read through word_file and store each line as an item in word_list
  # uses str.strip() to get rid of any messy whitespace
  word_list = [word.strip() for word in word_file.readlines()]

  return word_list

  
def select_word(word_list):
  """
  Selects a random word from word_list and returns that word.
  """
  return random.choice(word_list) # random.choice() chooses an item from a list

def is_valid_guess(guess):
  """
  Validates user input, guess, to be a single letter.
  """

  return (len(guess) == 1 and guess.isalpha())
  # checks if the guess is 1 character and is alphabetic

def get_guess(letters_guessed):
  """
  Prompts the user to guess a letter, keeps prompting until letter is valid, returns the valid letter.

  Arguments:
  letters_guessed -- list of previously guessed letters
  """

  # not the only way to do this, but the way I like to do it.
  # emulates a common statement type that we don't have in Python called "do-while loop"

  while True: # run until we break
    guess = input("Please enter a single letter guess: ").lower() # get guess from user, cast to lowercase immediately for simplicity
  
    if is_valid_guess(guess) and guess not in letters_guessed:
      break # if guess is valid, break loop
      # I decided here to also include previously guessed letter check here for simplicity.
      # Depending on whether you want to penalize re-guesses, you could do otherwise.

  return guess

def is_already_guessed(guess, letters_guessed):
  """
  Takes a guessed letter and checks whether it has been guessed before.

  Arguments:
  guess -- a single character
  letters_guessed - a list (or string) containing previously guessed letters
  """

  return guess in letters_guessed # true if already guessed, false otherwise

def is_word_guessed(secret_word, letters_guessed):
  """
  Checks to see if all letters in the secret word have been guessed.

  Arguments:
  secret_word -- the word the user is trying to guess
  letters_guessed - a list (or string) containing previously guessed letters
  """

  # simple for loop checking whether each letter is in our guessed list. if we find one that isn't, return false.

  for letter in secret_word:
    if letter not in letters_guessed:
      return False
  return True

def is_out_of_guesses(guesses_remaining):
  """
  Checks whether player is out of guesses.
  """

  # you could do this a number of other ways, but it doesn't require an if statement.
  # remember that boolean expressions (like the one below) evaluate to true or false, so we can just return the expression.
  
  return guesses_remaining < 1


def display_board(secret_word, letters_guessed, guesses_remaining):
  """
  Uses the secret word, the letters guessed, and the number of guesses remaining to build a string that displays the game board.
  
  Arguments:
  secret_word -- the word the user is trying to guess
  letters_guessed - a list (or string) containing previously guessed letters
  guesses_remaining -- an int of guesses unused
  """

  # this one can be a bit confusing, and as long as you have something that displays a readable board, you should mess around and have fun with it. here's my solution.

  # this list comprehension builds the word display of letters and underscores.
  # it does this by building a list and joining it to make a string.
  # this is much more efficient than concatenation, and probably more efficient than an equivalent for loop.
  # it's also a good example of how to use boolean checks inside of list comprehensions.

  word_display = " ".join([letter if letter in letters_guessed else "_" for letter in secret_word])

  # equivalent for loop using concatenation:
  # word_display = ""
  
  # for letter in secret_word:
  #   if letter in letters_guessed:
  #     secret_word += letter + " "
  #   else:
  #     secret_word += "_ "

  # the rest of this is a single str.format to create the board and fill it with info. useful if you're building complex modular strings like this.

  return """Current word: {0}
You've guessed: {1}
You have {2} incorrect guesses remaining.
""".format(word_display, " ".join(sorted(letters_guessed)), guesses_remaining)

def hangman(secret_word):
  """
  Runs hangman game.

  Arguments:
  secret_word -- string of word to be guessed
  """
  
  # initialize empty list to track letters the user guesses
  letters_guessed = []
  
  # set difficulty by assigning the number of guesses a user gets
  guesses_remaining = 5

  # welcome the player
  print("Welcome to Hangman!\n")

  # display initial board
  print(display_board(secret_word, letters_guessed, guesses_remaining))

  # while the player hasn't won and hasn't lost

  while not is_word_guessed(secret_word, letters_guessed) and not is_out_of_guesses(guesses_remaining):

    # take and validate input
    guess = get_guess(letters_guessed)
    
    # add the letter to letters_guessed if it has not been guessed already
    letters_guessed.append(guess)
    
    # if the guess is wrong, remove a remaining guess
    if guess not in secret_word:
      guesses_remaining -= 1
    
    # print the board
    print(display_board(secret_word, letters_guessed, guesses_remaining))

  # simple end of game screen
  if is_out_of_guesses(guesses_remaining):
    print("Oops! You lost! The word was {0}.".format(secret_word))
  else:
    print("Congratulations! You guessed {0} with {1} guesses left!".format(secret_word, guesses_remaining))

if __name__ == "__main__":
  word_list = populate_word_list("words.txt") # looks for a word list in file words.txt -- create one to play!
  hangman(select_word(word_list))
