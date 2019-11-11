#include<bits/stdc++.h>
using namespace std;

int diameter,x;
void dfs(int v, int cnt, vector<int> &vis, vector<vector<int>> &adj){
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

	int t; cin>>t;
	while(t--){

		int n; cin>>n;
		vector<vector<int>> adj(n,vector<int>());
		vector<int> vis(n,false);

		for(int i=0; i<n-1; ++i){
			int x,y; cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		diameter = INT_MIN;
		dfs(0,0,vis,adj);
		
		vis.assign(n,false);
		diameter = INT_MIN;
		dfs(x,0,vis,adj);
		
		if(diameter & 1){
			cout<<((diameter/2)+1)<<'\n';
		}else{
			cout<<diameter/2<<'\n';
		}

	}

}