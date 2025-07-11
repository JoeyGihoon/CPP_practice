#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;
        
        // 예약된 좌석만 저장
        for (auto seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }
        
        int answer = 0;

        for (auto [row, seats] : reserved) {
            bool left = true, middle = true, right = true;

            // 왼쪽 구역 [2,3,4,5]
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }

            // 오른쪽 구역 [6,7,8,9]
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }

            // 중간 구역 [4,5,6,7]
            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }

            if (left && right) answer += 2;
            else if (left || middle || right) answer += 1;
        }

        // 예약 없는 행은 2개 그룹 모두 가능
        int freeRows = n - reserved.size();
        answer += freeRows * 2;

        return answer;
    }
};