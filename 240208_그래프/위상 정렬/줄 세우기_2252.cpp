#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>>A(N + 1);
	vector<int>D(N + 1);
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		D[e]++;
	}

	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (D[i] == 0) {
			q.push(i);
		}
	}

	while (q.size() != 0) {
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (int next : A[now]) {
			D[next]--;
			if (D[next] == 0) {
				q.push(next);
			}
		}
	}
}