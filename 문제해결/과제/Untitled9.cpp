#include <stdio.h>
#include <map>
using namespace std;
map<int,int> m;
long long dp[500001];
int prime[500001];
int dup[500001];
void make(){
	for(int i=2;i<500001;i++){
		if(prime[i]==0){
			int c = 2;
			
			while(c*i<500001){
				prime[c*i]=1;
				c++;
			}
		}
	}
}
int main(){
	make();
	prime[1]=1;
	prime[0]=1;

	int num;
	scanf("%d",&num);
	long long candy;
	dp[0]=1;
	long long max = 0;
	long long cnt=1;
	
	for(int i=0;i<num;i++){
		scanf("%d",&candy);
		if(m.find(candy)==m.end()){
			m.insert(make_pair(candy,1));
		}else{//Äµµð ÀÖÀ½  
			m[candy]++;
		}
	}
	
	for(auto iter:m){
		
		if(iter.first==0){
			cnt++;
			continue;
		}
		
		for(int j =max+candy;j>=candy;j--){
			dp[j]+=dp[j-candy];
			
		}
		max = max+candy;
		for(int j=0;j<=16;j++){
			printf("%d ",dp[j]);
		}
		printf("\n");
	}
	unsigned long long sum =0;
	for(int i=2;i<=max;i++){
		if(prime[i]==0){
			sum+=dp[i];
		}
	}

	sum= sum*cnt;
	printf("%lld",sum);
}
