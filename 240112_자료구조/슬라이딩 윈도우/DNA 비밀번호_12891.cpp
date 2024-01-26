#include <iostream>
#include <vector>
#include <string>
using namespace std;

static int flag = 0;
static vector<int>check(4);
static vector<int>now(4);
void Add(char input);
void Remove(char input);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;
	cin >> S >> P;
	string DNA;
	cin >> DNA;


	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		cin >> check[i];
		if (check[i] == 0) {
			flag++;
		}
	}

	for (int i = 0; i < P; i++) {
		Add(DNA[i]);
	}
	if (flag == 4) cnt++;

	for (int i = P; i < S; i++) {
		int j = i - P;

		Add(DNA[i]);
		Remove(DNA[j]);
		if (flag == 4) cnt++;
	}

	cout << cnt << '\n';
}

void Add(char input) {
	if (input == 'A') {
		now[0]++;
		if (check[0] == now[0]) {
			flag++;
		}
	}
	else if (input == 'C') {
		now[1]++;
		if (check[1] == now[1]) {
			flag++;
		}
	}
	else if (input == 'G') {
		now[2]++;
		if (check[2] == now[2]) {
			flag++;
		}
	}
	else if (input == 'T') {
		now[3]++;
		if (check[3] == now[3]) {
			flag++;
		}
		
	}
}

void Remove(char input) {
	if (input == 'A') {
		if (check[0] == now[0]) {
			flag--;
		}
		now[0]--;
	}
	else if (input == 'C') {
		if (check[1] == now[1]) {
			flag--;
		}
		now[1]--;
	}
	else if (input == 'G') {
		if (check[2] == now[2]) {
			flag--;
		}
		now[2]--;
	}
	else if (input == 'T') {
		if (check[3] == now[3]) {
			flag--;
		}
		now[3]--;
	}
}