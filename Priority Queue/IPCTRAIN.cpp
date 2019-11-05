#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

struct trainer{
    ll t,s;
};

struct cmp{
    bool operator()(trainer const& p1, trainer const& p2){
        if(p1.s == p2.s)return p1.t < p2.t;
        return p1.s < p2.s;
    }
};

int main(){

    FAST;

     int t; cin>>t;
     while(t--){
        
        int n,days; cin>>n>>days;
        vector<vector<pair<ll,ll>>> a(days+1,vector<pair<ll,ll>>());

        for(int i=0; i < n; ++i){
            ll x,y,z; cin>>x>>y>>z;
            a[x].push_back({y,z});
        }

        priority_queue<trainer, vector<trainer>, cmp> pq;

        for(int i=1; i<=days; ++i){
            for(int j=0; j < a[i].size(); ++j){
                pair<ll,ll> tmp = a[i][j];
                trainer tr;
                tr.t = tmp.first;
                tr.s = tmp.second;
                pq.push(tr);
            }

            if(pq.size() > 0){
                trainer tr = pq.top();
                pq.pop();
                tr.t -= 1ll;
                if(tr.t > 0)pq.push(tr);
            }
        }

        ll ans = 0;
        while(pq.size() > 0){
            trainer tr = pq.top();
            pq.pop();
            ans += tr.t * tr.s;
        }
        cout<<ans<<'\n';
     }   

}