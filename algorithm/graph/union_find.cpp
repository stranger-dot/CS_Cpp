#include <iostream>
#include <vector>

using namespace std;

/* 
 * Union Find
 * Represent a Disjoint Set
 * Determine whether two elements belong to same set 
 * or to merge two sets into one
 */

class UnionFind {
		vector<int> parent;
		vector<int> rank;

		public:
				UnionFind(int n) {
						parent.resize(n);
						rank.resize(n, 0);

						for (int i = 0; i < n; i++)
								parent[i] = i;
				}

				int find(int x) {
						if (parent[x] != x)
								parent[x] = find(parent[x]);

						return parent[x];
				}

				void unite(int x, int y) {
						int px = find(x);
						int py = find(y);

						if (px == py)
								return;

						if (rank[px] < rank[py])
								parent[px] = py;
						else if (rank[px] > rank[py])
								parent[py] = px;
						else {
								parent[py] = px;
								rank[px]++;
						}
				}

				bool connected(int x, int y) {
						return find(x) == find(y);
				}
};

int main() {
		UnionFind uf(10);

		uf.unite(1, 2);
		uf.unite(2, 3);
		uf.unite(4, 5);

		cout << uf.connected(1, 3) << "\n";
		cout << uf.connected(1, 4) << "\n";

		uf.unite(3, 4);

		cout << uf.connected(1, 5) << "\n";

		return 0;
}
