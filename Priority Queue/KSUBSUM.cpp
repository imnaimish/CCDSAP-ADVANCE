#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define FAST ios_base::sync_with_stdio(0) ; cin.tie(0); 

int main(){

	int t; cin>>t;

	while(t--){

		int n,k1,k2,k3; cin>>n>>k1>>k2>>k3;
		vector<int> a(n);
		priority_queue<int> pq;

		for(int i=0;i<n;++i)cin>>a[i];

		bool f = false;
		for(int i=0;i<n;++i){
			int sum = 0;
			for(int j=i;j<n;++j){
				sum += a[j];
				pq.push(sum);
				if(pq.size() > 2500){
					f = true; break;
				}
			}
			if(f)break;
		}

		int x = k1; int ans;
		while(x > 0){
			ans = pq.top();
			pq.pop();
			--x;
		}

		cout<<ans<<" ";

		x = (k2-k1);
		while(x > 0){
			ans = pq.top();
			pq.pop();
			--x;
		}
		cout<<ans<<" ";

		x = (k3-k2);
		while(x > 0){
			ans = pq.top();
			pq.pop();
			--x;
		}
		cout<<ans<<" ";
		cout<<'\n';
	}

}