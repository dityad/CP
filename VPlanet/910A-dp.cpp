#include<bits/stdc++.h>
using namespace std;

// Create a array that holds the number of counts that the frog takes to reach a position i.
// for every i+1 position we take the minimum of the all the counts that are at most a distance "d" away + 1(including that particular hop to reach i+1).

int main(void)
{
    int n,d;
    cin >> n >> d;
    string s;
    cin >> s;
    int dp[n];
    int flag; // The cases where the endpoint isnt reached dp[i] gets set to infinity and does not get updated further.
    // So the final answer becomes infinity, instead of -1. The flag finds such cases and makes the answer -1 instead.

    for(int i=0;i<n;i++) dp[i] = -1;
    dp[0] = 0;

    for(int i=1;i<d;i++) if(s[i]=='1') dp[i] = 1;

    for(int i=d;i<n;i++)
    {
        flag = 0;
        if(s[i]=='1')
        {   
            dp[i] = numeric_limits<int>::max(); // Set the initial value to infinity
            // When the endpoint is unreachable this doesn't get updated hence the need for the flag.
            for(int j=1;j<=d;j++)
            {
                if(dp[i-j] != -1)
                {
                    dp[i] = min(dp[i],dp[i-j]+1);
                    flag = 1;
                }
            }

            if(flag==0) dp[i] = -1;
        }

    }
    
    // for(int i=0;i<n;i++) cout << dp[i];

    cout << dp[n-1] << endl;









    return 0;
}