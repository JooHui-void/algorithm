#include <stdio.h>
int arr[1000];
int ans[1000];
int max(int a,int b){
	return a>b?a:b;
}
int rev(int x){
	if(x<0)
		return -1*x;
	else
		return x;
}
int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	
	ans[1]=arr[1]-arr[0];
	
		
	ans[2]=max(max(rev(arr[1]-arr[0]),rev(arr[2]-arr[0])),rev(arr[2]-arr[1]));
	int x,y;
	for(int i=3;i<num;i++){
	
		if(arr[i]>arr[i-1]){
			x = arr[i]-arr[i-1];
		}else{
			x = arr[i-1]-arr[i];
		}
		int tmp = max(rev(arr[i]-arr[i-2]),rev(arr[i-1]-arr[i-2]));
		y = max(tmp,rev(arr[i-1]-arr[i]));
		ans[i]=max(max(x+ans[i-2],ans[i-1]),y+ans[i-3]);
	}
	
	printf("%d",ans[num-1]);
}
