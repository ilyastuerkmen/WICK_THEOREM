#ifndef PFSTT_H
#define PFSTT_H

#include "STR.h"
#include <map>
#include <initializer_list>

  using namespace std;

template<class Formalism>
class PFSTT : public map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> > {
public:

PFSTT();
PFSTT( initializer_list<STR<TwoTensorSQO<Formalism>>> , double const & = 0);
PFSTT( PFSTT<Formalism> const & );

double realnumber;
double & operator [] ( STR<TwoTensorSQO<Formalism>> const & ) ;
PFSTT<Formalism> & operator = ( PFSTT<Formalism> const & );
PFSTT<Formalism> cleanUpZero();

};

template<class Formalism> PFSTT<Formalism> operator + ( PFSTT<Formalism> const & , double const & );
template<class Formalism> PFSTT<Formalism> operator + ( double const & , PFSTT<Formalism> const & );
template<class Formalism> PFSTT<Formalism> operator + ( PFSTT<Formalism> const & , STR<TwoTensorSQO<Formalism>> const & );
template<class Formalism> PFSTT<Formalism> operator + ( STR<TwoTensorSQO<Formalism>> const & , PFSTT<Formalism> const & );
template<class Formalism> PFSTT<Formalism> operator + ( PFSTT<Formalism> const & , PFSTT<Formalism> const & );

template<class Formalism> PFSTT<Formalism> operator * ( PFSTT<Formalism> const &, double const & );
template<class Formalism> PFSTT<Formalism> operator * ( double const & , PFSTT<Formalism> const &);
template<class Formalism> PFSTT<Formalism> operator * ( PFSTT<Formalism> const &, STR<TwoTensorSQO<Formalism>> const & );
template<class Formalism> PFSTT<Formalism> operator * ( STR<TwoTensorSQO<Formalism>> const &, PFSTT<Formalism> const & );
template<class Formalism> PFSTT<Formalism> operator * ( PFSTT<Formalism> const &, PFSTT<Formalism> const & );

template<class Formalism> ostream & operator << ( ostream &, PFSTT<Formalism> const & );

#include "PFSTT.ch"

#endif
