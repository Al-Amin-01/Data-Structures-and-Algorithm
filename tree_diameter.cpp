#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> tree[N];
int depth[N];

void dfs(int vertex,int parent=0){

    
    for(int child:tree[vertex]){
        if(child == parent) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        

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
    int mx_node=-1;
    int mx_i;

    for(int i=1;i<=n;i++){
        if(mx_node<depth[i]){
            mx_node=depth[i];
            mx_i=i;
        }
        depth[i]=0;
    }

    dfs(mx_i);
    //mx_node=-1;
    for(int i=1;i<=n;i++){
        if(mx_node<depth[i]){
            mx_node=depth[i];
            
        }
    }

    cout << mx_node<< endl;


    

    return 0;

}