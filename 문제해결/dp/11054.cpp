#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std; // lower bound : value보다 작지않은 첫번째 원소 위치  
///upper_bound : value 보다 더 큰 원소 위치 
//같은 값이 없다면 두 값은 같다. 
vector<int> v1;
vector<int> v2;
int small[1002];
int big[1001];
int arr[1001];
int min(int a, int b){
	return a<b?a:b;
}

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int num;
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		scanf("%d",&arr[i]);
	}
	int m = 0; 
	for(int i=1;i<=num;i++){
		int pos = lower_bound(v1.begin(),v1.end(),arr[i])-v1.begin();
		
		if(pos==v1.size()){
			v1.push_back(arr[i]);
		}else{
			v1[pos]=arr[i];
		}
		big[i]=v1.size();
	}
	for(int i=num;i>=1;i--){
		int pos = lower_bound(v2.begin(),v2.end(),arr[i])-v2.begin();
		
		if(pos==v2.size()){
			v2.push_back(arr[i]);
		}else{
			v2[pos]=arr[i];
		}
		small[i]=v2.size();
	}

	int Max =0;
	
//	for(int i=0;i<=num;i++){
//		printf("%d ",big[i]);
//	}
//	printf("\n");
//	for(int i=0;i<=num+1;i++){
//		printf("%d ",small[i]);
//	}
//	printf("\n");
//	
	for(int i=1;i<=num;i++){
		if(big[i]+small[i]-1>Max){
			Max = big[i]+small[i]-1;
		}
	}
	printf("%d",Max);
}
