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
    int left[n] ={}, right[n] ={};
    foo(i,1,n) right[i] = right[i-1] + (a[i - 1] == 1 ? 1 : 0); 
    for(int i = n - 2; i >= 0; i--) left[i] = left[i+1] + (a[i + 1] == 0 ? 1 : 0); 
    priority_queue<int, vector<int>, greater<int>> q; 
    foo(i,0,n){
      q.push(left[i] + right[i]);
    }
    int ans = 0, used = 0;
    while(!q.empty()){
      ans += q.top() - used;
      // cout<<ans<<" "<<q.top()<<" "<<used<<ed;
      if() used += 1;
      q.pop();
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}