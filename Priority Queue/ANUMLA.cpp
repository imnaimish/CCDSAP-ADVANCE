#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main(){
    FAST;

     int t; cin>>t;

     while(t--){
        int n; cin>>n;
        vector<int> ans, subsetsum;
        multiset<int> st;
        int N = binpow(2,n);
        for(int i=0; i<N; ++i){
            int x; cin>>x;
            if(x==0)continue;
            st.insert(x);
        }

        while(ans.size() < n){
            int x = *st.begin();
            st.erase(st.find(x));
            int sz = subsetsum.size();
            for(int i=0; i<sz; ++i){
                st.erase(st.find(subsetsum[i]+x));
            }
            for(int i=0; i<sz; ++i){
                subsetsum.push_back(subsetsum[i]+x);
            }
            ans.push_back(x);
            subsetsum.push_back(x);
        }
        for(int i=0; i<n; ++i)cout<<ans[i]<<" ";
        cout<<'\n';
     }   

}