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
vector<int> grp[200005], val(200005);
int ans[200005];
set<int> dfs(int s, int p){
    set<int> t;
    t.insert(val[s]); 
    for(auto x : grp[s]){
        if(x != p){
            set<int> child =  dfs(x, s);
            if(child.size() > t.size()) swap(child, t);
            for(int x : child) t.insert(x);
        }
    }
    ans[s] = t.size();
    return t ;
}

void solve(){
    int n; cin>>n;
    foo(i,1,n + 1) cin>>val[i];
    foo(i,0,n - 1){
        int x, y; cin>>x>>y;
        grp[x].pb(y);
        grp[y].pb(x);
    }

    dfs(1, -1);
    
    foo(i,1,n+1) cout<<ans[i]<<" ";
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