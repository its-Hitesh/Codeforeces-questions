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
const int maxa = 1000005;
bool prime[maxa];
int spf[maxa];

void solve(){
    int n; cin>>n;
    int a[n]; foo(i,0,n) cin>>a[i];
    int ans = 1;
    foo(i,0,n){
        int temp = 0;
        
        
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

    foo(i,0,maxa){
        prime[i] = true;
    }
    prime[0] = prime[1] = false ;
    for(int i = 2; i < maxa; i++){
        if(prime[i]){
            spf[i] = i;
            for(int j = i*i; j < maxa; j+=i){
                spf[j] = i;
                prime[j] = false ;
            }
        }
    }
  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}