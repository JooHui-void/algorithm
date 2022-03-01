#include <stdio.h>
char map[3072 +1][3072 * 2+1];

void divide(int x, int y, int size) {
	if (size == 3) {
		map[x][y] = 1;
		map[x + 1][y - 1] = 1;
		map[x + 1][y + 1] = 1;
		for (int i = y - 2; i <= y + 2; i++) {
			map[x + 2][i] = 1;
		}
	}
	else {
		/*printf("1");*/
		divide(x, y, size / 2);
		divide(x + size / 2, y + size / 2, size / 2);
		divide(x + size / 2, y - size / 2, size / 2);
	}
}
int main() {
	int num;
	scanf("%d", &num);

	divide(0, num, num);

	for (int i = 0; i < num ; i++) {
		for (int j = 1; j < num * 2; j++) {
			if (map[i][j] == 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}