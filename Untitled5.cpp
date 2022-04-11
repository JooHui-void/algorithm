#include <stdio.h>
#include <queue>
#include <set>
#include <cstdio>

using namespace std;
set<int> m;
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >q;
int main(){
	int arr[]={0,-1,0,-2,8,-2,0,-2,0};
	q.push(make_pair(0,0));
	while(!q.empty()){
		printf("%d %d\n",q.top().first,q.top().second);
		m.insert(q.top().first);
		if(q.top().first>=8){
			
			printf("%d",q.top().second);
			return 0;
		}
		if(arr[q.top().first]==0){
			for(int i=1;i<=6;i++){
				if(m.find(q.top().first+i)==m.end()){ 
					q.push(make_pair(q.top().first+i,q.top().second+1)); 
				}
			}
		}else{
			if(m.find(q.top().first+arr[q.top().first])==m.end()){ 
					q.push(make_pair(q.top().first+arr[q.top().first],q.top().second)); 
				}
		}
		q.pop();
	}
}
