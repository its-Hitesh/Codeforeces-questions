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
vector<int> grp[200005];
int vis[200005], siz[200005];
ll n; 
int dfs(int s, int p){
    siz[s] = 1;
    for(auto x : grp[s]){
        if(x != p){
            siz[s] += dfs(x,s);
        }
    }
    return siz[s];
}
int findCentroid(int x, int p){
            // cout<<siz[x]<<" "<<x<<" "<<p<<ed;
    for(auto z : grp[x]){
        if(z != p){
            if(siz[z] > (n / 2)) return findCentroid(z, x);
        }
    }
    return x; 
}
void solve(){
    cin>>n;
    foo(i,0,n - 1){
        int x, y; 
        cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    dfs(0, -1);
    // foo(i,0,n) cout<<siz[i]<<" ";
    cout<<findCentroid(0, -1) + 1;
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