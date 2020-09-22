#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <cstdlib>

using fptr  = double(double);
using fptr2 = double(fptr, double, double, int);

double f(double x);
double trapezoid(fptr fun, double a, double b, int n);
double richardson(fptr2 alg, fptr func, double a, double b, double eps);

int main(int argc, char **argv){
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  const double eps = std::atof(argv[1]);
  std::cout << richardson(trapezoid, f, 0, 1, eps) << "\n";

  return 0;
}

double f(double x){
  return (std::pow(x, 0.1))*(1.2-x)*(1-(std::exp(20*(x-1))))
}

