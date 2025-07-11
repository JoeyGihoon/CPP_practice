#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {       
        /*Generate adjacency list*/
        vector<vector<pair<int, int>>> graph(n);
        for(auto flight : flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].push_back({to, price});
        }

        /*(current city, (price, stops))*/
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0,0}});

         /*Generate distance vector from src*/
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        int result = INT_MAX;

        while(!q.empty()){
            int to = q.front().first;
            int cost = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();

            if (to == dst){
                result = min(result, cost);
                continue;
            }

            if(stops > k) continue;

            for(auto neighbor : graph[to]){
                int next = neighbor.first;
                int price = neighbor.second;
                int nextCost = cost + price;

                if(nextCost >= dist[next] && stops < k) continue;

                dist[next] = nextCost;
                q.push({next, {nextCost, stops+1}});
            }
        }

        if(result == INT_MAX) return -1;
        else return result;
    }
};