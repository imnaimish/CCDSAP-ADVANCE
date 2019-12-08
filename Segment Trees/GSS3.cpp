#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct node{
    ll pref, suff, total, ans;

    void leaf(int num){
        pref = suff = total = ans = num;
    }

    void merge(node& left, node& right){
        total = right.total + left.total;
        pref = max(left.pref, left.total + right.pref);
        suff = max(right.suff, right.total + left.suff);
        ans = max({total, left.suff + right.pref, left.ans, right.ans, pref, suff});
    }
};

int n,m;
vector<int> a;
vector<node> t;

void build(int i, int tl, int tr){
    if(tl > tr)
        return;

    if(tl == tr){
        t[i].leaf(a[tl]);
        return;
    }

    int tm = (tl+tr)/2;
    build(2*i, tl, tm);
    build(2*i+1,tm+1,tr);

    t[i].merge(t[2*i], t[2*i+1]);
}

void update(int i, int tl, int tr, int pos, int val){
    if(tl > tr)
        return;
    if(tl == tr){
        t[i].leaf(val);
        return;
    }

    int tm = (tl+tr)/2;
    if(pos <= tm){
        update(2*i, tl, tm, pos, val);
    }else{
        update(2*i+1, tm+1, tr, pos, val);
    }
    t[i].merge(t[2*i],t[2*i+1]);
}

node query(int i, int tl, int tr, int ql, int qr){
    if(tr==qr && tl==ql){
        return t[i];
    }

    int tm = (tl+tr)/2;
    if(qr <= tm){
        return query(2*i, tl, tm, ql, qr);
    }else if(tm < ql){
        return query(2*i+1, tm+1, tr, ql, qr);
    }

    node ans1 = query(2*i, tl, tm, ql, tm);
    node ans2 = query(2*i+1, tm+1, tr, tm+1, qr);
    node temp;
    temp.merge(ans1,ans2);
    return temp;
}


int main(){

    cin>>n;
    a.resize(n); t.resize(4*n);

    for(int i=0;i<n;++i)cin>>a[i];

    build(1,0,n-1);

    cin>>m;
    while(m--){
        int i; cin>>i;
        if(i == 0){
            int pos,val; cin>>pos>>val; --pos;
            update(1,0,n-1,pos,val);
        }else{
            int l,r; cin>>l>>r; --l; --r;
            node res = query(1,0,n-1,l,r);
            cout<<res.ans<<'\n';
        }
    }

}