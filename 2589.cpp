#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;
queue<pair<int,int> > q;
char map[51][51];
int map2[51][51];
int Max=0;
int _x[4]={0,0,-1,1};
int _y[4]={1,-1,0,0};
int main(){
	int N,M;
	
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%s",map[i]);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='L'){
				while(!q.empty()){
					q.pop();
				}
				memset(map2,0,sizeof(map2));
				map2[i][j]=1;
				q.push(make_pair(i,j));
				while(!q.empty()){
					if(map2[q.front().first][q.front().second]>Max){
						Max=map2[q.front().first][q.front().second];
//						for(int p=0;p<N;p++){
//							for(int q=0;q<M;q++){
//								printf("%d ",map2[p][q]);
//							}
//							printf("\n");
//						}
//						printf("\n");
					}
					for(int k=0;k<4;k++){
						int xx=_x[k]+q.front().first;
						int yy=_y[k]+q.front().second;
						if(xx>=0&&xx<N&&yy>=0&&yy<M){
							if(map[xx][yy]=='L'&&map2[xx][yy]==0){
								map2[xx][yy]=map2[q.front().first][q.front().second]+1;
								q.push(make_pair(xx,yy));
							}
						}
					}
					
					q.pop();
				}
			}
		}
	}
	printf("%d",Max-1);
}
