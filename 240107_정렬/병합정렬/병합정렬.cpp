#include<iostream>
#include<vector>

using namespace std;

void merge_sort(int s, int e);
static vector<int> A;
static vector<int> tmp;
static int result = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	A.resize(N + 1);
	tmp.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	merge_sort(1, N);

	cout << result << '\n';
}

void merge_sort(int s, int e) {
	if (e - s < 1) return;
	 
	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m + 1, e);

	for (int i = s; i <= e; i++) {
		tmp[i] = A[i];
	}

	int k = s;
	int i1 = s;
	int i2 = m + 1;
	while (i1 <= m && i2 <= e) {
		if (tmp[i1] > tmp[i2]) {
			A[k] = tmp[i2];
			k++;
			i2++;
			result += i2 - k;
		}
		else {
			A[k] = tmp[i1];
			k++;
			i1++;
		}
	}

	while (i1 <= m) {
		A[k] = tmp[i1];
		k++;
		i1++;
	}

	while (i2 <= e) {
		A[k] = tmp[i2];
		k++;
		i2++;
	}
}