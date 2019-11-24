#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)
 
int main(){
    FAST;

    multiset<int> st; priority_queue<int> pq;
    int n; cin>>n;
    int sz = 0;
    while(n--){
        int i; cin>>i;
        if(i==2){
            if(((sz/3) == 0) || st.size()==0){
                cout<<"No reviews yet"<<'\n';
            }else{
                cout<<*st.begin()<<'\n';
            }
        }else{
            ++sz;
            int x; cin>>x;
            pq.push(x);
            if((sz/3) == 0){
                continue;
            }
            if((sz/3) > st.size()){
                if(!pq.empty()){
                    st.insert(pq.top()); pq.pop();
                }
            }else{
                if(st.size()>0 && !pq.empty()){
                    if(pq.top() > *st.begin()){
                        int y = pq.top(); pq.pop();
                        int z = *st.begin(); st.erase(st.begin());
                        st.insert(y); pq.push(z);
                    }
                }
            }
        }
    }
}