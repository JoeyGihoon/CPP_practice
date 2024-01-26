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
	vector<int>num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());
	int ans = 0;

	for (int i = 0; i < N; i++) {
		int s = 0;
		int e = N - 1;
		int now = num[i];
		while (s < e) {
			long long sum = num[s] + num[e];
			if (now == sum) {
				if (s != i && e != i) {
					ans++;
					break;
				}
				else if (s == i) {
					s++;
				}
				else if (e == i) {
					e--;
				}
			}

			else if (sum > now) {
				e--;
			}

			else {
				s++;
			}
		}
	}

	cout << ans << '\n';
}