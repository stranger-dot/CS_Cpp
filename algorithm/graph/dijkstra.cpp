#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <limits.h>

using namespace std;

/* Dijkstra
 * Find the shortest path(cost) in a weighted graph (different weights)
 * O(ElogV)
 */

int main() {
		vector<vector<int>> cost = {
				{1, 3, 1},
				{1, 5, 1},
				{4, 2, 1}
		};

		int n = 3, m = 3;

		vector<vector<int>> dist(n, vector<int>(m, INT_MAX));	
		dist[0][0] = cost[0][0];

		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
		pq.push({dist[0][0], 0, 0});

		vector<int> dx {1, 0, -1, 0};
		vector<int> dy {0, 1, 0, -1};

		while (!pq.empty()) {
				auto [time, x, y] = pq.top();

				/* tuple<int, int, int> t = pq.top();
				 * time = get<0>(t);
				 * x = get<1>(t);
				 * y = get<2>(t);
				 */
				
				pq.pop();

				if (time > dist[x][y])
						continue;

				for (int i = 0; i < 4; i++) {
						int nx = x + dx[i], ny = y + dy[i];

						if (0 <= nx && nx < n && 0 <= ny && ny < m) {
								int arr = time + cost[nx][ny];

								if (arr < dist[nx][ny]) {
										dist[nx][ny] = arr;
										pq.push({arr, nx, ny});
								}
						}
				}	
		}

		cout << dist[n - 1][m - 1];

		return 0;
}
