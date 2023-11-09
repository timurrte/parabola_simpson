#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 3) - 3 * pow(x, 2) + 6 * x - 2;
}


double parabol(double a, double b, int n, double(f)(double)) {
    const double width = (b - a) / n;

    double x = 0;
    for (int step = 0; step < n; step++) {
        const double x1 = a + step * width;
        const double x2 = a + (step + 1) * width;

        x += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f(0.5 * (x1 + x2)) + f(x2));
    }

    return x;
}

int main() {
    double a, b, eps;
    double s1, s;
    int n = 1;

    a = 0;
    b = 3;
    eps = 0.0001;

    cout << "Integral" << parabol(a, b, n, f) << endl;
}
