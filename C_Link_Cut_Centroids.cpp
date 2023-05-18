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
           
    for(auto z : grp[x]){
        if(z != p){
            if(siz[z] > (n / 2)) return findCentroid(z, x);
        }
    }
    return x; 
}

void solve(){
    cin>>n;
    foo(i,0,n + 1){
        vis[i] = 0;
        siz[i] = 0;
        grp[i].clear();
    }
    foo(i, 0, n - 1){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    dfs(0, -1);

    int cntroid = findCentroid(0, -1);
    // cout<<cntroid<<ed;
    for(auto x : grp[cntroid]){
        bool f = 0;
        if(siz[x] > siz[cntroid]) continue;
        
        // cout<<siz[x]<<" "<<x<<ed;
        if(n - siz[x] > n / 2) f = 1;
        if(!f){
            int temp = 0, tans = 0;
            for(auto z : grp[x]){
                if(z != cntroid){
                    if(siz[z] > temp){
                        temp = siz[z];
                        tans = z;
                    }
                }
            }
            cout<<x + 1<<" "<<tans + 1<<ed;
            cout<<cntroid + 1<<" "<<tans + 1<<ed;
            return ;
        }
    }
        for(auto x : grp[cntroid]){
            if(siz[x] > siz[cntroid]) continue;
            cout<<cntroid + 1<<" "<<x + 1<<ed;
            cout<<cntroid + 1<<" "<<x + 1<<ed;
            return;
        }
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

  while(tt--){

    solve();
  }
  return 0;
}