#include<bits/stdc++.h>
const long long int mod=1e9+7;
using namespace std;
int main(){
    long long int n,x;
    cin>>n>>x;
    vector<long long int> coins(n);
    vector<long long int> DP(x+1,0);
     DP[0]=1;
    // cout<<DP[0];
    for (long long int i = 0; i < n; i++)
    {
        // long long int ele;
        cin>>coins[i];
    }
   
    for (long long int i = 1; i <=x; i++)
    {
        /* code */
        for (long long int j = 0; j < n; j++)
        {
            /* code */
            if (coins[j]>i){continue;}
            
             DP[i]=(DP[i]+DP[i-coins[j]])%mod;          
            
 
        }
      
        
    }
    // cout<<DP.size();
    cout<<DP[x]%mod;
    

}