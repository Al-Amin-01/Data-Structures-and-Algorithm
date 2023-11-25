#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
vector<int> dp(N,-1);

int coinChange(int amount,vector<int> &coins){
    
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];

    int ans=INT_MAX;
    for(int coin : coins){
        if(amount-coin>=0)
            ans=min(ans+0LL ,coinChange(amount-coin,coins)+1LL);
        else return INT_MAX;
    }
    //cout << ans << endl;
    return dp[amount]=ans;

}
int main(){
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin >> coins[i];
    int amount;
    cin >> amount;
    int ans=coinChange(amount,coins);
    if(ans==INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;


}