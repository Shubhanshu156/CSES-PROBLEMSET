#include <bits/stdc++.h>
using namespace std;
        // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
        // dp[i][v] = number of ways to fill the array up to index i, if x[i] = v.
        // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main() {
  int mod = 1e9+7;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(n,vector<int>(m+1,0));
  int x0;
  cin >> x0;
  if (x0 == 0) {                                    // if first element is 0 then we can make only 1 number of array with size(1,m)
    fill(dp[0].begin(), dp[0].end(), 1);            // so array we filled 1
  } else {
    dp[0][x0] = 1;                                  //if first element in nit zero then we can make 1 array of max element 1
  }
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) {                                    //if element if zero then we can choose value from 1 to m
      for (int j = 1; j <= m; j++) {                  
	for (int k : {j-1,j,j+1}) {
	  if (k >= 1 && k <= m) {
	    (dp[i][j] += dp[i-1][k]) %= mod;
	  }
	}
      }
    } else {
      for (int k : {x-1,x,x+1}) {
	if (k >= 1 && k <= m) {
	  (dp[i][x] += dp[i-1][k]) %= mod;
	}
      }
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; j++) {
    (ans += dp[n-1][j]) %= mod;
  }
  cout << ans << endl;
}