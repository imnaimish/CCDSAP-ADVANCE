#include<bits/stdc++.h>
using namespace std;
struct node{
	long long vertex, distance, mode = -1;
};

int n,m;
vector<vector<node>> adj;
vector<long long> dist, h, c;

struct cmp{
	bool operator()(node const& a, node const& b){
		return a.distance > b.distance;
	}
};

int main(){
	cin>>n>>m;
	adj.resize(n); dist.assign(n,LLONG_MAX);
	h.resize(n); c.resize(n);

	for(int i=0;i<n;++i){
		cin>>h[i];
	}

	for(int i=0;i<n;++i){
		cin>>c[i];
	}

	for(int i=0;i<m;++i){
		int x,y; cin>>x>>y;
		--x; --y;
		node nx,ny;

		nx.vertex = x; nx.distance = LLONG_MAX;
		ny.vertex = y; ny.distance = LLONG_MAX;

		adj[nx.vertex].push_back(ny);
		adj[ny.vertex].push_back(nx);
	}

	priority_queue<node, vector<node>, cmp> pq;

	node temp;
	temp.vertex = 0;
	temp.distance = 0;
	dist[0] = 0;
	pq.push(temp);

	while(!pq.empty()){

		node v = pq.top();
		pq.pop();

		for(node u : adj[v.vertex]){
			if(h[v.vertex] > h[u.vertex]){
				if(v.mode == 0){
					if(v.distance < u.distance){
						u.distance = v.distance;
						u.mode = 0;
						pq.push(u);
					}
				}else{
					if(u.distance > (v.distance + c[v.vertex])){
						u.distance = v.distance + c[v.vertex];
						u.mode = 0;
						pq.push(u);
					}
				}
			}else if(h[v.vertex] < h[u.vertex]){
				if(v.mode == 1){
					if(v.distance < u.distance){
						u.distance = v.distance;
						u.mode = 1;
						pq.push(u);
					}
				}else{
					if((v.distance + c[v.vertex]) < u.distance){
						u.distance = v.distance + c[v.vertex];
						u.mode = 1;
						pq.push(u);
					}
				}
			}else{
				if(v.distance < u.distance){
					u.distance = v.distance;
					u.mode = v.mode;
					pq.push(u);
				}
			}
		}
	}

	if(dist[n-1] == LLONG_MAX)cout<<"-1\n";
	else cout<<dist[n-1]<<'\n';
}