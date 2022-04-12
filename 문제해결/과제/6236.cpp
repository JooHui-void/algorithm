#include <stdio.h>
int arr[100001];
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int max = 0;
	
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		if(arr[i]>max){
			max = arr[i];
		}
	}
	
	int start =max;
	int end = max*N;
	while(start<=end){
		int mid = (start+end)/2; // ²¨³¾ µ·  
		int cnt = 0;
		int sum =0;
		for(int i=0;i<N;i++){
			if(sum+arr[i]>mid){
				sum=arr[i];
				cnt++;
			}else if(sum+arr[i]==mid){
				sum =0;
				cnt++;
			}else{
				sum+=arr[i];
			}
		}
		if(sum!=0){
			cnt++;
		}
		if(cnt>M){
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
	printf("%d",start);
}
