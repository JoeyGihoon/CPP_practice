#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

typedef tuple<int, int, int> edge;
vector<int> Union; //유니온 파인드 배열
struct cmp { //가중치 기준 오름차순 정렬 위한 구조체
	bool operator()(const edge& e1, const edge& e2) {
		int v1 = get<2>(e1);
		int v2 = get<2>(e2);
		return v1 > v2;
	}
};

void unionfunc(int a, int b);
int find(int a);
bool checksame(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E; //V: 노드 개수, E: 에지 개수
	cin >> V >> E;
	priority_queue<edge, vector<edge>, cmp> pq; //가중치 기준 오름차순 정렬
	Union.resize(V + 1);

	/*에지리스트에 데이터 저장*/
	for (int i = 0; i < E; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		pq.push(make_tuple(s, e, v));
	}

	/*유니온 파인드 배열 초기화*/
	for (int i = 1; i <= V; i++) {
		Union[i] = i;
	}

	int useEdge = 0; //찾은 에지 개수
	int res = 0; //찾은 에지의 가중치 더하기(정답)

	/*MST 구현*/
	while (useEdge < V - 1) {
		edge now = pq.top();
		pq.pop();
		int s = get<0>(now);
		int e = get<1>(now);
		int v = get<2>(now);
		if (!checksame(s, e)) {
			unionfunc(s, e);
			res = res + v;
			useEdge++;
		}
	}
	cout << res << '\n';

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
		return Union[a] = find(Union[a]); //거쳐간 모든 노드의 대표 노드 변경
	}
}

bool checksame(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) {
		return true;
	}
	else {
		return false;	
	}
}