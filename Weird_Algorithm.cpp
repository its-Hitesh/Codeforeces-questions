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
 
void fun(int x){
    if(x == 1) {
        cout<<1;
        return;
    }
    if(x & 1){
        cout<<x<<" ";
        fun(3*x + 1);
    }
    else {
        cout<<x<<" ";
        fun(x/2);
    }
}
 
void solve(){
    int n; cin>>n;
    fun(n);
}
 
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
 
  int tt =1; //cin>>tt;
 
  while(tt--){
 
    solve();
  }
  return 0;
}