#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int>item(N);

	for (int i = 0; i < N; i++) {
		cin >> item[i];
	}

	sort(item.begin(), item.end());

	int s = 0;
	int e = N - 1;
	int answer = 0;
	while (s < e) {
		int sum = item[s] + item[e];
		if (sum == M) {
			answer++;
			s++;
		}
		else if (sum > M) {
			e--;
		}
		else {
			s++;
		}
	}

	cout << answer << '\n';
}