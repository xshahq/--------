#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 101;
int n;
 
int main() {
	string file[maxn];
	int cmax;
	while (scanf("%d", &n) != EOF) {
		printf("------------------------------------------------------------\n");
		cmax = 0;
		for (int i = 0; i < n; i++) {
			cin >> file[i];
			cmax = max(cmax, (int)file[i].size());
		}
		int col = 62 / (cmax + 2);
		int row = ceil(1.0 * n / col);
		sort (file, file + n);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				//	printf("%s", file[i * row + j]);
				int t = j * row + i;
				if (t >= n)
					continue;
				cout << file[t];
				int k = cmax - file[t].size();
				while (k--)
					printf(" ");
				if (j != col - 1)
					printf("  ");
			}
			if (i <= row - 1)
				printf("\n");
		}
	}
	return 0;
}
