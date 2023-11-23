#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
int graph[N][N];
vector<pair<int,int>> graph2[N];
//vector<vector<pair<int,int>> graph2(N);
int main(){
    int n,m;
    cin >> n >> m;
    int v1,v2,w;
    for(int i=0;i<m;i++){
        cin >> v1 >> v2 >> w;
        graph[v1][v2]=w;
        graph[v2][v1]=w;

        graph2[v1].push_back({v2,w});
        graph2[v2].push_back({v1,w});
    }

    int x,y;
    cin >> x >> y;
    cout << graph[x][y] << '\n';
    bool f=0;
    for(auto child : graph2[x]){
        if(child.first==y) f=1,cout << child.second << '\n';
    }
    if(!f) cout << 0 << '\n';

    return 0;
}