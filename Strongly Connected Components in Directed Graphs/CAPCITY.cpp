#include <bits/stdc++.h>
using namespace std;

 
vector<vector<int>> g,gr;
vector<bool> vis;
vector<int> cmp;
stack<int> st;

void dfs1(int v){
  vis[v] = true;
  for(int u : g[v]){
    if(!vis[u]){
      dfs1(u);
    }
  }
  st.push(v);
}

void dfs2(int v){
  vis[v] = true;
  cmp.push_back(v+1);
  for(int u : gr[v]){
    if(!vis[u]){
      dfs2(u);
    }
  }
}

int main(){

    int n,m; cin>>n>>m;

    g.assign(n,vector<int>());
    gr.assign(n,vector<int>());

    for(int i=0;i<m;++i){
      int x,y; cin>>x>>y;
      --x; --y;
      g[x].push_back(y);
      gr[y].push_back(x);
    }

    vis.assign(n,false);

    for(int i=0;i<n;++i){
      if(!vis[i]){
        dfs1(i);
      }
    }

    vector<vector<int>> arr;
    vis.assign(n,false);

    while(!st.empty()){
      int i = st.top();
      st.pop();
      if(!vis[i]){
        cmp.clear();
        dfs2(i);
        sort(cmp.begin(), cmp.end());
        arr.push_back(cmp);
      }
    }

    vector<int> res = arr[arr.size() - 1];

    cout<<res.size()<<'\n';
    for(int i=0;i<res.size();++i)cout<<res[i]<<" ";
}