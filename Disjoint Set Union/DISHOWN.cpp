#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

vector<int> par;
vector<int> s;

int find_par(int v){
    if(par[v] == v)
        return v;
    return par[v] = find_par(par[v]);
}

void unite(int x, int y){
    x = find_par(x);
    y = find_par(y);
    if(s[x] > s[y])par[y] = x;
    else if(s[y] > s[x])par[x] = y;
}
 
int main(){

    FAST;

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        par.resize(n);
        s.resize(n);

        for(int i=0;i<n;++i){
            cin>>s[i]; par[i] = i;
        }

        int q; cin>>q;
        while(q--){

            int i; cin>>i;
            if(i==1){
                int x; cin>>x; --x;
                cout<<find_par(x)+1<<'\n';
            }else{
                int x,y; cin>>x>>y;
                --x; --y;
                x = find_par(x);
                y = find_par(y);
                if(x != y){
                    unite(x,y);
                }else{
                  cout<<  "Invalid query!\n";
                }
            }

        }


    }
    
}