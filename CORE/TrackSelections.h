#ifndef TRACKSELECTIONS_H
#define TRACKSELECTIONS_H

#include <utility>

std::pair<double , double> trks_d0_pv      (int itrk, int ipv);
std::pair<double , double> trks_dz_pv      (int itrk, int ipv);
std::pair<double , double> gsftrks_dz_pv   (int itrk, int ipv);
std::pair<double , double> gsftrks_d0_pv   (int itrk, int ipv);

#endif
