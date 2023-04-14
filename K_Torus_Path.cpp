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
        int total =0;
        int a[n][n]; foo(i,0,n) foo(j,0,n) cin>>a[i][j], total += a[i][j];
        int mini = INT_MAX;
        for(int i=n-1,j=0;i>=0 && j < n;i--,j++){
            mini = min(mini,a[i][j]);
        }
        ct<<total-mini<<ed;
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


  int t =1; //cin>>t;

  while(t--){

    solve();

  }
  return 0;
}

