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
ostream & operator << ( ostream &, TwoTensorSQO<Elementary> const & );
ostream & operator << ( ostream &, TwoTensorSQO<ParticleHole> const & );

#endif
