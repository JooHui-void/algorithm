#include <stdio.h>
int sdoku[9][9];
int tmp;
int check(int x,int y,int k){
	
	if(tmp){
		return 0;
	}
	for(int i=0;i<9;i++){
		if(sdoku[i][y]==k||sdoku[x][i]==k){
			return 0;
		}
	}
	int n=x-x%3;
	int m=y-y%3;
	for(int i=n;i<n+3;i++){
		for(int j=m;j<m+3;j++){
			if(sdoku[i][j]==k){
				return 0;
			}
		}
	}
	return 1;
}

void back(int x,int y){
	int j=y;
	for(int i=x;i<9;i++){
		
		for(j;j<9;j++){
			if(sdoku[i][j]==0){
				for(int k=1;k<=9;k++){
					if(check(i,j,k)){
					
						sdoku[i][j]=k;
						back(i,j+1);
						sdoku[i][j]=0;
					}
				}
				return;
			}
			
		}
		j=0;
	
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%d",sdoku[i][j]);
		}
		printf("\n");
	}
	tmp=1;
}
int main(){
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			scanf("%1d",&sdoku[i][j]);
		}
	}

	back(0,0);
	
}
