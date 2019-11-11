#include<bits/stdc++.h>
using namespace std;

int cnt;

void dfs(int v,vector<bool> &vis, vector<vector<int>> &adj){
	vis[v] = true;
	for(int u : adj[v]){
		if(!vis[u]){
			dfs(u,vis,adj);
		}
	}
}

int main(){

	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;

		vector<vector<int>> adj(n, vector<int>());
		vector<bool> vis(n,false);

		for(int i=0; i<m; ++i){
			int x,y; cin>>x>>y;
			adj[x].push_back(y); 
			adj[y].push_back(x);
		}

		cnt = 0;
		for(int i=0;i<n;++i){
			if(!vis[i]){
				dfs(i,vis,adj);
				++cnt;
			}
		}

		cout<<cnt<<'\n';

	}

}