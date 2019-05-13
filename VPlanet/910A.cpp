#include<bits/stdc++.h>
using namespace std;

// Greedly choose the maximum distance to jump
int main(void)
{
    int n,d;
    cin >> n >> d;
    string s;
    cin >> s;

    int current = 0;
    int count = 0;
    while(current < n-1)
    {
        for(int i=d;i>=0;i--)
        {
            if(i==0)
            {
                cout << -1 << endl;
                exit(0);
            }

            else if((s[current + i])=='1') // To compare char to number use '1'
            {
                current += i;
                count += 1;
                break;
            }

        }
    }

    cout << count << endl;







}
