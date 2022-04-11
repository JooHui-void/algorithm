#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <string.h>>
using namespace std;
map<pair<int,int>, int> m;
int N, M, K;
int dp[301][301];

int max(int x,int y){
	return x>y?x:y;
}

int plane(int x, int visit){
	if(visit==M && x!=N) //안되는 사례  
		return -99999999;
	if(x==N){ // 조건 성립
		return 0;  
	}
	
	if(dp[x][visit]!=-1){ // 방문한적 있음  
		return dp[x][visit];
	}
	dp[x][visit]=-99999999;
	
	for(int i=x+1;i<=N;i++){
		if(m.find(make_pair(x,i))!=m.end()){
			dp[x][visit] = max(dp[x][visit],plane(i,visit+1)+m[make_pair(x,i)]);
		}
	}
	return dp[x][visit];
}

int main(){

	scanf("%d %d %d",&N,&M,&K);
	int t1,t2,t3;
	for(int i=0;i<K;i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		if(t1>=t2){
			continue;
		}
		if(m.find(make_pair(t1,t2))==m.end()){ // 없음  
			m.insert(make_pair(make_pair(t1,t2),t3));
		}else{
			if(m[make_pair(t1,t2)]<t3){
				m[make_pair(t1,t2)]=t3;
			}
		}
	}
	
//	for(auto i:m){
//		printf("%d %d %d\n",i.first.first,i.first.second,i.second);
//	}
	for(int i=0;i<301;i++){
		for(int j=0;j<301;j++){
			dp[i][j]=-1;
		}
	}
	printf("%d",plane(1,1));
	
}
