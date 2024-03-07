#include <iostream>
#include <vector>
#include <limits.h>//무한대 표현 위함
#include <tuple>
using namespace std;

typedef tuple<int, int, int> edge;
vector<long> mdis, plusmoney;
vector<edge> list;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*배열 초기화*/
	int N, S, E, M;
	cin >> N >> S >> E >> M;
	mdis.resize(N, LONG_MIN);
	plusmoney.resize(N);

	/*에지 리스트 생성 및 데이터 저장*/
	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		list.push_back(make_tuple(s, e, v));
	}
	for (int i = 0; i < N; i++) { //각 도시에서 벌 수 있는 돈 저장
		cin >> plusmoney[i];
	}

	/*변형 벨만포드 알고리즘 수행*/
	mdis[S] = plusmoney[S];

	for (int i = 0; i <= N + 50; i++) { //양수 사이클이 전파되도록 충분히 큰 수로 반복
		for (int j = 0; j < M; j++) {
			edge now = list[j];
			int s = get<0>(now);
			int e = get<1>(now);
			int v = get<2>(now);

			if (mdis[s] == LONG_MIN) { //한번도 방문하지 않았다면 continue
				continue;
			}
			else if (mdis[s] == LONG_MAX) {
				mdis[e] = LONG_MAX;
			}
			else if (mdis[e] < mdis[s] + plusmoney[e] - v) { // 도착도시 < 시작도시 + 도착도시수입 - 비용
				mdis[e] = mdis[s] + plusmoney[e] - v;
				if (i >= N - 1) {
					mdis[e] = LONG_MAX;
				}
			}
		}
	}

	/*출력*/
	if (mdis[E] == LONG_MIN) {
		cout << "gg" << '\n';
	}
	else if (mdis[E] == LONG_MAX) {
		cout << "Gee" << '\n';
	}
	else {
		cout << mdis[E] << '\n';
	}
}