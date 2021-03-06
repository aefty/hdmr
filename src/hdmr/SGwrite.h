#ifndef SGwrite_h_is_included
#define SGwrite_h_is_included

#include "SparseGrid.h"

class SGwrite: public AdaptiveSparseGrid {
 public:
  // Properties
  void (*problem)(double*, int, double*);
  int verbose;

  vector<double> maskedX;
  vector<double> xBar;
  vector<int> activeDim;

  // Methods
  SGwrite(void (*problem_)(double*, int, double*), int dim_ , int dof_ , int Lmax_, double epsilon_, int gridType_ , int verbose_ = 0);
  ~SGwrite();

  void build(vector<int>& activeDim_ );
  void build();
  int write(string surplusFileName);

  void integrateDomain(double* fvalue);

  void resetMPI(MPI_Comm mpiCOMM_);
  void setAnchor(vector<double>& xBar);

  void clear();

 private:
  // Methods
  virtual void EvaluateFunctionAtThisPoint( AdaptiveARRAY<double>* x);
};
#endif