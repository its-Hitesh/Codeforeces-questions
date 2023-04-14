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

int fuc(string s, int a[])
{
    int n=sizeof(a[n]);
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int l=i;
        int r=i;
        int temp=1;
        while(s[l] == s[r] &&l>=0 && r<n)
        {
            temp+=2;
            l--;
            r++;
        }
        ans=max(temp,ans);
    }
    return ans;
}


int32_t main()
{
  

  return 0;
}