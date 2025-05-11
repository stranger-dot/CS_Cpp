#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> &m) {
		for (vector<int> mm : m) {
				for (int mmm : mm)
						cout << mmm << " ";
				cout << "\n";
		}

		cout << "\n";

		return ;
}

int main() {
		vector<vector<int>> matrix {
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
		};

		print(matrix);

		int n = matrix.size();

		// new martrix - clockwise
		vector<vector<int>> rot_clockwise(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
						rot_clockwise[j][n - i - 1] = matrix[i][j];
		
		print(rot_clockwise);

		// new matrix - counterclockwise
		vector<vector<int>> rot_counterclockwise(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
						rot_counterclockwise[n - j - 1][i] = matrix[i][j];

		print(rot_counterclockwise);

		// in place - clockwise
		vector<vector<int>> tmp = matrix;

		for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
						swap(tmp[i][j], tmp[j][i]);
		
		for (int i = 0; i < n; i++)
				reverse(tmp[i].begin(), tmp[i].end());

		print(tmp);

		// in place - counterclockwise
		tmp = matrix;

		for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
						swap(tmp[i][j], tmp[j][i]);
		
		for (int j = 0; j < n; j++)
				for (int i = 0, k = n - 1; i < k; i++, k--)
						swap(tmp[i][j], tmp[k][j]);

		print(tmp);

		return 0;
}
