#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quicksort(vector<int>input, int S, int E);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int>A(N);
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}

	quicksort(A, 1, N - 1);
	cout << A[K - 1] << '\n';
}

void quicksort(vector<int>input, int S, int E) {
	if (S == E) return;

	int M = (S + E) / 2;
	swap(input[S], input[M]);
	int pivot = S;
	int i = S + 1;
	int j = E;

	while (i <= j) {
		while (i <= E && input[i] <= input[pivot]) {
			i++;
		}
		while (j >= S && input[j] >= input[pivot]) {
			j--;
		}

		if (i <= j) {
			int tmp = input[i];
			input[i] = input[j];
			input[j] = tmp;
		}
		else {
			int tmp = input[j];

		}
	}
}