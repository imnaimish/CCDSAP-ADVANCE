#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans, indeg;

void dfs(int v){
    vis[v] = true;
    for(int u : adj[v]){
        if(!vis[u])dfs(u);
    }
    ans.push_back(v);
}
 
int main(){

    cin>>n>>m;
    adj.assign(n,vector<int>());
    vis.assign(n,false); indeg.assign(n,0);

    for(int i=0;i<m;++i){
        int a,b; cin>>a>>b;
        --a; --b;
        adj[a].push_back(b);
        ++indeg[b];
    } 

    for(int i=n-1;i>=0;--i){
        sort(adj[i].rbegin(),adj[i].rend());
    }

    for(int i=n-1;i>=0;--i){
        if(!vis[i]){
            dfs(i);
        }
    }

    reverse(ans.begin(),ans.end());

    for(int i=0;i<n;++i){
        if(indeg[ans[i]] > 0){
            cout<<"Sandro fails.\n"; return 0;
        }
        for(int u : adj[ans[i]]){
            --indeg[u];
        }
    }

    for(int i=0;i<n;++i)cout<<ans[i]+1<<" ";

}