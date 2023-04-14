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

int dp[300005][2], team[300005];                         // 0 is even and 1 is odd
int  ans = 1;
bool dfsrec(int x, vector<int> grp[], int t, int visited[]){
    visited[x] = 1;
    team[x] = t;
    dp[x][1] = 2;
    dp[x][0] = 1;
    for(auto u : grp[x]){
        if(team[u] == team[x]) return true ;
        if(visited[u] == 0){
            if(dfsrec(u,grp,(t==1)? 2 : 1, visited)) return true ;
            dp[x][1] = mmul(dp[u][0], dp[x][1]);
            dp[x][0] = mmul(dp[u][1],dp[x][0]);
        }
    }
    return false ;
}
 
bool dfs(int n, int visited[], vector<int> grp[]){
    foo(i,0,n){
        if(visited[i] == 0){
            if(dfsrec(i,grp,1, visited)) return false;
            ans = mmul(ans,madd(dp[i][0], dp[i][1]));    
        }
    }
    return true ;
}

void solve(){
    ans = 1;
    int n, m; cin>>n>>m;
    vector<int> grp[n];
    foo(i,0,m){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    int visited[n] = {};
    foo(i,0,n) team[i] = -1;
    bool f = dfs(n, visited, grp);
    if(f == false ) cout<< 0 << ed;
    else cout<<ans<<ed;
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