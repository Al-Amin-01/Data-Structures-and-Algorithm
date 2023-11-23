#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex,int parent){

    vis[vertex]=true;
    bool loop=false;
    for(int child : g[vertex]){
        if(vis[child] && child == parent) continue;
        if(vis[child]) return true;

        loop |= dfs(child,vertex);


    }

    return loop;

}

int main(){

    int n,e,x,y;
    cin >> n >> e;

    for(int i=0;i<e;i++){
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool loop=false;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(dfs(1,0)){
            loop=true;
            break;
        }
    }

    cout << loop << endl;


    return 0;
}