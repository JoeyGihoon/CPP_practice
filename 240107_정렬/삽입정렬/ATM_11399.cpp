#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int>A(N + 1);
	vector<int>S(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	//sort(A.begin(), A.end());

	//»ðÀÔÁ¤·Ä
	for (int i = 2; i <= N; i++) {
		int pnt = 0;
		int val = A[i];
		for (int j = 1; j < i; j++) {
			if (A[i] < A[j]) {
				pnt = j;
				break;
			}
		}

		if (pnt != 0) {
			for (int j = i; j > pnt; j--) {
				A[j] = A[j - 1];
			}

			A[pnt] = val;
		}
		
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		S[i] = S[i - 1] + A[i];
		sum += S[i];
	}

	cout << sum << '\n';
}