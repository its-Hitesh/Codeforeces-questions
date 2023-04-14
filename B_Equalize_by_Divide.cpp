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

void solve(){
    int n; cin>>n;
    int cntone = 0, cntnot = 0;
    vector<int> a(n); 
    foo(i,0,n) {
        cin>>a[i];
        if(a[i] == 1) cntone++;
        else cntnot++;
    }
    if(cntone == n){
        cout<<0<<ed;
        return;
    }
    if(cntone == 0){
        vector<pair<int,int>> ans ;
        int loop = 30 * n;
        while(loop--){
            int mini = INT_MAX, idx = 0;
            foo(i,0,n){
                if(mini > a[i]) {
                    mini = a[i];
                    idx = i;
                }
            }
            foo(i,0,n){
                if(a[i] == mini){
                    continue;
                }
                a[i] = (a[i] + mini - 1) / mini ;
                ans.pb({i+1,idx+1});
            }
            bool f = true ;
            foo(i,0,n-1){
                if(a[i] != a[i+1]){
                    f = false ;
                    break;
                }
            }
            if(f){
                cout<<ans.size()<<ed;
                for(auto x : ans) cout<<x.first<<" "<<x.second<<ed;
                return;
            }
        }
        cout<<-1<<ed;
    }
    else{
        cout<<-1<<ed;
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