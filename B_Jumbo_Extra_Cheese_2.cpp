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
    int a[n],b[n];
    int totala=0,totalb=0;
    foo(i,0,n){
        int x,y;
        cin>>x>>y;
        a[i] = max(x,y);
        b[i] = min(x,y);
        totala += a[i];
        totalb += b[i];
    }
    totala*=2;
    totalb*=2;
    sort(a,a+n);
    sort(b,b+n);
    //ct<<totala<<" "<<totalb<<" "<<a[n-1]<<" "<<b[n-1]<<ed;
    totala += 2*b[n-1];
    totalb += 2*a[n-1];
    ct<<min(totala,totalb)<<ed;
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

