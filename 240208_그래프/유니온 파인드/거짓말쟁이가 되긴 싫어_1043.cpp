#include <iostream>
#include <vector>
using namespace std;

vector<int>A; //집합 표현
vector<vector<int>> party; //파티
vector<int> D; //알고 있는 사람
void unionfunc(int a, int b);
int find(int a);
bool isunion(int a, int b);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	A.resize(N + 1);
	party.resize(M);
	
	int know;
	cin >> know;
	D.resize(know);
	for (int i = 0; i < D.size(); i++) {
		cin >> D[i];
	}

	for (int i = 1; i <= N; i++) {
		A[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int people;
		cin >> people;
		for (int j = 0; j < people; j++) {
			int num;
			cin >> num;
			party[i].push_back(num);
		}
	}

	for (int i = 0; i < M; i++) {
		int parent = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			unionfunc(parent, party[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool flag = true;

		for (int j = 0; j < D.size(); j++) {
			if (isunion(party[i][0], D[j])) {
				flag = false;
				break;
			}
		}

		if (flag) {
			cnt++;
		}
	}

	cout << cnt << '\n';
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		A[b] = a;
	}
}

int find(int a) {
	if (a == A[a]) {
		return a;
	}

	return A[a] = find(A[a]);
}

bool isunion(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) {
		return true;
	}
	return false;
}