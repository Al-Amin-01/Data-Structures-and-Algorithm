#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int dp[N];
int lis(int i){
    if(dp[i]!=-1) return dp[i];
    int ans=1;
    int j=0;
    while(j<i){
        if(a[i]>a[j]) ans=max(ans,lis(j)+1);
        j++;
    }
    return dp[i]=ans;
}
int main(){
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) cin >> a[i];

    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,lis(i));
    }

    cout << ans << endl;

    return 0;
}