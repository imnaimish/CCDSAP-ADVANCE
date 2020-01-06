#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> low, tin;
set<pair<int,int>> ans;
int timer;

void find_bridges(int v, int p = -1){
  vis[v] = true;
  tin[v] = low[v] = timer++;
  for(int u : adj[v]){
    if(u == p)continue;
    if(vis[u]){
      low[v] = min(low[v], tin[u]);
    }else{
      find_bridges(u,v);
      low[v] = min(low[v],low[u]);
      if(low[u] > tin[v]){
        int x = u, y = v;
        if(x > y)
          swap(x,y);
        if(ans.find({x,y}) == ans.end()){
          ans.insert({x,y});
        }
      }
    }
  }
}

int main(){
    int T; cin>>T;
    for(int t=1;t<=T;++t){

        int n,m; cin>>n>>m;
        adj.clear(); vis.clear(); ans.clear(); tin.clear(); low.clear(); timer = 0;
        adj.assign(n,vector<int>());
        vis.assign(n,false);
        tin.assign(n,-1);
        low.assign(n,-1);

        while(m--){
          int x,y; cin>>x>>y;
          --x; --y;
          adj[x].push_back(y);
          adj[y].push_back(x);
        }

        for(int i=0;i<n;++i){
          if(!vis[i]){
            find_bridges(i);
          }
        }

        cout<<"Caso #"<<t<<'\n';
        if(ans.size() == 0){
          cout<<"Sin bloqueos\n";
        }else{
          cout<<ans.size()<<'\n';
          for(pair<int,int> p : ans){
            cout<<p.first+1<<" "<<p.second+1<<'\n';
          }
        }

    }
}