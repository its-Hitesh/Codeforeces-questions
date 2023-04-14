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
    int n, m, l, o; cin >> n >> m >> l >> o;
    n--; m--;
    vector<vector<char>>a(50, vector<char>(50, 'z'));
    for(int i = 1; i <= 25; i+=2){
      for(int j = 0; j < 50; j ++){
        a[i][j] = 'A';
      }
    }
    for(int j = 1; j < 50; j += 2){
      for(int i = 0; i < 25; i++) a[i][j] = 'A';
    }
    int i = 0, j = 0;
    while(m--){
      a[i][j] = 'B';
      j += 2;
      if(j >= 50) j = 0, i+=2;
    }
    while(l--){
      a[i][j] = 'C';
      j += 2;
      if(j >= 50) j = 0, i+=2;
    }
    while(o--){
      a[i][j] = 'D';
      j += 2;
      if(j >= 50) j = 0, i+=2;
    }

    for(int k = 26; k < 50; k+=2){
      for(int q = 0; q < 50; q ++){
        a[k][q] = 'B';
      }
    }
    for(int k = 1; k < 50; k += 2){
      for(int q = 26; q < 50; q++) a[q][k] = 'B';
    }
    i = 27; j = 0;
    while(n--){
      a[i][j] = 'A';
      j += 2;
      if(j >= 50) j = 0, i += 2;
    }
  cout<<50<<" "<<50<<ed;
  foo(q,0,50) {
    foo(k,0,50) {
      if(a[q][k] == 'z') a[q][k] = a[q][k+1];
      cout<<a[q][k];
    }
    cout<<ed;
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