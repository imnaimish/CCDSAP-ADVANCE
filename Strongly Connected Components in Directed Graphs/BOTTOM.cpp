#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g,gr;
vector<bool> vis;
set<int> cmp;
vector<set<int>> arr;
stack<int> st;

int n,m;

void dfs1(int v){
  vis[v] = true;
  for(int u : g[v]){
    if(!vis[u])
      dfs1(u);
  }
  st.push(v);
}

void dfs2(int v){
  vis[v] = true;
  cmp.insert(v+1);
  for(int u : gr[v]){
    if(!vis[u])
      dfs2(u);
  }
}


int main(){

    while(1){
      cin>>n;
      if(n == 0)return 0;
      cin>>m;

      g.clear(); gr.clear(); vis.clear(); cmp.clear(); arr.clear();

      g.assign(n,vector<int>()); gr.assign(n,vector<int>());

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

      vis.assign(n,false);
      while(!st.empty()){
        int i = st.top();
        st.pop();

        if(!vis[i]){
          cmp.clear();
          dfs2(i);
          arr.push_back(cmp);
        }
      }

      vector<int> ans;

      for(set<int> p : arr){
        bool f = true;

        for(int u : p){
          int x = u-1;
          for(int v : g[x]){
            if(p.find(v+1) == p.end()){
              f = false;
            }
          }
        }

        if(f){
            for(int u : p)ans.push_back(u);
        }
      }

      sort(ans.begin(),ans.end());
      if(ans.size() == 0)cout<<'\n';
      else{
        for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
        cout<<'\n';
      }
    }

}