#include<bits/stdc++.h>
using namespace std;

int main(void)
{

    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;

    int dp[n+1][m+1];

    //Suffixes are still confusing, lets try prefixes

    for(int i=0;i<=n;i++)
    {
        for(int j =0;j<=m;j++)
        {
            if(i==0) dp[i][j] = j; 
            else if (j==0) dp[i][j] = i;

            else{
            int cost = 0;
            if(s[i]!=t[j]) cost = 1;
            dp[i][j] = min(min(dp[i-1][j-1]+cost,dp[i-1][j]+1),dp[i][j-1]+1);
            }

        }
    }

    cout << dp[n][m] << endl;








    return 0;
}