#include <bits/stdc++.h>
#define ll            long long
#define pb            push_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define ct            cout
#define m_p           make_pair
#define vi            vector<ll>
#define vpll           vector<pll>
#define ff            first
#define ss            second
#define mod           1000000007
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    int a[n+1]; foo(i,1,n+1) cin>>a[i];
    int dp[n+2] = {};
    dp[0] =1;
    foo(i,1,n+1){
        if(i-a[i]-1 >=0 && dp[i-a[i]-1]==1){
            dp[i]=1;
        }
        if(dp[i-1]==1 && i+a[i] <=n){
            dp[i+a[i]] = 1 ;
        }
    }
    if(dp[n]==1) ct<<"YES"<<ed;
    else ct<<"NO"<<ed;
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


  int t =1; cin>>t;

  while(t--){

    solve();

  }
  return 0;
}

