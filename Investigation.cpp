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
#define mod           1000000007
#define int long long
const int M = 100000000000000000;
int n, m;
vector<int> dis(100001, M), route(100001,0), minf(100001, M), maxf(100001, 0);
void dijkstra(int st, vector<pll> grp[]){
    vector<int> vis(n + 1, 0);
    priority_queue<pll, vector<pll>, greater<pll> > q;
    q.push({0, st});
    dis[st] = 0;
    route[st] = 1;
    minf[st] = 0; maxf[st] = 0;
    while(!q.empty()){
        pll tt = q.top();
        q.pop();
        if(vis[tt.second]) continue;
        vis[tt.second] = 1;
        for(auto x : grp[tt.second]){
            // cout<<tt.second<<" "<<x.first<<ed;
                if(vis[x.first]) continue;
                if(dis[x.first] > dis[tt.second] + x.second){
                    dis[x.first] = dis[tt.second] + x.second;
                    route[x.first] = route[tt.second];
                    minf[x.first] = minf[tt.second] + 1;
                    maxf[x.first] = maxf[tt.second] + 1;
                    q.push({dis[x.first], x.first});
                }
                else if(dis[x.first] == dis[tt.second] + x.second){
                    route[x.first] += route[tt.second];
                    route[x.first] %= mod ;
                    minf[x.first] = min(minf[x.first], minf[tt.second] + 1);
                    maxf[x.first] = max(maxf[x.first], maxf[tt.second] + 1);
                    q.push({dis[x.first], x.first});
                }
        }
    }
}

void solve(){
    cin>>n>>m;
    vector<pll> grp[n + 1];
    foo(i,0,m){
        int x, y, z; cin>>x>>y>>z;
        x--; y--;
        grp[x].pb({y,z});
    }
    dijkstra(0, grp);

    cout<<dis[n - 1]<<" "<<route[n - 1]<<" "<<minf[n - 1]<<" "<<maxf[n - 1]<<ed;
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