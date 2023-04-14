#include <bits/stdc++.h>
#define ll            long long
#define pb            push_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define ct            cout
#define m_p           make_pair
#define vi            vector<ll>
#define vpll           vector<pll>
#define ff            first
#define ss            second
#define mod           1000000007
#define int long long
using namespace std;

void solve(){
    string s; cin>>s;
    int k,st=0,n=s.size(); cin>>k;
    bool zero = false ;
    string ans="";
    while(k > 0){
      if(!zero){
        foo(i,1,10){
          bool f = false;
          foo(j,st,k+1){
            if(s[j]-'0' == i){
              
              k -=(j-st);
              ans+=s[j];
              st = j+1;
              zero = true ; 
              f = true;
              break;
            }
          }
          if(f) break;
        }
      }
      else{
        foo(i,0,10){
          bool f = false;
          foo(j,st,k+1){
            if(s[j]-'0' == i){
              k -= (j-st);
              ans+=s[j] ;
              st = j+1; 
              f = true;
              break;
            }
          }
          if(f) break;
        }
      }
    }
    foo(i,st,n){
      ans+=s[i];
    }
    ct<<ans<<ed;
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


  int t =1; cin>>t;

  while(t--){

    solve();

  }
  return 0;
}

