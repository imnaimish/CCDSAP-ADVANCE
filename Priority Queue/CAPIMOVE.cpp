#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

struct node{
    int num, index;     
}; 

struct cmp{
    bool operator()(node const& a, node const& b){
        return a.num > b.num;
    }
};

int main(){

    FAST;

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        set<node,cmp> st;
        for(int i=0;i<n;++i){
            cin>>a[i];
            node temp;
            temp.num = a[i];
            temp.index = i;
            st.insert(temp);
        }

        vector<vector<node>> adj(n);

        for(int i=0;i<n-1;++i){
            int x,y; cin>>x>>y;
            node tempx; tempx.index = x-1; tempx.num = a[x-1];
            node tempy; tempy.index = y-1; tempy.num = a[y-1];
            adj[x-1].push_back(tempy);
            adj[y-1].push_back(tempx);
        }

        node temp;

        for(int i=0;i<n;++i){
            vector<node> b;
            temp.index = i; temp.num = a[i];
            b.push_back(temp); st.erase(temp);
            for(node u : adj[i]){
                b.push_back(u); st.erase(u);
            }
            node temp2 = *st.begin();
            cout<<temp2.index+1<<" ";
            for(int i=0;i<b.size();++i){
                st.insert(b[i]);
            }
        }
    }

}