// Following is a code for Kadane's Algorithm used to find largest contiguous subarray sum

#include "bits/stdc++.h"
using namespace std;

int kadane_algo(vector<int> arr) {
	int n = arr.size();
	int best_sum  = INT_MIN, current_sum = 0;
	for (int i = 0; i < n; i++) {
		current_sum = max(current_sum+arr[i], arr[i]);
		best_sum = max(best_sum, current_sum);
	}
	return best_sum;
}

int main() {
	vector<int> arr{-2,-3,4,-1,-2,1,5,-3};
	int best_sum = kadane_algo(arr);
	cout<< "Largest contiguous subarray sum is " << best_sum;
	return 0;
}