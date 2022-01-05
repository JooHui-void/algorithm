#include <stdio.h>

int paper[10][10];
int Min=999;
int Cnt=0;
int size[6]={5,5,5,5,5,5};

int check(int x,int y,int k){
	if(x+k>10||y+k>10){
		return 0;
	}
	for(int i=x;i<x+k;i++){
		for(int j=y;j<y+k;j++){
			if(paper[i][j]==0){
				return 0;
			}
		}
	}
	return 1;
}
void make0(int x,int y,int k){
	for(int i=x;i<x+k;i++){
		for(int j=y;j<y+k;j++){
			paper[i][j]=0;
		}
	}
}
void make1(int x,int y,int k){
	for(int i=x;i<x+k;i++){
		for(int j=y;j<y+k;j++){
			paper[i][j]=1;
		}
	}
}
void back(int x,int y){
	int j=y;
	
//	for(int i=0;i<10;i++){
//		for(int j=0;j<10;j++){
//			printf("%d",paper[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	
	for(int i=x;i<10;i++){
		for(j;j<10;j++){
			if(paper[i][j]==1){
				for(int k=5;k>=1;k--){
					if(check(i,j,k)&&size[k]>0){
						make0(i,j,k);
						Cnt++;
						size[k]--;
						back(i,j+1);
						make1(i,j,k);
						size[k]++;
						Cnt--;
					}
				}
				return;
			}
		}
		j=0;
	}
	if(Min>Cnt){
		Min=Cnt;
	}
}

int main(){
	int n,m;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			
			scanf("%d",&paper[i][j]);
		}
	}
	back(0,0);
	if(Min==999){
		printf("-1");
	
	}else{
	printf("%d",Min);	
	}
	
}
