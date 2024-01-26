#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	vector<int>A(str.size());

	for (int i = 0; i < str.size(); i++) {
		A[i] = stoi(str.substr(i, 1));
	}

	sort(A.begin(), A.end(), greater<>());

	for (int i = 0; i < str.size(); i++) {
		cout << A[i];
	}
}