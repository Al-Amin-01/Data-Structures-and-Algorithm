#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int h[N];
vector<int> dp(N,-1);
int callMe(int n){

    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int cost=callMe(n-1) + abs(h[n]-h[n-1]);
    if(n>1)
    cost=min(cost,callMe(n-2) + abs(h[n]-h[n-2]));
    return dp[n]=cost;


}


int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> h[i];
    
    cout << callMe(n-1) << endl;



    return 0;
}