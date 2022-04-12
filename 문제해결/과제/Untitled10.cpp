#include <stdio.h>
int N,r,c;

long long visit(int x,int y,int size){
	printf("%d %d %d\n",x,y,size);
	if(size == 1){
		return 0;
	}
	if(r<x+size/2&&c<y+size/2){
		return visit(x,y,size/2);
	}else if(r>=x+size/2&&c<y+size/2){
		return visit(x+size/2,y,size/2)+2*size/2*size/2;
	}else if(r>=x+size/2&&c>=y+size/2){
		return visit(x+size/2,y+size/2,size/2)+3*size/2*size/2;
	}else{
		return visit(x,y+size/2,size/2)+size/2*size/2;
	}
}

int main(){
	scanf("%d %d %d",&N,&r,&c);
	int num = 1;
	for(int i=0;i<N;i++){
		num=num*2;
	}
	long long a=visit(0,0,num);	
	printf("%lld",a);
}
