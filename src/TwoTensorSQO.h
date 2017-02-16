#ifndef TwoTensorSQO_H
#define TwoTensorSQO_H

#include "SQOEnumClasses.h"
#include <iostream>
#include <algorithm>

  using namespace std;

template<class Formalism> class TwoTensorSQO {
public:
  TwoTensorSQO( pair<string, SQO_Idx_Type> const &, pair<string, SQO_Idx_Type> const & );
  TwoTensorSQO( TwoTensorSQO<Formalism> const & );
  pair<string, SQO_Idx_Type> idx1;
  pair<string, SQO_Idx_Type> idx2;
};

template<class Formalism> bool operator == ( TwoTensorSQO<Formalism> const &, TwoTensorSQO<Formalism> const & );

template<class Formalism> ostream & operator << ( ostream &, TwoTensorSQO<Formalism> const & );

#endif
