#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    ll to,len;
};

struct cmp{
    bool operator()(node const& a, node  const& b){
        return a.len > b.len;
    }
};

int main(){

    int t; cin>>t;
    while(t--){

        int n,m,source,destination;
        cin>>n>>m>>source>>destination;

        if(m == 0){
            cout<<"NONE\n"; continue;
        }

        vector<vector<node>> a(n,vector<node>());

        while(m--){
            int u,v,wt; cin>>u>>v>>wt;
            node a1,a2;
            a1.to = u-1; a1.len = wt;
            a2.to = v-1; a2.len = wt;
            a[u-1].push_back(a2);
            a[v-1].push_back(a1);
        }

        priority_queue<node, vector<node>, cmp> pq;

        vector<ll> dist(n,LLONG_MAX);
        vector<bool> vis(n,false);

        node temp; temp.to = source-1; temp.len = 0;
        pq.push(temp);
        dist[source-1] = 0;

        while(!pq.empty()){
            node temp = pq.top();
            int v = temp.to;
            pq.pop();

            if(v == (destination - 1))
                break;
            if(vis[v])
                continue;

            vis[v] = true;

            for(node p : a[v]){
                int u = p.to, wt = p.len;
                if(!vis[u] && (dist[v] + wt) < dist[u]){
                    dist[u] = dist[v] + wt;
                    node q; q.to = u; q.len = dist[u];
                    pq.push(q);
                }
            }

        }

        if(dist[destination - 1] == LLONG_MAX){
            cout<<"NONE\n";
        }else{
            cout<<dist[destination-1]<<'\n';
        }

    }

}