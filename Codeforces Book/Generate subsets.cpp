#include<bits/stdc++.h>
using namespace std;

vector<int> subset;

void search(int curr, int n)
{
    if(curr == n)
    {
        for(auto x: subset) cout << x;
        cout << endl;
    }
    else
    {
        search(curr+1,n); // First search the space without choosing anything
        subset.push_back(curr); // THen choose and search
        search(curr+1,n);
        subset.pop_back();
    }
    
}

int main(void)
{
    // Length of subset is n;
    int n;
    cin >> n;
    search(0,n);















    return 0;
}