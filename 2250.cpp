#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v;
int node[10001][2];
void preOrder(int num) {
	if(node[num][0]!=-1){
		preOrder(node[num][0]);
	}
	v.push_back(num);
	if (node[num][1] != -1) {
		preOrder(node[num][1]);
	}
}


int main() {
	int num,tmp;
	scanf("%d ", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		scanf("%d %d", node[tmp][0], &node[tmp][1]);
	}
	preOrder(1);
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
}