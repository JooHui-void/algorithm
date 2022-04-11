#include <stdio.h>
#include <queue>

using namespace std;

int pos[10001]; // 중위순회를 통한 x좌표 
int node[10001][2]; // 트리 노드의 두 자식노드 번호
int cnt; //중위순회 번호 
int root; // 루트노드 번호
int check[10001]; // 루트노드 여부 저장

queue<pair<int, int> > q; //레벨 탐색 이용할 큐
void Inorder(int num) {} // 중위순회로 x좌표 구하는 함수
void FindRoot() {} // 루트 노드 구하는 함수




void Inorder(int num) { 

	if (node[num][0] != -1) {
		Inorder(node[num][0]);
	}

	pos[num] = ++cnt;

	if (node[num][1] != -1) {
		Inorder(node[num][1]);
	}

}// 중위순회로 x좌표 구하는 함수


void FindRoot() { // 루트 찾는 함수

	for (int i = 1; i <= num; i++) {
		if (check[i] == 0) {
			root = i;
			return;
		}
	}
}

int main() {

	int num, tmp; // num = 트리의 노드 수
	scanf("%d ", &num);
	for (int i = 0; i < num; i++) { 
		scanf("%d", &tmp); 
		scanf("%d %d", &node[tmp][0], &node[tmp][1]); //자식노드 번호 저장 

		if (node[tmp][1] != -1) { // 루트 아님을 체크
			check[node[tmp][1]]++;
		}
		if (node[tmp][0] != -1) {
			check[node[tmp][0]]++;
		}
	}

	FindRoot(); // 루트를 찾음
	Inorder(root); // 중위순회로 pos 에 번호 저장해둠

	q.push(make_pair(root, 1)); // 큐에 루트 번호와 레벨 1 pair로 넣어줌

	int level = 1; //
	int start = 1, end = 1; //레벨별 가장 왼쪽, 가장 오른쪽 x좌표 저장
	int Max = 0, Maxlevel = 0; // 가장 너비가 넓은 레벨, 그 레벨의 너비 저장

	while (!q.empty()) { //큐로 레벨순으로 탐색
		
		// 자식노드가 존재한다면 (!=-1) level을 1 더해서 큐에 넣어준다.
		if (node[q.front().first][0] != -1) { 
			q.push(make_pair(node[q.front().first][0], q.front().second + 1));
		}
		if (node[q.front().first][1] != -1) {
			q.push(make_pair(node[q.front().first][1], q.front().second + 1));
		}

		
		if (level != q.front().second) { // 현재 레벨과 다를경우 (== 다음 레벨로 넘어왔을 경우)
			int mid = pos[end] - pos[start] + 1; //앞 레벨의 너비 계산
			/*printf("%d:%d\n", level, mid);*/
			if (Max < mid) {	// 현재 저장한 Max보다 넓다면 최대너비, 레벨 갱신
				Max = mid;
				Maxlevel = level;
			}

			//다음 레벨 정보로 바꿔줌
			start = q.front().first; 
			end = q.front().second;
			level++;
		}
		else { // 현재 레벨과 같을 경우 
			end = q.front().first; // 오른쪽 x좌표 갱신 (무조건 더 넓어진다)
		}
		q.pop();
	}
	// 마지막 레벨의 너비 계산
	int mid = pos[end] - pos[start] + 1;

	if (Max < mid) {
		Max = mid;
		Maxlevel = level;
	}
	printf("%d %d", Maxlevel, Max);
}