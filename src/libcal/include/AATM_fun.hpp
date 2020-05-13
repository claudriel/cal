/*
   Copyright (c) 2015-2018 by the parties listed in the AUTHORS file.
   All rights reserved.  Use of this source code is governed by
   a BSD-style license that can be found in the LICENSE file.
 */

#ifndef CAL_AATM_UTILS_HPP
#define CAL_AATM_UTILS_HPP

#include <cmath>
#include <cstddef>

namespace cal {
double atm_get_absorption_coefficient(double altitude, double temperature,
                                      double pressure, double pwv, double freq);

int atm_get_absorption_coefficient_vec(double altitude, double temperature,
                                       double pressure, double pwv,
                                       double freqmin, double freqmax, size_t nfreq,
                                       double * absorption);

double atm_get_atmospheric_loading(double altitude, double temperature,
                                   double pressure, double pwv, double freq);

int atm_get_atmospheric_loading_vec(double altitude, double temperature,
                                    double pressure, double pwv,
                                    double freqmin, double freqmax, size_t nfreq,
                                    double * loading);
}

#endif // ifndef CAL_AATM_UTILS_HPP
