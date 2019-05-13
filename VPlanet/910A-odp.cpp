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

    // We are storing the position of the '1' closest to each i. The idea being we want to use this value directly instead of looping.
    // https://www.youtube.com/watch?time_continue=1&v=Vhi4mv-f6Ic
    // Around 45 Min
    queue<int> pos;
    for(int i=0;i<n;i++) if(s[i]=='1') pos.push(i);

    for(int i=d;i<n;i++)
    {
        // flag = 0;
        if(s[i]=='1')
        {   
            
            while(pos.front() < i-d) // These 1's are too far to the left and don't effect the decision of the dp[i]
            {
                pos.pop();
            }
            if(dp[pos.front()]==-1) dp[i] == -1; // When it is unreachable we don't want to add 1 
            else dp[i] = dp[pos.front()] + 1;

            // if(flag==0) dp[i] = -1;
        }

    }
    
    // for(int i=0;i<n;i++) cout << dp[i];

    cout << dp[n-1] << endl;



    return 0;
}