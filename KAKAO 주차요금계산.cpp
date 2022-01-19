#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;
map<int,int>IN;
map<int,int> money;
int math(int in,int baset,int basem,int overt,int overm){
    int mid = in;
    if(mid<=baset){
        return basem;
    }else{
        int sum = basem;
        mid -=baset;
        mid+=+overt-1;
        mid=mid/overt;
        sum+=mid*overm;
        return sum;
    }
}
    

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    string s2;
    int h,min,num;
    char c;
    
    for(int i=0;i<records.size();i++){
        istringstream iss(records[i]);
        iss>>h>>c>>min>>num>>s2;
        int minut=h*60+min;
        if(IN.find(num)==IN.end()){
            IN.insert(make_pair(num,minut));
        }else{
            money[num]+=minut-IN[num];
            IN.erase(num);
//             if(s2=="IN"){
//                 int M=23*60+59;
//                 int Mon=math(IN[num],M,fees[0],fees[1],fees[2],fees[3]);
//                 money[num]+=Mon;
//                 printf("%d %d\n",num,Mon);
//                 IN.erase(num);
//                 IN.insert(make_pair(num,minut));
                
//             }else{
//                 int Mon = math(IN[num],minut,fees[0],fees[1],fees[2],fees[3]);
//                 money[num]+=Mon;
//                 printf("%d %d\n",num,Mon);
//                 IN.erase(num);
//             }
        }
    }
    int M=23*60+59;
    map<int,int>::iterator iter;
    for(iter=IN.begin();iter!=IN.end();iter++){
        money[iter->first]+=M-iter->second;
    }
    for(iter=money.begin();iter!=money.end();iter++){
        int Mon=math(iter->second,fees[0],fees[1],fees[2],fees[3]);
        answer.push_back(Mon);
    }
    return answer;
}
