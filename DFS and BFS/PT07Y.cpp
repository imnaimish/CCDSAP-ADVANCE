#include<bits/stdc++.h>
using namespace std;

int cnt;

void dfs(int v, vector<bool> &vis, vector<vector<int>> &adj){
	vis[v] = true;
	for(int u : adj[v]){
		if(!vis[u]){
			dfs(u,vis,adj);
		}
	}
}

int main(){
	int n,m; cin>>n>>m;

	vector<vector<int>> adj(n,vector<int>());
	vector<bool> vis(n,false);

	for(int i=0;i<m;++i){
		int x,y; cin>>x>>y;
		--x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	if(m != (n-1)){
		cout<<"NO\n"; return 0;
	}

	for(int i=0;i<n;++i){
		if(!vis[i]){
			++cnt;
			dfs(i,vis,adj);
		}
	}

	if(cnt == 1){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}

	return 0;
}