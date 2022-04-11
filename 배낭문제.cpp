#include <stdio.h>

int map[101][100001];
int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	int W,V;
	for(int i=1;i<=N;i++){
		scanf("%d %d",&W,&V);
		for(int j=1;j<=K;j++){
			if(j<W){
				map[i][j]=map[i-1][j];
			}else{
				map[i][j]=map[i-1][j-W]+V>map[i-1][j]?map[i-1][j-W]+V:map[i-1][j];
			}
		}
		
	}
	printf("%d",map[N][K]);
}
