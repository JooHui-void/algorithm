#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int _y[4]={0,0,-1,1};
int _x[4]={-1,1,0,0};
int map[1000][1000];
int boundary[1000][1000];
int answer[1000][1000];
int m,n;
int cnt;
int tmp=3;
//boundary 에는 영역끼리 같은 수로 표기
//map에는 연결된 0의 수 표기
 
 void back(int x,int y){
 
	cnt++;
	boundary[x][y]=tmp;
	for(int i=0;i<4;i++){
		int xx=x+_x[i];
		int yy=y+_y[i];
		if(xx>=0&&xx<m&&yy>=0&&yy<n&&boundary[xx][yy]==0){
			back(xx,yy);

		}
	}
	
}

void back2(int x,int y){
	map[x][y]=cnt;
	for(int i=0;i<4;i++){
		int xx=x+_x[i];
		int yy=y+_y[i];
		if(xx>=0&&xx<m&&yy>=0&&yy<n&&map[xx][yy]==0){
			back2(xx,yy);
		}
	}
}

int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&map[i][j]);
		}
	}

	memcpy(boundary,map,sizeof(map));
	memcpy(answer,map,sizeof(map));
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(boundary[i][j]==0){
				cnt=0;
				tmp++;
				back(i,j);
				back2(i,j);
			}
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(answer[i][j]==1){
				vector<int> v;
				for(int p=0;p<4;p++){
					int xx=i+_x[p];
					int yy=j+_y[p];
					if(xx>=0&&xx<m&&yy>=0&&yy<n&&boundary[xx][yy]!=1){
						int check=0;
						for(int k=0;k<v.size();k++){
							if(v[k]==boundary[xx][yy]){
								check=1;
								break;
							}
						}
						if(!check){
							answer[i][j]+=map[xx][yy];
							v.push_back(boundary[xx][yy]);
						}
					}
				}
				answer[i][j]=answer[i][j]%10;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",answer[i][j]);
		}
		printf("\n");
	}
}
