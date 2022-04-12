#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

vector<int> v[20001];
int c[20001];

int isbi(int x,int color){
	if(c[x]==-1){
		c[x]=color;

		for(int i=0;i<v[x].size();i++){
			if(isbi(v[x][i],!color)==0){
				return 0;
			}
		}
		return 1;
	}else{
		if(c[x]!=color){
			return 0;
		}else{
			return 1;
		}
	}
	
}
int ans[5];
int main(){
	int num;
	scanf("%d",&num);
	int V,E;
	int t1,t2;
	memset(ans,1,sizeof(ans));
	for(int i=0;i<num;i++){
		memset(c,-1,sizeof(c));
		scanf("%d %d",&V,&E);
		for(int i=0;i<=V;i++){
			v[i].clear();
	
		}
		for(int j=0;j<E;j++){
			scanf("%d %d",&t1,&t2);
			v[t1].push_back(t2);
			v[t2].push_back(t1);
		}
		
		for(int j=1;j<=V;j++){
			if(c[j]==-1){
				ans[i] = ans[i]*isbi(j,0);
			}
		}
		
	
	}
	for(int i=0;i<num;i++){
		if(ans[i]){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
}
