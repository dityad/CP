#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main(void)
{
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;

    int dp[n+1][m+1];

    for(int i =0;i<=n;i++)
    {
        for(int j =0;j<=m;j++)
        {
            if (i==0 || j==0) dp[i][j] = 0;
            else if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1; 
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        }
    }

    // for(int i =0;i<=n;i++)
    // {
    //     for(int j =0;j<=m;j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][m] << endl;









    return 0;
}