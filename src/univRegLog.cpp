/******************************************************************************/

#include <RcppArmadillo.h>
#include <bigstatsr/BMCodeAcc.h>
#include <bigstatsr/univLogReg.hpp>

using namespace Rcpp;

/******************************************************************************/

#define CALL_IRLS(ACC) {                                                       \
  return bigstatsr::IRLS(ACC, covar, y, z0, w0, tol, maxiter);                 \
}

// Dispatch function for IRLS
// [[Rcpp::export]]
List IRLS(Environment FBM,
          arma::mat& covar,
          const arma::vec& y,
          const arma::vec& z0,
          const arma::vec& w0,
          const IntegerVector& rowInd,
          const IntegerVector& colInd,
          double tol,
          std::size_t maxiter) {

  DISPATCH_SUBMATACC(CALL_IRLS)
}

/******************************************************************************/
