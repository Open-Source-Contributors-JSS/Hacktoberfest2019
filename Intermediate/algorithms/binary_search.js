/* Binary Search implementation in Javascript 
   Assumption that array is sorted
*/


function binarySearch(input, elementToFind) {
	if (input && input.length === 0) return -1;
	let middleIndex = Math.floor(input.length / 2);
	let startIndex = 0;
	let endIndex = input.length - 1;
	if (input[middleIndex] === elementToFind) {
		return elementToFind;
	}

	else if (input[middleIndex] < elementToFind) {
		input = input.slice(middleIndex, input.length);
		return binarySearch(input, elementToFind);
	}

	else if (input[middleIndex] > elementToFind) {
		input = input.slice(startIndex, middleIndex);
		return binarySearch(input, elementToFind);
	}

}



function testCases() {
	let arr = [1,2,3,4,5];
	let result = binarySearch(arr, 4);
	console.log("Should be four : " + result);
	arr = [1,2,3,4,5];
	result = binarySearch(arr, 1);
	console.log("Should be one : " + result);
	arr = [1,2,3,4,5];
	result = binarySearch(arr, 0);
	console.log("Should be negative one : " + result);
}


testCases();