#include <iostream>

using namespace std;

int main()
{
    constexpr double safeSpeed = 10.0;
    constexpr double G = 9.81;
    // rope strength    k
    // rope length      l
    // bridge height    h
    // body weight      m
    double k, l, h, m;
    while (cin >> k >> l >> h >> m && !(k == 0 && l == 0 && h == 0 && m == 0))
    {
        double energy = m * G * h;

        if (energy <= m * safeSpeed * safeSpeed / 2) 
        {
            cout << "James Bond survives.\n";
            continue;
        }

        if (l >= h )
        {
            cout << "Killed by the impact.\n";
            continue;
        }

        double mExtend = h - l;
        double bottomEnergy = energy - k * mExtend * mExtend / 2;

        if (energy <= k * mExtend * mExtend / 2) {
            cout << "Stuck in the air.\n";
            continue;
        }

        if (bottomEnergy <= m * safeSpeed * safeSpeed / 2) 
        {
            cout << "James Bond survives.\n";
            continue;
        } else {
            cout << "Killed by the impact.\n";
            continue;
        }

    }
}
