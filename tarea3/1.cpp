# include <iostream>
# include <cstdlib>
# include <cmath>
# include <functional>

using fptr = double(double);

double f(double x);
double deriv2a(fptr fun, double x, double d);
double deriv2b(fptr fun, double x, double h);
double deriv2_exact(double b);


int main(int argc, char **argv)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    const double x = std::atof(argv[1]);
    double h = 0;
    double delta1, delta2; // percentual diffs
    for (int ii = 1; ii <= 16; ++ii)
    {
        double h = M_PI * std::pow(10.0, -ii);
        delta1 = std::fabs(1.0 - deriv2a(f, x, h) / deriv2_exact(x));
        delta2 = std::fabs(1.0 - deriv2b(f, x, h) / deriv2_exact(x));
        std::cout << h << " \t" << delta1 << "\t" << delta2 << "\n";
    }

    return 0;
}

double f(double a)
{
    return a * std::cos(a);
}

double deriv2a(fptr fun, double x, double h){
    return ((f(x+h)-f(x))-(f(x)-f(x-h))/std::pow(h,2));
}
double deriv2b(fptr fun, double x, double h){
    return ((f(x+h))+(f(x-h))-(2*f(x)))/std::pow(h,2);
}
double deriv2_exact(double b){
    return (-2 * std::sin(b)) - (b * std::cos(b));
}

