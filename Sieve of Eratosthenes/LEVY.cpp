#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

bool prime[10005];
void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0]=0;
    prime[1]=0;
    for(ll p=2;p*p<=10000;p++)
    {
        if(prime[p]==true)
        {
            for(ll i=p*2;i<=10000;i+=p)
            prime[i]=false;
        }
    }    
}
 
int main(){
    FAST;

    sieve();
    vector<int> p;
    for(int i=1;i<=10000;++i){
      if(prime[i]){
        p.push_back(i);
      }
    }

    vector<int> ans(10001,0);
    for(int i=0;i<p.size();++i){
      for(int j=0;j<p.size();++j){
        int x = p[i] + 2*p[j];
        if(x > 10000)break;
        ++ans[x];
      }
    }

    int t; cin>>t;
    while(t--){
      int n; cin>>n;
      cout<<ans[n]<<"\n";
    }

}