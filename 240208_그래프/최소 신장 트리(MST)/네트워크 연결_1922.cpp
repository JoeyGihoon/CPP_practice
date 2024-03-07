#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> edge;
vector<int> A;
void unionfunc(int a, int b);
int find(int a);
bool isSame(int a, int b);

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
    
    int N, M; //N: 컴퓨터 개수, M: 연결 선 개수
    cin >> N >> M;
    priority_queue<edge, vector<edge>, cmp> pq;
    A.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        pq.push(make_tuple(s, e, v));
    }

    for (int i = 1; i <= N; i++) {
        A[i] = i;
    }

    int union_cnt = 0;
    int res = 0;

    while (union_cnt < N - 1) {
        edge now = pq.top();
        int s = get<0>(now);
        int e = get<1>(now);
        int v = get<2>(now);
        if (!isSame(s, e)) {
            unionfunc(s, e);
            union_cnt++;
            res += v;
        }
        pq.pop();
    }

    cout << res << '\n';
}
void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) { //중요
        A[b] = a;
    }
  
}

int find(int a) {
    if (a == A[a]) {
        return a;
    }
    return A[a] = find(A[a]);
}

bool isSame(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return true;
    }
    return false;
}