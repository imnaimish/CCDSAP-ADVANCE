#include<bits/stdc++.h>
using namespace std;

struct node{
    int c0 = 0, c1 = 0, c2 = 0;
    void leaf(){
        c0 = 1;
    }
    void merge(node &a, node &b){
        c0 = a.c0+b.c0;
        c1 = a.c1+b.c1;
        c2 = a.c2+b.c2;
    }
    void flip(){
        int temp = c0;
        c0 = c2;
        c2 = c1;
        c1 = temp;
    }
};

vector<node> t;
vector<int> d;

void push(int i, int l, int r){
    if(d[i]%3 != 0){
        for(int j=0;j<d[i]%3;++j){
            t[i].flip();
        }
    }
    if(l != r){
        d[i+i] += d[i];
        d[i+i+1] += d[i];
    }
    d[i] = 0;
}

void build(int i, int tl, int tr){
    if(tl > tr)
        return;
    if(tl == tr){
        t[i].leaf();
        return;
    }
    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    build(x,tl,tm);
    build(y,tm+1,tr);
    t[i].merge(t[x],t[y]);
}

void update(int i, int tl, int tr, int ql, int qr){
    if(d[i] != 0){
        push(i,tl,tr);
    }
    if(tl > qr || tr < ql || tl >tr)
        return;
    if(tl >= ql && tr <= qr){
        d[i] += 1;
        push(i,tl,tr);
        return;
    }
    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    update(x,tl,tm,ql,qr);
    update(y,tm+1,tr,ql,qr);
    t[i].merge(t[x],t[y]);
}

node query(int i, int tl, int tr, int ql, int qr){
    if(d[i] != 0){
        push(i,tl,tr);
    }
    if(ql == tl &&  qr == tr){
        return t[i];
    }
    int tm = (tl+tr)>>1, x = i<<1, y = x|1;
    if(qr <= tm){
        return query(x,tl,tm,ql,qr);
    }else if(tm < ql){
        return query(y,tm+1,tr,ql,qr);
    }
    node a1 = query(x,tl,tm,ql,tm);
    node a2 = query(y,tm+1,tr,tm+1,qr);
    node ans;
    ans.merge(a1,a2);
    return ans;
}

int main(){
    int n,q; cin>>n>>q;
    t.resize(4*n); d.assign(4*n,0);

    build(1,0,n-1);

    while(q--){
        int i,l,r; cin>>i>>l>>r;
        if(i == 0){
            update(1,0,n-1,l,r);
        }else{
            node ans = query(1,0,n-1,l,r);
            cout<<ans.c0<<"\n";
        }
    }

}