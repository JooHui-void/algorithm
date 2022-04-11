#include <stdio.h>
#include <queue>

using namespace std;

int pos[10001]; // ������ȸ�� ���� x��ǥ 
int node[10001][2]; // Ʈ�� ����� �� �ڽĳ�� ��ȣ
int cnt; //������ȸ ��ȣ 
int root; // ��Ʈ��� ��ȣ
int check[10001]; // ��Ʈ��� ���� ����

queue<pair<int, int> > q; //���� Ž�� �̿��� ť
void Inorder(int num) {} // ������ȸ�� x��ǥ ���ϴ� �Լ�
void FindRoot() {} // ��Ʈ ��� ���ϴ� �Լ�




void Inorder(int num) { 

	if (node[num][0] != -1) {
		Inorder(node[num][0]);
	}

	pos[num] = ++cnt;

	if (node[num][1] != -1) {
		Inorder(node[num][1]);
	}

}// ������ȸ�� x��ǥ ���ϴ� �Լ�


void FindRoot() { // ��Ʈ ã�� �Լ�

	for (int i = 1; i <= num; i++) {
		if (check[i] == 0) {
			root = i;
			return;
		}
	}
}

int main() {

	int num, tmp; // num = Ʈ���� ��� ��
	scanf("%d ", &num);
	for (int i = 0; i < num; i++) { 
		scanf("%d", &tmp); 
		scanf("%d %d", &node[tmp][0], &node[tmp][1]); //�ڽĳ�� ��ȣ ���� 

		if (node[tmp][1] != -1) { // ��Ʈ �ƴ��� üũ
			check[node[tmp][1]]++;
		}
		if (node[tmp][0] != -1) {
			check[node[tmp][0]]++;
		}
	}

	FindRoot(); // ��Ʈ�� ã��
	Inorder(root); // ������ȸ�� pos �� ��ȣ �����ص�

	q.push(make_pair(root, 1)); // ť�� ��Ʈ ��ȣ�� ���� 1 pair�� �־���

	int level = 1; //
	int start = 1, end = 1; //������ ���� ����, ���� ������ x��ǥ ����
	int Max = 0, Maxlevel = 0; // ���� �ʺ� ���� ����, �� ������ �ʺ� ����

	while (!q.empty()) { //ť�� ���������� Ž��
		
		// �ڽĳ�尡 �����Ѵٸ� (!=-1) level�� 1 ���ؼ� ť�� �־��ش�.
		if (node[q.front().first][0] != -1) { 
			q.push(make_pair(node[q.front().first][0], q.front().second + 1));
		}
		if (node[q.front().first][1] != -1) {
			q.push(make_pair(node[q.front().first][1], q.front().second + 1));
		}

		
		if (level != q.front().second) { // ���� ������ �ٸ���� (== ���� ������ �Ѿ���� ���)
			int mid = pos[end] - pos[start] + 1; //�� ������ �ʺ� ���
			/*printf("%d:%d\n", level, mid);*/
			if (Max < mid) {	// ���� ������ Max���� �дٸ� �ִ�ʺ�, ���� ����
				Max = mid;
				Maxlevel = level;
			}

			//���� ���� ������ �ٲ���
			start = q.front().first; 
			end = q.front().second;
			level++;
		}
		else { // ���� ������ ���� ��� 
			end = q.front().first; // ������ x��ǥ ���� (������ �� �о�����)
		}
		q.pop();
	}
	// ������ ������ �ʺ� ���
	int mid = pos[end] - pos[start] + 1;

	if (Max < mid) {
		Max = mid;
		Maxlevel = level;
	}
	printf("%d %d", Maxlevel, Max);
}