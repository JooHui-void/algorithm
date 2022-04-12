#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int X,Y;
int _x[4] = {1,-1,0,0};
int _y[4] = {0,0,1,-1};
int map[501][501];
int dp[501][501];
int back(int x,int y){

	if((x==X-1)&&(y==Y-1)){
		return 1;
	}
	
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	dp[x][y]=0;
	for(int i=0;i<4;i++){
		int xx = x+_x[i];
		int yy = y+_y[i];
		if(xx>=0&&xx<X&&yy>=0&&yy<Y){
			if(map[x][y]>map[xx][yy]){
				dp[x][y]+=back(xx,yy);
			}
		}
	}
	return dp[x][y];
}
int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d %d",&X,&Y);
	for(int i=0;i<X;i++){
		for(int j = 0; j<Y;j++){
			scanf("%d",&map[i][j]);
		}
	}
	int a = back(0,0);
	printf("%d",a);
	
}
 
