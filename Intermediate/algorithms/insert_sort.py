def insertionSort(inputs):
	for x in range(1,len(inputs)):
		item = inputs[x]

		i = x - 1
		while (i > -1) and (inputs[i] > item):
			inputs[i + 1] = inputs[i]
			i = i - 1
		inputs[i + 1] = item
