#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
vector<pair<int,int> >ans;
int real[1001];
int main(){
	int num;
	scanf("%d",&num);
	int tmp;
	for(int i=0;i<num;i++){
//		for(int i=0;i<v.size();i++){
//			printf("%d ",v[i]);
//			
//		}
//		printf("\n");
		scanf("%d",&tmp);
		int lower = lower_bound(v.begin(),v.end(),tmp)-v.begin();
		if(lower==v.size()){
			v.push_back(tmp);
			ans.push_back(make_pair(lower,tmp));
		}else{
			v[lower]=tmp;
			ans.push_back(make_pair(lower,tmp));
		}
	}
	printf("%d\n",v.size());
	int cnt = v.size()-1;
	for(int i=ans.size()-1;i>=0;i--){
		if(ans[i].first==cnt){
			real[cnt]=ans[i].second;
			cnt--;
			if(cnt==-1){
				break;
			}
		}
	}

	for(int i=0;i<v.size();i++){
		printf("%d ",real[i]);
	}
}
// 9 10 7 8 9 5
// 0 1  0 1 2 0
