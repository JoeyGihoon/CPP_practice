#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<vector<int>>A(N + 1);
	vector<int>D(N + 1);
	vector<int>Time(N + 1);
	vector<int>Result(N + 1);

	for (int i = 1; i <= N; i++) {
		int time;
		cin >> time;
		Time[i] = time;

		while (true) {
			int build;
			cin >> build;
			if (build == -1) {
				break;
			}
			else {
				A[build].push_back(i); //Áß¿ä
				D[i]++;
			}
		}
	}

	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (D[i] == 0) {
			q.push(i);
			Result[i] = Time[i];
		}
	}

	while (q.size() != 0) {
		int now = q.front();
		q.pop();
		for (int next : A[now]) {
			D[next]--;
			Result[next] = Result[now] + Time[next];
			if (D[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << Result[i] << '\n';
	}
}