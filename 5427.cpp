#include <stdio.h>
#include <queue>
#include <tuple>

using namespace std;

int _x[4]={0,0,-1,1};
int _y[4]={1,-1,0,0};

char map[1001][1001];
int test[100];
queue<tuple<int,int,int> > fire;
queue<tuple<int,int,int> >sang;
int main(){
	int cas;
	scanf("%d",&cas);
	int x,y;
	
	for(int c=0;c<cas;c++){
		
		while(!fire.empty()){
			fire.pop();
		}
		while(!sang.empty()){
			sang.pop();
		}
		scanf("%d %d",&y,&x);
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				scanf(" %c",&map[i][j]);
				if(map[i][j]=='@'){
					sang.push(make_tuple(i,j,0));
				}else if(map[i][j]=='*'){
					fire.push(make_tuple(i,j,0));
				}
			}
		}
		int time=0;
		while(!sang.empty()){
		
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					printf("%c",map[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			while(!sang.empty()&&get<2>(sang.front())==time){
				int pox=get<0>(sang.front());
				int poy=get<1>(sang.front());
				if(pox==0||poy==0||pox==x-1||poy==y-1){
					test[c]=time+1;
					while(!sang.empty()){
						sang.pop();
					}
					break;
				}else{
					for(int i=0;i<4;i++){
						int xx=_x[i]+pox;
						int yy = _y[i]+poy;
						if(xx>=0&&xx<x&&yy>=0&&yy<y){
							if(map[xx][yy]=='.'){
								map[xx][yy]='@';
								sang.push(make_tuple(xx,yy,time+1));
							}
						}
					}
				}
				sang.pop();
			}
			while(!fire.empty()&&get<2>(fire.front())==time){
				int pox=get<0>(fire.front());
				int poy=get<1>(fire.front());
				for(int i=0;i<4;i++){
					int xx=_x[i]+pox;
					int yy = _y[i]+poy;
					if(xx>=0&&xx<x&&yy>=0&&yy<y){
						if(map[xx][yy]=='@'||map[xx][yy]=='.'){
							map[xx][yy]='*';
							fire.push(make_tuple(xx,yy,time+1));
						}
					}
				}
				fire.pop();
			}
			time++;
		}
		
	}
	for(int i=0;i<cas;i++){
		if(test[i]==0){
			printf("IMPOSSIBLE\n");
		}else{
			printf("%d\n",test[i]);
		}
	}
}
