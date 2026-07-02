#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int n = 6 - max(a, b) + 1;
  int d = 6;

  if (n % 2 == 0 && d % 2 == 0) {
    n /= 2;
    d /= 2;
  }

  if (n % 3 == 0 && d % 3 == 0) {
    n /= 3;
    d /= 3;
  }

  if (n == 0) {
    d = 1;
  }

  cout << n << '/' << d << '\n';
}
