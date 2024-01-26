#include<iostream>
#include<vector>
#include<queue>

using namespace std;

static vector<int> A;
static queue<int> q[10];
static int N;
void radix_sort(int MAX);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	A.resize(N);

	int MAX = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		MAX = max(MAX, A[i]);
	}

	radix_sort(MAX);

	for (int i = 0; i < N; i++) {
		cout << A[i] << ' ';
	}
}

void radix_sort(int MAX) {
	int radix = 1;
	while (radix <= MAX) {
		radix *= 10;
	}

	for (int i = 0; i < radix; i *= 10) {
		for (int j = 0; j < N; j++) {
			int k;
			if (A[j] < i) {
				k = 0;
			}
			else {
				k = (A[j] / i) % 10;
			}
			q[k].push(A[j]);
		}

		int idx = 0;
		for (int j = 0; j < 10; j++) {
			while (q[j].size() != 0) {
				A[idx] = q[j].front;
				q[j].pop();
				idx++;
			}
		}
	}
}