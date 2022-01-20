#include <string>
#include <vector>

using namespace std;
int Max=0;
int apeach[11];
int result[11];
int best[11];
int peachsum;
void cal(){
    peachsum=0;
    for(int i=0;i<10;i++){
        if(result[i]==0&&apeach[i]!=0){
            peachsum+=10-i;
        }
    }
}
void back(int start,int n,int sum){
    if(n>=0){
        cal();
        int minus = sum-peachsum;
        if(Max<minus){
            
            Max=minus;
            
            for(int i=0;i<11;i++){
                best[i]=result[i];
            }
            best[10]=n;
            printf("%d : ",Max);
            for(int i=0;i<11;i++){
                printf("%d ",best[i]);
            }
            printf("\n");
        }
        for(int i=start;i>=0;i--){
           result[i]=apeach[i]+1;
          back(i-1,n-apeach[i]-1,sum+10-i);
            result[i]=0;
        }   
    }
    
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    for(int i=0;i<=10;i++){
        apeach[i]=info[i];
    }
    back(9,n,0);
    if(Max!=0){
      for(int i=0;i<11;i++){
        answer.push_back(best[i]);
    }  
    }else{
        answer.push_back(-1);
    }
    
    return answer;
}
