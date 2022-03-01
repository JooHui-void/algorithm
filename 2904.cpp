#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v;
int cnt[1000000];
int prime[1000000];
void make() {
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == 0) {
			v.push_back(i);
		}
	}
}
void makePrime() {
	for (int i = 2; i < 1000000; i++) {
		if (prime[i] == 0) {
			int n = 2;
			int tmp = i*n;
			while (tmp <=1000000) {
				prime[tmp] = 1;
				n++;
				tmp = i * n;
			}
		}
	}
}
int primeSum[1000000]={0,};
int primeSave[100][1000000];
int main() {
	int num;
	scanf("%d", &num);
	makePrime();
	int tmp;
	make();
	primeSum[0] = 0;
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		int pos = 0;
		
		while (tmp != 1) {
			if (tmp % v[pos] == 0) {
				tmp = tmp / v[pos];
				primeSave[i][pos]++;
				primeSum[pos]++;
				
			}
			else {
				pos++;
			}
		}
		/*for (int j = 0; j < 10; j++) {
			printf("%d ", primeSave[i][j]);
		}
		printf("\n");*/
	}

	/*for (int j = 0; j < 10; j++) {
		printf("%d ", primeSum[j]);
	}
	printf("\n");*/

	int count = 0;
	int Max = 1;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < primeSum[i]/num; j++) {
			Max = Max * v[i];
		}
	}
	printf("%d ", Max);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 1001; j++) {
			if (primeSave[i][j] < primeSum[j] / num) {
				count += primeSum[j] / num - primeSave[i][j];
			}
		}
	}
	printf("%d", count);
}