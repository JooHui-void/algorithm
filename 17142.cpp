#include <stdio.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

int _x[4]={-1,1,0,0};
int _y[4]={0,0,-1,1};
using namespace std;
int map[50][50];
vector<pair<int,int> >v;
vector<pair<int,int> >pick;
queue<pair<pair<int,int>,int> >q;

int m,n;
int visit[50][50];
int max;
int Empty;

int tmp;
int Min=999999;
void back(int x,int start){
	if(x==n){
//		for(int i=0;i<pick.size();i++){
//			printf("%d %d  ",pick[i].first,pick[i].second);
//		}
//		printf("\n");
		memcpy(visit,map,sizeof(map));
		int empty_tmp=Empty;
		while(!q.empty()){
			q.pop();
		}
		
		for(int i=0;i<pick.size();i++){
			q.push(make_pair(pick[i],0));
		}
		
		while(!q.empty()){
			if(empty_tmp==0){
				break;
			}
			for(int i=0;i<4;i++){
				int xx=_x[i]+q.front().first.first;
				int yy=_y[i]+q.front().first.second;
				if(xx>=0&&xx<m&&yy>=0&&yy<m&&(visit[xx][yy]==0||visit[xx][yy]==999999)){
					if(visit[xx][yy]!=999999){
						empty_tmp--;
						tmp=q.front().second+1;
					}
					visit[xx][yy]=q.front().second+1;
					q.push(make_pair(make_pair(xx,yy),q.front().second+1));
					
				}
			}
			
			q.pop();
		}
		if(empty_tmp==0&&tmp<Min){
			Min=tmp;
		}
	}else{	
		if(start<v.size()){
			pick.push_back(v[start]);
			back(x+1,start+1);
			pick.pop_back();
			back(x,start+1);	
		}
			
	}
}

int main(){

	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==2){
				v.push_back(make_pair(i,j));
				map[i][j]=999999;
			}else if(map[i][j]==0){
				Empty++;
			}
		}
	}
	back(0,0);
	if(Min==999999){
		printf("-1");	
	}else{
		printf("%d\n",Min);
	}
	

}
