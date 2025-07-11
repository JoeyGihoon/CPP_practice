#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;             // 윈도우 내 인덱스를 저장
        vector<int> answer;        // 결과를 저장할 벡터

        for (int i = 0; i < nums.size(); i++) {
            // 1. 덱 앞에 있는 값이 윈도우 범위를 벗어나면 제거
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            // 2. 덱 뒤에서부터 현재 값보다 작은 값은 제거 (최댓값만 남기기 위함)
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            // 3. 현재 인덱스를 덱에 추가
            dq.push_back(i);

            // 4. 윈도우가 처음 완성된 시점부터 결과에 최댓값을 추가
            if(i >= k-1){
                answer.push_back(nums[dq.front()]);
            }
        }

        return answer;
    }
};