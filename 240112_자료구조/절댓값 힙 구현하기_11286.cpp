#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct cmp {
	bool operator()(long long v1, long long v2) {
		if (abs(v1) == abs(v2)) {
			return v1 > v2;
		}
		else {
			return abs(v1) > abs(v2);
		}
	}
};

int main() { 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<long long, vector<long long>, cmp>q;

	while (q.size() != 0) {
		cout << q.top() << ' ';
		q.pop();
	}
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		if (tmp == 0) {
			if (q.size() == 0) {
				cout << 0 << '\n';
			}

			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}

		else {
			q.push(tmp);
		}
	}
}