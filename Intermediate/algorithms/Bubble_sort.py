def bubble_sort(array):
	temp = 0
	#  Counts number of Sorts
	sort = 0
	# Counts number of Runs
	runs = 0
	swap = True
	for i in range(len(array)):
		if swap is True:
			runs +=1
		swap = False
		#  Prints each step of array
		print(array)
		for j in range(len(array) -1):
			if array[j+1] < array[j]:
				temp = array[j]
				array[j] = array[j+1]
				array[j+1] = temp
				sort +=1
				swap = True
	return array

test_array = [1,7,6,5,4,2,8,3,9]
print(bubble_sort(test_array))
