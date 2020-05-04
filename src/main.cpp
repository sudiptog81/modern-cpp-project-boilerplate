#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/array.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <gsl/gsl_linalg.h>

#include "classes/Class.h"

typedef long long ll;
typedef boost::multiprecision::int128_t int128;

// Returns high-precision product
int128 product(long long a, long long b)
{
  return static_cast<int128>(a) * b;
}

int main()
{
  // Testing Project Includes
  std::cout << "Version: " << (new Class())->getVersion()
            << std::endl;

  // Testing Boost.Array
  boost::array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::for_each(
      arr.begin(), arr.end(),
      std::cout << (boost::lambda::_1 * 3) << " ");
  std::cout
      << std::endl;

  // Testing Boost.Multiprecision
  ll first = 98745636214564698ll;
  ll second = 7459874565236544789ll;
  std::cout << "Product " << first << " * " << second << " = "
            << product(first, second)
            << std::endl;

  // Testing GSL Linear Algebra Routines
  int signum;
  double A_data[] = {0.57092943, 0.00313503, 0.88069151, 0.39626474,
                     0.33336008, 0.01876333, 0.12228647, 0.40085702,
                     0.55534451, 0.54090141, 0.85848041, 0.62154911,
                     0.64111484, 0.8892682, 0.58922332, 0.32858322};
  double b_data[] = {1.5426693, 0.74961678, 2.21431998, 2.14989419};
  gsl_vector *x = gsl_vector_alloc(4);
  gsl_permutation *perm = gsl_permutation_alloc(4);
  gsl_matrix_view A = gsl_matrix_view_array(A_data, 4, 4);
  gsl_vector_view b = gsl_vector_view_array(b_data, 4);
  gsl_linalg_LU_decomp(&A.matrix, perm, &signum);
  gsl_linalg_LU_solve(&A.matrix, perm, &b.vector, x);
  std::cout << "x = \n";
  gsl_vector_fprintf(stdout, x, "%lf");
  gsl_vector_free(x);
  gsl_permutation_free(perm);

  return 0;
}