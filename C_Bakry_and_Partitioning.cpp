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
    #define mod           998244353
    #define int long long

    // for fast hashing
    const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
    struct chash { // To use most bits rather than just the lowest ones:
        const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
        ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
    };
    template<class K,class V> using ht = gp_hash_table<K,V,chash>;
    //__gnu_pbds::gp_hash_table<ll, int, chash> ht({},{},{},{}, {1 << 16});

    //oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
    template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
    int totalxor = 0; bool f = 0, ans = 0;
    void dfs(int s, int p, vector<int> &xxor, vector<int> grp[], int a[]){
        xxor[s] = a[s];
        for(auto x : grp[s]){
            if(x != p){
                dfs(x, s, xxor, grp, a);
                xxor[s] ^= xxor[x];
            }
        }
        if(xxor[s] == totalxor){
            if(f == 0){
                if(p != -1){
                    grp[p].pop_back();
                    f = 1;
                    xxor[s] = 0;
                }  
            }
            else{
                ans = 1;
            }
        }
    }   

    void solve(){
        int n, k; cin>>n>>k;
        totalxor = 0; f = 0, ans = 0;
        int a[n]; foo(i,0,n) cin>>a[i], totalxor ^= a[i];
        vector<int> grp[n], xxor(n, 0);
        foo(i,0,n - 1){
            int x, y; cin>>x>>y;
            x--; y--;
            grp[x].pb(y);
            grp[y].pb(x);
        }
        if(totalxor == 0) {
            cout<<"YES"<<ed;
            return;
        }
        dfs(0, -1, xxor, grp, a);
        if(k == 2) ans = 0; 
        cout << (ans ? "YES" : "NO") << ed;
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