#include <bits/stdc++.h>
#include <bits/extc++.h>//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long ;
#define pb            push_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define m_p           make_pair
// #define mod           998244353
#define int long long

int GCD(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return GCD(b, a % b);
}
int cnt[100005];
void solve(){
    int n; cin>>n;
    int a[n]; foo(i,0,n) cin>>a[i];
    int evencnt = 0, oddcnt = 0;
    map<int,int> m;
    foo(i,0,n){
        if(m[a[i]] == 0){
            m[a[i]] = 1;
            if(a[i] & 1) oddcnt++;
            else evencnt++;
        }
        else {
            cout<<"NO"<<ed;
            return;
        }
    }
    int CRT_able = 1;
		for (int mod = 2;mod <= n / 2;++mod) {                        // no need to check primes greater than n / 2 because then min(cnt of(a[i] % p)) > 2 is not possiable
			fill(cnt, cnt + mod, 0);
			for (int i = 0;i < n;++i) {
				cnt[a[i] % mod]++;
			}                                                            // min of mod values should be less than 2 otherwise that prime will divide the number no matter what is x
			if (*min_element(cnt, cnt + mod) >= 2) CRT_able = 0;
		}                                                                   // a[i] % p + x % p   ==  a[j] % p + x % p if there is i, j for every mod p 
	cout << (CRT_able ? "YES" : "NO") << endl;
    
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