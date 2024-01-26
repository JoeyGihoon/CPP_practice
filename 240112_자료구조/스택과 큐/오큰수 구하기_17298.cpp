#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int>A(N);
	vector<int>NGE(N);
	stack<int>mystack;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	mystack.push(0);
	for (int i = 1; i < N; i++) {
		while (mystack.size() != 0 && A[mystack.top()] < A[i]) {
			NGE[mystack.top()] = A[i];
			mystack.pop();
		}

		mystack.push(i);
	}

	if (mystack.size() != 0) {
		while (mystack.size() != 0) {
			NGE[mystack.top()] = -1;
			mystack.pop();
		}
	}

	for (int i = 0; i < N; i++) {
		cout << NGE[i] << ' ';
	}
}