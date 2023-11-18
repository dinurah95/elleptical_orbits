#include <cassert>

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

#include <cmath>

using std::fabs;
using std::sin;
using std::cos;
using std::tan;
using std::atan2;

const double R = 6378.1; // km (radius of the earth)
const double r2 = R + 3000.0; // km (apogee)
const double r1 = R + 500.0; // km (perogee)
const double a = 0.5*(r1 + r2); // semi-major axis
const double e = (r2-r1)/(2.0*a); // eccentricity
const double mu = 398600.4418; // km^3/s^2
const double P = 2*M_PI*sqrt(a*a*a/mu)/3600.; // period in hrs
const double dt = P/5075;

double eccentric_anomaly(double M, double E0)
{
   double E = E0;
   double f = E - e*sin(E) - M;
   double fp = 1.0 - e*cos(E);
   int iter = 0;
   const int max_iter = 100;
   const double tol = 1e-12;
   while (fabs(f) > tol && iter < max_iter) {
        E -= f/fp;
        f = E - e*sin(E) - M;
        fp = 1.0 - e*cos(E);
        ++iter; 
}
   if (iter == max_iter) {
     cerr << "WARNING: maximum iterations reached in eccentric_anomaly()" << endl;
   }
   
   return E;
}

int main()
{
   cerr << "Eccentricity e = " << e << endl;
   cerr << "Period P = " << P << endl;
   double E0 = 0.0;
   for (int n = 1; n < 50000; ++n)
   {
      const double t = n*dt;
      const double M = 2.0*M_PI*t/P;
      const double E =  eccentric_anomaly(M, E0);
      const double theta = 2.0 * atan2((sqrt((1.0 + e) / (1.0 - e)) * tan(E / 2.0)), 1.0); 
      const double r = a*(1.0 - e*cos(E)); 
      cout << t << "\t" << r << "\t" << theta << endl;
      E0 = E;
   }
   return 0;
}
