#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> tmp(board.size(), vector<int>(board[0].size()));
    for(int k=0;k<skill.size();k++){
        if(skill[k][0]==1){
            tmp[skill[k][1]][skill[k][2]]-=skill[k][5];
            if(skill[k][4]!=board[0].size()-1){
                tmp[skill[k][1]][skill[k][4]+1]+=skill[k][5];
            }
            if(skill[k][3]!=board.size()-1){
                tmp[skill[k][3]+1][skill[k][2]]+=skill[k][5];
            }
            if(skill[k][3]!=board.size()-1&&skill[k][4]!=board[0].size()-1){
                tmp[skill[k][3]+1][skill[k][4]+1]-=skill[k][5];
            }
            
        }else{
            tmp[skill[k][1]][skill[k][2]]+=skill[k][5];
            if(skill[k][4]!=board[0].size()-1){
                tmp[skill[k][1]][skill[k][4]+1]-=skill[k][5];
            }
            if(skill[k][3]!=board.size()-1){
                tmp[skill[k][3]+1][skill[k][2]]-=skill[k][5];
            }
            if(skill[k][3]!=board.size()-1&&skill[k][4]!=board[0].size()-1){
                tmp[skill[k][3]+1][skill[k][4]+1]+=skill[k][5];
            }
        }
        // for(int i=0;i<tmp.size();i++){
        // for(int j=0;j<tmp[0].size();j++){
        //     printf("%d ",tmp[i][j]);
        // }
        // printf("\n");
        // }
        // printf("\n");
    }
    
    for(int i=0;i<board.size();i++){
        for(int j=1;j<board[0].size();j++){
            tmp[i][j]+=tmp[i][j-1];
        }
    }
    for(int j=0;j<board[0].size();j++){
        for(int i=1;i<board.size();i++){
            tmp[i][j]+=tmp[i-1][j];
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(tmp[i][j]+board[i][j]>0){
                answer++;
            }
        }
    }
     // for(int i=0;i<tmp.size();i++){
     //    for(int j=0;j<tmp[0].size();j++){
     //        printf("%d ",tmp[i][j]+board[i][j]);
     //    }
     //    printf("\n");
     //    }
     //    printf("\n");
    return answer;
}
