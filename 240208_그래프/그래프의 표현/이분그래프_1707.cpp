#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Map;
vector<bool> visited;
vector<int> check;
void DFS(int input);
bool flag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int V, E;
		cin >> V >> E;

		Map.resize(V + 1);
		visited.resize(V + 1, false);
		check.resize(V + 1);

		for (int j = 0;j < E;j++) {
			int s, e;
			cin >> s >> e;
			Map[s].push_back(e);
			Map[e].push_back(s);
		}

		flag = true;
		for (int j = 1; j <= V; j++) {
			if (!flag) {
				break;
			}
			DFS(j);
		}

		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

		for (int j = 0; j <= V; j++) {
			Map[j].clear();
		}
		fill(visited.begin(), visited.end(), false);
		fill(check.begin(), check.end(), 0);
	}
}

void DFS(int input) {
	visited[input] = true;

	for (int i : Map[input]) {
		if (!visited[i]) {
			check[i] = (check[input] + 1) % 2;
		}
		else if (check[i] == check[input]) {
			flag = false;
			break;
		}
	}
}