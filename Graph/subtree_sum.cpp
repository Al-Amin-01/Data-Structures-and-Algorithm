#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> tree[N];
int sum[N];
int even[N];
void dfs(int vertex,int parent=0){

    
    for(int child:tree[vertex]){
        if(child == parent) continue;
        dfs(child,vertex);
        sum[vertex]+=sum[child];
        even[vertex]+=even[child];

    }
    sum[vertex]+=vertex; 
    if(vertex%2==0) even[vertex]++;
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
        cout << sum[i] << " " << even[i] << endl;
    }

    return 0;

}