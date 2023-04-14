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
    int n;
    cin>>n;
    int a[n]; foo(i,0,n) cin>>a[i];
    sort(a,a+n);
    int ans1=0 , ans2=0 ;
    foo(i,0,n-2){
        ans1 = max(ans1,a[n-1]-a[i]+a[i+1]-a[i]);
    }
    foo(i,1,n-1){
        ans2 = max(ans2,a[i+1]-a[0]+a[i+1]-a[i]);
    }
    ct<<max(ans1,ans2)<<ed;

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

