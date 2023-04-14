#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds; 
using ll = long long int;
#define INF             1e14
#define dd              double
#define MOD             1000000009
#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 
#define nl              cout<<endl
#define fill(a,val)     memset(a,val,sizeof(a))
#define mp              make_pair
#define endl            "\n"
#define pb              push_back
#define ff              first    
#define ss              second
#define SIZE            200005
#define all(v)          v.begin(),v.end()
#define s(ar,n)         sort(ar,ar+n)
#define rs(ar,n)        sort(ar, ar+n, greater<ll>()) 
#define oa(a,n)         for(ll i=0;i<n;i++)cout<<a[i]<<" ";nl
#define cn(a,n)         for(ll i=0;i<n;i++)cin>>a[i];
#define maxa(ar,N)      *max_element(ar,ar+N)
#define mina(ar,N)      *min_element(ar,ar+N)
#define fastio()        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define printclock      cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n";
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order() - 0 indexing
// order_of_key() - number of elements strictly smaller
ll power(ll x, ll y){
    ll res=1;x=x%MOD;
    while(y>0){
        if(y&1)
            res = (res*x)%MOD;
        y = y>>1;
        x = (x*x)%MOD;
    }
    return res;
}  
ll logtwo(ll n){
    if(n==1)
        return 0;
    return logtwo(n/2)+1;
}
//---------------------------------------GL HF------------------------------------------------------
// -------------------------------------ManavJ07----------------------------------------------------
bool bin_search(vector<ll> &h, vector<ll> &p_pow, vector<ll> &r_pow, ll idx, string &s){
    ll N = p_pow.size();
    ll low = idx-1, high = min(N-1, idx*2-1);
    ll ans = low;
    while(low <= high){
        ll mid = (low+high)/2;
        ll hash_val = (h[mid+1] - h[idx] + MOD)%MOD;
        hash_val = (hash_val * r_pow[idx])%MOD;
        if(hash_val == h[mid-idx+1]){
            low = mid+1;
            ans = mid;
        }
        else
            high = mid-1;
    }
    if(ans == min(N-1, idx*2-1))
        return false;
    if(s[ans+1] > s[ans-idx+1])
        return true;
    return false;
}

signed main()
{
    fastio();   
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        ll N, K;
        string s;
        cin>>N>>K>>s;
        string temp = s;
        while(s.size()<K)
            s += temp;
        s.resize(K);
        ll p = 31, m = 1e9+9;
        vector<ll> p_pow(K);
        vector<ll> r_pow(K);
        r_pow[0] = 1;
        ll x = power(p, MOD-2);
        p_pow[0] = 1;
        for (int i = 1; i < K; i++){
            r_pow[i] = (r_pow[i-1] * x) % m;
            p_pow[i] = (p_pow[i-1] * p) % m;
        }
        vector<ll> h(K + 1, 0);
        for (int i = 0; i < K; i++)
            h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        ll index = K;
        for(int i = 1;i < K; i++){
            if(bin_search(h, p_pow, r_pow, i, s)){
                index = i;
                break;
            }
        }
        string t = "";
        for(ll i = 0;i < index;i++)
            t += s[i];
        temp = t;
        while(t.size() < K)
            t += temp; 
        t.resize(K);
        cout<<t<<endl;
    }
}