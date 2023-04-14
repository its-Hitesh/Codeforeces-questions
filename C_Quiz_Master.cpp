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

vector<vector<int>>ds(100001);
void fac(){
    foo(i,1,100001){
        for(int j = i; j < 100001; j+=i){
            ds[j].pb(i);
        }
    }
}

int n,m;
bool good(int x, int a[]){
    int count = 0; 
    vector<int> cnt(1000001, 0);
    int l = 0, differ = 0;
    foo(i,0,n){
        differ = a[i] - a[l];
        for(auto z : ds[a[i]]) {
            if(z > m) break;
            // s.emplace(z);
            if(cnt[z] == 0) count++;
            cnt[z]++;
        }
        while(differ > x){
            for(auto z : ds[a[l]]) {
                if(z > m) break ;
                cnt[z]--;
                if(cnt[z] == 0){
                    count--;
                }
            }
            l++;
            differ = a[i] - a[l];
        }
        if(count == m) {
            return true ;
        }
    } 
    return false ;
}
void solve(){
    cin>>n>>m;
    // memset(a, 0, sizeof(a));
    int a[n];
    foo(i,0,n) {
        cin>>a[i];
    }
    sort(a,a+n);
    if(a[n] < m){
        cout<<-1<<ed;
        return ;
    }
    int l = 0, r = 100001, ans = INT_MAX;
    while(l <= r){
        int mid = l + (r -l) / 2;
        if(good(mid, a)){
            ans = min(ans,mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if(ans >= INT_MAX) ans = -1 ;
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

  int tt =1; cin>>tt;
    fac();
  while(tt--){

    solve();
  }
  return 0;
}