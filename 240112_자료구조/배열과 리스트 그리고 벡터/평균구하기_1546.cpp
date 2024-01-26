#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int maximum = 0;
    double sum = 0;
    cin >> N;
    vector<int>score(N);
    for (int i = 0; i < N; i++) {
        cin >> score[i];
        maximum = max(maximum, score[i]);
    }

    for (int i = 0; i < N; i++) {
        sum += (double) score[i] / maximum * 100;
    }

    cout << sum / N << '\n';
}