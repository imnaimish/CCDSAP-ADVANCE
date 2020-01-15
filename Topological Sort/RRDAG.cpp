#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

int main(){
    int n; cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    vector<int> outdeg(n,0);

    for(int i=0;i<n;++i){
        string s; cin>>s;
        for(int j=0;j<n;++j){
            a[i][j] = s[j]-'0';
            if(a[i][j] == 1){
                ++outdeg[i];
            }
        }
    }

    priority_queue<int> pq;

    for(int i=0;i<n;++i){
        if(outdeg[i] == 0)pq.push(i);
    }

    set<pair<int,int>> ans;
    vector<bool> vis(n,false);

    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        vis[v] = true;
        for(int i=0;i<n;++i){
            if(i == v || vis[i])continue;
            if(a[i][v] == 1){
                --outdeg[i];
                if(outdeg[i] == 0)pq.push(i);
                continue;
            }
            ans.insert({i,v});
        }
    }

    cout<<ans.size()<<"\n";
    for(pair<int,int> u : ans){
        cout<<u.first+1<<" "<<u.second+1<<"\n";
    }
}