#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll,ll>;

int n,m; 

struct cmp{
    bool operator()(pii const& a, pii const& b){
        return a.first > b.first;
    }
};

ll solve(vector<vector<pii>> &adj){
    vector<ll> dist(2*n+2, LLONG_MAX);
    vector<bool> vis(2*n+2,false);

    priority_queue<pii, vector<pii>, cmp> pq;
    dist[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();

        if(vis[v])continue;
        vis[v] = true;

        if(vis[2*n+1])break;

        for(pii e : adj[v]){
            int u = e.first;
            if(!vis[u] && ((dist[v]+ e.second) < dist[u])){
                dist[u] = dist[v]+e.second;
                pq.push({dist[u],u});
            }

        }
    }

    return dist[2*n+1];
}


int main(){

    cin>>n>>m;
    vector<int> h(n+1), c(n+1);
    vector<vector<pii>> adj(2*n+2);

    for(int i=1;i<=n;++i)cin>>h[i];
    for(int i=1;i<=n;++i)cin>>c[i];

    for(int i=1;i<=m;++i){
        int u,v; cin>>u>>v;
        if(h[u] >= h[v]){
            adj[v].push_back({u,0});
            adj[n+u].push_back({n+v,0});
        }
        if(h[u] <= h[v]){
            adj[u].push_back({v,0});
            adj[n+v].push_back({n+u,0});
        }
    }

    for(int i=1;i<=n;++i){
        adj[i].push_back({n+i,c[i]});
        adj[n+i].push_back({i,c[i]});
    }

    adj[0].push_back({1,c[1]});
    adj[0].push_back({1+n,c[1]});
    adj[n].push_back({2*n+1,0});
    adj[2*n].push_back({2*n+1,0});

    ll ans = solve(adj);

    if(ans == LLONG_MAX)cout<<"-1";
    else cout<<ans;

}