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

int get_hash(int n){
    int temp = n;
    for(int i = 2; i * i <= n; i++){
        while(temp % (i * i) == 0){
            temp /= (i * i);
        }
    }
    return temp ;
}

void solve(){
    int n, k; cin>>n>>k;
    int a[n]; foo(i,0,n) cin>>a[i];
    unordered_map<int,int> m, ht;
    int ans = 1;
    foo(i,0,n) {
        int hash = ht[a[i]] == 0 ? ht[a[i]] = get_hash(a[i]) : ht[a[i]];
        if(m[hash] == 1){
            ans++;
            m.clear();
        }
        m[hash] = 1;
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