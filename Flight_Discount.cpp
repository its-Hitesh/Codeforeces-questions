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
const int M = 100000000000000000;
int n, m; 
void dijkstra(int st, vector<int> &dis, vector<pll> grp[]){
    vector<int> vis(n + 1, 0);
    priority_queue<pll, vector<pll>, greater<pll> > q;
    q.push({0, st});
    dis[st] = 0;
    while(!q.empty()){
        pll tt = q.top();
        q.pop();
        if(vis[tt.second]) continue;
        vis[tt.second] = 1;
        for(auto x : grp[tt.second]){
            if(vis[x.first] == 0){if(dis[x.first] > dis[tt.second] + x.second){
                dis[x.first] = dis[tt.second] + x.second;
                q.push({dis[x.first], x.first});
            }}
        }
    }
}
void solve(){
    cin>>n>>m;
    vector<pll> grp[n + 1], grpr[n + 1];
    vector<pair<ll,pll>> edges;
    foo(i,0,m){
        int x, y, z; cin>>x>>y>>z;
        x--; y--;
        edges.pb({x,{y,z}});
        grp[x].pb({y,z});
        grpr[y].pb({x,z});
    }
    vector<int> dis1(n + 1, M), dis2(n + 1, M);
    dijkstra(0, dis1, grp);
    dijkstra(n - 1, dis2, grpr);
    // foo(i,0,n) cout<<dis1[i]<<" ";
    // cout<<ed;
    // foo(i,0,n) cout<<dis2[i]<<" ";
    // cout<<ed;

    int ans = LLONG_MAX;
    foo(i,0,m){
        ans = min(ans, dis1[edges[i].first] + dis2[edges[i].second.first] + edges[i].second.second / 2);
        // ans = min(ans, dis2[edges[i].first] + dis1[edges[i].second.first] + edges[i].second.second / 2);
        // cout<<ans<<ed;
    }
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}