#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

vector<ll> t,d;

void push(int i, int l, int r){
    t[i] += d[i]*(r-l+1);
    if(l != r){
        d[i+i] += d[i];
        d[i+i+1] += d[i];
    }
    d[i] = 0;
}

void update(int i, int tl, int tr, int ql, int qr, int val){
    if(d[i] != 0){
        push(i,tl,tr);
    }

    if(tl > qr || tr < ql || tl > tr)
        return;

    if(tl >= ql && tr <= qr){
        d[i] += val;
        push(i,tl,tr);
        return;
    }

    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    update(x,tl,tm,ql,qr,val);
    update(y,tm+1,tr,ql,qr,val);
    t[i] = t[x] + t[y];
}

ll query(int i, int tl, int tr, int ql, int qr){
    if(d[i] != 0){
        push(i,tl,tr);
    }

    if(tl == ql && tr == qr){
        return t[i];
    }

    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    if(qr <= tm){
        return query(x,tl,tm,ql,qr);
    }else if(tm < ql){
        return query(y,tm+1,tr,ql,qr);
    }

    ll a1 = query(x,tl,tm,ql,tm);
    ll a2 = query(y,tm+1,tr,tm+1,qr);
    return (a1+a2);
}

int main(){

    FAST;

    int T; cin>>T;
    while(T--){
        int n,q; cin>>n>>q;
        t.clear(); d.clear();
        t.assign(4*n,0); d.assign(4*n,0);

        while(q--){
            int i; cin>>i;
            if(i == 0){
                int p,q,val; cin>>p>>q>>val;
                update(1,0,n-1,p-1,q-1,val);
            }else{
                int p,q; cin>>p>>q;
                cout<<query(1,0,n-1,p-1,q-1)<<'\n';
            }
        }
    }

}