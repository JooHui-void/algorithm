#include <stdio.h>
#include <string.h>
#include <iostream>

typedef struct B{
	bool a;
	bool b;	
}B;

B dp[17000][17000];

using namespace std;

string str1,str2;
int arr[2][17000];

void print(int x,int y){
	
	if(x==0&&y==0){
		return;
	}
	if(dp[x][y].a==false&&dp[x][y].b==false){
		print(x-1,y-1);
		printf("c %c\n",str1[x-1]);
	}else if(dp[x][y].a==false){
		print(x,y-1);
		printf("a %c\n",str2[y-1]);
	}else if(dp[x][y].b==false){
		print(x-1,y);
		printf("d %c\n",str1[x-1]);
		
	}else{
		print(x-1,y-1);
		printf("m %c\n",str2[y-1]);
	}
}
// 1 0 north d
// 0 1 west a
// 1 1 m
int main(){
	
	cin>>str1;
	cin>>str2;
	
	for(int i=1;i<=str1.length();i++){
		dp[i][0].a = true;
	}
	
	for(int i=1;i<=str2.length();i++){
		dp[0][i].b= true;
		arr[0][i]=i;
		arr[1][i]=i;
	}
	
	
	for(int i=1;i<=str1.length();i++){
		

		memcpy(arr[0],arr[1],sizeof(arr[0]));
		arr[0][0]=i-1;
		arr[1][0]=i;
		for(int j=1;j<=str2.length();j++){
			
			if(str1[i]==str2[j]){
				arr[1][j]=arr[0][j-1];
			}else{
				if((arr[0][j-1]<arr[0][j])&&(arr[0][j-1]<arr[1][j-1])){//m
					dp[i][j].a=true;
					dp[i][j].b=true;
					arr[1][j]=arr[0][j-1]+1;
				}else if(arr[0][j]<arr[1][j-1]){//d
				
					dp[i][j].a=true;
					arr[1][j]=arr[0][j]+1;
				}else{//a
					arr[1][j]=arr[1][j-1]+1;
					dp[i][j].b=true;
				}
				
				
			}
		}
//	for(int i=0;i<=str2.length();i++){
//			printf("%d ",arr[1][i]);
//		}
//		printf("\n");
	}

	print(str1.length(),str2.length());
//	for(int i=0;i<str1.length();i++){
//		for(int j=0;j<str2.length();j++){
//			printf("%d ",dp[i][j]);
//		}
//		printf("\n");
//	}
	
}
