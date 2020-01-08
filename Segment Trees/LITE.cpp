#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

vector<int> t;
vector<bool> d;
int n,q;

void push(int i, int l, int r){
    t[i] = (r-l+1)-t[i];
    if(l != r){
        d[i+i] = !d[i+i];
        d[i+i+1] = !d[i+i+1];
    }
    d[i] = false;
}

void update(int i, int tl, int tr, int ql, int qr){
    if(d[i]){
        push(i,tl,tr);
    }

    if(tl > qr || tr < ql || tl > tr)
        return;

    if(tl >= ql && tr <= qr){
        push(i,tl,tr);
        return;
    }

    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    update(x,tl,tm,ql,qr);
    update(y,tm+1,tr,ql,qr);
    t[i] = t[x]+t[y];
}

int query(int i, int tl, int tr, int ql, int qr){
    if(d[i]){
        push(i,tl,tr);
    }

    if(ql == tl && qr == tr){
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
    return (a1+a2);
}

int main(){

    FAST;

    cin>>n>>q;
    t.assign(4*n,0); d.assign(4*n,false);

    while(q--){
        int i,l,r; cin>>i>>l>>r;
        if(i == 0){
            update(1,0,n-1,l-1,r-1);
        }else{
            cout<<query(1,0,n-1,l-1,r-1)<<"\n";
        }
    }
}