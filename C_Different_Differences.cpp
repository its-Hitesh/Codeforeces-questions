#include<bits/stdc++.h>
typedef long long ll ;
#define int ll 
using namespace std ;
signed main( )
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int testcases = 1 ;
    cin >> testcases ;
    while( testcases -- )
    {
        int n,k ;
        cin >> k>>n ;
        int rem=n-k;
        vector<int> v;
        int b=1;
        int tot=0;
        while(true)
        {
        	tot+=b;
        	if(tot<=rem) v.push_back(b+1);
        	else break;
        	b++;
        	// cout<<b;
        	
        }
        int cur=n;
        vector<int>ans;
        int ct=1;
        for(int i=0;i<v.size();i++)
        {
        	// cout<<v[i];
        	ans.push_back(cur);
        	ct++;
        	cur-=v[i];
        }
        while(ct<=k)
        {
        	ans.push_back(cur);
        	cur-=1;
        	ct++;
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
        	cout<<ans[i]<<" ";
        }
        cout << endl ;
    }
    return 0 ;
}