#include<bits/stdc++.h>
using namespace std;

vector<int> p;

// curr = current number of elements in a permutation. Should be equal to n in the end.

void search(int curr, int n,int chosen[])
{
    if(curr == n)
    {
        for(auto x: p) cout << x;
        cout << endl;
    }
    else
    {
        for(int i =0;i<n;i++)
        {
            if(chosen[i] == 1) continue; // Important part, if it is already chosen, the next element in the n numbers is chosen, the for loop takes care of this.
            chosen[i] = 1;
            p.push_back(i);
            search(curr+1,n,chosen);
            chosen[i] = 0;
            p.pop_back();
        }
    }
    
}

int main(void)
{
    int n;
    cin >> n;
    int chosen[n] = {0}; 
    search(0,n,chosen);

    return 0;
}