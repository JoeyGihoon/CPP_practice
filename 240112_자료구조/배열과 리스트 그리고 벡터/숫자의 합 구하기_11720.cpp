#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string num;
    cin >> num;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += num[i] - '0';
    }

    cout << sum << '\n';
}