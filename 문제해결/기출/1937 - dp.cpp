#include <stdio.h>
int _x[4]={0,0,1,-1};
int _y[4]= {1,-1,0,0};
int max(int a,int b){
	return a>b?a:b;
}
int size;
int map[501][501];
int dp[501][501];
int M;
int move(int x,int y){
	if(dp[x][y]!=0){
		return dp[x][y];
	}
	dp[x][y]=1;
	for(int i=0;i<4;i++){
		int xx = x+_x[i];
		int yy = y+_y[i];
		if(xx>=0&&xx<size&&yy>=0&&yy<size){
			if(map[xx][yy]<map[x][y]){
				dp[x][y]=max(move(xx,yy)+1,dp[x][y]);
			}
		}
	}
	
	return dp[x][y];
}
int main(){
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(dp[i][j]==0){
				move(i,j);
			}
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(M<dp[i][j]){
				M = dp[i][j];
			}
		}
	}

	printf("%d",M);
} 
