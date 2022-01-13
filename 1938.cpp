#include <stdio.h>
#include <set>
#include <tuple>
#include <queue>
using namespace std;
queue<pair<tuple<int,int,int>,int > >q;
set<tuple<int,int,int> >s;

tuple<int,int,int> ans;
tuple<int,int,int> start;
int n;
char map[51][51];

void findB(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='B'){
				if(j+1<n&&map[i][j+1]=='B'){
					get<0>(start)=i;
					get<1>(start)=j+1;
					get<2>(start)=0;
				}else{
					get<0>(start)=i+1;
					get<1>(start)=j;
					get<2>(start)=1;
				}
				return;
			}
			
		}
	}
}

void findE(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='E'){
				if(j+1<n&&map[i][j+1]=='E'){
					get<0>(ans)=i;
					get<1>(ans)=j+1;
					get<2>(ans)=0;
				}else{
					get<0>(ans)=i+1;
					get<1>(ans)=j;
					get<2>(ans)=1;

				}
				return;
			}
			
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %c",&map[i][j]);
		}
	}
	findB();
	findE();
//	printf("%d %d %d\n\n",get<0>(ans),get<1>(ans),get<2>(ans));
	q.push(make_pair(start,0));
	while(!q.empty()){
	
		if(q.front().first==ans){
			printf("%d\n",q.front().second);
//			printf("%d %d %d",get<0>(q.front().first),get<1>(q.front().first),get<2>(q.front().first));
			return 0;
		}
		if(s.find(q.front().first)==s.end()){
			s.insert(q.front().first);
			int x = get<0>(q.front().first);
			int y = get<1>(q.front().first);
			int dir=get<2>(q.front().first);
			int time = q.front().second;
//			printf("%d %d %d %d\n",x,y,dir,time);
			if(dir==0){
				int tmp=0;
				int tmp2=0;
				if(x>0){
					for(int i=y-1;i<=y+1;i++){
						if(map[x-1][i]=='1'){
							tmp++;
						}
					}
					if(tmp==0){
						q.push(make_pair(make_tuple(x-1,y,dir),time+1));
					}
				}else{
					tmp=9;
				}
				if(x+1<n){
					for(int i=y-1;i<=y+1;i++){
						if(map[x+1][i]=='1'){
							tmp2++;
						}
					}
					if(tmp2==0){
						q.push(make_pair(make_tuple(x+1,y,dir),time+1));
					}
				}else{
					tmp2=9;
				}
				if(tmp==0&&tmp2==0){
					q.push(make_pair(make_tuple(x,y,1),time+1));
				}
				if(y-2>=0&&map[x][y-2]!='1'){
					q.push(make_pair(make_tuple(x,y-1,0),time+1));
				}
				if(y+2<n&&map[x][y+2]!='1'){
					q.push(make_pair(make_tuple(x,y+1,0),time+1));
				}
			}else{
				int tmp=0;
				int tmp2=0;
				if(y>0){
					for(int i=x-1;i<=x+1;i++){
						if(map[i][y-1]=='1'){
							tmp++;
						}
					}
					if(tmp==0){
						q.push(make_pair(make_tuple(x,y-1,dir),time+1));
					}
				}else{
					tmp=9;
				}
				if(y+1<n){
					for(int i=x-1;i<=x+1;i++){
						if(map[i][y+1]=='1'){
							tmp2++;
						}
					}
					if(tmp2==0){
						q.push(make_pair(make_tuple(x,y+1,dir),time+1));
					}
				}else{
					tmp2=9;
				}
				if(tmp==0&&tmp2==0){
					q.push(make_pair(make_tuple(x,y,0),time+1));
				}
				if(x-2>=0&&map[x-2][y]!='1'){
					q.push(make_pair(make_tuple(x-1,y,dir),time+1));
				}
				if(x+2<n&&map[x+2][y]!='1'){
					q.push(make_pair(make_tuple(x+1,y,dir),time+1));
				}
			}
		}
		
		q.pop();
	}
	printf("0");
}
