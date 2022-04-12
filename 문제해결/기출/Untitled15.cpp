#include <stdio.h>
int arr[100];
int dp[101][101];
int N,M;
int max(int x,int y){
	return x>y?x:y;
}
int sum(int x,int y){
	int sum=0;
	for(int i=x;i<=y;i++){
		sum+=arr[i];
	}
	return sum;
}
int find(int x,int cnt){
	
	if(x<=0){
		return -999999999;
	}
	if(cnt ==0){
		return 0;
	}
	if(dp[x][cnt]!=-999999999){
		return dp[x][cnt];
	}
	
	dp[x][cnt] = find(x-1,cnt); // 포함 안했을때  
	dp[x][cnt] = max(dp[x-1][cnt],sum(1,x));  //포함 했을때  
	for(int k=x-1;k>=1;k--){ // k == 빈칸  
		dp[x][cnt] = max(dp[x][cnt],find(k-1,cnt-1)+sum(k+1,x));
	}
	printf("%d %d %d\n",x,cnt,dp[x][cnt]);
	return dp[x][cnt];
	
	
}
int main(){
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			dp[i][j]=-999999999;
		}
	}
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d",find(N,M));
}
