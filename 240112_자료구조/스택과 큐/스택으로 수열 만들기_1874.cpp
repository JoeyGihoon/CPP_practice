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
	vector<int>A(N + 1);
	vector<char>ans;
	stack<int>mystack;
	int j = 1;
	bool flag = true;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		while (j <= A[i]) {
			mystack.push(j);
			ans.push_back('+');
			j++;
		}

		if (mystack.top() > A[i]) {
			flag = false;
			break;
		}

		if (mystack.top() == A[i]) {
			mystack.pop();
			ans.push_back('-');
		}
	}

	if (flag) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}
	}
	else {
		cout << "NO" << '\n';
	}
}