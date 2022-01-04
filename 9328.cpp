#include <stdio.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
queue<pair<int ,int> >q;
int _y[4]={0,0,-1,1};
int _x[4]={-1,1,0,0};
char map[102][102];
int m,n;
int num;
int key[30];
int paper;
int answer[101];
void back(int x,int y){
	if(map[x][y]=='.'){
		map[x][y]='*';
	}else if(map[x][y]=='$'){
		paper++;
		map[x][y]='*';
	}else if(map[x][y]>='a'){
		key[map[x][y]-'a']++;
		map[x][y]='*';
	}else{
		if(key[map[x][y]-'A']){
			map[x][y]='*';
		}else{
			q.push(make_pair(x,y));
			return;
		}
	}
	
	for(int i=0;i<4;i++){
		int xx = x+_x[i];
		int yy = y+_y[i];
		if(xx>=0&&xx<m&&yy>=0&&yy<n&&map[xx][yy]!='*'){
			back(xx,yy);
		}
	}
}

int main(){
	scanf("%d",&num);
	
	for(int k=0;k<num;k++){
		while(!q.empty()){
			q.pop();
		}
		paper=0;
		memset(key,0,sizeof(key));
		memset(map,0,sizeof(map));
		scanf("%d %d",&m,&n);

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf(" %c",&map[i][j]);
			}
		}
		string arr;
		cin>>arr;
		if(arr!="0"){
			for(int i=0;i<arr.length();i++){
				key[arr.at(i)-'a']++;
			}
		}
		
		for(int i=0;i<m;i++){
			if(map[i][0]!='*'){
				back(i,0);
			}
			if(map[i][n-1]!='*'){
				back(i,n-1);
			}
		}
		for(int i=0;i<n;i++){
			if(map[0][i]!='*'){
				back(0,i);
			}
			if(map[m-1][i]!='*'){
				back(m-1,i);
			}
		}
		int circle=0;
		while(!q.empty()&&circle<50){
			int tmp = map[q.front().first][q.front().second];
			if(key[tmp-'A']){
				back(q.front().first,q.front().second);
				circle=0;
			}else{
				q.push(make_pair(q.front().first,q.front().second));
				circle++;
			}
			q.pop();
		}
		answer[k]=paper;
	}
	for(int i=0;i<num;i++){
		printf("%d\n",answer[i]);
	}
}
