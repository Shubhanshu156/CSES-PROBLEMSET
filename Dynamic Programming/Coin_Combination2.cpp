#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n, target;
  cin >> n >> target;
  vector<int> x(n);
  for (int&v : x) cin >> v;

  vector<vector<int>> dp(n+1,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
        if (x[i-1]<=j)
        {
            /* code */
             dp[i][j]=dp[i][j-x[i-1]]%mod+dp[i-1][j]%mod; // exclude coin and include coin
        }
        else{
            dp[i][j]=dp[i-1][j]; //exclude the coin no choice copy above value
        }
        
    //   dp[i][j] = dp[i-1][j];
    //   int left = j-x[i-1];
    //   if (left >= 0) {
	// (dp[i][j] += dp[i][left]) %= mod;
    //   }
    }
  }
  cout << dp[n][target]%mod<< endl;
}