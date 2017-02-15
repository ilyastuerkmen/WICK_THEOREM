#include "PF.h"

template<class STR>
PF<STR>::PF() : map<STR, double>() {}

template<class STR>
PF<STR>::PF( initializer_list<STR> il) {
  (*this)();
  for ( typename initializer_list<STR>::const_iterator it=il.begin(); it!=il.end(); it++ ) {
    double pre = (*it)._prefactor;
    (*it)._prefactor = 1;
    (*this).insert( make_pair((*it), pre) );
  }
}

template<class STR>
PF<STR>::PF( PF<STR> const & PF) : map<STR, double>( PF ) {}

template class STR<TwoTensorSQO<Elementary>>;
template class STR<TwoTensorSQO<ParticleHole>>;
