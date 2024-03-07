#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N = 10;
void BFS(int s);
vector<bool>visited;
vector<vector<int>>Map;
vector<int>result;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;
	Map.resize(N + 1);
	result.resize(N + 1);
	visited.resize(N + 1, false);
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		Map[s].push_back(e);
	}

	BFS(X);

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		if (result[i] == K) {
			flag = true;
			cout << i << '\n';
		}
	}
	if (!flag) {
		cout << -1 << '\n';
	}
}

void BFS(int s) {
	queue<int>q;
	q.push(s);
	visited[s] = true;

	while (q.size() != 0) {
		int now = q.front();
		q.pop();

		for (int i : Map[now]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
				result[i] = result[now] + 1;
			}
		}
	}
}