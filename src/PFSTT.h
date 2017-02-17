#ifndef PFSTT_H
#define PFSTT_H

#include "STR.h"
#include <map>
#include <initializer_list>

  using namespace std;

template<class Formalism>
class PFSTT : map< STR<TwoTensorSQO<Formalism>> , double > {
public:

PFSTT();
PFSTT( initializer_list<STR<TwoTensorSQO<Formalism>>> , double const & = 0);
PFSTT( PFSTT<Formalism> const & );

double realnumber;

PFSTT<Formalism> & operator = ( PFSTT<Formalism> const & );

};

template<class Formalism> PFSTT<Formalism> operator + ( PFSTT<Formalism> const & , double const & );
template<class Formalism> PFSTT<Formalism> operator + ( double const & , PFSTT<Formalism> const & );

template<class Formalism> PFSTT<Formalism> operator + ( PFSTT<Formalism> const & , STR<TwoTensorSQO<Formalism>> const & );
template<class Formalism> PFSTT<Formalism> operator + ( STR<TwoTensorSQO<Formalism>> const & , PFSTT<Formalism> const & );

template<class Formalism> PFSTT<Formalism> operator + ( PFSTT<Formalism> const & , PFSTT<Formalism> const & );
/*
template<class Formalism> PFSTT<Formalism> operator * ( double const & );
template<class Formalism> PFSTT<Formalism> operator * ( STR<TwoTensorSQO<Formalism>> const & )
template<class Formalism> PFSTT<Formalism> operator * ( STR<TwoTensorSQO<Formalism>> const & )
*/

template<class Formalism> ostream & operator << ( ostream &, PFSTT<Formalism> const & ); 

#endif
