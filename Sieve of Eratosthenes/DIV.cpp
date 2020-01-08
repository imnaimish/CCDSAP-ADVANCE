#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)
template<class T>
int len(T n){
   return n.size();
}
 
template<class T>
bool isPrime(T n){
   if(n==1)return false;
   T i = 2;
   while(i*i<=n){
      if(n%i==0)return false;
      i+=1;
   }
   return true;
}
 
int N = 1E6+5;
int main(){

    FAST;

    vector<int> divisors(N,1);
    for(int i=2;i<N;++i){
        for(int j=i;j<N;j+=i){
            divisors[j]+=1;
        }
    }

    vector<int> prime;
    for(int i=2;i<=240;++i){
        if(isPrime(i))prime.push_back(i);
    }

    int c = 0;
    for(int i=1;i<=1E6;++i){
        int x = divisors[i];
        bool f = false;
        for(int j=0;j<len(prime);++j){
            if(prime[j] > x)break;
            if(x%prime[j] == 0){
                int y = x/prime[j];
                auto it = lower_bound(prime.begin(), prime.end(),y);
                if(it != prime.end() && *it==y && *it != prime[j]){
                    f = true; ++c;
                }
            }
            if(f)break;
        }
        if(c == 9){
            c = 0;
            cout<<i<<"\n";
        }
    }

}