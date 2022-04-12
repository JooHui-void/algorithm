#include <stdio.h>

int arr[5001];
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	int start =0;
	int end = 10000;
	
	while(start<=end){
		int mid = (start+end)/2;
		int cut=1;
		
		int big=0;
		int small =9999999;
		for(int i=0;i<N;i++){
			
			if(arr[i]>big){
				big = arr[i];
			}
			if(arr[i]<small){
				small = arr[i];
			}
			
			if(big-small>mid){
				cut++;
				big = arr[i];
				small = arr[i];
			}else{
				continue;
			}
		}
	
		if(cut>M){
			start = mid+1;
		
		}else{
			end = mid-1;	
		}
		
	}
	printf("%d",start);
}
