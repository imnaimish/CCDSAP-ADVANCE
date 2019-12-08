#include<bits/stdc++.h>
using namespace std;


struct Edge{
    int u,v,wt;

    bool operator < (Edge& a) const{
        return wt < a.wt;
    }
};

vector<int> par,sz;
vector<Edge> edges;

int find(int v){
    if(v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(sz[a] < sz[b])
            swap(a,b);
        par[b] = par[a];
        sz[a] += sz[b];
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    par.assign(n,-1); sz.assign(n,1);
    for(int i=0;i<n;++i)
        par[i] = i;

    while(m--){
        int x,y,w; cin>>x>>y>>w;
        Edge temp;
        temp.u = x-1; temp.v = y-1; temp.wt = w;
        edges.push_back(temp);
    }

    sort(edges.begin(), edges.end());

    long long ans = 0;
    for(int i=0;i<edges.size();++i){
        int u = edges[i].u, v = edges[i].v, cost = edges[i].wt;
        if(find(u) != find(v)){
            ans += cost;
            unite(u,v);
        }
    }
    cout<<ans<<'\n';
}