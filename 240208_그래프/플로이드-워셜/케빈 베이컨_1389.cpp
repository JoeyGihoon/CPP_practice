#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<vector<long long>> A;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	A.resize(N + 1, vector<long long>(N + 1, INT_MAX));
	for (int i = 1; i <= N; i++) {
		A[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s][e] = 1;
		A[e][s] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				//A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}

	int Min = INT_MAX;
	int tmp;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		tmp = 0;
		for (int j = 1; j <= N; j++) {
			tmp += A[i][j];

		}
		if (Min > tmp) {
			Min = tmp;
			ans = i;
		}
	}

	cout << ans << '\n';
}
