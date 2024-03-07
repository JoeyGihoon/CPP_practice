#include <iostream>
#include <vector>
#include <limits.h>//���Ѵ� ǥ�� ����
#include <tuple>
using namespace std;

typedef tuple<int, int, int> edge;
vector<long> mdis, plusmoney;
vector<edge> list;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*�迭 �ʱ�ȭ*/
	int N, S, E, M;
	cin >> N >> S >> E >> M;
	mdis.resize(N, LONG_MIN);
	plusmoney.resize(N);

	/*���� ����Ʈ ���� �� ������ ����*/
	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		list.push_back(make_tuple(s, e, v));
	}
	for (int i = 0; i < N; i++) { //�� ���ÿ��� �� �� �ִ� �� ����
		cin >> plusmoney[i];
	}

	/*���� �������� �˰��� ����*/
	mdis[S] = plusmoney[S];

	for (int i = 0; i <= N + 50; i++) { //��� ����Ŭ�� ���ĵǵ��� ����� ū ���� �ݺ�
		for (int j = 0; j < M; j++) {
			edge now = list[j];
			int s = get<0>(now);
			int e = get<1>(now);
			int v = get<2>(now);

			if (mdis[s] == LONG_MIN) { //�ѹ��� �湮���� �ʾҴٸ� continue
				continue;
			}
			else if (mdis[s] == LONG_MAX) {
				mdis[e] = LONG_MAX;
			}
			else if (mdis[e] < mdis[s] + plusmoney[e] - v) { // �������� < ���۵��� + �������ü��� - ���
				mdis[e] = mdis[s] + plusmoney[e] - v;
				if (i >= N - 1) {
					mdis[e] = LONG_MAX;
				}
			}
		}
	}

	/*���*/
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