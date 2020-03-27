#include <iostream>

using namespace std;

int main() {
    double x1, x2, y1, y2, q, m;
    cin >> x1 >> y1 >> x2 >> y2;

    m = (y2 - y1) / (x2 - x1);
    q = y1 - (m * x1);

    cout << m << endl;
    cout << q << endl;

    return 0;
}
