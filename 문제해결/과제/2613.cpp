#include <stdio.h>
int arr[300];

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int max =0;
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		if(arr[i]>max){
			max = arr[i];
		}
	}
	int start = max;
	int end = max*N;
	while(start<=end){
		int mid = (start+end)/2; // 구슬합 최소  
		int cnt =0;
		int sum = 0;
		for(int i=0;i<N;i++){
			if(arr[i]+sum>mid){
				sum = arr[i];
				cnt++;
			}else if(arr[i]+sum==mid){
				cnt++;
				sum=0;
			}else{
				sum+=arr[i];
			}
		}
		if(sum!=0){
			cnt++;
		}
		
		if(M<cnt){
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
	printf("%d\n",start);
	int cnt = 0;
	int sum =0;
	
	for(int i=0;i<N;i++){
		if(arr[i]+sum>start){
				sum = arr[i];
				printf("%d ",cnt);
				cnt=1;
			}else if(arr[i]+sum==start){
				printf("%d ",cnt+1);
				cnt=0;
				sum=0;
			}else{
				sum+=arr[i];
				cnt++;
			}
	}
	if(cnt!=0){
		printf("%d",cnt);
	}
}
