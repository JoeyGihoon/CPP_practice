#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

long mdis[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M; //���� ���� N, ���� ���� M

	/*�迭 �ʱ�ȭ*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				mdis[i][j] = 0;
			}
			else {
				mdis[i][j] = LONG_MAX;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		if (mdis[s][e] > v) {
			mdis[s][e] = v;
		}
	}

	/*�÷��̵� ���� �˰��� ����*/
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (mdis[i][j] > mdis[i][k] + mdis[k][j]) {
					mdis[i][j] = mdis[i][k] + mdis[k][j];
				}
			}
		}
	}

	/*���*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (mdis[i][j] == LONG_MAX) {
				cout << 0 << ' ';
			}
			else {
				cout << mdis[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}


//���ͽ�Ʈ�� �˰��� ���� ����
/*#include <iostream>
#include <vector>
#include <limits.h>//���Ѵ� ǥ�� ����
#include <queue>
using namespace std;

typedef pair<int, int> edge;
vector<long> mdis;
vector<bool> visited;
vector<vector<edge>> list;
priority_queue<edge, vector<edge>, greater<edge>> q;
void getmdis(int K);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M; // ���� ���� N, ���� ���� M
	list.resize(N + 1);
	mdis.resize(N + 1, LONG_MAX);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		list[s].push_back(make_pair(e, v));
	}

	for (int i = 1; i <= N; i++) {
		getmdis(i);
		for (int j = 1; j <= N; j++) {
			if(mdis[j]==LONG_MAX){
				cout<<0<<' ';
			}
			else{
				cout << mdis[j] << ' ';
			}
		}
		fill(mdis.begin(), mdis.end(), LONG_MAX);
		fill(visited.begin(), visited.end(), false);
		cout << '\n';
	}

}
void getmdis(int K) {
	mdis[K] = 0;
	q.push(make_pair(0, K));
	while (q.size() != 0) {
		edge now = q.top();
		q.pop();
		visited[now.second] = true;
		for (edge next : list[now.second]) {
			if (!visited[next.first]) {
				if (mdis[next.first] > mdis[now.second] + next.second) {
					mdis[next.first] = mdis[now.second] + next.second;
					q.push(make_pair(mdis[next.first], next.first));
				}
			}
		}
	}
}*/


