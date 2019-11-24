#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0);


int main(){

	int f,s,g,u,d; cin>>f>>s>>g>>u>>d;

	vector<int> dist(f+1,-1);
	queue<int> q;

	q.push(s);
	dist[s] = 0;

	while(!q.empty()){
		int v = q.front();
		q.pop();

		int x = v+u, y = v-d;
		if(x<=f){
			if((dist[x]!=-1)){
				dist[x] = min(dist[x],dist[v]+1);
			}else{
				q.push(x); dist[x] = dist[v]+1;
			}
		}

		if(y>0){
			if((dist[y]!=-1)){
				dist[y] = min(dist[y],dist[v]+1);
			}else{
				q.push(y); dist[y] = dist[v]+1;
			}
		}
	}	

	if(dist[g] == -1){
		cout<<"use the stairs\n";
	}else{
		cout<<dist[g]<<'\n';
	}
}