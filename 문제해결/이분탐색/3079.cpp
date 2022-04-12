#include <stdio.h>
int time[100000];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	unsigned long long max =0;
	for(int i=0;i<n;i++){
		scanf("%d",&time[i]);
		if(max<time[i]){
			max = time[i];
		}
	}
	unsigned long long left = 0;
	unsigned long long right = max*m;
	
	while(left<=right){
		unsigned long long mid = (left+right)/2;
		unsigned long long sum =0;
		for(int i=0;i<n;i++){
			sum+=mid/time[i];
		}
		if(sum<m){
			left = mid+1;
		}else{
			right = mid-1;
		}
	}
	printf("%llu",left);
	
}
