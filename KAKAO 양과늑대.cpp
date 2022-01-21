#include <string>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
vector<int> v[18];
vector<int> pus(vector<int>vv,int x){
    
    int xx = vv[x];
    for(int i=0;i<v[xx].size();i++){
        vv.push_back(v[xx][i]);
    }
    vv.erase(vv.begin()+x);
    return vv;
}
int Max;
queue<tuple<int, int ,vector<int>>>q;
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
    }
   
    vector<int> tmp;
    for(int i=0;i<v[0].size();i++){
        tmp.push_back(v[0][i]);
    }
    q.push(make_tuple(1,0,tmp));
    while(!q.empty()){
        int lamb = get<0>(q.front());
        int wolf = get<1>(q.front());
        // printf("%d %d: ",lamb,wolf);
        // for(int i=0;i<get<2>(q.front()).size();i++){
        //     printf("%d ",get<2>(q.front())[i]);
        // }
        // printf("\n");
        if(Max<lamb){
            Max=lamb;
        }
        int ch=0;
        for(int i=0;i<get<2>(q.front()).size();i++){
            if(info[get<2>(q.front())[i]]==0){
                vector<int> tm=pus(get<2>(q.front()),i);
                q.push(make_tuple(lamb+1,wolf,tm));
                ch++;
                q.pop();
                break;
            }
        }
        if(!ch){
            if(lamb==wolf+1){
                q.pop();
            }else{
                for(int i=0;i<get<2>(q.front()).size();i++){
                    vector<int> tt=pus(get<2>(q.front()),i);
                    q.push(make_tuple(lamb,wolf+1,tt));
                }
                q.pop();
            }
            
        }
        
    }
    answer=Max;
    return answer;
}
