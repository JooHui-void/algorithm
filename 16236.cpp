#include <stdio.h>
#include <queue>
#include <tuple>
#include <stdlib.h>
#include <string.h>
using namespace std;
int _x[4]={-1,0,0,1};
int _y[4]={0,-1,1,0};
int num;

queue<tuple<int,int,int> >q;
int map[20][20];
int visit[20][20];
int size=2;
int point =0;
int step=0;

void print(){
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			printf("%d ",map[i][j]);
		}
		printf("   ");
		for(int j=0;j<num;j++){
			printf("%d ",visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){

	scanf("%d",&num);
	int posx,posy;
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==9){
				posx=i;
				posy=j;
				map[i][j]=0;
			}
			
		}
	}
	visit[posx][posy]=1;
	q.push(make_tuple(posx,posy,0));
		
	while(!q.empty()){
		int time =get<2>(q.front());
		print();
		printf("%d\n",step);
		int x=get<0>(q.front());
		int y = get<1>(q.front());
		visit[xx][yy]=1;
		
		if(map[x][y]!=0){
			if(map[x][y]<size){
				map[x][y]=0;
				step+=time;
				point++;
				if(point==size){
					size++;
					point=0;
				}
				memset(visit,0,sizeof(visit));
				visit[xx][yy]=1;
				while(!q.empty()){
					q.pop();
				}
				q.push(make_tuple(x,y,0));
				q.push(make_tuple(x,y,0));
				break;
			}else if(map[x][y]==size){
				visit[x][y]=1;
				q.push(make_tuple(x,y,time));
			}
		}else{
			visit[x][y]=1;
			q.push(make_tuple(xx,yy,time+);
					
		}
		
		
		for(int i=0;i<4;i++){
			int xx= _x[i]+get<0>(q.front());
			int yy= _y[i]+get<1>(q.front());
			
			if(xx>=0&&xx<num&&yy>=0&&yy<num&&visit[xx][yy]==0){
//				printf("%d %d %d\n",xx,yy,map[xx][yy]);
				q.push(make_tuple(xx,yy,time+1));
			}	
		}
		q.pop();	
	}
	printf("%d",step);
	
}
