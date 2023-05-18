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
vector<pll> grp[100001] ;
int cnt[100001];
vector<int> ans ;
void dijkstra(int n, int k){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0,0});
    while(cnt[n] < k){                               // works fine with loop multiple edges but not negative edges 
        pll tt = q.top();
        q.pop();
        if(cnt[tt.second] == k) continue;
        if(tt.second == n){
            ans.pb(tt.first);
        }
        cnt[tt.second] += 1;
        for(auto x : grp[tt.second]){
            q.push({x.second + tt.first, x.first});
        }
    }
}
void solve(){
    int n, m, k; cin>>n>>m>>k;
    foo(i,0,m){
        int x, y ,z; cin>>x>>y>>z;
        x--; y--;
        grp[x].pb({y,z});
    }
    dijkstra(n - 1, k);
    sort(ans.begin(), ans.end());
    foo(i,0,k) cout<<ans[i]<<" ";
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