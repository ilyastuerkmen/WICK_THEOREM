#include "PFSTR.h"

template<class STR>
PFSTR<STR>::PFSTR() : map<STR, double>() {}

template<class STR>
PFSTR<STR>::PFSTR( initializer_list<STR> il) {
  (*this)();
  for ( typename initializer_list<STR>::const_iterator it=il.begin(); it!=il.end(); it++ ) {
    double pre = (*it)._prefactor;
    (*it)._prefactor = 1; 
    (*this).insert( make_pair((*it), pre) );
  }
}

template<class STR>
PFSTR<STR>::PFSTR( PFSTR<STR> const & pfstr) : map<STR, double>( pfstr ) {}

