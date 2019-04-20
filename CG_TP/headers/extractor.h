#ifndef CG_TP_EXTRACTOR_H
#define CG_TP_EXTRACTOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <cfloat>
#include "parser.h"

using namespace std;

typedef tuple<double, double, double> coords;

void extractor(vector<First*>& files, vector<coords>& triangles);

#endif
