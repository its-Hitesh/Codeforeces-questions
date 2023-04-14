#include <bits/stdc++.h>
#include <bits/extc++.h>//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long ;
#define pb            push_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define m_p           make_pair
#define mod           998244353
#define int long long

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve(){
    string s, t;
    cin>>s>>t;
    int n = s.size(), m = t.size(), cnts = 0, cntt[m]={}, cntz[m] ={};
    foo(i,0,n) if(s[i] == '1') cnts++;
    foo(i,0,m) if(t[i] == '1') cntt[i]++;
    foo(i,1,m) cntt[i] += cntt[i-1];
    foo(i,0,m) cntz[i] = i + 1 - cntt[i] ;
    
    if(n == m) {
        if(cnts == cntt[m-1]) cout<<t<<ed;
        else cout<<s<<ed;
    }
    else if(n < m) cout<<s<<ed;
    else if(cntt[m-1] == 0){
        string ans = "";
        while(cnts--) ans += '1';
        while(ans.size() < n) ans += '0';
        cout<<ans<<ed;
    }
    else{
        vector<int> z = z_function(t);
        int upto = -1;
        for(int i = 0; i < m; i++){
            int j = m - 1 - i;
            if(z[j] == i + 1) upto = i;   
        }
        string ans = "";
        if(upto == -1){
            // cout<<cnts<<" "<<cntt[m-1]<<ed;
            int zeros = s.size() - cnts;
            while(cnts >= cntt[m-1] && zeros - cntz[m-1] >= 0){
                cnts -= cntt[m - 1];
                zeros -= cntz[m-1];
                ans += t;
            }
            while(cnts--){
                ans += '1';
            }
            while(ans.size() < n){
                ans += '0';
            }
            cout<<ans<<ed;
        }
        else{
            int zeros = s.size() - cnts;
            if(cnts - cntt[upto] >= 0 && zeros - cntz[upto]) {
                cnts -= cntt[upto];
                zeros -= cntz[upto];
                ans += t.substr(0,upto + 1);
                int ones = cntt[m - 1] - cntt[upto] ;
                int zero = cntz[m - 1] - cntz[upto] ;
                string tt = t.substr(upto+1);
                // cout<<ones<<" "<<tt<<" "<<ans<<ed;
                while(cnts - ones >= 0 && zeros - zero >= 0){
                    ans += tt;
                    cnts -= ones;
                    zeros -= zero ;
                }
                while(cnts--){
                    ans += '1';
                }
                while(ans.size() < n){
                    ans += '0';
                }
            }
            else ans = s;
            cout<<ans<<ed;
        }
    } 
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
*/

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}