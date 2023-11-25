#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    //after entering vertex
    cout << "parent:" << vertex << '\n';
    vis[vertex]=true;
    for(int child : g[vertex]){
        if(vis[child]) continue;
        cout << "child:" << child << '\n';
        //if(vis[child]) continue;
        //before entering child
        dfs(child);
        //after exiting child
    }

    //before exiting vertex
}
int main(){
    int n,e,v1,v2;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }
    dfs(1);

    return 0;

}