#include <iostream>
#include <vector>

using namespace std;

int main() {
		vector<int> v {0, 1, 2, 3, 4, 5, 6, 7, 8};
		vector<int> sum {0, };


		// Prefix Sum Array
		sum[0] = v[0];

		for (int i = 1; i < v.size(); i++) {
				sum.push_back(sum[i - 1] + v[i]);	
		}

		/* Sum (i to j)
		 * sum[j] - sum[i - 1]
		 */

		cout << sum[5] - sum[2]; 

		return 0;
}
