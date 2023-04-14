#include <bits/stdc++.h>
// #include <bits/extc++.h>//
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define int long long

// // for fast hashing
// const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { // To use most bits rather than just the lowest ones:
//     const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
//     ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
// };
// template<class K,class V> using ht = gp_hash_table<K,V,chash>;
// //__gnu_pbds::gp_hash_table<ll, int, chash> ht({},{},{},{}, {1 << 16});

// //oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

namespace number_theory {
	ll gcd(ll x, ll y) {
	  if (x == 0) return y;
	  if (y == 0) return x;
	  return gcd(y, x % y);
	}
	bool isprime(ll n) { 
	  if (n <= 1) return false; 
	  if (n <= 3) return true; 
	  
	  if (n % 2 == 0 || n % 3 == 0) return false; 
	  
	  for (ll i = 5; i * i <= n; i += 6) 
		if (n % i == 0 || n % (i+2) == 0) 
		  return false; 
	  
	  return true; 
	} 
	 
	bool prime[15000105]; 
	void sieve(int n) { 
	  for (ll i = 0; i <= n; i++) prime[i] = 1;
	  for (ll p = 2; p * p <= n; p++) { 
		if (prime[p] == true) { 
		  for (ll i = p * p; i <= n; i += p) 
			prime[i] = false; 
		} 
	  } 
	  prime[1] = prime[0] = 0;
	} 
	 
	vector<ll> primelist;
	bool __primes_generated__ = 0;
	 
	void genprimes(int n) {
	  __primes_generated__ = 1;
	  sieve(n + 1);
	  for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
	}
	 
	vector<ll> factors(ll n) {
	  if (!__primes_generated__) {
		cerr << "Call genprimes you dope" << endl;
		exit(1);
	  }
	  vector<ll> facs;
	 
	  for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
		if (n % primelist[i] == 0) {
		  while (n % primelist[i] == 0) {
			n /= primelist[i];
			facs.push_back(primelist[i]);
		  }
		}
	  }
	  if (n > 1) {
		facs.push_back(n);
	  }
	  sort(facs.begin(), facs.end());
	  return facs;
	}
	
	vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divs.push_back(i);
        divs.push_back(n / i);
      }
    }

    getunique(divs);
    return divs;
  }
}
using namespace number_theory;


void solve(){
    int n ; cin>> n;
    genprimes(n);
    vector<int> d = factors(n);
    map<int,int> m ; 
    for(auto x : d ){
        m[x]++;
    }
    int cnts = 0,cnta=0;
    for(auto x : m){
        int t = x.second;
        while(t != 1){
            if(t % 2 ==0) t /= 2, cnts++;
            else t++, cnta++;
        }
        m[x.first] = 1;
    }
    int ans = 1;
    for(auto x : m ){
        if(x.second == 1){
            ans *= x.first;
        }
    }
    cout<<ans<<" "<<cnt<<ed;
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