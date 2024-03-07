#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

typedef tuple<int, int, int> edge;
vector<int> Union; //���Ͽ� ���ε� �迭
struct cmp { //����ġ ���� �������� ���� ���� ����ü
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

	int V, E; //V: ��� ����, E: ���� ����
	cin >> V >> E;
	priority_queue<edge, vector<edge>, cmp> pq; //����ġ ���� �������� ����
	Union.resize(V + 1);

	/*��������Ʈ�� ������ ����*/
	for (int i = 0; i < E; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		pq.push(make_tuple(s, e, v));
	}

	/*���Ͽ� ���ε� �迭 �ʱ�ȭ*/
	for (int i = 1; i <= V; i++) {
		Union[i] = i;
	}

	int useEdge = 0; //ã�� ���� ����
	int res = 0; //ã�� ������ ����ġ ���ϱ�(����)

	/*MST ����*/
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
		return Union[a] = find(Union[a]); //���İ� ��� ����� ��ǥ ��� ����
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