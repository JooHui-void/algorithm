#include <stdio.h>


int arr[1000000];

int min(int a, int b){
	return a<b?a:b;
}
int main(){
	int num;
	scanf("%d",&num);
	arr[1]=0;
	int M;
	int two, three, minus;
	for(int i=2;i<=num;i++){
		M = arr[i-1]+1;
		if(i%2==0){
		
			M = min(M,arr[i/2]+1);
			
		}
		if(i%3==0){
			M = min(M, arr[i/3]+1);
		}
		arr[i]=M;
	}
	printf("%d",arr[num]);
	
}
