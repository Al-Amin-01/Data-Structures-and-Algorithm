#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> tree[N];
int par[N];

void dfs(int vertex,int parent=-1){

    par[vertex]=parent;
    for(int child:tree[vertex]){
        if(child == parent) continue;
        
        dfs(child,vertex);
        
    }
   
}
vector<int> path(int x){
    vector<int> ans;

    while(x!=-1){
        ans.push_back(x);
        x=par[x];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n,x,y;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    cin >> x >> y;
    dfs(1);
    vector<int> p1=path(x);
    vector<int> p2=path(y);
    int mn=min(p1.size(),p2.size());
    int lca=-1;
    for(int i=0;i<mn;i++){
        if(p1[i]==p2[i]) lca=p1[i];
        else break;
    }

    cout << lca << endl;
    

    return 0;

}