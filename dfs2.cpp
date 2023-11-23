#include<bits/stdc++.h>
using namespace std;

const int N=1e4;
vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> cur;
void dfs(int vertex){
    //after entering vertex
    vis[vertex]=1;
    cur.push_back(vertex);
    for(int child : g[vertex] ){
        //before entering child
        if(vis[child]) continue;
        dfs(child);

        //after exiting child
    }

    //before exiting vertex
}


int main(){
    int n,e,x,y,cnt=0;

    cin >> n >> e;

    for(int i=0;i<e;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        cur.clear();
        dfs(i);
        cc.push_back(cur);
        //cnt++;
    }

    cout << "total connected component : " << cc.size() << endl;
    for(auto cp : cc){
        for(int x:cp) cout << x << " ";
        cout << endl;
    }




    return 0;
}