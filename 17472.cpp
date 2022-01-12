#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int _x[4]={0,0,-1,1};
int _y[4]={1,-1,0,0};

int map[10][10];
int Cnt=2;
int m,n;
vector<pair<int,pair<int,int> > >v;
int parent[10];
void dfs(int x,int y){
	map[x][y]=Cnt;
	for(int i=0;i<4;i++){
		int xx=_x[i]+x;
		int yy = _y[i]+y;
		if(xx>=0&&xx<m&&yy>=0&&yy<n&&map[xx][yy]==1){
			dfs(xx,yy);
		}
	}
//	for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			printf("%d",map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
}
int iland[10][10];
void garo(int ilandnum,int x,int y){
	int cnt=0;
	while(y+1<n){
		if(map[x][y+1]!=0){
			if(ilandnum<map[x][y+1]){
				if(cnt>1&&iland[ilandnum][map[x][y+1]]>cnt){
					iland[ilandnum][map[x][y+1]]=cnt;
				
				}
				
			}else{
				if(cnt>1&&iland[map[x][y+1]][ilandnum]>cnt){
					iland[map[x][y+1]][ilandnum]=cnt;
				
				}	
			}
				return;
		}
			y++;
			cnt++;
		
	}
}
void sero(int ilandnum,int x,int y){
	int cnt=0;
	while(x+1<m){
		if(map[x+1][y]!=0){
			if(ilandnum<map[x+1][y]){
				if(cnt>1&&iland[ilandnum][map[x+1][y]]>cnt){
					iland[ilandnum][map[x+1][y]]=cnt;
				
				}
				
			}else{
				if(cnt>1&&iland[map[x+1][y]][ilandnum]>cnt){
					iland[map[x+1][y]][ilandnum]=cnt;
					
				}	
			}
			return;
		}
		x++;
		cnt++;
		
	}
}
int find(int x){
	if(x==parent[x]){
		return x;
	}else{
		int y = find(parent[x]);
		parent[x]=y;
		return y;
	}
}

int main(){

	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			iland[i][j]=999;
		}
	}
	for(int i=0;i<10;i++){
		parent[i]=i;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]==1){
				dfs(i,j);
				Cnt++;
			}
		}
	}
//	for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			printf("%d",map[i][j]);
//		}
//		printf("\n");
//	}
//		printf("\n");

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]>0&&j+1<n&&map[i][j+1]==0){
				garo(map[i][j],i,j);
			}
			if(map[i][j]>0&&i+1<m&&map[i+1][j]==0){
				sero(map[i][j],i,j);
			}
		}
	}
	for(int i=2;i<Cnt;i++){
		for(int j=i+1;j<Cnt;j++){
			if(iland[i][j]!=999){
				v.push_back(make_pair(iland[i][j],make_pair(i,j)));
			}
		}
	}
	sort(v.begin(),v.end());
//	for(int i=0;i<v.size();i++){
//		printf("%d %d %d\n",v[i].first,v[i].second.first,v[i].second.second);
//	}
	int sum=0;
	int c=0;
	for(int i=0;i<v.size();i++){
		int f1 = find(v[i].second.first);
		int f2 = find(v[i].second.second);
		if(f1!=f2){
			sum+=v[i].first;
			if(parent[f1]<parent[f2]){
				parent[f2]=f1;
			}else{
				parent[f1]=f2;
			}
			c++;
		}
		
	}
	if(c!=Cnt-3){
		printf("-1");
	}else{
		printf("%d",sum);
	}
//	printf("%d %d",c,sum);
}
