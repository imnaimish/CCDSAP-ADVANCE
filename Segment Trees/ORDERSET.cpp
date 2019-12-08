#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
  
// a new data structure defined. Please refer below 
// GNU link : https://goo.gl/WVDL6g 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 


int main(){
	int t; cin>>t;
	new_data_set st;
	while(t--){
		char ch; cin>>ch;
		int n; cin>>n;
		if(ch == 'I'){
			st.insert(n);
		}else if(ch == 'D'){
			st.erase(n);
		}else if(ch == 'K'){
			int ans = *st.find_by_order(n-1);
			if(ans == 0){
				cout<<"invalid\n";
			}else{
				cout<<ans<<endl;
			}
		}else if(ch == 'C'){
			cout<<st.order_of_key(n)<<endl;
		}
	}
}