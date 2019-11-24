#include<bits/stdc++.h>
using namespace std;

int main(){
	string s; cin>>s;
	int n = s.size();
	
	vector<vector<int>> adj(10,vector<int>());
	vector<int> dist(n,INT_MAX);
	vector<bool> vis(n,false);

	for(int i=1;i<n;++i){
		adj[s[i]-'0'].push_back(i);
	}

	queue<int> q;
	q.push(0);
	vis[0] = true;
	dist[0] = 0;

	while(!q.empty()){
		int v = q.front();
		q.pop();
		if(v==(n-1))break;
		if((v-1 >= 0) && !vis[v-1]){
			vis[v-1] = true;
			dist[v-1] = dist[v] + 1;
			q.push(v-1);
		}

		if((v+1 < n) && !vis[v+1]){
			vis[v+1] = true;
			dist[v+1] = dist[v] + 1;
			q.push(v+1);
		}

		for(int u : adj[s[v]-'0']){
			if(!vis[u]){
				vis[u] = true;
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
		adj[s[v]-'0'].clear();
	}
	cout<<dist[n-1];
}