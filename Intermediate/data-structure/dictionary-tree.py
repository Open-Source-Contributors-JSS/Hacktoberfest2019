class Node:
	data = {}
	done = False

def insertToTree(char, *tree):
	if char not in tree.data:
		if char != '*':
			tree.data[char] = Node()
			insertToTree(tree.data[char])
		else:
			tree.done = True

def add(text, *tree):
	currNode = tree[0]
	print(currNode)
	for char in text:
		if char not in currNode.data:
			currNode.data[char] = Node()
			currNode = currNode.data[char]
		else:
			return False
		currNode = currNode
	currNode.done = True
	return True

def printTree(*tree):
	currNode = tree[0]
	for char in currNode.data:
		if not currNode.done:
			print(currNode.data.keys())
			currNode = currNode.data[char]
			printTree(currNode)
tree = Node()
# test = 'Test'
# add(test, tree)
add('hahaha*', tree)
printTree(tree)