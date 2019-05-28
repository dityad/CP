// Codeforces book pg 51 

#include<bits/stdc++.h>
using namespace std;
// count the number of solutions in a N Queens problem.
int sol = 0;

void search(int y, int n, int col[],int diag1[],int diag2[])
{
    if(y == n)
    {
       sol++;
    }
    else
    {
        for(int x =0;x<n;x++)
        {
            if(col[x]|| diag1[y+x] || diag2[x-y+n-1]) continue;
            col[x] = 1;
            diag1[y+x] = 1;
            diag2[x-y+n-1] = 1;
            search(y+1,n,col,diag1,diag2);
            col[x] = 0;
            diag1[y+x] = 0;
            diag2[x-y+n-1] = 0;

        }
        
    }
    

}

int main(void)
{
    int n;
    cin >> n;
    int col[2*n] = {0},diag1[2*n] =  {0},diag2[2*n] ={0};
    search(0,n,col,diag1,diag2);
    cout << sol << endl;

    return 0;
}