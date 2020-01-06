#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> low,tin;
set<int> st;
int timer = 0;

void dfs(int v, int p = -1){
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;

    for(int u : adj[v]){
      if(vis[u]){
        low[v] = min(low[v],tin[u]);
      }else{
        dfs(u,v);
        low[v] = min(low[v],low[u]);
        if(low[u] >= tin[v] && p!=-1)st.insert(v);
        ++children;
      }
    }

    if(children > 1 && p==-1)st.insert(v);
}
 
int main(){

    while(1){
      int n,m; cin>>n>>m;
      if(n==0 && m==0)return 0;
      adj.clear(); tin.clear(); low.clear(); timer = 0; st.clear();
      adj.assign(n,vector<int>());
      for(int i=0;i<m;++i){
        int x,y; cin>>x>>y;
        --x; --y;
        adj[x].push_back(y); adj[y].push_back(x);
      }

      vis.assign(n,false);
      tin.assign(n,-1);
      low.assign(n,-1);

      dfs(0);

      cout<<st.size()<<'\n';
    }

}