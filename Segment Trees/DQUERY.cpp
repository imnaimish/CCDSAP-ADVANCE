//Using Mo's Algorithm

#include<bits/stdc++.h>
using namespace std;

int blockSize,n;

struct qnode{
    int l,r,idx;

    bool operator < (qnode a) const{
        return make_pair(l / blockSize, r) < make_pair(a.l / blockSize, a.r);
    }
};

vector<int> a,ans;
vector<qnode> query;
int freq[1000005];

void solve(){
    int l = 0, r = -1, cnt = 0;

    for(qnode q : query){

        while(l > q.l){
            --l;
            ++freq[a[l]];
            if(freq[a[l]] == 1)++cnt;
        }

        while(l < q.l){
            --freq[a[l]];
            if(freq[a[l]] == 0)--cnt;
            ++l;
        }

        while(r > q.r){
            --freq[a[r]];
            if(freq[a[r]] == 0)--cnt;
            --r;
        }

        while(r < q.r){
            ++r;
            ++freq[a[r]];
            if(freq[a[r]] == 1)++cnt;
        }

        ans[q.idx] = cnt;
    }

}

int main(){

    memset(freq, 0, sizeof freq);
    cin>>n;
    a.resize(n);
    blockSize = sqrt(n);

    for(int i=0;i<n;++i)cin>>a[i];

    int q; cin>>q;
    query.resize(q); ans.resize(q);
    for(int i=0;i<q;++i){
        int l,r; cin>>l>>r;
        --l; --r;
        query[i].l = l;
        query[i].r = r;
        query[i].idx = i;
    }

    sort(query.begin(), query.end());

    solve();

    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';

}