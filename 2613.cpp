#include <stdio.h>
int marble[300];
int num,cut;
int divide(int x){
	int cnt = 1;
	int sum=0;
	for(int i=0;i<num;i++){
		if(marble[i]+sum>x){
			cnt++;
			sum = marble[i];
		}else{
			sum+=marble[i];
		}
	}

	return cnt;
}

int main(){
	int Max = 0;
	int max = 0;
	scanf("%d %d",&num,&cut);
	for(int i=0;i<num;i++){
		scanf("%d",&marble[i]);
		Max+=marble[i];
		if(max<marble[i]){
			max = marble[i];
		}
	}

	int start = max,end = Max;
	
	while(start<=end){
		int mid = (start+end)/2;
		int div = divide(mid);
		if(div>cut){
			start = mid+1;
		}else{
			end = mid-1;
		}
		
	}
	printf("%d\n",start);
	int sum =0;
	int cnt = 0;
	for(int i=0;i<num;i++){
//		printf("%d : %d\n",cut,num-i);
		if(sum+marble[i]>start){
			sum=marble[i];
			printf("%d ",cnt);
			cut--;
			cnt = 1;
		}else if(cut==num+1-i){
			sum=marble[i];
			printf("%d ",cnt);
			cut--;
			cnt = 1;
		}else{
			sum+=marble[i];
			cnt++;	
		}
	}
	printf("%d",cnt);
}
