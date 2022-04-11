#include <stdio.h>
#include <string.h>
int app[100][2];
int map[2][10000001];

int main(){
	int N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=0;i<N;i++){
		scanf("%d",&app[i][0]); // 가치  
	}
	
	for(int i=0;i<N;i++){
		scanf("%d",&app[i][1]); // 비용  
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(map[0][j]+app[i][0]<j){
				map[1][j]=map[0][j]+app[i][0];			
			}else if(){
				
			}else{
				map[1][j]=map[0][j-app[i][0]]+app[i][1]<map[0][j]?map[0][j-app[i][0]]+app[i][1]:map[0][j];
			} 
		}
		memcpy(map[0],map[1],sizeof(map[1]));
	}
	printf("%d",map[1][M]);
} 
