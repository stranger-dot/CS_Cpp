#include <iostream>
#include <vector>

using namespace std;

bool twoSum(vector<int> &v, int target) {
		int i = 0, j = v.size() - 1;
		
		while (i < j) {
				int sum = v[i] + v[j];

				if (sum == target) 
						return true;
				else if (sum < target) 
						i++;
				else 
						j--;
		}

		return false;
}

long long countSubarr(vector<int> &v, int k) {
		int sz = v.size();
		int j = 0;

		long long answer = 0, sum = 0;

		for (int i = 0; i < sz; i++) {
				sum += v[i];

				while (j <= i && sum >= k) {
						sum -= v[j];
						j++;
				}

				answer += (i - j + 1);
		}

		return answer;
}

int main() {
		vector<int> v {1, 2, 4, 7, 11, 18 ,27};
		int target = 9;

		cout << twoSum(v, target) << "\n";
		cout << countSubarr(v, 11);

		return 0;
}
