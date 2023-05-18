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
#define mod           1000000007
#define int long long

	namespace modop {
		ll madd(ll a, ll b) {
		return (a + b) % mod;
		}
		ll msub(ll a, ll b) {
		return (((a - b) % mod) + mod) % mod;
		}
		ll mmul(ll a, ll b) {
		return ((a % mod) * (b % mod)) % mod;
		}
		ll mpow(ll base, ll exp) {
		ll res = 1;
		while (exp) {
			if (exp % 2 == 1){
				res = (res * base) % mod;
			}
			exp >>= 1;
			base = (base * base) % mod;
		}
		return res;
		}
		ll minv(ll base) {
		return mpow(base, mod - 2);
		}
		ll mdiv(ll a, ll b) {
		return mmul(a, minv(b));
		}
		
		const ll FACTORIAL_SIZE = 1.1e6;
		ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
		bool __factorials_generated__ = 0;
		void gen_factorial(ll n) {
			__factorials_generated__ = 1;
			fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
			
			for (ll i = 2; i <= n; i++) {
				fact[i] = (i * fact[i - 1]) % mod;
			}
			ifact[n] = minv(fact[n]);
			for (ll i = n - 1; i >= 2; i--) {
				ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
			}
		}
		ll nck(ll n, ll k) {
			if (!__factorials_generated__) {
				cerr << "Call gen_factorial you dope" << endl;
				exit(1);
			}
			if (k < 0 || n < k) return 0;
			ll den = (ifact[k] * ifact[n - k]) % mod;
			return (den * fact[n]) % mod;
		}
	}

	using namespace modop;

void solve(){
    string s; cin>>s;
    int n = s.size();
    int pre[n + 1];
    foo(i,0,n + 1){
        pre[i] = mmul(i + 1, mpow(10, i));
        // cout<<pre[i]<<ed;
    }
    foo(i,1,n + 1){
        pre[i] = madd(pre[i], pre[i - 1]);
    }
    int ans = 0;
    foo(i,1,n + 1){
        ans = madd(ans, mmul(mmul(i * (i - 1) / 2, mpow(10, n - i)),s[i-1] - '0'));
    }
    foo(i,1,n) ans = madd(ans, mmul(pre[n - i - 1],s[i - 1] - '0'));
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}