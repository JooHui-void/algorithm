#include <stdio.h>
#include <string.h>
#include <set>
#include <queue>
#include <iostream>
#include <string>

int _x[4]={-1,1,0,0};
int _y[4]={0,0,-1,1};

using namespace std;
set<string> s;
queue<pair<string,int> > q;

int main(){
	string s1 = "";
	char c;
	for(int i=0;i<9;i++){
		scanf(" %c",&c);
		s1+=c;
	}
	s.insert(s1);
	q.push(make_pair(s1,0));
	
	while(!q.empty()){
		if(q.front().first=="123456780"){
			printf("%d",q.front().second);
			return 0;
		}
		int zero= q.front().first.find('0');
		int x=zero/3;
		int y = zero%3;
		for(int i=0;i<4;i++){
			int xx=x+_x[i];
			int yy=y+_y[i];
			if(xx>=0&&xx<3&&yy>=0&&yy<3){
				string s2 = q.front().first;
				swap(s2[zero],s2[xx*3+yy]);

				if(s.find(s2)==s.end()){
					s.insert(s2);
					q.push(make_pair(s2,q.front().second+1));

				}
			}
		}
		q.pop();
	}
	printf("-1");
}


