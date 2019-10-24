var unsortedArr = [340, 1, 3, 3, 76, 23, 4, 12, 122, 7642, 646];
function merge(leftArr, rightArr) {
  var sortedArr = [];
  while (leftArr.length && rightArr.length) {
    if (leftArr[0] <= rightArr[0]) {
      sortedArr.push(leftArr[0]);
      leftArr = leftArr.slice(1);
    } else {
      sortedArr.push(rightArr[0]);
      rightArr = rightArr.slice(1);
    }
  }
  while (leftArr.length) sortedArr.push(leftArr.shift());
  while (rightArr.length) sortedArr.push(rightArr.shift());
  return sortedArr;
}
function mergesort(arr) {
  if (arr.length < 2) {
    return arr;
  } else {
    var midpoint = parseInt(arr.length / 2);
    var leftArr = arr.slice(0, midpoint);
    var rightArr = arr.slice(midpoint, arr.length);
    return merge(mergesort(leftArr), mergesort(rightArr));
  }
}
console.log("This should be the sorted array!");
console.log(mergesort(unsortedArr));
