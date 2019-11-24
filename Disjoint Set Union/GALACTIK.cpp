#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

vector<vector<int>> adj;
vector<bool> vis;
vector<int> cost;
long long value;

void dfs(int v){
    vis[v] = true;
    if(cost[v] >= 0){
        value = min(value,(long long)cost[v]);
    }

    for(int u : adj[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
}
 
int main(){

    FAST;

    int n,m; cin>>n>>m;
    vis.assign(n,false);
    adj.resize(n); cost.resize(n);

    for(int i=0;i<m;++i){
        int x,y; cin>>x>>y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0;i<n;++i){
        cin>>cost[i]; 
        if(cost[i] < 0){
            cost[i] = INT_MAX;
        }
    }

    long long minn = INT_MAX, sum = 0, c = 0;
    for(int i=0;i<n;++i){
        if(!vis[i]){
            ++c;
            value = INT_MAX;
            dfs(i);
            minn = min(minn,value);
            sum += value;
        }
    }
    
    long long ans = minn*(c-1) + (sum-minn);
    if(ans >= INT_MAX)cout<<-1<<'\n';
    else cout<<ans<<'\n';
}