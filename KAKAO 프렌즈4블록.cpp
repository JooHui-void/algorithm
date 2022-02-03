#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;
char map[50][50];
int visit[50][50];
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            map[i][j]=board[i][j];
        }
    }
    int cnt =1;
    while(cnt){
        cnt=0;
        memset(visit,0,sizeof(visit));
        for(int i=0;i<board.size()-1;i++){
            for(int j=0;j<board[0].size()-1;j++){
                if(map[i][j]!=0&&map[i][j]==map[i][j+1]&&map[i][j]==map[i+1][j]&&map[i][j]==map[i+1][j+1]){
                    visit[i][j]=1;
                    visit[i][j+1]=1;
                    visit[i+1][j]=1;
                    visit[i+1][j+1]=1;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(visit[i][j]==1){
                    map[i][j]=0;
                    cnt++;
                }
            }
        }
        answer+=cnt;
        vector<int> v;
        for(int j=0;j<board[0].size();j++){
            v.clear();
            for(int i=board.size()-1;i>=0;i--){
                if(map[i][j]!=0){
                    v.push_back(map[i][j]);
                }
            }
            for(int k=0;k<v.size();k++){
                map[board.size()-k-1][j]=v[k];
            }
            for(int k=0;k<board.size()-v.size();k++){
                map[k][j]=0;
            }
        }
    }
    return answer;
}
