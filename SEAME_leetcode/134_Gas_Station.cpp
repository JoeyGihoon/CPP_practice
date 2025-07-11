#include <vector>
using namespace std;

class Solution {
private:
    vector<int> maybe;
    vector<bool> visited;

public:
    /*bool isSolution(vector<int>& gas, vector<int>& cost, int &num){
        visited.resize(gas.size(), false);
        
        int tank = gas[num];
        while(!visited[num]){
            if(tank<0) return false;

            if(num+1 > gas.size()) num = 0;

            tank = tank + gas[num+1] - cost[num];
            visited[num] = true;
            num++;
        }
        return true;
        /*for(int i=num; i<gas.size(); i++){
            if(tank<0) return false;
            
            tank = tank + gas[i] - cost[i];
        }
    }*/

    /*int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int answer = 0;

        for(int i=0; i<gas.size(); i++){
            if(gas[i] > cost[i]){
                maybe.push_back(i);
            }
        }
        
        //for(int a : maybe) cout<<a<<endl;

        for(int can : maybe){
            if(isSolution(gas, cost, can)){
                answer = can;
                break;
            } 
        }

        return answer;
    }*/
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int currentGas = 0;
        int startIndex = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];
            
            // 현재까지 가스가 부족하면, 다음 지점부터 다시 시작
            if (currentGas < 0) {
                startIndex = i + 1;
                currentGas = 0;
            }
        }
        
        // 전체 가스가 충분해야지만 가능한 경우
        return totalGas >= 0 ? startIndex : -1;
    }
};