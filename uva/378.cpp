#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << "INTERSECTING LINES OUTPUT\n";

    cout << fixed << setprecision(2);

    for (int i{}; i < n; ++i) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if (x1 == x2 && x3 == x4 && x1 != x3) {
            cout << "NONE\n";
            continue;
        }

        if (x1 == x2 && x3 == x4 && x1 == x3) {
            cout << "LINE\n";
            continue;
        }

        if (x1 == x2) {
            double m = double(y4 - y3) / (x4 - x3);
            double b = y3 - m * x3;
            double x = x1;
            double y = m * x + b;
            cout << "POINT " << x << ' ' << y << '\n';
            continue;
        }

        if (x3 == x4) {
            double m = double(y2 - y1) / (x2 - x1);
            double b = y1 - m * x1;
            double x = x3;
            double y = m * x + b;
            cout << "POINT " << x << ' ' << y << '\n';
            continue;
        }

        bool sslope = ((y2 - y1) * (x4 - x3)) == ((y4 - y3) * (x2 - x1));
        bool sint = ((x4 - x3) * (y1 * (x2 - x1) - (y2 - y1) * x1)) == ((x2 - x1) * (y3 * (x4 - x3) - (y4 - y3) * x3));

        if (sslope && sint) {
            cout << "LINE\n";
        } else if (sslope) {
            cout << "NONE\n";
        } else if (sint) {
            double b = y1 - double(y2 - y1) / (x2 - x1) * x1;

            cout << "POINT 0.00 " << b << '\n';
        } else {
            double m1 = double(y2 - y1) / (x2 - x1);
            double b1 = y1 - m1 * x1;
            double m2 = double(y4 - y3) / (x4 - x3);
            double b2 = y3 - m2 * x3;
            double x = (b2 - b1) / (m1 - m2);
            double y = m1 * x + b1;

            cout << "POINT " << x << ' ' << y << '\n';
        }
    }

    cout << "END OF OUTPUT\n";
}
