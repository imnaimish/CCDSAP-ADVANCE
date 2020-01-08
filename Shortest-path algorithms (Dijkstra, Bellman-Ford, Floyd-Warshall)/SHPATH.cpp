#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)
using pii = pair<int,int>;

vector<vector<pii>> adj;
unordered_map<string,int> mp;
vector<int> dist,vis;

int dijkstra(int n, int s, int d){
  if(s > d)
    swap(s,d);
  vis.assign(n+1,0);
  dist.assign(n+1,INT_MAX);

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0,s});
  dist[s] = 0;

  while(!pq.empty()){
    int v = pq.top().second;
    int wt = pq.top().first;
    if(v == d)break;
    pq.pop();
    if(vis[v])
      continue;

    vis[v] = true;
    for(auto p : adj[v]){
      int u = p.first;
      int len = p.second;
      if(dist[v] + len < dist[u]){
        dist[u] = dist[v]+len;
        pq.push({dist[u],u});
      }
    }
  }
  return dist[d];
}

int main(){

  FAST;

  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    adj.assign(n+1,vector<pii>());
    for(int i=1;i<=n;++i){
      string s; cin>>s;
      mp[s] = i;
      int m; cin>>m;
      while(m--){
        int x,wt; cin>>x>>wt;
        adj[i].push_back({x,wt});
      }
    }

    int r; cin>>r;
    while(r--){
      string x,y; cin>>x>>y;
      int ans = dijkstra(n,mp[x],mp[y]);
      cout<<ans<<"\n";
    }
  }
}