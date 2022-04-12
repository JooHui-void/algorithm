#include <stdio.h>
#include <map>
#include <queue>
#include <string.h>
using namespace std;
queue<int> q;
vector<int> v[10001];
map<pair<int,int>, int> m;
int visit[100001];
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int min =99999999;
	int t1, t2,t3;
	int i1, i2;
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		if(min>t3){
			min = t3;
		}
		if(t1>t2){
			int tmp = t1;
			t1 = t2;
			t2 = tmp;
		}
		if(m.find(make_pair(t1,t2))==m.end()){
			m.insert(make_pair(make_pair(t1,t2),t3));
			v[t1].push_back(t2);
		}else{
			if(m[make_pair(t1,t2)]<t3){
				m[make_pair(t1,t2)]=t3;
			}
		}
		
	}
	scanf("%d %d",&i1,&i2);
	int start = min;
	int end = 1000000000;
	while(start<=end){
		int mid = (start+end)/2;
		
		memset(visit, 0, sizeof(visit));
		while(!q.empty()){
			q.pop();
		}
		q.push(i1);
		int check =0;
		while(!q.empty()){
			visit[q.front()]=1;
			if(q.front()==i2){
				check=1;
				break;
			}
			for(int i=0;i<v[q.front()].size();i++){
				int aa= q.front();
				int bb = v[q.front()][i];
				if(!visit[bb]){
					if(aa>bb){
						if(m[make_pair(bb,aa)]>=mid){
							q.push(bb);
						}
					}else{
						if(m[make_pair(aa,bb)]>=mid){
							q.push(bb);
						}	
					}
					
				}
				
				
			}
			
			q.pop();
		}
		
		if(check){
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
	printf("%d",end);
}
