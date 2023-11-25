#include<bits/stdc++.h>
using namespace std;

const int N=1e4;
const int INF = 1e9+7;
int n,m;
vector<pair<int,int>> g[N];
vector<int> lvl(N,INF);

int bfs(){
    deque<int> q;
    q.push_back(1);
    lvl[1]=0;

    while(!q.empty()){
        int cur=q.front();
        q.pop_front();

        for(auto child:g[cur]){
            int childValue=child.first;
            int wt=child.second;
            if(lvl[cur]+wt< lvl[childValue]){
                lvl[childValue]=lvl[cur]+wt;
                if(wt==0){
                    q.push_front(childValue);
                }
                else q.push_back(childValue);
            }
        }

    }
    return lvl[n];


}

int main(){

    cin >> n >> m;
    int x,y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        if(x==y) continue;
        g[x].push_back({y,0});
        g[y].push_back({x,1});

    }

    cout << bfs();


    return 0;
}
