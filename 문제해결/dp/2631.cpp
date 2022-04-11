#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[201];
vector<int> v;
int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d",&arr[i]);
		int s = lower_bound(v.begin(),v.end(),arr[i])-v.begin();
		if(s==v.size()){
			v.push_back(arr[i]);
		}else{
			v[s]=arr[i];
		}
		
	}
	printf("%d",num-v.size());
}
