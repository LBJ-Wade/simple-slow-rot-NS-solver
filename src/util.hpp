/*
 * util.h
 * Author: Leo C. Stein (leo.stein@gmail.com)
 * Date: 2014 Feb
 *
 * Declarations of utility (helper) functions useful for running models
 *
 */

#pragma once

#include "BackgroundModel.hpp"

#include <gsl/gsl_spline.h>

#include <functional>
#include <vector>
#include <algorithm>
#include <queue>

// Convenience function: run the BG
void runBG( double pc, double phic,
            BackgroundModel &model0 );

// Determine the number of monotonically increasing entries in an
// array, starting at the beginning.
template< class T >
int numMonotonicallyIncreasing( const std::vector<T> & vals )
{
  auto firstGE =
    std::adjacent_find(vals.begin(), vals.end(), std::greater_equal<T>());
  return std::distance(vals.begin(), firstGE);
};

// This info struct is used for queueing the extra models
struct extra_info
{
  double pc;
  double phic;
  std::string prop_name;
  double prop_value;
};

// Add some extra runs into a queue
void enqueue_extra( std::queue< extra_info > & extra_q,
                    const std::vector<double> & extra_arg,
                    const std::vector<double> & extra_arg_lookup,
                    double arg_min, double arg_max,
                    gsl_spline * pc_spline,
                    gsl_spline * phic_spline,
                    gsl_interp_accel *acc,
                    const std::string &label );
