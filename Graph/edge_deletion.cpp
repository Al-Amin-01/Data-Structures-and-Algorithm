#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> tree[N];
int sum[N];
int val[N];

void dfs(int vertex,int parent=-1){

    sum[vertex]+=vertex;
    for(int child:tree[vertex]){
        if(child == parent) continue;
        
        dfs(child,vertex);
        sum[vertex]+=sum[child];
        
    }
   
}


int main(){
    int n,x,y;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
   
    dfs(1);
    long long ans=0;
    for(int i=2;i<=n;i++){
        int sum1=sum[i];
        int sum2=sum[1]-sum1;

        ans=max(ans,sum1*1LL*sum2);

    }

    cout << ans << '\n';
 
    

    return 0;

}