#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
string tmp;
set<string> ss;
map<string,int> m[11];
bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

void back(string s,int x){
    
    if(x!=tmp.length()){
        back(s,x+1);
        s+=tmp[x];
        int len=s.length();
    if(len>=2){
        if(m[len].find(s)==m[len].end()){
            m[len].insert(make_pair(s,1));
        }else{
            m[len][s]++;
        }
    }
        back(s,x+1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++){
        sort(orders[i].begin(),orders[i].end());
        tmp=orders[i];
        back("",0);
    }
   
    map<string,int>::iterator iter;
    for(int i=0;i<course.size();i++){
        int k = course[i];
        vector<pair<string,int>> v(m[k].begin(),m[k].end());
        sort(v.begin(),v.end(),cmp);
        if(v.size()!=0&&v[0].second>=2){
            int com=v[0].second;
            for(int j=0;j<v.size();j++){
                if(v[j].second==com){
                    answer.push_back(v[j].first);
                    
                }else{
                    break;
                }
            }
        }
//         for(int j=0;j<v.size();j++){
//             cout<<v[j].first<<" "<<v[j].second<<endl;
             
//         }
        
        
    }
    // for(iter=m[2].begin();iter!=m[2].end();iter++){
    //     cout<<iter->first<<endl;
    // }
    sort(answer.begin(),answer.end());
    return answer;
}
