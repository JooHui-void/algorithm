#include <stdio.h>
#include <string.h>

int map[51][51];
int map2[51][51];
int m,n,k;
int cas[6][3];
int visit[6];
int store[6];
int min=999999;

void print(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void move(int x,int y,int size){
	for(int i=1;i<=size;i++){
		int tmp=map[x+i][y+i];
		for(int p=x+i-1;p>=x-i;p--){
			map[p+1][y+i]=map[p][y+i];
		}
//		print();
		for(int p=y+i-1;p>=y-i;p--){
			map[x-i][p+1]=map[x-i][p];
		}
//		print();
		for(int p=x-i;p<x+i;p++){
			map[p][y-i]=map[p+1][y-i];
		}
//		print();
		for(int p=y-i;p<y+i;p++){
			map[x+i][p]=map[x+i][p+1];
		}
//		print();
		map[x+i][y+i-1]=tmp;
	}
//	print();
}
void back(int x){
	if(x==k){
		memcpy(map,map2,sizeof(map));
		for(int i=0;i<k;i++){
			int tmp = store[i];
			move(cas[tmp][0],cas[tmp][1],cas[tmp][2]);
		}
		for(int i=1;i<=m;i++){
			int tp=0;
			for(int j=1;j<=n;j++){
				tp+=map[i][j];
			}
			if(tp<min){
				min=tp;
			}
		}	
//		for(int i=0;i<k;i++){
//			printf("%d ",store[i]);
//		}
//		printf("\n");
	}else{
		for(int i=0;i<k;i++){
			if(!visit[i]){
				visit[i]=1;
				store[x]=i;
				back(x+1);
				visit[i]=0;
			}
		}
	}
	
}


int main(){
	
	scanf("%d %d %d",&m,&n,&k);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
			
		}
	}
	memcpy(map2,map,sizeof(map));
	int a, b,c;
	for(int i=0;i<k;i++){
		scanf("%d %d %d",&cas[i][0],&cas[i][1],&cas[i][2]);
	}
	

	back(0);
	
	printf("%d",min);
}
