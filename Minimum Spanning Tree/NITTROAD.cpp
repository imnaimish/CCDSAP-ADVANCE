#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m;
vector<int> par,sz;

int find(int v){
    if(par[v] == v)
        return v;
    return par[v] = find(par[v]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b]){
            swap(a,b);
        }
        par[b] = a;
        sz[a] += sz[b];
    }
}

struct enode{
    int u,v; bool added = false;
};

int main(){
    
    int t; cin>>t;
    while(t--){
        cin>>n;
        par.clear(); sz.clear();
        par.resize(n); sz.assign(n,1);

        for(int i=0;i<n;++i)par[i] = i;

        vector<enode> edge(n-1);

        for(int i=0;i<n-1;++i){
            int x,y; cin>>x>>y;
            edge[i].u = x-1; edge[i].v = y-1;
        }

        int q; cin>>q;
        stack<int> query;
        while(q--){
            char ch; cin>>ch;
            if(ch == 'R'){
                int k; cin>>k; --k;
                edge[k].added = true;
                query.push(k);
            }else{
                query.push(-1);
            }
        }

        ll connectedVertex = 0;
        for(int i=0;i<n-1;++i){
            if(!edge[i].added){
                int a = find(edge[i].u);
                int b = find(edge[i].v);
                if(a != b){
                    connectedVertex += sz[a] * sz[b];
                    unite(a,b);
                }
            }
        }

        ll disconnectedVertex = (n*(n-1))/2 - connectedVertex;
        stack<ll> ans;

        while(!query.empty()){
            int k = query.top();
            query.pop();

            if(k == -1){
                ans.push(disconnectedVertex);
            }else{
                int a = find(edge[k].u);
                int b = find(edge[k].v);
                disconnectedVertex -= sz[a]*sz[b];
                unite(a,b);
            }
        }

        while(!ans.empty()){
            cout<<ans.top()<<'\n';
            ans.pop();
        }
        cout<<'\n';
    }

    return 0;
}