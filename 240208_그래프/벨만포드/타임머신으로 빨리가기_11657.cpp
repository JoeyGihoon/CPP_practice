#include <iostream>
#include <vector>
#include <limits.h>//무한대 표현 위함
#include <tuple>
using namespace std;

//typedef tuple<int, int, int> edge;
struct edge {
	int s, e, v;
};
vector<long> res;
vector<edge> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; //노드, 엣지
	cin >> N >> M;
	res.resize(N + 1);
	fill(res.begin(), res.end(), LONG_MAX); //무한대 저장

	/*에지리스트 생성 및 데이터 저장*/
	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		A.push_back(edge{ s, e, v });
	}

	/*벨만포드 알고리즘*/
	res[1] = 0; //출발 노드 0으로 초기화
	for (int i = 1; i < N; i++) { //N-1까지만 업데이트
		for (int j = 0; j < M; j++) { //에지의 개수만큼 반복
			edge now = A[j];
			int s = now.s;
			int e = now.e;
			int v = now.v;

			if (res[s] != LONG_MAX && res[e] > res[s] + v) { //업데이트 조건
				res[e] = res[s] + v;
			}
		}
	}

	/*음수 사이클 확인*/
	bool cycle = false;

	for (int i = 0; i < M; i++) {
		edge now = A[i];
		int s = now.s;
		int e = now.e;
		int v = now.v;

		if (res[s] != LONG_MAX && res[e] > res[s] + v) { 
			cycle = true;
			break;
		}
	}

	if (!cycle) {
		for (int i = 2; i <= N; i++) {
			if (res[i] == LONG_MAX) {
				cout << -1 << '\n';
			}
			else {
				cout << res[i] << '\n';
			}
		}
	}
	else {
		cout << -1 << '\n';
	}
}