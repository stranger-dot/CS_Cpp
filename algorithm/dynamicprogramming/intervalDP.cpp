#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

/* dp[i][j] : Optimal value for i~j
 * Divide into two subintervals (i, k) and (k + 1, j) based on k
 * Get the entire optimal value using the subintervals optimal values
 */

int cost (int i, int j, int k) {
		// Fill code

		return 0;
}

int main() {
		int N = 10;

		vector<vector<int>> dp;

		for (int len = 2; len <= N; len++) {
				for (int i = 0; i <= N - len; i++) {
						int j = i + len - 1;

						dp[i][j] = INT_MAX; // or INT_MIN

						for (int k = i; k < j; k++) {
								dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost(i, j, k)); // or max
						}
				}
		}

		cout << dp[0][N - 1];

		return 0;
}
