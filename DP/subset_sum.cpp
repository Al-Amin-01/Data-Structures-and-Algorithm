#include<bits/stdc++.h>
using namespace std;

int dp[1000][100];
bool callMe(vector<int> &v,int ind,int amount){
    bool ans=false;
    if(amount==0) return true;
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    if(ind==v.size()) return false;

    ans|=callMe(v,ind+1,amount);
    if(amount-v[ind]>=0)
        ans|=callMe(v,ind+1,amount-v[ind]);

    return dp[ind][amount]=ans;


}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int amount;
    cin >> amount;
    if(callMe(v,0,amount)) cout << "true\n";
    else cout << "false";

    return 0;
}