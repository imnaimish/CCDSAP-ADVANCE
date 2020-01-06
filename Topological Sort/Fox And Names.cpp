#include <bits/stdc++.h>
using namespace std;


vector<set<int>> outDegree(26);
vector<int> inDegree(26);

void create(string s, string t){
    int i = 0;
    while(i<s.size() && i<t.size() && s[i]==t[i]){
        ++i;
    }
    if(i == s.size()){
        return;
    }
    if(i == t.size()){
        cout<<"Impossible\n"; exit(0);
    }

    if(outDegree[s[i]-'a'].find(t[i]-'a') == outDegree[s[i]-'a'].end()){
        outDegree[s[i]-'a'].insert(t[i]-'a');
        ++inDegree[t[i]-'a'];
    }
}

void solve(){
    stack<int> st;
    for(int i=0;i<26;++i){
        if(inDegree[i]==0)st.push(i);
    }
    string ans = "";
    while(!st.empty()){
        int x = st.top();
        st.pop();
        ans += (char)(x+'a');
        for(auto p : outDegree[x]){
            if(inDegree[p] > 0){
                --inDegree[p];
                if(inDegree[p] == 0)st.push(p);
            }
        }
    }
    if(ans.size() < 26){
        cout<<"Impossible\n";
    }else{
        cout<<ans<<'\n';
    }
}

int main(){
    int n; cin>>n;
    vector<string> arr(n);
    
    for(int i=0;i<n;++i)cin>>arr[i];

    string s,t; s = arr[0];

    for(int i=1;i<n;++i){
        t = arr[i];
        create(s,t);
        s = t;
    }

    solve();
}