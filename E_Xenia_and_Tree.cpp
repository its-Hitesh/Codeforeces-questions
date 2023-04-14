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

int n, m;
int vis[100005], siz[100005], parent[100005], lca[100005][26];
vector<int> grp[100005], cenGrp[100005];
vector<ll> best(100005, INT_MAX);

int depth[100005];
void dfs(int s, int p){
    lca[s][0] = p;
    foo(j,1,24){
            if(lca[s][j - 1] == -1) lca[s][j] = -1;
            else lca[s][j] = lca[lca[s][j - 1]][j - 1] ;
    }
    for(auto x : grp[s]){
        if(x != p) {
            depth[x] = depth[s] + 1;
            dfs(x, s);
        }
    }
}

void initLca(){
    dfs(0, -1);
}

int LCA(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);
        int up = depth[x] - depth[y];
        for(int j = 24; j >= 0; j--){
            if(up & (1 << j)){
                x = lca[x][j];
                up -= (1 << j);
            }
        }
        if(x == y) return x;
        else{
            for(int j = 23; j >= 0; j--){
                if(lca[x][j] != lca[y][j]){
                    x = lca[x][j];
                    y = lca[y][j];
                }
            }
            return lca[x][0] ;
        }
}

int distance(int x, int y){
    int lc = LCA(x, y);
    return depth[x] + depth[y] - 2 * depth[lc];
}

int sizOfTree(int s, int p){
    if(vis[s]) return 0;
    siz[s] = 1;
    for(auto x : grp[s]){
        if(x != p){
            siz[s] += sizOfTree(x,s);
        }
    }
    return siz[s];
}
int findCentroid(int x, int p, int n){
            // cout<<siz[x]<<" "<<x<<" "<<p<<ed;
    for(auto z : grp[x]){
        if(z != p){
            if(vis[z] == 0 && siz[z] > (n / 2)) return findCentroid(z, x, n);
        }
    }
    return x; 
}

void initCentroid(int s, int p){
    sizOfTree(s, -1);                                              //siz of subtree taking root as s

    int c = findCentroid(s, -1, siz[s]);
    vis[c] = 1;                                                   
    parent[c] = p;

    for(auto x : grp[c]){
        if(vis[x] == 0){
            initCentroid(x, c);
        }
    }
}

void update(int v){
    best[v] = 0;
    int u = v ;
    while(parent[u] != -1){
        u = parent[u];
        best[u] = min(best[u], (ll)distance(u,v));
        // cout<<best[u]<<" "<<u<<ed;
    }
}

ll query(int v){
    ll ans = best[v];
    int u = v ;
    while(parent[u] != -1){
        u = parent[u];
        ans = min(ans, best[u] + (ll)distance(u,v));
    }
    return ans ;
}

void solve(){
    cin>>n>>m;
    foo(i,0,n - 1){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    initCentroid(0, -1);                                 // making centroid tree , get grp as parents array
    // foo(i,0,n) cout<<parent[i]<<" ";

    int root = 0;
    dfs(0, -1);
    initLca();
    update(0);
    
    // foo(i,0,n){
    //     foo(j,i,n) cout<<distance(i,j)<<" "<<i<<" "<<j<<" "<<best[i]<<ed;
    // }
    
    foo(i,0,m){
        int x, y;
        cin>>x>>y;
        y--;
        if(x == 1){
            update(y);
        }
        else{   
            cout<<query(y)<<ed;
        }
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}
// #include <bits/stdc++.h>
// #include <chrono> 
 
// using namespace std;
// using namespace std::chrono; 
 
// // #pragma GCC target ("avx2")
// // #pragma GCC optimization ("O3")
// // #pragma GCC optimization ("unroll-loops")
// // #pragma optimization_level 3
// // #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// // #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
// #define f0r(a, b) for (long long a = 0; a < (b); ++a)
// #define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
// #define f0rd(a, b) for (long long a = (b); a >= 0; --a)
// #define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
// #define ms(arr, v) memset(arr, v, sizeof(arr))
// #define pb push_back
// #define send {ios_base::sync_with_stdio(false);}
// #define help {cin.tie(NULL); cout.tie(NULL);}
// #define fix(prec) {cout << setprecision(prec) << fixed;}
// #define mp make_pair
// #define f first
// #define s second
// #define all(v) v.begin(), v.end()
// #define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
// #define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
// #define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
// #define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
// #define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
// #define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
// #define vsz(x) ((long long) x.size())
// typedef long long ll;
// typedef long double lld;
// typedef unsigned long long ull;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<pii> vpi;
// typedef vector<pll> vpl;
 
// template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
// template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
// template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
// 	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
// }
// template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
// 	cin >> p.first;
// 	return cin >> p.second;
// }
 
// mt19937 rng(steady_clock::now().time_since_epoch().count());
// // mt19937 rng(61378913);
// /* usage - just do rng() */
 
// void usaco(string filename) {
//   // #pragma message("be careful, freopen may be wrong")
// 	freopen((filename + ".in").c_str(), "r", stdin);
// 	freopen((filename + ".out").c_str(), "w", stdout);
// }
 
// const lld pi = 3.14159265358979323846;
// // const ll mod = 1000000007;
// // const ll mod = 998244353;
// // ll mod;

// struct lca_lift {
//   const int lg = 24;
//   int n;
//   vector<int> depth;
//   vector<vector<int> > edges;
//   vector<vector<int> > lift;
  
//   void init(int sz) {
//     n = sz;
//     depth = vector<int>(n);
//     edges = vector<vector<int> >(n, vector<int>());
//     lift = vector<vector<int> >(n, vector<int>(lg, -1));
//   }

//   void edge(int a, int b) {
//     edges[a].push_back(b);
//     edges[b].push_back(a);
//   }

//   void attach(int node_to_attach, int node_to_attach_to) {
//     int a = node_to_attach, b = node_to_attach_to;
//     edge(a, b);

//     lift[a][0] = b;

//     for (int i = 1; i < lg; i++) {
//       if (lift[a][i - 1] == -1) lift[a][i] = -1;
//       else lift[a][i] = lift[lift[a][i - 1]][i - 1];
//     }

//     depth[a] = depth[b] + 1;
//   }

//   void init_lift(int v = 0) {
//     depth[v] = 0;
//     dfs(v, -1);
//   }

//   void dfs(int v, int par) {
//     lift[v][0] = par;

//     for (int i = 1; i < lg; i++) {
//       if (lift[v][i - 1] == -1) lift[v][i] = -1;
//       else lift[v][i] = lift[lift[v][i - 1]][i - 1];
//     }

//     for (int x: edges[v]) {
//       if (x != par) {
//         depth[x] = depth[v] + 1;
//         dfs(x, v);
//       }
//     }
//   }

//   int get(int v, int k) {
//     for (int i = lg - 1; i >= 0; i--) {
// 	  if (v == -1) return v;
//       if ((1 << i) <= k) {
//         v = lift[v][i];
//         k -= (1 << i);
//       }
//     }
//     return v;
//   }

//   int get_lca(int a, int b) {
//     if (depth[a] < depth[b]) swap(a, b);
//     int d = depth[a] - depth[b];
//     int v = get(a, d);
//     if (v == b) {
//       return v;
//     } else {
//       for (int i = lg - 1; i >= 0; i--) {
//         if (lift[v][i] != lift[b][i]) {
//           v = lift[v][i];
//           b = lift[b][i];
//         }
//       }
//       return lift[b][0];
//     }
//   }
  
//   int get_dist(int a, int b) {
// 	  int v = get_lca(a, b);
// 	  return depth[a] + depth[b] - 2 * depth[v];
//   }
// };

// struct centroid {
//   vector<vector<int> > edges;
//   vector<bool> vis;
//   vector<int> par;
//   vector<int> sz;
//   int n;

//   void init(int s) {
//     n = s;
//     edges = vector<vector<int> >(n, vector<int>());
//     vis = vector<bool>(n, 0);
//     par = vector<int>(n);
//     sz = vector<int>(n);
//   }

//   void edge(int a, int b) {
//     edges[a].pb(b);
//     edges[b].pb(a);
//   }

//   int find_size(int v, int p = -1) {
//     if (vis[v]) return 0;
//     sz[v] = 1;

//     for (int x: edges[v]) {
//       if (x != p) {
//         sz[v] += find_size(x, v);
//       }
//     }

//     return sz[v];
//   }

//   int find_centroid(int v, int p, int n) {
//     for (int x: edges[v]) {
//       if (x != p) {
//         if (!vis[x] && sz[x] > n / 2) {
//           return find_centroid(x, v, n);
//         }
//       }
//     }

//     return v;
//   }

//   void init_centroid(int v = 0, int p = -1) {
//     find_size(v);

//     int c = find_centroid(v, -1, sz[v]);
//     vis[c] = true;
//     par[c] = p;

//     for (int x: edges[c]) {
//       if (!vis[x]) {
//         init_centroid(x, c);
//       }
//     }
//   }
// };

// ll n, m, k, q, l, r, x, y, z;
// ll a[1000005];
// ll b[1000005];
// ll c[1000005];
// string s, t;
// ll ans = 0;

// lca_lift lca;
// centroid ct;
// int best[100005];

// void update(int v) {
// 	best[v] = 0;
	
// 	int u = v;
// 	while (ct.par[u] != -1) {
// 		u = ct.par[u];
// 		best[u] = min(best[u], lca.get_dist(u, v));
// 	}
// }

// int query(int v) {
// 	int ans = best[v];
	
// 	int u = v;
// 	while (ct.par[u] != -1) {
// 		u = ct.par[u];
// 		ans = min(ans, best[u] + lca.get_dist(u, v));
// 	}
// 	return ans;
// }

// void solve(int tc = 0) {
// 	cin >> n >> q;
	
// 	lca.init(n);
// 	ct.init(n);
	
// 	f0r(i, n) best[i] = 2e5;
	
// 	f0r(i, n - 1) {
// 		cin >> x >> y;
// 		--x; --y;
// 		lca.edge(x, y);
// 		ct.edge(x, y);
// 	}
	
// 	lca.init_lift();
// 	ct.init_centroid();
	
//     f0r(i, n){
//         f1r(j,i,n) cout<<lca.get_dist(i,j)<<" "<<i<<" "<<j<<" "<<best[i]<<"\n";
//     }

// 	update(0); // include this b/c node 1 is initially red
	
// 	f0r(i, q) {
// 		int t; cin >> t >> x;
// 		--x;
		
// 		if (t == 1) update(x);
// 		else cout << query(x) << '\n';
// 	}
// }

// int main() {
// 	#ifdef galen_colin_local
// 		auto begin = std::chrono::high_resolution_clock::now();
// 	#endif
	
// 	send help

// 	#ifndef galen_colin_local
// 		// usaco("cowland");
// 	#endif
	
// 	// usaco("cowland");

// 	int tc = 1;
// 	// cin >> tc;
// 	for (int t = 0; t < tc; t++) solve(t);
	
// 	#ifdef galen_colin_local
// 		auto end = std::chrono::high_resolution_clock::now();
// 		cout << setprecision(4) << fixed;
// 		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
// 	#endif
// } 