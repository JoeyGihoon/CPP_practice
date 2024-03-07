#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> edge;
vector<int> Union;
void unionfunc(int s, int e);
int find(int s);
int isSame(int s, int e);

struct cmp {
    bool operator()(const edge& e1, const edge& e2) {
        int v1 = get<2>(e1);
        int v2 = get<2>(e2);
        return v1 > v2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;
    priority_queue<edge, vector<edge>, cmp> pq;
    Union.resize(V + 1);
    
    for (int i = 0; i < E; i++) {
        int s, e, v;
        pq.push(make_tuple(s, e, v));
    }

    for (int i = 1; i <= V; i++) {
        Union[i] = i;
    }

    int union_cnt = 0;
    while (union_cnt != V - 1) {
        edge now = pq.top();
        int s = get<0>(now);
        int e = get<1>(now);
        int v = get<2>(now);

        if (!isSame(s, e)) {
            unionfunc(s, e);
            union_cnt++;
        }
    }
}
void unionfunc(int s, int e) {
    int v1 = find(s);
    int v2 = find(e);

    if (v1 != v2) {
        Union[e] = s;
    }
}

int find(int s) {
    if (Union[s] == s) {
        return s;
    }
    return Union[s] = find(Union[s]);
}

int isSame(int s, int e) {
    int v1 = find(s);
    int v2 = find(e);

    if (v1 == v2) {
        return true;
    }
    return false;
}
