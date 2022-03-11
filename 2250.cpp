#include <stdio.h>
#include <queue>

using namespace std;

int pos[10001];
int node[10001][2];
int cnt;
int root;
int check[10001];

queue<pair<int, int> > q;

void Inorder(int num) { //중위순회 함수

	if (node[num][0] != -1) {
		Inorder(node[num][0]);
	}

	pos[num] = ++cnt;

	if (node[num][1] != -1) {
		Inorder(node[num][1]);
	}

}


void FindRoot() {

	for (int i = 1; i <= num; i++) {
		if (check[i] == 0) {
			root = i;
			return;
		}
	}
}

int main() {

	int num, tmp;
	scanf("%d ", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		scanf("%d %d", &node[tmp][0], &node[tmp][1]);
		if (node[tmp][1] != -1) {
			check[node[tmp][1]]++;
		}
		if (node[tmp][0] != -1) {
			check[node[tmp][0]]++;
		}
	}

	FindRoot(); // 루트를 찾음
	Inorder(root); // 중위순회로 pos 에 번호 저장해둠

	q.push(make_pair(root, 1));
	int level = 1;
	int start = 1, end = 1;
	int Max = 0, Maxlevel = 0;

	while (!q.empty()) {

		if (node[q.front().first][0] != -1) {
			q.push(make_pair(node[q.front().first][0], q.front().second + 1));
		}
		if (node[q.front().first][1] != -1) {
			q.push(make_pair(node[q.front().first][1], q.front().second + 1));
		}

		if (level != q.front().second) {
			int mid = pos[end] - pos[start] + 1;
			/*printf("%d:%d\n", level, mid);*/
			if (Max < mid) {
				Max = mid;
				Maxlevel = level;
			}
			start = q.front().first;
			end = q.front().second;
			level++;
		}
		else {
			end = q.front().first;
		}
		q.pop();
	}
	int mid = pos[end] - pos[start] + 1;

	if (Max < mid) {
		Max = mid;
		Maxlevel = level;
	}
	printf("%d %d", Maxlevel, Max);
}