#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)
using ll = long long;

vector<vector<int>> g,gr;
vector<set<int>> G,GR;
vector<ll> vis,order,cost,C;
int n,m,maxx;
void dfs1(int v){
    vis[v] = 1;
    for(int u : g[v]){
        if(vis[u] == 0)
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v){
    vis[v] = maxx;
    for(int u : gr[v]){
        if(vis[u] == -1)
            dfs2(u);
    }
}

int main(){
    FAST;

    cin>>n>>m;
    g.assign(n,vector<int>());
    gr.assign(n,vector<int>());
    cost.resize(n);

    for(int i=0;i<n;++i)cin>>cost[i];

    while(m--){
        int x,y; cin>>x>>y;
        g[x-1].push_back(y-1);
        gr[y-1].push_back(x-1);
    }

    vis.assign(n,0);
    for(int i=0;i<n;++i){
        if(vis[i] == 0)
            dfs1(i);
    }

    reverse(order.begin(), order.end());
    vis.assign(n,-1);
    maxx = 0;
    for(int i=0;i<n;++i){
        if(vis[order[i]] == -1){
            dfs2(order[i]);
            ++maxx;
        }
    }

    C.assign(maxx,0);
    for(int i=0;i<n;++i){
        C[vis[i]] += cost[i];
    }

    vector<int> outdeg(maxx,0);

    G.assign(maxx,set<int>());
    GR.assign(maxx,set<int>());
    for(int i=0;i<n;++i){
        for(int u : g[i]){
            if(vis[i] != vis[u] && G[vis[i]].find(vis[u]) == G[vis[i]].end()){
                G[vis[i]].insert(vis[u]);
                GR[vis[u]].insert(vis[i]);
            }
        }
    }

    for(int i=0;i<maxx;++i){
        outdeg[i] = (int)G[i].size();
    }

    vector<pair<ll,ll>> ans(maxx);
    queue<int> q;
    for(int i=0;i<maxx;++i){
        ans[i].first = C[i]; ans[i].second = C[i];
        if(outdeg[i] == 0)q.push(i);
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : GR[v]){
            --outdeg[u];
            if(outdeg[u] == 0)q.push(u);
            ans[u].second = max(ans[u].second, ans[v].second + ans[u].first);
        }
    }
    for(int i = 0; i < n; ++i)cout<<ans[vis[i]].second<<" ";
}