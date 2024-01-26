#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, tmp;
    int answer = 0;
    cin >> N >> M;
    vector<int>S(N + 1);
    vector<int>C(M);

    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        S[i] = (S[i - 1] + tmp) % M;
        if (S[i] == 0) {
            answer++;
        }
        C[S[i]]++;
    }

    
    for (int i = 0; i < M;i++) {
        if (C[i] != 0) {
            answer += C[i] * (C[i] - 1) / 2;
        }
    }

    cout << answer << '\n';
}