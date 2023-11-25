#include<bits/stdc++.h>
using namespace std;
int dp[100];
int call(vector<int> &v,int len){

    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len];
    int ans=0;
    for(int i=1;i<=v.size();i++){
        if(len>=i){
            ans=max(ans,call(v,len-i)+v[i-1]);
        }
    }
    return dp[len]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int len;
    cin >> len;
    cout << call(v,len) << endl;


    
}