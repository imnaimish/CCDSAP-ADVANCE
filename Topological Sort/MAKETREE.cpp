#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
queue<int> q;
vector<int> boss,order;
vector<bool> vis;
int n,m;

void top_sort(int v){
    vis[v] = true;
    for(int u : adj[v]){
        if(!vis[u]){
            top_sort(u);
        }
    }
    order.push_back(v);
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);

    cin>>n>>m;
    adj.assign(n,vector<int>());
    boss.assign(n,-1); vis.assign(n,false);

    for(int i=0;i<m;++i){
        int x; cin>>x;
        for(int j=0;j<x;++j){
            int y; cin>>y;
            --y;
            adj[i].push_back(y);
        }
    }

    for(int i=0;i<n;++i){
        if(!vis[i])
            top_sort(i);
    }

    reverse(order.begin(),order.end());


    int prev = 0;
    for(int i=0;i<n;++i){
        boss[order[i]] = prev;
        prev = order[i]+1;
    }

    for(int i=0;i<n;++i)cout<<boss[i]<<'\n';
}