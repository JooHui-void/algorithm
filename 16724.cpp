#include <stdio.h>
char arr[1001][1001];
int visit[1001][1001];
int cnt=0;
int M,N;
int sum=0;
void move(int x,int y,int cnt){

	visit[x][y]=cnt;
	
	if(arr[x][y]=='R'&&y+1!=N){
		if(visit[x][y+1]!=0){
			if(visit[x][y+1]!=cnt){
				sum--;

			}
		}else{
			move(x,y+1,cnt);	
		}
		
	}else if(arr[x][y]=='L'&&y!=0){
		if(visit[x][y-1]!=0){
			if(visit[x][y-1]!=cnt){
				sum--;

			}
		}else{
			move(x,y-1,cnt);	
		}		
	}else if(arr[x][y]=='U'&&x!=0){
		if(visit[x-1][y]!=0){
			if(visit[x-1][y]!=cnt){
				sum--;

			}
		}else{
			move(x-1,y,cnt);	
		}		
	}else{
		if(visit[x+1][y]!=0){
			if(visit[x+1][y]!=cnt){
				sum--;

			}
		}else{
			move(x+1,y,cnt);	
		}
	}
}

int main(){

	scanf("%d %d",&M,&N);
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			scanf(" %c",&arr[i][j]);
		}
	}
	

	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(visit[i][j]==0){
				move(i,j,++cnt);
				sum++;
			}
		}
	}
	
//	for(int i=0;i<M;i++){
//		for(int j=0;j<N;j++){
//			printf("%d ",visit[i][j]);
//		}
//		printf("\n");
//	}
	
	printf("%d",sum);
	
}
