#include <CALAtmSim.hpp>
#include <sys_utils.hpp>
#include <sys_env.hpp>
#include <math_rng.hpp>
// #inluce <qualcosa per PRNG>

#include <sstream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <random>    // Ha un sacco di generatori
#include <functional>
#include <cmath>
#include <algorithm> // per fare il std::sort

double cal::atm_sim::kolmogorov(double r)
{
    // Return autocovariance of a Kolmogorov process at separation r

    if (r == 0) return kolmo_y[0];

    if (r == rmax_kolmo) return kolmo_y[nr - 1];

    if ((r < rmin_kolmo) || (r > rmax_kolmo)) {
        std::ostringstream o;
        o.precision(16);
        o << "Kolmogorov value requested at " << r
          << ", outside gridded range [" << rmin_kolmo << ", " << rmax_kolmo << "].";
        throw std::runtime_error(o.str().c_str());
    }

    // Simple linear interpolation for now.  Use a bisection method to find the rigth elements.

    long low = 0, high = nr - 1;
    long ir;

    while (true) {
        ir = low + 0.5 * (high - low);
        if (kolmo_x[ir] <= r and r <= kolmo_x[ir + 1]) break;
        if (r < kolmo_x[ir]) high = ir;
        else low = ir;
    }

    double rlow = kolmo_x[ir];
    double rhigh = kolmo_x[ir + 1];
    double rdist = (r - rlow) / (rhigh - rlow);
    double vlow = kolmo_y[ir];
    double vhigh = kolmo_y[ir + 1];

    double val = (1 - rdist) * vlow + rdist * vhigh;

    return val;
}