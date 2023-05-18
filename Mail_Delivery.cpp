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

int solve(){
      int n, m; cin>>n>>m;
    //   vector<vector<int>> g(n, vector<int>(n, 0));
      map<pair<int,int>,int> m;
      vector<int> grp[n];
      // reading the graph in the adjacency matrix
      foo(i,0,m){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
      }
      vector<int> deg(n);
      for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j)
              deg[i] += grp[i].size();
      }

      int first = 0;
      while (first < n && !deg[first])
          ++first;
      if (first == n) {
          cout <<"IMPOSSIBLE";
          return 0;
      }

      int v1 = -1, v2 = -1;
      bool bad = false;
      for (int i = 0; i < n; ++i) {
          if (deg[i] & 1) {
              if (v1 == -1)
                  v1 = i;
              else if (v2 == -1)
                  v2 = i;
              else
                  bad = true;
          }
      }

      if (v1 != -1)
          grp[v1].pb(v2), grp[v2].pb(v1);

      stack<int> st;
      st.push(first);
      vector<int> res;
      while (!st.empty()) {
          int v = st.top();
          
          for(auto x : grp[v]){

          }
        //   int i;
        //   for (i = 0; i < n; ++i)
        //       if (g[v][i])
        //           break;
        //   if (i == n) {
        //       res.push_back(v);
        //       st.pop();
        //   } else {
        //       --g[v][i];
        //       --g[i][v];
        //       st.push(i);
        //   }
      }

      if (v1 != -1) {
          for (size_t i = 0; i + 1 < res.size(); ++i) {
              if ((res[i] == v1 && res[i + 1] == v2) ||
                  (res[i] == v2 && res[i + 1] == v1)) {
                  vector<int> res2;
                  for (size_t j = i + 1; j < res.size(); ++j)
                      res2.push_back(res[j]);
                  for (size_t j = 1; j <= i; ++j)
                      res2.push_back(res[j]);
                  res = res2;
                  break;
              }
          }
      }

      for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
              if (g[i][j])
                  bad = true;
          }
      }

      if (bad || res[0] != 0) {
          cout << "IMPOSSIBLE";
      } else {
          for (int x : res)
              cout << x + 1 << " ";
      }
    return 0;
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