#include<bits/stdc++.h>
using namespace std;

int x,diameter;

void dfs(int v,int cnt, vector<bool> &vis, vector<vector<int>> &adj){
	vis[v] = true;
	++cnt;
	for(int u : adj[v]){
		if(!vis[u]){
			if(cnt > diameter){
				diameter = cnt;
				x = u;
			}
			dfs(u,cnt,vis,adj);
		}
	}
}

int main(){
	int n; cin>>n;

	vector<vector<int>> adj(n,vector<int>());
	vector<bool> vis(n,false);

	for(int i=0;i<n-1;++i){
		int x,y; cin>>x>>y;
		--x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	diameter = INT_MIN;
	dfs(0,0,vis,adj);

	diameter = INT_MIN;
	vis.assign(n,false);
	dfs(x,0,vis,adj);

	cout<<diameter<<'\n';

	return 0;
}