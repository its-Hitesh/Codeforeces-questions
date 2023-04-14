#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    int x[n]; for(int i=0;i<n;i++) cin>>x[i];
    int d[n]; for(int i=0;i<n;i++) cin>>d[i];
    vector<double> ans ;
    for(int i=0;i<n;i++){
         double tt = x[i]-d[i];
         double tt2 = x[i]+d[i];
         ans.push_back(tt);
         ans.push_back(tt2);
    }
    sort(ans.begin(),ans.end());
    double show = (ans[0]+ans[2*n-1])/2;
    cout<<setprecision(7)<<show<<"\n";
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

