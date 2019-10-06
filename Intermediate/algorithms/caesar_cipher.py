

def caesar_cipher(rotateKey = 0, myStr = ''):
	alphabet = 'abcdefghijklmnopqrstuvwxyz'

	MAX_SIZE = 26
	myStr = myStr.lower()

	for i in myStr:
		rotate = alphabet.index(i)+rotateKey
		if (rotate % MAX_SIZE) == 0:
			print("encode:", alphabet[rotate])
		else:
			print("encode:", alphabet[rotate % MAX_SIZE])
