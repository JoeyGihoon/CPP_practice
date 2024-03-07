#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

void unionfunc(int a, int b);
int find(int a);
bool isSame(int a, int b);
void BFS(int i, int j);

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int map[101][101];
bool visited[101][101] = { false, };
vector<int> Union;
int N, M, sNum;
vector<vector<pair<int, int>>> sumlist; //��� �� ���� ����
vector<pair<int, int>> mlist; // �ϳ��� �� ���� ����

/*typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge& tmp) const {
        return v > tmp.v;
    }
} Edge;*/

struct Edge { // ����ü ����
    int s, e, v;
};

struct cmp { // ����° ���� ���� �������� ������ ����
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.v > e2.v;
    }
};

priority_queue<Edge, vector<Edge>, cmp> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    sNum = 1;

    /*�� �и�*/
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0 && visited[i][j] != true) { //map�� ���ƴٴϸ� �湮���� �ʾҰ� ���̸� �� ����
                BFS(i, j);
                sNum++;
                sumlist.push_back(mlist);
            }
        }
    }

    /*���� �� �������� ���� �� �ִ� ��� ���� ����*/
    for (int i = 0; i < sumlist.size(); i++) {
        vector<pair<int, int>> now = sumlist[i];

        for (int j = 0; j < now.size(); j++) {
            int x = now[j].first;
            int y = now[j].second;
            int now_S = map[x][y];

            for (int i = 0; i < 4; i++) {
                int tmpx = dx[i];
                int tmpy = dy[i];
                int blength = 0;

                while (x + tmpx >= 0 && x + tmpx < N && y + tmpy >= 0 && y + tmpy < M) {
                    if (map[x + tmpx][y + tmpy] == now_S) { //���� ���� �ƴϾ�� ��
                        break;
                    }
                    else if (map[x + tmpx][y + tmpy] != 0) {
                        if (blength > 1) {
                            pq.push(Edge{ now_S, map[x + tmpx][y + tmpy], blength });
                        }
                        break;
                    }
                    else { //�ٴ��̸� �ٸ� ���� ����
                        blength++;
                    }

                    if (tmpx < 0) {
                        tmpx--;
                    }
                    else if (tmpx > 0) {
                        tmpx++;
                    }
                    else if (tmpy < 0) {
                        tmpy--;
                    }
                    else if (tmpy > 0) {
                        tmpy++;
                    }
                }
            }
        }
    }

    /*�ٸ� ������ MST ���ϱ�*/
    Union.resize(sNum);

    for (int i = 0; i < Union.size(); i++) {
        Union[i] = i;
    }

    int Edge_cnt = 0;
    int res = 0;

    while (pq.size() != 0) { 
        Edge now = pq.top();
        pq.pop();
        if (!isSame(now.s, now.e)){
            unionfunc(now.s, now.e);
            res += now.v;
            Edge_cnt++;
        }
    }

    if (Edge_cnt == sNum - 2) { //sNum�� 1���� �����Ͽ����Ƿ� ���� ���� ������ sNum���� 1 ���� ������
        cout << res << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}
void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        Union[b] = a;
    }
}

int find(int a) {
    if (a == Union[a]) {
        return a;
    }
    else {
        return Union[a] = find(Union[a]);
    }
    
}

bool isSame(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        return true;
    }
    return false;
}

void BFS(int i, int j) {
    queue<pair<int, int>> myq;
    mlist.clear();                  //�� ���� �ʱ�ȭ
    myq.push(make_pair(i, j));
    mlist.push_back(make_pair(i, j));
    visited[i][j] = true;
    map[i][j] = sNum;               //�� ��ȣ �ű��

    while (myq.size() != 0) {
        int x = myq.front().first;
        int y = myq.front().second;
        myq.pop();

        for (int i = 0; i < 4; i++) {
            int tmpx = dx[i];
            int tmpy = dy[i];

            while (x + tmpx >= 0 && x + tmpx < N && y + tmpy >= 0 && y + tmpy < M) { //4�������� �̵� ��, ���� �ȿ� ������ ��
                if (!visited[x + tmpx][y + tmpy] && map[x + tmpx][y + tmpy] != 0) {
                    map[x + tmpx][y + tmpy] = sNum; // �� ����
                    visited[x + tmpx][y + tmpy] = true; // �湮 ǥ��
                    mlist.push_back(make_pair(x + tmpx, y + tmpy));
                    myq.push(make_pair(x + tmpx, y + tmpy));
                }

                else {
                    break;
                }

                if (tmpx < 0) { //�� ���� 4���� ��ĭ�����θ� �̵��ϹǷ� ��ó�� ���� �� ������ �����ϰԲ� ��
                    tmpx--;
                }
                else if (tmpx > 0) {
                    tmpx++;
                }
                else if (tmpy < 0) {
                    tmpy--;
                }
                else if (tmpy > 0) {
                    tmpy++;
                }
            }
        }
    }
}