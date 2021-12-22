#include <stdio.h>
#include <vector>

using namespace std;
int map[11][11];
vector<pair<int,int> > v;

int num;

int abs(int x){
	if(x<0){
		return -x;
	}else{
		return x;
	}
}

int check(int x,int y,int a,int b){
	if(abs(x-a)==abs(y-b)){
		return 0;
	}else{
		return 1;
	}
}

int c=0;
int maxx=0;
int maxx2=0;

void back(int x,int y){
	int j=y;
	if(num%2==1&&y==num+1){
		x=x+1;
		j=1;
	}else if(num%2==0){
		if(y==num+1){
			x=x+1;
			j=0;
			
		}else if(y==num){
			x=x+1;
			j=1;
		}
	}
	
	
	
	if(v.size()>maxx){
		maxx=v.size();
//		for(int i=0;i<num;i++){
//			for(int j=0;j<num;j++){
//				printf("%d ",map[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
	}
	
	for(int i=x;i<num;i++){
		for(j;j<num;j+=2){
			if(map[i][j]==1){
				c=0;
				for(int k=0;k<v.size();k++){
					if(!check(i,j,v[k].first,v[k].second)){
						c=1;
						break;
					}
				}
				if(c==0){
					map[i][j]=2;
					v.push_back(make_pair(i,j));
					
					back(i,j+2);
					v.pop_back();
					map[i][j]=1;
				}
				
			}
		}
		if(num%2==0){
			if(j==num+1){
				j=0;
			}else{
				j=1;
			}
		}else{
		if(j==num+1){
			j=1;
		}else{
			j=0;
		}	
		}
		
	}
}

void back2(int x,int y){
	
	int j=y;
	if(num%2==1&&y==num+1){
		x=x+1;
		j=1;
	}else if(num%2==0){
		if(y==num+1){
			x=x+1;
			j=0;
			
		}else if(y==num){
			x=x+1;
			j=1;
		}
	}

	if(v.size()>maxx2){
		maxx2=v.size();
//		for(int i=0;i<num;i++){
//			for(int j=0;j<num;j++){
//				printf("%d ",map[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
	}
	
	for(int i=x;i<num;i++){
		for(j;j<num;j+=2){
			if(map[i][j]==1){
				c=0;
				for(int k=0;k<v.size();k++){
					if(!check(i,j,v[k].first,v[k].second)){
						c=1;
						break;
					}
				}
				if(c==0){
					map[i][j]=2;
					v.push_back(make_pair(i,j));
					
					back2(i,j+2);
					v.pop_back();
					map[i][j]=1;
				}
			}
		}
		
		if(num%2==0){
			if(j==num+1){
				j=0;
			}else{
				j=1;
			}
		}else{
		if(j==num+1){
			j=1;
		}else{
			j=0;
		}	
		}
	}
}

int main(){

	scanf("%d",&num);
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			scanf("%d",&map[i][j]);
		}
	}
	back(0,0);
	v.clear();
//	printf("max2\n");
	back2(0,1);
//	printf("%d %d ",maxx,maxx2);
	printf("%d",maxx+maxx2);
}
