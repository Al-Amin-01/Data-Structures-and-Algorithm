#include<bits/stdc++.h>
using namespace std;

const int N=1e4;
vector<int> g[N];
int vis[N];
int level[N];

void bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v]=1;

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout << cur << " ";
        for(int child: g[cur]){
            if(!vis[child]){
                vis[child]=1;
                q.push(child);
                level[child]=level[cur]+1;
            }


        }

    }
    cout << '\n';


}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);
    for(int i=1;i<=n;i++) cout <<  i << " : " << level[i] << endl;



    return 0;
}