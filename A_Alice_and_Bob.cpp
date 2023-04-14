//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long fac[1000001];
	const int mod = 1000000007 ;
	long long binaryExponentiation(int x,int n)
    {
        long long res=1;
        while(n){
        if(n%2==1){
            res*=x;
            res%=mod;
        }
        n/=2;
        x*=x;
        x%=mod;
        }
        return res;
    }
    void fact(){
        fac[0] =1;
        for(int i = 1; i< 1e6 + 1; i++){
            fac[i] = ((fac[i-1]%mod)*i)%mod;
        }
    }
    long long ncr(int n , int r){
        if(r == 0 ||  r == n) return 1 ;
        long long temp1 = fac[n];
        long long temp2 = fac[n-r]*fac[r];
        temp2%=mod;
        long long temp3 = binaryExponentiation(temp2,mod-2);
        // cout<<temp1<<" "<<temp2<<" "<<temp3<<endl;
        temp1*=temp3;
        temp1%=mod;
        return temp1;
    }
	int compute_value(int n)
	{
	    // Code here
	    fact();
	    long long ans = 0;
	    for(int i=0; i<=n; i++){
	        long long x = ncr(n,i);
	        cout<<x<<endl;
	        ans = (ans + (x*x))% mod;
	    }
	    return ans ;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends