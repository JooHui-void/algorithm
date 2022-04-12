#include <stdio.h>
#include <string.h>

int arr[5001];
int num;
int dp[5001][5001];

int min(int a,int b){
	return a<b?a:b;
}

int back(int x,int y){
	if(x>=y){
		return 0;
	}
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	if(arr[x]==arr[y]){
		dp[x][y] = back(x+1,y-1);
	}else{
		dp[x][y]= min(back(x+1,y),back(x,y-1))+1;
	}
	return dp[x][y];
}
int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d",back(0,num-1));
}
