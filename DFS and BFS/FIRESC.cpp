#include<bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7;
vector<int> component;
int cnt;

void dfs(int v,vector<bool> &vis, vector<vector<int>> &adj){
	vis[v] = true;
	++cnt;

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
		component.clear();
		vector<vector<int>> adj(n, vector<int>());
		vector<bool> vis(n,false);

		for(int i=0; i<m; ++i){
			int x,y; cin>>x>>y;
			--x; --y;
			adj[x].push_back(y); 
			adj[y].push_back(x);
		}

		for(int i=0;i<n;++i){
			if(!vis[i]){
				cnt = 0;
				dfs(i,vis,adj);
				component.push_back(cnt);
			}
		}

		long long captain = 1;
		for(int i=0;i<component.size();++i){
			captain = (captain*component[i])%MOD;
		}

		cout<<(int)component.size()<<" "<<captain<<'\n';

	}

}