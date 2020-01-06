#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
stack<int> st;
vector<int> indeg, rnk;
vector<set<int>> ans;

int n,m;
 
int main(){

    int T; cin>>T;

    for(int t=1;t<=T;++t){

        cin>>n>>m;
        adj.clear(); ans.clear(); indeg.clear(); rnk.clear();

        adj.assign(n,vector<int>()); ans.assign(n+1,set<int>()); indeg.assign(n,0); rnk.assign(n,0);

        while(m--){
            int x,y; cin>>y>>x;
            adj[x].push_back(y);
            ++indeg[y];
        }

        for(int i=0;i<n;++i){
            if(indeg[i] == 0){
                st.push(i);
                rnk[i] = 1;
                ans[1].insert(i);
            }
        }

        while(!st.empty()){
            int x = st.top();
            st.pop();

            for(int u : adj[x]){
                --indeg[u];
                if(indeg[u] == 0){
                    st.push(u);
                    rnk[u] = rnk[x] + 1;
                    ans[rnk[u]].insert(u);
                }
            }
        }
        cout<<"Scenario #"<<t<<":\n";
        for(int i=1;i<=n;++i){
            if(ans[i].size() > 0){
                for(int u : ans[i]){
                    cout<<i<<" "<<u<<'\n';
                }
            }
        }

    }    

}