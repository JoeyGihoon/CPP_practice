#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, tmp;
    cin >> N >> M;
    
    vector<vector<int>>A(N + 1, vector<int>(N + 1));
    vector<vector<int>>S(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        int result = S[X2][Y2] - S[X1 - 1][Y2] - S[X2][Y1 - 1] + S[X1 - 1][Y1 - 1];
        cout << result << '\n';
    }
    
}