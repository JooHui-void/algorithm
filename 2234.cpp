#include <stdio.h>
int map[50][50];
int visit[50][50];
int cnt=1;
int count;
int arr[251];

void dfs(int x,int y){
	visit[x][y]=cnt;
	count++;
	if(!(map[x][y]&1)&&visit[x][y-1]==0){
		dfs(x,y-1);
	}
	if(!(map[x][y]&2)&&visit[x-1][y]==0){
		dfs(x-1,y);
	}
	if(!(map[x][y]&4)&&visit[x][y+1]==0){
		dfs(x,y+1);
	}
	if(!(map[x][y]&8)&&visit[x+1][y]==0){
		dfs(x+1,y);
	}
}

int main(){
	int m,n;

	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	int maxroom=0;
	int maxplus=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(!visit[i][j]){
				count=0;
				dfs(i,j);
				arr[cnt]=count;
				if(count>maxroom){
					maxroom=count;
				}
				cnt++;
				
			}
			
		}
	}
	int tmp;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(j!=n-1){
				if(visit[i][j]!=visit[i][j+1]){
					tmp=arr[visit[i][j]]+arr[visit[i][j+1]];
					if(tmp>maxplus){
						maxplus=tmp;
					}
				}
			}
			if(i!=m-1){
				if(visit[i][j]!=visit[i+1][j]){
					tmp=arr[visit[i][j]]+arr[visit[i+1][j]];
					if(tmp>maxplus){
						maxplus=tmp;
					}
				}
			}
		}
	}
	printf("%d\n%d\n%d",cnt-1,maxroom,maxplus);
//	for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			printf("%d ",visit[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for(int i=0;i<10;i++){
//		printf("%d ",arr[i]);
//	}
}
