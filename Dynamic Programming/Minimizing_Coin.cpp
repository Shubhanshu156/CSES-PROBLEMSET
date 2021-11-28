#include<bits/stdc++.h>
const long long int mod=1e9+7;
using namespace std;
int main(){
    long long int n,x;
    cin>>n>>x;
    vector<long long int> coins(n);
    vector<int> DP(x+1,1e9);
     DP[0]=0;
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
            
             DP[i]=min(DP[i],DP[i-coins[j]]+1)%mod;   //if we include the coin then just add 1
            //  cout<<DP[i]<<endl;       
            
 
        }
      
        
    }
    // cout<<DP.size();
    if (DP[x]==1e9)
    {cout<<-1<<endl;
        /* code */
    }
    else
    {
    cout<<DP[x]%mod<<endl;
        /* code */
    }
      
    

}