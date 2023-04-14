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
    int n, t;
    cin>>n>>t;
    int k; cin>>k;
    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = (l+r) / 2;
        cout<<"? "<<l<<" "<<mid<<endl;
        cout.flush();
        int z1, z2;
        cin>>z1;
        z1 = (mid - l + 1) - z1;
        // cout<<"? "<<mid + 1<<" "<<r<<endl;
        // cout.flush();
        // cin>>z2;
        // z2 = (r - mid) - z2;
        if(z1 > k){
            r = mid - 1;
        }
        else if(z1 < k){
            k -= z1;
            l = mid + 1;
        }
        else{
            ans = mid;
            r = mid - 1;
        }
    }
    cout<<'!'<<" "<<ans<<endl;
    cout.flush();
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