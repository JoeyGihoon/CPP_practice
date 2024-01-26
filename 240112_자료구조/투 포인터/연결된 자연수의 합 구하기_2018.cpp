#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	int s = 1;
	int e = 1;
	int sum = 1;
	int ans = 0;
	while (e <= N) {
		if (sum == N) {
			ans++;
			e++;
			sum += e;
		}

		else if (sum < N) {
			e++;
			sum += e;
		}

		else {
			sum -= s;
			s++;
		}
	}

	cout << ans << '\n';
}