#include <iostream>
#include <vector>
#include <limits.h>//���Ѵ� ǥ�� ����
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

	int N, M; //���, ����
	cin >> N >> M;
	res.resize(N + 1);
	fill(res.begin(), res.end(), LONG_MAX); //���Ѵ� ����

	/*��������Ʈ ���� �� ������ ����*/
	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		A.push_back(edge{ s, e, v });
	}

	/*�������� �˰���*/
	res[1] = 0; //��� ��� 0���� �ʱ�ȭ
	for (int i = 1; i < N; i++) { //N-1������ ������Ʈ
		for (int j = 0; j < M; j++) { //������ ������ŭ �ݺ�
			edge now = A[j];
			int s = now.s;
			int e = now.e;
			int v = now.v;

			if (res[s] != LONG_MAX && res[e] > res[s] + v) { //������Ʈ ����
				res[e] = res[s] + v;
			}
		}
	}

	/*���� ����Ŭ Ȯ��*/
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