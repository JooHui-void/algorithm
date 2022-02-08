#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <iostream>
int visit[3];
using namespace std;
long long a,b;
char c;
long long Max;
void back(int x,string s){
    cout<<s<<endl;
    if(x==3){
        // cout<<s<<endl;
        long long t = stoll(s);
        if(0>t){
            t*=-1;
        }
        if(Max<t){
            Max=t;
        }
    }else{
        for(int i=0;i<3;i++){
            if(visit[i]==0){
                visit[i]=1;
                string tmp = s;
                stringstream str(tmp);
                string n = "";
                str>>b;
                if(i==0){
                    a=b;
                    while(str>>c&&str>>b){
                        // cout<<c<<" "<<b<<endl;
                        if(c=='+'){
                            a+=b;
                        }else{
                            n+=to_string(a);
                            n+=c;
                            a=b;
                        }
                        
                    }
                    n+=to_string(a);
                    // cout<<n<<endl;
                    back(x+1,n);
                }else if(i==1){
                    a=b;
                    while(str>>c&&str>>b){
                        // cout<<c<<" "<<b<<endl;
                        if(c=='-'){
                            a-=b;
                        }else{
                            n+=to_string(a);
                            n+=c;
                            a=b;
                        }
                        
                    }
                    n+=to_string(a);
                    // cout<<n<<endl;
                    back(x+1,n);
                }else{
                    a=b;
                    while(str>>c&&str>>b){
                        // cout<<c<<" "<<b<<endl;
                        if(c=='*'){
                            a=a*b;
                        }else{
                            n+=to_string(a);
                            n+=c;
                            a=b;
                        }
                        
                    }
                    n+=to_string(a);
                    // cout<<n<<endl;
                    back(x+1,n);
                }
                visit[i]=0;
                // cout<<n<<endl;
            }
        }
    }
}
long long solution(string expression) {
    long long answer = 0;
    back(0,expression);

    return Max;
}
