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

	int V, E, K; //V: 노드 개수, E: 에지 개수, K: 출발 노드
	cin >> V >> E >> K;
	A.resize(V + 1);
	visited.resize(V + 1, false);
	D.resize(V + 1);

	// 경로 초기화
	for (int i = 0; i < E; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		A[s].push_back(make_pair(e, v));
	}

	for (int i = 1; i <= V; i++) {
		D[i] = 200001;
	}

	D[K] = 0;
	q.push(make_pair(0, K));
	while (q.size() != 0) {
		path now = q.top();
		q.pop();
		visited[now.second] = true;
		for (path next : A[now.second]) {
			if (!visited[next.first]) {
				if (D[next.first] > D[now.second] + next.second) {
					D[next.first] = D[now.second] + next.second;
					q.push(make_pair(D[next.first], next.first));
				}
				//D[next.first] = min(D[next.first], D[now.second] + D[next.second]);
				
			}
		}
	}
	
	for (int i = 1; i <= V; i++) {
		if (visited[i]) {
			cout << D[i] << '\n';
		}
		else {
			cout << "INF" << '\n';
		}
	}
}