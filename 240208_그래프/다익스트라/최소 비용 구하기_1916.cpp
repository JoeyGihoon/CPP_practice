#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> path;
vector<vector<path>> A;
vector<bool> visited;
vector<int> D;
priority_queue<path, vector<path>, greater<path>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	A.resize(N + 1);
	visited.resize(N + 1);
	D.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		D[i] = 1000000001;
	}

	for (int i = 0; i < M;i++) {
		int s, e, v;
		cin >> s >> e >> v;
		A[s].push_back(make_pair(e, v));
	}

	int S, E;
	cin >> S >> E;
	D[S] = 0;
	
	q.push(make_pair(0, S));
	while (q.size() != 0) {
		path now = q.top();
		q.pop();
		visited[now.second] = true;

		for (path next : A[now.second]) {
			int next_idx = next.first;
			int next_val = next.second;
			if (!visited[next_idx] && D[next_idx] > D[now.second] + next_val) {
				D[next_idx] = D[now.second] + next_val;
				q.push(make_pair(D[next_idx], next_idx));
			}
		}
	}

	cout << D[E] << '\n';
	
}