#include<bits/stdc++.h>
using namespace std;
using ll = long long;


struct enode{
    int u,v,wt;

    bool operator < (enode& other) const{
        return wt < other.wt;
    }
};

vector<int> par,sz;

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
        par[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    int t; cin>>t;
    while(t--){

        int price,n,m; cin>>price>>n>>m;
        par.clear(); sz.clear();
        par.resize(n); sz.assign(n,1);

        for(int i=0;i<n;++i)par[i] = i;

        vector<enode> edge;

        for(int i=0;i<m;++i){
            int x,y,w; cin>>x>>y>>w;
            enode temp;
            temp.u = x-1; temp.v = y-1; temp.wt = w;
            edge.push_back(temp);
        }

        sort(edge.begin(), edge.end());

        ll totalLen = 0;
        for(int i=0;i<edge.size();++i){
            int u = edge[i].u, v = edge[i].v, len = edge[i].wt;
            if(find(u) != find(v)){
                totalLen += len;
                unite(u,v);
            }
        }

        cout<<totalLen*price<<'\n';

    }
}