#include <iostream>
#include <vector>
using namespace std;

vector<int>A;
void unionfunc(int a, int b);
int find(int a);
bool isunion(int a, int b);
bool flag = true;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	A.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		A[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int city;
			cin >> city;
			if (city == 1) {
				unionfunc(i, j);
			}
		}
	}

	vector<int>route(M + 1);
	for (int i = 1; i <= M; i++) {
		int city;
		cin >> city;
		route[i] = city;
	}
	int idx = find(route[1]);

	for (int i = 2; i <= M; i++) {
		if (!isunion(idx, route[i])) {
			cout << "NO" << '\n';
			flag = false;
			break;
		}
	}

	if (flag) {
		cout << "YES" << '\n';
	}
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