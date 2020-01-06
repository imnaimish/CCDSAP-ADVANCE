#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int u,v,wt;

    bool operator < (node& other) const{
        return wt < other.wt;
    }
};

vector<int> par,sz;
vector<node> edge;

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
        int n,m; cin>>n>>m;
        par.clear(); sz.clear(); edge.clear();
        par.resize(n+1); sz.assign(n+1,1);

        for(int i=0;i<n;++i){
            int x; cin>>x;
            if(x == 1){
                node temp; temp.u = i; temp.v = n; temp.wt = 0;
                edge.push_back(temp);
            }
            par[i] = i;
        }
        par[n] = n;
        while(m--){
            int x,y,z; cin>>x>>y>>z;
            --x; --y;
            node temp;
            temp.u = x; temp.v = y; temp.wt = z;
            edge.push_back(temp);
        }

        sort(edge.begin(), edge.end());

        ll ans = 0;
        for(int i=0;i<edge.size();++i){
            int a = find(edge[i].u), b = find(edge[i].v);
            if(a != b){
                unite(edge[i].u,edge[i].v);
                ans += edge[i].wt;
            }
        }

        bool f = false;
        for(int i=1;i<n+1;++i){
            if(find(0) != find(i)){
                f = true; break;
            }
        }

        if(f)cout<<"impossible\n";
        else cout<<ans<<'\n';
    }

}