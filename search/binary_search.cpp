#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Ascending sort required
 * O(log N)
 */

using namespace std;

int binarySearch(vector<int> &arr, int low, int high, int target) {
		if (low > high)
				return -1;

		int mid = (low + high) / 2;

		if (arr[mid] == target)
				return mid;

		if (arr[mid] > target)
				return binarySearch(arr, low, mid - 1, target);
		else
				return binarySearch(arr, mid + 1, high, target);
}

int main() {
		vector<int> v {1, 7, 5, 3, 8, 9};
		int sz = v.size();

		sort(v.begin(), v.end());

		cout << binarySearch(v, 0, sz - 1, 5) << "\n"; // return index
													   
		cout << binary_search(v.begin(), v.begin() + sz, 5) << "\n"; // return bool (exists or not)
																	 
		cout << lower_bound(v.begin(), v.end(), 5) - v.begin() << "\n"; // return first index of key
																		
		cout << upper_bound(v.begin(), v.end(), 5) - v.begin() << "\n"; // return first index of greater than key

		return 0;
}
