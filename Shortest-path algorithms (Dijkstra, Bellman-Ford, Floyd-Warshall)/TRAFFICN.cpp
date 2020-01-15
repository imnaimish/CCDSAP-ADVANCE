#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1061109567;
using pii = pair<ll,ll>;

int n,m,k,s,t;
vector<vector<pii>> g,gr;
vector<ll> vis,dist1,dist2;

void dijkstra(int S, vector<vector<pii>> &g, vector<ll> &dist){
    vis.assign(n,0);
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    pq.push({0,S});
    dist[S] = 0;
    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();
        if(vis[v]==1)
            continue;
        vis[v]=1;
        for(pii p : g[v]){
            int u = p.first, len = p.second;
            if(dist[v]+len < dist[u]){
                dist[u] = dist[v]+len;
                pq.push({dist[u],u});
            }
        }
    }
}
int main(){
    int T; cin>>T;
    while(T--){
        cin>>n>>m>>k>>s>>t;
        g.clear(); vis.clear(); dist1.clear(); dist2.clear();
        g.assign(n,vector<pii>());
        gr.assign(n,vector<pii>());
        dist1.assign(n,INF);
        dist2.assign(n,INF);

        while(m--){
            int u,v,wt; cin>>u>>v>>wt;
            --u; --v;
            g[u].push_back({v,wt});
            gr[v].push_back({u,wt});
        }

        dijkstra(s-1,g,dist1);
        dijkstra(t-1,gr,dist2);

        int ans = dist1[t-1];
        while(k--){
            int a,b,wt; cin>>a>>b>>wt;
            --a;--b;
            int a1 = min(dist1[b],dist1[a]+wt)+dist2[b];
            int a2 = min(dist1[a],dist1[b]+wt)+dist2[a];
            ans = min(ans,min(a1,a2));
        }
        if(ans == INF)cout<<"-1\n";
        else cout<<ans<<"\n";
    }
}