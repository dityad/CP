// Seems to work
// Check with https://www.geeksforgeeks.org/subset-sum-problem-dp-25/ if there is any bug.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{

    int n,sum;
    int arr[n];
    cin >> n >> sum;
    int temp;
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }

    int dp[n][sum+1];

    for(int i =0;i<n;i++) dp[i][0] = 1;
    for(int i =1;i<=sum;i++) dp[0][i] = 0;

    for(int i =1;i<n;i++)
    {
        for(int s=1;s<=sum;s++)
        {
            if(s-arr[i]>=0) dp[i][s] = dp[i-1][s] || dp[i-1][s-arr[i]];
            else if(s-arr[i]<0) dp[i][s] = dp[i-1][s];
        }
    }
    
    cout << dp[n-1][sum] << endl;











    return 0;
}