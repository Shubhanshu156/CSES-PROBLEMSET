#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int m=n+1;
        vector<pair<long long int,long long int>> dp(n+1,{0,0});
        // construct a dp of length_error n+1 where dp[i] mean number of way to construct tower of size i
        // dp[i][0] mean top tile is of width 1 and dp[i][1] store way to build tower with upper tile is of width 2
        
        // If the last tile is split (dp[i][0]), it can have the following options:

            // It can extend both the split tiles at (i — 1): dp[i - 1][0]
            // It can extend on the left split tile at (i — 1): dp[i - 1][0]
            // It can extend on the right split tile at (i — 1): dp[i - 1][0]
            // It can extend none of the split tiles at (i — 1) but add it's own: dp[i - 1][0] and both tile are split
            // Tt can add split tiles over the continuous tile of i - 1th height: dp[i - 1][1]

        // Similarly if the last tile is continuous (dp[i][1]):

        //     It can extend the continuous tile at (i — 1): dp[i - 1][1]
        //     It can not extend the continuous tile at (i — 1): dp[i - 1][1]
        //     It can add a continuous tile over split tiles of (i — 1): dp[i - 1][0]
        dp[1].first=1;
        dp[1].second=1;
        for (int i = 2; i <=n; i++)
        {
            dp[i].first=(4*dp[i-1].first+dp[i-1].second)%mod;
            dp[i].second=(2*dp[i-1].second+dp[i-1].first)%mod;
        }
        long long int v=dp[n].first+dp[n].second;
        cout<<v%mod<<endl;
    }
    

}