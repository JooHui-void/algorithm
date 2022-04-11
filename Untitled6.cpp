#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<pair<int,int> > v;
map<int,int> m;
map<int,int> rev;
int arr[10001];
int ans[10001];
int main(){
	int num;
	scanf("%d",&num);
	int tmp;
	for(int i=0;i<num;i++){
		scanf("%d",&tmp);
		
		m.insert(make_pair(tmp,i));
		rev.insert(make_pair(i,tmp));
		v.push_back(make_pair(i,0));
	}
	
	for(int i=0;i<num;i++){
		scanf("%d",&tmp);
		v[i].second = m[tmp];
	}
	
//	sort(v.begin(),v.end());
	
	int len =1;
	arr[0]=v[0].second;
	for(int i=1;i<num;i++){
		
	
		int a = upper_bound(arr,arr+len,v[i].second)-arr;
		arr[a]=v[i].second;
		if(a==len){
			len++;
			
			for(int i=0;i<len;i++){
				ans[i]=arr[i];
			
			}	
		}
	}
	printf("%d\n",len);
	vector<int> vv;
	
	for(int i=0;i<len;i++){
		vv.push_back(rev[ans[i]]);
	}
	sort(vv.begin(),vv.end());
	for(int i=0;i<len;i++){
			printf("%d ",vv[i]);
		}
}
