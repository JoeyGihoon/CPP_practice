#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int>arr(N + 1);
    vector<int>S(N + 1);
    vector<int>answer(M + 1);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (i == 1) {
            S[i] = arr[i];
        }
        else {
            S[i] = S[i - 1] + arr[i];
        }
    }

    for (int i = 1; i <= M; i++) {
        int s, e;
        cin >> s >> e;
        answer[i] = S[e] - S[s - 1];
    }

    for (int i = 1; i <= M;i++) {
        cout << answer[i] << '\n';
    }
}