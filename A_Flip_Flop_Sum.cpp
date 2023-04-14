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
    int n,total = 0; cin>>n;
    int a[n];
    bool neg = false, cot = false ;
    foo(i,0,n){
        cin>>a[i];
        if(a[i] < 0) neg = true ;
        total += a[i];
        if(i > 0) if(a[i] < 0 && a[i-1] < 0) cot = true ;
    }
    if(cot) cout<<total + (int)4 << endl;
    else if(neg) cout<<total <<ed;
    else cout<<(total - (int)4) <<ed;

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