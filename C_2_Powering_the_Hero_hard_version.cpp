#include <bits/stdc++.h>
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


void solve(){
    int n; cin>>n;
    int a[n]; foo(i,0,n) cin>>a[i];
    priority_queue<int> q;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            if(q.empty()) continue;
            ans += q.top();
            q.pop();
        }
        else q.push(a[i]);
    }
    cout<<ans<<ed;
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

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}