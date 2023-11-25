#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
const int INF=1e9;


int dijkstra(vector<int,int>> &g,int src,int n){
    vector<int> vis(N,0);
    vector<int> dist(N,INF);

    set<pair<int,int>> st;
    st.insert({0,src});
    dist[src]=0;
    while(st.size()!=0){
        auto x=*st.begin();
        int v=x.second;

        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v]=1;

        for(auto child : g[v]){
            int ch=child.first;
            int wt=child.second;
            if(dist[v]+wt<dist[ch]){
                dist[ch]=dist[v]+wt;
                st.insert({dist[ch],ch});
            }
        }

    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        if(dist[i]==1e9) return -1;
        ans=max(ans,dist[i]);
    }
    return ans;

    

}
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int>> g[N];
    for(int i=0;i<times.size();i++){
        g[times[i][0]].push_back({times[i][1],times[i][2]});
    }
    return dijkstra(g,k,n);
        
}
int main(){

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin >> x >> y >> wt;
        g[x].push_back({y,wt});
    }

    //dijkstra(1,n);

    return 0;

}