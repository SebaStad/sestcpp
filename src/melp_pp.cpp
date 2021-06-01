// [[Rcpp::depends(RcppArmadillo)]]

#include <RcppArmadillo.h>
#include <RcppArmadilloExtensions/sample.h>
#include <Rcpp.h>
using namespace Rcpp;
using namespace arma;
// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
  //
  //   http://www.rcpp.org/
  //   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
  //
  
  //' emulates reshape2::melt
//'
//' @param myarray 2D-Array for melt to use!
//' @return melt_matrix melted matrix!
//' @export
  // [[Rcpp::export]]
arma::mat melt_pp(NumericVector myArray) {
  // DataFrame melt_pp(NumericVector myArray) {
    NumericVector vecArray(myArray);
    IntegerVector arrayDims = vecArray.attr("dim");
    
    
    int col_x = arrayDims[0];
    int col_y = arrayDims[1];
    // Rprintf("%i",col_x);
    // Rprintf("%i",col_y);
    
    int cntr = 0;
    // arma::mat matArray(myArray(), col_x, col_y, false);
    
    int row_melt = col_x * col_y;
    
    arma::mat melt_matrix(row_melt,3);
    //melt_matrix.zeros();
    for (int i = 0; i < col_x; i++) {
      for (int j = 0; j < col_y; j++) {
        
        melt_matrix(cntr,0) = i+1;
        melt_matrix(cntr,1) = j+1;
        melt_matrix(cntr,2) = vecArray(i,j);
        
        cntr = cntr + 1;
      }
    }
    return melt_matrix;
    
    //return DataFrame::create(Named("Var1") = melt_matrix.col(0),
                               //                           Named("Var1") = melt_matrix.col(0),
                               //                           Named("Var1") = melt_matrix.col(0)()
  }
  
  
  //' emulates reshape2::melt
//'
//' @param myarray 2D-Array for melt to use!
//' @return dataframe melted matrix!
//' @export
    // [[Rcpp::export]]
  DataFrame melt_pp2(NumericVector myArray) {
    NumericVector vecArray(myArray);
    IntegerVector arrayDims = vecArray.attr("dim");
    
    
    int col_x = arrayDims[0];
    int col_y = arrayDims[1];
    // Rprintf("%i",col_x);
    // Rprintf("%i",col_y);
    
    int cntr = 0;
    // arma::mat matArray(myArray(), col_x, col_y, false);
    
    int row_melt = col_x * col_y;
    
    arma::mat melt_matrix(row_melt,3);
    //melt_matrix.zeros();
    for (int i = 0; i < col_x; i++) {
      for (int j = 0; j < col_y; j++) {
        
        melt_matrix(cntr,0) = i+1;
        melt_matrix(cntr,1) = j+1;
        melt_matrix(cntr,2) = vecArray(i,j);
        
        cntr = cntr + 1;
      }
    }
    
    return DataFrame::create(Named("Var1") = melt_matrix.col(0),
                             Named("Var2") = melt_matrix.col(1),
                             Named("value") = melt_matrix.col(2));
  }
  
  
  // You can include R code blocks in C++ files processed with sourceCpp
  // (useful for testing and development). The R code will be automatically
  // run after the compilation.
  //
    
    /*** R
  a <- matrix(runif(10), nrow = 2, ncol=5)
  
  melt_pp(a)
  melt_pp2(a)
  */
    