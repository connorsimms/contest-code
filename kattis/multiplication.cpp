#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string x, y;
    while ( cin >> x >> y && !(x == "0" && y == "0"))
    {
        int r = y.size();
        int c = x.size();

        int xi = stoi(x);
        int yi = stoi(y);
        int zi = xi * yi;

        string z = to_string(zi);

        int rows = 5 + 4 * r;
        int cols = 5 + 4 * c;

        vector<vector<char>> out(rows, vector<char>(cols, ' '));

        out[0][0] = '+';
        out[0][cols - 1] = '+';
        out[rows - 1][0] = '+';
        out[rows - 1][cols - 1] = '+';

        for ( int i = 1 ; i < rows - 1; ++i) 
        {
            out[i][0] = '|';
            out[i][cols - 1] = '|';
        }

        for ( int i = 1 ; i < cols - 1; ++i) 
        {
            out[0][i] = '-';
            out[rows - 1][i] = '-';
        }

        for (int d = 0 ; d < x.size(); ++d) { out[1][4 * (d + 1)] = x[d]; }

        for (int d = 0 ; d < y.size(); ++d) { out[4 * (d + 1)][cols - 2] = y[d]; }

        for (int r = 2 ; r < rows; r += 4)
        {
            for (int c = 2 ; c < cols; c += 4)
            {
                out[r][c] = '+'; 
            }
        }

        for (int r = 2 ; r < rows - 2; r += 4)
        {
            for (int c = 3 ; c < cols - 2; c += 4)
            {
                out[r][c] = '-'; 
                out[r][c + 1] = '-'; 
                out[r][c + 2] = '-'; 
            }
        }

        for (int c = 2 ; c < cols - 2; c += 4)
        {
            for (int r = 3 ; r < rows - 2; r += 4)
            {
                out[r][c] = '|'; 
                out[r + 1][c] = '|'; 
                out[r + 2][c] = '|'; 
            }
        }

        for (int c = 5 ; c < cols - 2 ; c+=4)
        {
            for (int r = 3; r < rows - 2; r+=4)
            {
                out[r][c] = '/';
                out[r+1][c-1] = '/';
                out[r+2][c-2] = '/';
            }
        }

        for (int i = 0 ; i < x.size(); ++i)
        {
            for (int j = 0 ; j < y.size(); ++j)
            {
                int a = x[i] - '0';
                int b = y[j] - '0';
                int prod = a * b;
                string p = to_string(prod);
                if (p.size() == 1) { p = "0" + p; }

                out[(j + 1) * 4 - 1][(i + 1)* 4 - 1] = p[0];
                out[(j + 1) * 4 + 1][(i + 1)* 4 + 1] = p[1];
            }
        }

        for (int i = z.size() - 1, j = 0; i >= 0, j < x.size(); --i, ++j)
        {
            out[rows - 2][cols - 6 - 4 * j] = z[i];
            out[rows - 2][cols - 8 - 4 * j] = '/';
        }

        reverse(z.begin(), z.begin() + z.size() - x.size());

        for (int i = z.size() - x.size() - 1; i >= 0; --i)
        {
            out[rows -4 - 4 * i][1] = z[i];
            out[rows -2 - 4 * i][1] = '/';
        }

        if (z.size() == 1) { out[rows - 2][1] = ' '; }

        for (auto r: out)
        {
            for (auto c : r) { cout << c; }
            cout << '\n';
        }
    }
}
