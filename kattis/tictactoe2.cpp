#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    int N; cin >> N;
    for(int i = 0 ; i < N; ++i)
    {
        vector<vector<char>> grid(3, vector<char>(3));

        int no = 0, nx = 0;
        
        for(int i = 0 ; i < 3 ; ++i)
        {
            for(int j = 0 ; j < 3 ; ++j)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'X') { ++nx; }
                if (grid[i][j] == 'O') { ++no; }
            }
        }

        if(no > nx) { cout << "no\n"; continue; }
        if(abs(nx - no) > 1) { cout << "no\n"; continue; }

        int nxr = 0;
        int nor = 0;
        for(int i = 0 ; i < 3 ; ++i)
        {
            bool xRow = true;
            bool oRow = true;
            for(int j = 0 ; j < 3 ; ++j)
            {
                if (grid[i][j] == 'X' || grid[i][j] == '.') { oRow = false; }
                if (grid[i][j] == 'O' || grid[i][j] == '.') { xRow = false; }
            }
            if (xRow) { ++nxr; }
            if (oRow) { ++nor; }
        }
        if (nxr + nor > 1) { cout << "no\n"; continue; }

        int nxc = 0;
        int noc = 0;
        for(int i = 0 ; i < 3 ; ++i)
        {
            bool xCol = true;
            bool oCol = true;
            for(int j = 0 ; j < 3 ; ++j)
            {
                if (grid[j][i] == 'X' || grid[j][i] == '.') { oCol = false; }
                if (grid[j][i] == 'O' || grid[j][i] == '.') { xCol = false; }
            }
            if (xCol) { ++nxc; }
            if (oCol) { ++noc; }
        }
        if (nxc + noc > 1) { cout << "no\n"; continue; }

        int nxd = 0;
        int nod = 0;

        bool xDia = true;
        bool oDia = true;
        for(int i = 0 ; i < 3; ++i)
        {
            if (grid[i][i] == 'X') { oDia = false; } 
            if (grid[i][i] == 'O') { xDia = false; } 
            if (grid[i][i] == '.') { oDia = false; xDia = false; } 
        }
        if(xDia) { nxd++; }
        if(oDia) { nod++; }

        xDia = true;
        oDia = true;
        for(int i = 0 ; i < 3; ++i)
        {
            if (grid[i][2 - i] == 'X') { oDia = false; } 
            if (grid[i][2 - i] == 'O') { xDia = false; } 
            if (grid[i][2 - i] == '.') { oDia = false; xDia = false; } 
        }
        if(xDia) { nxd++; }
        if(oDia) { nod++; }

        if(nod > 0 || noc > 0 || nor > 0) { 
            if (nx > no) { cout << "no\n"; continue; }
        }

        if(nxd > 0 || nxc > 0 || nxr > 0) {
            if (nx == no) { cout << "no\n"; continue; }
        }

        cout << "yes\n";
    }
}
