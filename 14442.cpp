#include <stdio.h>
#include <queue>
using namespace std;
int map[21][21];
int visit[21][21][2];
int _x[4]={0,0,1,-1};
int _y[4]={1,-1,0,0};
queue<vector<int> > q;
int Min=9999;
int main(){
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	vector<int> v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(K);
	q.push(v);
	visit[0][0][0]=0;
	visit[0][0][1]=K;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			visit[i][j][0]=99999;
		}
	}
	while(!q.empty()){
		
		
		visit[q.front()[0]][q.front()[1]][0]=q.front()[2];
		visit[q.front()[0]][q.front()[1]][1]=q.front()[3];
//		for(int i=0;i<N;i++){
//			for(int j=0;j<M;j++){
//				printf("%d ",visit[i][j][0]);
//			}
//			printf("\n");
//		}
//		
//		printf("\n");
		if(q.front()[0]==N-1&&q.front()[1]==M-1){
			if(Min>q.front()[2]){
				Min=q.front()[2];
			}
		}else{
			for(int i=0;i<4;i++){
				int xx=_x[i]+q.front()[0];
				int yy= _y[i]+q.front()[1];
				
				if(xx>=0&&xx<N&&yy>=0&&yy<M){
					
					
					if(map[xx][yy]==1&&q.front()[3]>0){
						if(visit[xx][yy][0]<q.front()[2]+1&&visit[xx][yy][1]>=q.front()[3]-1){
							continue;
						}
						vector<int> v1;
						v1.push_back(xx);
						v1.push_back(yy);
						v1.push_back(q.front()[2]+1);
						v1.push_back(q.front()[3]-1);
						q.push(v1);
						
					}else if(map[xx][yy]==0){
						if(visit[xx][yy][0]<q.front()[2]+1&&visit[xx][yy][1]>=q.front()[3]){
							continue;
						}
						vector<int> v1;
						v1.push_back(xx);
						v1.push_back(yy);
						v1.push_back(q.front()[2]+1);
						v1.push_back(q.front()[3]);
						q.push(v1);
					}
				}
			}
		}
		
		q.pop();
		
	}
	if(Min==9999){
		printf("-1");
	}else{
			printf("%d",Min+1);
	}

}
