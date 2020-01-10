#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

vector<int> t,a,leastPrime;

void sieve(){
    leastPrime.resize(1E6+5,0);
    leastPrime[1] = 1;
    for(int i=2;i<=1E6;++i){
        if(leastPrime[i] == 0){
            for(int j=i;j<=1E6;j+=i){
                if(leastPrime[j] == 0)leastPrime[j] = i;
            }
        }
    }
}

void build(int i, int tl, int tr){
    if(tl > tr)
        return;
    if(tl == tr){
        t[i] = leastPrime[a[tl]];
        return;
    }
    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    build(x,tl,tm);
    build(y,tm+1,tr);
    t[i] = max(t[x],t[y]);
}

void update(int i, int tl, int tr, int pos){
    if(tl == tr){
        a[tl] /= leastPrime[a[tl]];
        t[i] = leastPrime[a[tl]];
        return;
    }
    int tm = (tl+tr)>>1, x = i<<1, y=x|1;
    if(pos <= tm)update(x,tl,tm,pos);
    else update(y,tm+1,tr,pos);
    t[i] = max(t[x],t[y]);
}

int query(int i, int tl, int tr, int ql, int qr){
    if(tl == ql && tr == qr){
        return t[i];
    }
    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    if(qr <= tm){
        return query(x,tl,tm,ql,qr);
    }else if(tm < ql){
        return query(y,tm+1,tr,ql,qr);
    }
    int a1 = query(x,tl,tm,ql,tm);
    int a2 = query(y,tm+1,tr,tm+1,qr);
    return max(a1,a2);
}

int main(){

    FAST;

    sieve();
    int T; cin>>T;
    while(T--){
        int n,q; cin>>n>>q;
        a.clear(); t.clear();
        a.resize(n); t.resize(4*n);

        set<int> st;
        for(int i=0;i<n;++i){
            cin>>a[i];
            st.insert(i);
        }
        build(1,0,n-1);
        while(q--){
            int i,l,r; cin>>i>>l>>r;
            if(i == 0){ 
                vector<int> temp;
                auto it = st.lower_bound(l-1);
                while(it != st.end() && *it<r){
                    update(1,0,n-1,*it);
                    if(a[*it] == 1)temp.push_back(*it);
                    ++it;
                }
                for(int j=0;j<temp.size();++j){
                    st.erase(temp[j]);
                }
            }else{
                int ans = query(1,0,n-1,l-1,r-1);
                cout<<ans<<" ";
            }
        }
        cout<<"\n";
    }

}