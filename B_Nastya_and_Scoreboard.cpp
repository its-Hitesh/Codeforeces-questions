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

int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

void solve(){
    int n, k; cin >> n >> k;
    int digit[10] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
    int a[n], ans[n];
    foo(i,0,n){
        int x ;cin>>x;
        a[i] = convert(x);
    }
    vector<int> req(n , 1e9);
    foo(i,0,n){
        foo(j,0,10){
            if((digit[j] | a[i]) == digit[j]){
                int x = __builtin_popcount(digit[j]) - __builtin_popcount(a[i]);
                if(x <= req[i]) ans[i] = j;
                req[i] = min(x, req[i]);
            }
        }
    }

    int sum = 0;
    
    foo(i,0,n) sum += req[i];
    if(sum > k) cout<<-1<<ed;
    else{
        k -= sum;
        foo(i,0,n){
            for(int j = 9; j >= 0; j--){
                if((digit[j] | a[i]) == digit[j]){
                    int before = __builtin_popcount(digit[ans[i]]) - __builtin_popcount(a[i]);
                    int y = __builtin_popcount(digit[j]) - __builtin_popcount(a[i]);
                    if(before + k >= y){
                        ans[i] = j;
                        k = k + before - y;
                        break;
                    }
                }
            }
        }
        if(k == 0){
            foo(i,0,n) cout<<ans[i];
            cout<<ed;
        }
        else{
            for(int i = n - 1; i >= 0; i--){
                int maxa = 0, temp = ans[i];
                int x = __builtin_popcount(digit[ans[i]]) - __builtin_popcount(a[i]);
                for(int j = 9; j >= 0; j--){
                    int y = __builtin_popcount(digit[j]) - __builtin_popcount(a[i]);
                    cout<<x<<" "<<y<<" "<<k<<ed;
                    if(((digit[j] | a[i]) == digit[j]) && y <= k + x){
                        cout<<i<<" "<<y<<" "<<k<<" "<<j<<" "<<ans[i]<<" "<<j<<" "<<(digit[j] | digit[ans[i]])<<ed;
                        if(maxa < y) temp = j;
                        maxa = max(maxa, y);
                    }
                }
                k -=  maxa - x;
                ans[i] = temp;    
            }
            if(k != 0) cout<<-1<<ed;
            else{
                foo(i,0,n) cout<<ans[i];
                cout<<ed;
            }
        }
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}