#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //available vector: (weight, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> available;

        //wait vector: (busy time, weight, index))
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> wait;

        vector<int> result;

        for(int i=0; i<servers.size(); i++){
            available.push({servers[i], i});
        }

        ll time = 0;
        for(int i=0; i<tasks.size(); i++){
            time = max(time, (ll)i);

            //wait -> available
            while(!wait.empty() && get<0>(wait.top()) <= time){
                auto [busy_time, weight, idx] = wait.top();
                wait.pop();
                available.push({weight, idx});
            }

            ////if nothing is available
            if(available.empty()){
                time = get<0>(wait.top());
                while(!wait.empty() && get<0>(wait.top()) <= time){
                auto [busy_time, weight, idx] = wait.top();
                wait.pop();
                available.push({weight, idx});
                }
            }

            //available -> wait
            auto [weight, idx] = available.top();
            available.pop();
            wait.push({time + tasks[i], weight, idx});
            result.push_back(idx);
            
        }
        return result;
    }
};