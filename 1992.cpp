#include <stdio.h>
int map[64][64];
void divide(int x,int y,int num){
	int zero = 0;
	int one = 0;
	
	for(int i=x;i<x+num;i++){
		for(int j=y;j<y+num;j++){
			if(map[i][j]==1){
				one++;
			}else{
				zero++;
			}
			if(zero&&one){
				printf("(");
				divide(x,y,num/2);
				divide(x,y+num/2,num/2);
				divide(x+num/2,y,num/2);
				divide(x+num/2,y+num/2,num/2);
				printf(")");
				return;
			}
		}
	}
	if(zero){
		printf("0");
	}else{
		printf("1");
	}

}
int main(){
	int num;
	scanf("%d",&num);
	
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	divide(0,0,num);
}
