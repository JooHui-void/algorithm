#include <stdio.h>
int coin[101];
long long dp[10001];

int main(){
	int sum,n;
	scanf("%d %d",&sum,&n);
	int t1,t2;
	dp[0]=1;
	for(int i=0;i<n;i++){
		scanf("%d %d",&t1,&t2);
		for(int j=10000;j>0;j--){
			for(int p =1;p<=t2;p++){
				if(j-t1*p>=0){
					dp[j]+=dp[j-t1*p];
				}
			
			}
		}
//		for(int t = 0;t<21;t++){
//			printf("%d ",dp[t]);
//		}
//		printf("\n");
	}
	printf("%d",dp[sum]);
}
