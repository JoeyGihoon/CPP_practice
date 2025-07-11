#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> cityA;
    vector<vector<int>> cityB;
    vector<vector<int>> pending;

public:
    static bool compare(const vector<int>& A, const vector<int>& B){
        return abs(A[0]-A[1]) < abs(B[0]-B[1]);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int answer = 0;
        int total = costs.size();
        int half = total / 2;

        // 1. A, B, Pending 분류
        for (auto& c : costs) {
            if (c[0] == c[1]) pending.push_back(c);
            else if (c[0] < c[1]) cityA.push_back(c);
            else cityB.push_back(c);
        }

        // 2. pending을 균형 맞추는 데 사용
        int A = cityA.size(), B = cityB.size();
        for (auto& c : pending) {
            if (A < half) {
                cityA.push_back(c);
                A++;
            } else {
                cityB.push_back(c);
                B++;
            }
        }

        // 3. A > B이면 A에서 일부를 B로 보내야 함
        if (A > B) {
            sort(cityA.begin(), cityA.end(), compare);
            for (int i = 0; i < A - half; ++i) {
                // 보내야 할 사람은 B로
                answer += cityA[i][1];
            }
            for (int i = A - half; i < cityA.size(); ++i) {
                answer += cityA[i][0];
            }
            for (auto& c : cityB) answer += c[1];
        }

        // 4. B > A이면 B에서 일부를 A로 보내야 함
        else if (B > A) {
            sort(cityB.begin(), cityB.end(), compare);
            for (int i = 0; i < B - half; ++i) {
                answer += cityB[i][0];
            }
            for (int i = B - half; i < cityB.size(); ++i) {
                answer += cityB[i][1];
            }
            for (auto& c : cityA) answer += c[0];
        }

        // 5. 이미 A, B 균형이 맞는 경우
        else {
            for (auto& c : cityA) answer += c[0];
            for (auto& c : cityB) answer += c[1];
        }

        return answer;
    }
};