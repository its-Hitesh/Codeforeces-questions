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

void solve(){
    int n; cin>>n;
    int cnt[10] = {};
    vector<int> down(10 ,0), right(10, 0), left(10, 1e5), up(10, 1e5);
    string a[n]; 
    foo(i,0,n){
        cin>>a[i];
        foo(j,0,n){
            cnt[a[i][j] - '0']++;
            left[a[i][j] - '0'] = min(left[a[i][j] - '0'], j);
            right[a[i][j] - '0'] = max(right[a[i][j] - '0'], j);
            down[a[i][j] - '0'] = max(down[a[i][j] - '0'], i);
            up[a[i][j] - '0'] = min(up[a[i][j] - '0'], i);
        }
        
    }
    int ans[10] = {};
    foo(i,0,10){
        if(cnt[i] < 2) continue;
        foo(k,0,n){
            int lt = -1, rt = -1;
            foo(l, 0, n){
                if(a[k][l] - '0' == i){
                    if(lt == -1) lt = l, rt = l;
                    else rt = l;
                }
            }
            if(lt == -1) continue;
            ans[i] = max(ans[i], max((rt - lt)* k, (rt - lt)* (n - k - 1)));                            //
            ans[i] = max(ans[i], max((n - lt - 1) *  (k - up[i]), (n - lt - 1)*(down[i] - k)));
            ans[i] = max(ans[i], max((lt) *  (k - up[i]), (lt)*(down[i] - k)));
            ans[i] = max(ans[i], max((n - rt - 1) * (k - up[i]), (n - rt - 1)*(down[i] - k)));
            ans[i] = max(ans[i], max((rt) * (k - up[i]), (rt)*(down[i] - k)));
        }
    }
    foo(i,0,10){
        if(cnt[i] < 2) continue;
        foo(l, 0, n){    
            int uper = -1, niche = -1;
            foo(k,0,n){            
                if(a[k][l] - '0' == i){
                    if(uper == -1) uper = k, niche = k;
                    else niche = k;
                }
            }
            // cout<<i<<" "<<uper<<" "<<niche<<ed;
            if(uper == -1) continue;
            ans[i] = max(ans[i], max((niche - uper)* l, (niche - uper)* (n - l - 1))); 
            // cout<<ans[i]<<ed;                           //
            ans[i] = max(ans[i], max((n - uper - 1) *  (l - left[i]), (n - uper - 1)*(right[i] - l)));
            ans[i] = max(ans[i], max((uper) *  (l - left[i]), (uper)*(right[i] - l)));
            // cout<<ans[i]<<ed;                           //
            ans[i] = max(ans[i], max((n - niche - 1) * (l - left[i]), (n - niche - 1)*(right[i] - l)));
            ans[i] = max(ans[i], max((niche) * (l - left[i]), (niche)*(right[i] - l)));
            // cout<<ans[i]<<ed;                           //
        }
    }

    foo(i,0,10){
        cout<<ans[i]<<" ";
    }
    cout<<ed;
    
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