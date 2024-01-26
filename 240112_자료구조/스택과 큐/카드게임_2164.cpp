#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	queue<int>q;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		q.pop();
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}

	cout << q.front() << '\n';
}