#include<bits/stdc++.h>
using namespace std;

int curr = 0;
int c = 0;

void search(int pos_x,int pos_y,int n,int grid[7][7])
{
    // if(curr == n*n) c++;
    if(grid[n-1][n-1] == 1) cout << "solution found";
    else
    {
        cout << pos_x << " " << pos_y << endl;
        if(grid[pos_x+1][pos_y]==0 && pos_x+1 < n)
        {
            grid[pos_x+1][pos_y]= 1;
            curr++;
            search(pos_x+1,pos_y,n,grid);

            grid[pos_x+1][pos_y]= 0;
            curr--;
        }


        if(grid[pos_x][pos_y+1]==0 && pos_y+1 < n)
        {
            grid[pos_x][pos_y+1]= 1;
            curr++;
            search(pos_x,pos_y+1,n,grid);

            grid[pos_x][pos_y+1]= 0;
            curr--;
        }

    }
    
}

int main(void)
{
    int n = 7;
    // cin >> n;
    int grid[7][7] = {0};
    search(0,0,n,grid);
    // cout << c << endl;









    return 0;
}