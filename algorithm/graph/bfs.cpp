#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* BFS
 * Find the shortest path in a unweighted graph (equal weights)
 * O(V + E)
 */

int main() {
		vector<vector<int>> grid = {
				{0, 0, 1},
				{1, 0, 0},
				{0, 1, 0}
		};

		int n = 3, m = 3;

		vector<vector<int>> dist(n, vector<int>(m, -1));
		dist[0][0] = 0;

		queue<pair<int, int>> q;
		q.push({0, 0});

		vector<int> dx = {1, -1, 0, 0};
		vector<int> dy = {0, 0, 1, -1};

		while (!q.empty()) {
				auto [x, y] = q.front(); 

				/* int x = q.front().first;
				 * int y = q.front().second;
				 */

				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
						
				    if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
						dist[nx][ny] = dist[x][y] + 1;
						q.push({nx, ny});
				    }
				}
		}

		cout << dist[n - 1][m - 1]; 

		return 0;
}
