#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
vector<int> tree[N];
int height[N],depth[N];
void dfs(int vertex,int parent=0){

    //depth[vertex]=depth[parent]+1;
    for(int child: tree[vertex]){
        if(child==parent) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
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

    for(int i=1;i<=n;i++){
        cout << depth[i] << " " << height[i] << endl;

    }


    return 0;
}