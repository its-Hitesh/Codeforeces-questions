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


void dfs(int root, vector<int> &ans, vector<vector<int>> &grp,vector<int> &c){
    bool f = true;
    // cout<<" root "<<root<<ed;
    for(auto x : grp[root]){
        if(c[x] == 0) f = false ;
        dfs(x,ans,grp,c);
    }
    if(c[root] == 1 && f) ans.pb(root);
}
void solve(){
    int n,root; cin>>n;
    vector<int> c(n+1);
    vector<vector<int>>grp(n+1);
    foo(i,0,n){
        int x,y; cin>>x>>y;
        c[i] = y;
        if(x == -1) root = i;
        else grp[x-1].pb(i);
    }
    vector<int> ans ;
    // dfs(root, ans, grp, c);
    foo(i,0,n){
        if(c[i] == 1){
            bool f = true ;
            for(auto x : grp[i]){
                if(c[x] == 0) {
                    f = false ;
                    break;
                }
            }
            if(f) ans.pb(i);
        }
    }

    sort(ans.begin(),ans.end());
    if(ans.size() == 0) cout<<-1<<ed;
    else 
        for(auto x : ans) cout<<x+1<<" ";
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