#include <string>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <set>
using namespace std;
map<string,int> ban;
map<string ,int> res;
set<string> s;
vector<string> v;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> tmp;
    string s1,s2;
    
    for(int i=0;i<report.size();i++){
        s.insert(report[i]);
        
    }
    set<string>::iterator iter;
    for(iter=s.begin();iter!=s.end();iter++){
        istringstream ss(*iter);
        ss>>s1>>s2;
        if(ban.find(s2)==ban.end()){
            ban.insert(make_pair(s2,1));
        }else{
            ban[s2]++;
        }
    }
    for(int i=0;i<id_list.size();i++){
        res.insert(make_pair(id_list[i],0));
        v.push_back(id_list[i]);
    }
    map<string,int>::iterator j;
    
    for(iter=s.begin();iter!=s.end();iter++){
        istringstream ss(*iter);
        ss>>s1>>s2;
        if(ban[s2]>=k){
            res[s1]++;
        }
    }
    
    for(int i=0;i<v.size();i++){
        answer.push_back(res.find(v[i])->second);
    }
    
    return answer;
}
