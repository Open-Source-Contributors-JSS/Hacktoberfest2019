from random import randrange

# ===================================================================
# Classes
# ===================================================================
class Player(object):
	"""Player class for each Player of the Tic Tac Toe game"""
	def __init__(self, symbol, isComputer):
		'''Constructor for Player'''
		self.symbol = symbol
		self.isComputer = isComputer

	def play(self, gameBoard):
		'''
		Play a move. Parameters are game board.
		If the player is a Computer, the move is decided by the AI.
		'''
		# Find the place to mark the symbol at.
		if self.isComputer:
			print('Computer Turn...')
			global count
			depth, alpha, beta, isMax = 9-count, -10, 10, True
			value, place = self.alphaBeta(gameBoard, depth, alpha, beta, isMax)
			print('Computer plays at:', place+1)
		else:
			print('Your Turn...')
			place = int(input('Enter a number from 1 to 9: ')) - 1
			while self.isInvalid(gameBoard, place):
				place = int(input('Enter again: ')) - 1
		# Mark the symbol at the calculated or user obtained place.
		gameBoard[place] = self.symbol

	def alphaBeta(self, gameBoard, depth, alpha, beta, isMaxPlayer):
		value = checkIfWon(gameBoard, player)
		if value != 0:
			return value, -1
		if depth == 0:
			return value, -1
		if isMaxPlayer:
			value = -10
			listOfNumbers = list(range(9))
			while listOfNumbers:
				random = listOfNumbers.pop(randrange(len(listOfNumbers)))
				if gameBoard[random] == 'b':
					gameBoard[random] = player[1].symbol
					temp_value = self.alphaBeta(gameBoard, depth-1, alpha, beta, False)[0]
					if temp_value > value:
						value = temp_value
						place = random
					alpha = max(alpha, value)
					gameBoard[random] = 'b'
					if alpha >= beta:
						break
		else:
			value = 10
			listOfNumbers = list(range(9))
			while listOfNumbers:
				random = listOfNumbers.pop(randrange(len(listOfNumbers)))
				if gameBoard[random] == 'b':
					gameBoard[random] = player[0].symbol
					temp_value = self.alphaBeta(gameBoard, depth-1, alpha, beta, True)[0]
					if temp_value < value:
						value = temp_value
						place = random
					beta = min(beta, value)
					gameBoard[random] = 'b'
					if beta <= alpha:
						break
		return value, place

	def isInvalid(self, gameBoard, place):
		'''
		Check if the place entered is valid. Return True if Invalid.
		'''
		if place not in list(range(9)):
			print('ERROR: Invalid input. Number not from 1 to 9.')
			return True
		if gameBoard[place] != 'b':
			print('ERROR: Invalid input. Place already marked.')
			return True

		return False

	def isSymbolX(self):
		return self.symbol == 'X'

# ===================================================================
# Functions
# ===================================================================

def welcomeMessage():
	'''Function to print the welcome message'''
	msg = 'Welcome to the Tic Tac Toe game. You will play the classic '\
	+ 'Tic Tac Toe game against the hardest AI. Rules of the game are simple: '\
	+ 'Try to mark your X\'s (or O\'s) three in row or column or diagonally '\
	+ 'to win the game. To mark on a particular place **ENTER A NUMBER '\
	+ 'FROM 1 TO 9 WITH AN EMPTY PLACE (MARKED AS b).**\nAll the Best! :)'
	print(msg)

def initialize():
	'''Initialize the game board and the players with new values'''
	global gameBoard, player, turn, count
	gameBoard, count = list('b'*9), 0
	# print(gameBoard)
	if input('Do you want to play first? (yes/no)\n')[0].lower() == 'y':
		player, turn = [Player('X', False), Player('O', True)], 0
	else:
		player, turn = [Player('O', False), Player('X', True)], 1

def drawBoard(gameBoard):
	for i in range(9):
		print(gameBoard[i], '\n'*((i%3)-1), end='')

def displayWinMsg(whoWon):
	if whoWon == 1:
		print('Sorry. You lose. Better luck next time.')
	elif whoWon == -1:
		print('Congratulations! You Win!')
	else:
		print('It\'s a Draw.')

def checkIfWon(gameBoard, player):
	# Create the gameState
	symbolToNumber, gameState = {}, [[0,0,0],[0,0,0],[0,0,0]]
	symbolToNumber['X'] = 2*player[1].isSymbolX() - 1
	symbolToNumber['O'] = 2*player[0].isSymbolX() - 1
	symbolToNumber['b'] = 0
	# print(symbolToNumber)
	for i in range(3):
		for j in range(3):
			gameState[i][j] = symbolToNumber[gameBoard[i*3+j]] 
	# print(gameState)
	# Check if any player has won
	for i in range(3):
		rowcount, colcount = 0, 0
		for j in range(3):
			rowcount += gameState[i][j]
			colcount += gameState[j][i]
		if (rowcount == -3 or colcount == -3):
			return -1
		if (rowcount == 3 or colcount == 3):
			return 1
	if gameState[1][1] == -1:
		if (gameState[0][0] == -1 and gameState[2][2] == -1) or (gameState[0][2] == -1 and gameState[2][0] == -1):
			return -1
	if gameState[1][1] == 1:
		if (gameState[0][0] == 1 and gameState[2][2] == 1) or (gameState[0][2] == 1 and gameState[2][0] == 1):
			return 1

	return 0

# ===================================================================
# Main Program
# ===================================================================
if __name__ == '__main__':
	welcomeMessage()
	option = 'y'
	while option == 'y':
		initialize()
		whoWon = False
		while not whoWon:
			drawBoard(gameBoard)
			player[turn].play(gameBoard)
			whoWon = checkIfWon(gameBoard, player)
			turn = 1 - turn
			count += 1
			if count == 9:
				break
		drawBoard(gameBoard)
		displayWinMsg(whoWon)
		option = input('Play Again? (yes/no)\n')[0].lower()

