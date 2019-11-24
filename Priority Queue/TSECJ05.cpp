#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

int main(){

    FAST;

    int t; cin>>t;
    while(t--){

        int n,k; cin>>k>>n;
        set<int> st;

        for(int i=0;i<n;++i){
            int x; cin>>x;
            st.insert(x);
            if(st.size() < k){
                cout<<"-1 ";
            }else if(st.size() == k){
                cout<<*st.begin()<<" ";
            }else{
                if(st.size() > k){
                    st.erase(st.begin());
                }
                cout<<*st.begin()<<" ";
            }
        }
        cout<<'\n';

    }

}