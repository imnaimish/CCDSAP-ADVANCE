#include<bits/stdc++.h>
using namespace std;


int main(){
	int T; cin>>T;

	for(int t=1;t<=T;++t){
		int n,m; cin>>n>>m;
		vector<vector<int>> adj(n,vector<int>());

		for(int i=0;i<m;++i){
			int x,y; cin>>x>>y;
			--x; --y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		vector<int> side(n,-1);

		bool is_bipartite = true;

		queue<int> q;
		
		for(int i=0;i<n;++i){
			if(side[i] == -1){
				q.push(i);
				side[i] = 0;

				while(!q.empty()){
					int v = q.front();
					q.pop();

					for(int u : adj[v]){
						if(side[u] == -1){
							q.push(u);
							side[u] = side[v]^1;
						}else{
							is_bipartite &= (side[u] != side[v]);
						}
					}
				}
			}
		}

		if(is_bipartite){
			cout<<"Scenario #"<<t<<":\n";
			cout<<"No suspicious bugs found!\n";
		}else{
			cout<<"Scenario #"<<t<<":\n";
			cout<<"Suspicious bugs found!\n";
		}
	}

}