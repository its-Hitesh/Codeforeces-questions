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

int answer = 0;
void dfs(int s, int p, vector<vector<int>> &grp, vector<int> &ans, vector<int> &val){
    if(grp[s].size() == 1){
        ans[s] = val[s];
    }
    for(auto x : grp[s]){
        if(p != x){
            dfs(x, s, grp, ans, val);
        }
    }
    int one = 0;
    for(auto x : grp[s]){
        if(x != p){
            if(ans[x] == 1){
                one++;
            }
        }
    }
    if((one & 1) && val[s] == 1){
        answer += one;
        ans[s] = 0;
    }
    else if( (one & 1) && val[s] == 0){
        ans[s] = 1;
        answer += one;
    }
    else if((one % 2 == 0) && val[s] == 1){
        ans[s] = 1;
        answer += one;
    }
    else if((one % 2 == 0) && val[s] == 0){
        answer += one ;
        ans[s] = 0;
    }

}
void solve(){
    int n; cin>>n;
    vector<vector<int>> grp(n);
    foo(i,0,n-1){
        int x, y;  cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    vector<int> val(n);
    int one = 0;
    foo(i,0,n) {
        cin>>val[i];
        if(val[i] == 1) one++;
    }
    if(one & 1) {
        cout<<-1<<ed;
        return ;
    }
    vector<int> ans(n);
    foo(i,0,n){
        if(val[i] == 1){
            dfs(i, -1, grp,ans, val);
            break;
        }
    }
    cout<<answer<<ed;
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