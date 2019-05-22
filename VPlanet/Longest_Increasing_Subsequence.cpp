#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }

    int dp[n][n] = {0};

    for(int i =0;i<n;i++)
    {
        for(int j =i;j<n;j++)
        {
            if(i==j) dp[i][j] = 1;
            else if(arr[j]>arr[j-1])
            {
                dp[i][j] = dp[i][j-1] + 1;
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
            
        }
    }

    // for(int i =0;i<n;i++)
    // {
    //     for(int j =0;j<n;j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[0][n-1] << endl;












    return 0;
}