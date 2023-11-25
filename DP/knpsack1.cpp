#include<bits/stdc++.h>
using namespace std;
int wt[100];
int val[100];
long long dp[100][100];
long long knapsack(int ind,int amount){
    cout << "call " << ind << " " << amount << endl;
    if(amount==0) return 0;
    if(ind<0) return 0;
    //if(dp[ind][amount]!=-1) return dp[ind][amount];

    long long ans;
    ans=knapsack(ind-1,amount);
    if(wt[ind]<=amount)
        ans=max(ans,knapsack(ind-1,amount-wt[ind])+val[ind]);
    
    return ans;
}
int main(){
    int n;
    cin >> n;
    int amount;

    for(int i=0;i<n;i++) cin >> wt[i] >> val[i];
    cin >> amount;
    memset(dp,-1,sizeof(dp));
    cout << knapsack(n-1,amount);
    return 0;

}