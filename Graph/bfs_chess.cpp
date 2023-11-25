#include<bits/stdc++.h>
using namespace std;

int level[8][8];
int vis[8][8];
int getX(string s){
    return s[0]-'a';
}
int getY(string s){
    return s[1]-'1';
}

bool isValid(int x,int y){
    return x>=0 && y>=0 && x<8 && y<8;
}
vector<pair<int,int>> mov = {
    {2,1},{2,-1},
    {-2,1},{-2,-1},
    {1,2},{1,-2},
    {-1,2},{-1,-2}
};


int bfs(string src,string dst){
    int srcX=getX(src);
    int srcY=getY(src);
    int dstX=getX(dst);
    int dstY=getY(dst);

    queue<pair<int,int>> q;
    q.push({srcX,srcY});
    vis[srcX][srcY]=1;
    //level[srcX][srcY]=0;

    while(!q.empty()){
        pair<int,int> v=q.front();
        int px=v.first;
        int py=v.second;
        q.pop();

        for(auto m : mov ){
            int xs=px+m.first;
            int xy=py+m.second;

            if(!isValid(xs,xy)) continue;
            if(!vis[xs][xy]){
                q.push({xs,xy});
                level[xs][xy]=level[px][py]+1;
                vis[xs][xy]=1;
            }

        }
        if(vis[dstX][dstY]==1) break;

    }
    return level[dstX][dstY];


    

}
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << bfs(s1,s2) << endl;
    
    return 0;

}