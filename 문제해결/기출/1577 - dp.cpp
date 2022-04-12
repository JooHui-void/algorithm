#include <stdio.h>
#include <tuple>
#include <set>
using namespace std;
long long map[101][101];
set<tuple<int,int,int,int> > s;
int main(){
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	int t1,t2,t3,t4;
	for(int i=0;i<K;i++){
		
		scanf("%d %d %d %d",&t1,&t2,&t3,&t4);
		if(t1<t3||t2<t4){
			s.insert(make_tuple(t1,t2,t3,t4));
		}else{
			s.insert(make_tuple(t3,t4,t1,t2));
		}
	}
	map[0][0]=1;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			if(i!=0){
				if(s.find(make_tuple(i-1,j,i,j))==s.end()){
					map[i][j]+=map[i-1][j];
				}
				
			}
			if(j!=0){
				if(s.find(make_tuple(i,j-1,i,j))==s.end()){
					map[i][j]+=map[i][j-1];
				}
			}
		}
	}
	printf("%lld",map[N][M]);
}
