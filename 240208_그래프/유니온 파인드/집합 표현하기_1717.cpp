#include <iostream>
#include <vector>
using namespace std;

vector<int>A;
void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	A.resize(n + 1);

	for (int i = 0; i <= n; i++) {
		A[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int s, a, b;
		cin >> s >> a >> b;

		if (s == 0) {
			unionfunc(a, b);
		}
		else {
			if (checkSame(a, b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
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
	else {
		return A[a] = find(A[a]); 
	}
}

bool checkSame(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) {
		return true;
	}
	return false;
}