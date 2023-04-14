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
    int n , k; cin>>n>>k;
    vector<pair<int,int>> z(n);
    foo(i,0,n){
        cin>>z[i].second;
    }
    foo(i,0,n){
        cin>>z[i].first;    // power
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pr;
    foo(i,0,n)
    {
        pr.push({z[i].first,z[i].second});
    }
    int result=k;
    while(!pr.empty() && k>0)
    {
        auto it=pr.top();
        pr.pop();
        
        if(it.second <= result)
        {   
            
            k-=it.first;
            pr.push({it.first,it.second});
 
        }
        result += k;
    }
     if(pr.empty())
        {
            cout<<"YES"<<endl;
            return;
        }
        
            cout<<"NO"<<endl;
 
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