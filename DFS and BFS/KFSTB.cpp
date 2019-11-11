#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
const int MOD = 1E9 + 7;

int main(){
	FAST;

	int t; cin>>t;
	while(t--){

		int c,b,s,t; cin>>c>>b>>s>>t;
		vector<vector<int>> adj(c,vector<int>());
		vector<bool> vis(c,false);
		vector<int> ways(c,0);
		for(int i=0;i<b;++i){
			int x,y; cin>>x>>y;
			--x; --y;
			adj[x].push_back(y);
		}

		ways[s-1] = 1;
		
		queue<int> q;
		q.push(s-1);
		vis[s-1] = true;

		while(!q.empty()){
			int v = q.front();
			q.pop();

			for(int u : adj[v]){
				ways[u] = (ways[u]+ways[v])%MOD;
				if(!vis[u]){
					q.push(u);
					vis[u] = true;
				}
			}
		}

		cout<<ways[t-1]<<'\n';

	}
}