#ifndef EIGEN_CHECKS_GTEST_H_
#define EIGEN_CHECKS_GTEST_H_
#include <limits>
#include <eigen-checks/internal/gtest-equal.h>
#include <eigen-checks/internal/traits.h>

#define EIGEN_MATRIX_EQUAL(MatrixA, MatrixB) \
  eigen_checks::internal::MatricesNear(MatrixA, #MatrixA, MatrixB, #MatrixB, \
      static_cast<typename eigen_checks::internal::RemoveCR<\
      decltype(MatrixA)>::type::Scalar>(0.0))

#define EIGEN_MATRIX_EQUAL_DOUBLE(MatrixA, MatrixB) \
  eigen_checks::internal::MatricesNear(MatrixA, #MatrixA, MatrixB, #MatrixB, \
      std::numeric_limits<typename eigen_checks::internal::RemoveCR<\
      decltype(MatrixA)>::type::Scalar>::min())

#define EIGEN_MATRIX_NEAR(MatrixA, MatrixB, Precision) \
  eigen_checks::internal::MatricesNear(MatrixA, #MatrixA, MatrixB, #MatrixB, \
                                       Precision)

#endif  // EIGEN_CHECKS_GTEST_H_
