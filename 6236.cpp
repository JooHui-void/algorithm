#include <stdio.h>
int money[100000];
	int N,M;
int find(int x){
	int cnt = 1;
	int sum=0;
	for(int i=0;i<N;i++){
		if(sum+money[i]>x){
			cnt++;
			sum=money[i];
		}else{
			sum+=money[i];
		}
	}
	return cnt;
}

int main(){

	
	int Max =0;
	scanf("%d %d",&N,&M);
	
	for(int i=0;i<N;i++){
		scanf("%d",&money[i]);
		if(money[i]>Max){
			Max = money[i];
		}
	}
	int start = Max, end = Max*N;
	int K=end;
	while(start<=end){
		int mid = (start+end)/2;
		int cnt = find(mid);
//		printf(" %d %d %d\n",cnt,start,end);
		if(cnt<=M){ // ´õ Å°¿öµµµÊ 
			end = mid-1;
		}else{
			start = mid+1;
				
		}
		
	}
	printf("%d\n",start); 
	
}
