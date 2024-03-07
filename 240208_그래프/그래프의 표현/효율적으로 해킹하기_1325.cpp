#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int s);
vector<bool>visited;
vector<vector<int>>Map;
vector<int>result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	Map.resize(N + 1);
	visited.resize(N + 1, false);
	result.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		Map[s].push_back(e);
	}

	for (int i = 1; i <= N; i++) {
		BFS(i);
		fill(visited.begin(), visited.end(), false);
	}

	int Min = 100000;
	int Max = 0;
	for (int i = 1; i <= N; i++) {
		Max = max(Max, result[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (result[i] == Max) {
			cout << i << ' ';
		}
	}
}

void BFS(int s) {
	queue<int>q;
	q.push(s);

	while (q.size() != 0) {
		int now = q.front();
		q.pop();
		visited[s] = true;
		for (int i : Map[now]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
				result[i]++;
			}
		}
	}
}