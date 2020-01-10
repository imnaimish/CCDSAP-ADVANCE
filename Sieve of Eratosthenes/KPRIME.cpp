#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

vector<int> cnt;
int N = 1e5+5;

void find(){
    cnt.assign(N,0);
    cnt[1] = 1;

    for(ll i=2;i<=N;++i){
        if(cnt[i] == 0){
            cnt[i] = 1;
            for(ll j=2*i;j<N;j+=i){
                ++cnt[j];
            }
        }
    }
}

int main(){
    FAST;

    find();
    
    vector<vector<int>> ans(N,vector<int>(7));
    for(int i=2;i<N;++i){
        int x = cnt[i];
        for(int j=1;j<=6;++j){
            if(j == x){
                ans[i][j] = ans[i-1][j]+1;
            }else{
                ans[i][j] = ans[i-1][j];
            }
        }
    }

    int q; cin>>q;
    while(q--){
        int a,b,k; cin>>a>>b>>k;
        cout<<(ans[b][k]-ans[a-1][k])<<"\n";
    }
}