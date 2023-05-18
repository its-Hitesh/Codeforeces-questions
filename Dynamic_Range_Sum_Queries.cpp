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
    const int N = 200005;
    int n, q; 
    int bit[N];

    void update(int x, int val){
        while(x <= n){
            bit[x] += val;
            x += (x & (-x));
        }
    }
    int sum(int x){
        int res = 0;
        while(x > 0){
            res += bit[x];
            x -= (x & (-x));
        }   
        return res ;
    }
    void solve(){
        cin>>n>>q;
        int a[n + 1];
        foo(i,1,n + 1) {
            int x; cin>>x;
            a[i] = x;
            update(i,x);
        }
        foo(i,0,q){
            int x, y, z; cin>>z>>x>>y;
            if(z == 2)
                cout<<sum(y) - sum(x - 1)<<ed;
            else {
                update(x, y - a[x]);
                a[x] = y;
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