#ifndef LCSSQO_H
#define LCSSQO_H

#include "PFSTT.h"

  using namespace std;

template<class Formalism>
class LCSSQO : public map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare> {
public:

LCSSQO();
LCSSQO( initializer_list< pair<STR<SQO<Formalism>>, PFSTT<Formalism>> > );
LCSSQO( LCSSQO<Formalism> const & );

double & operator [] ( STR<SQO<Formalism>> const & ) ;
LCSSQO<Formalism> & operator = ( PFSTT<Formalism> const & );

};

template<class Formalism> LCSSQO<Formalism> operator + ( LCSSQO<Formalism> const & , STR<SQO<Formalism>>  const & );
template<class Formalism> LCSSQO<Formalism> operator + ( STR<SQO<Formalism>>  const & , LCSSQO<Formalism> const & );
template<class Formalism> LCSSQO<Formalism> operator + ( LCSSQO<Formalism> const & , LCSSQO<Formalism> const & );

template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, double  const & );
template<class Formalism> LCSSQO<Formalism> operator * ( double  const & , LCSSQO<Formalism> const &);
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, PFSTT<Formalism>  const & );
template<class Formalism> LCSSQO<Formalism> operator * ( PFSTT<Formalism>  const & , LCSSQO<Formalism> const &);
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, STR<TwoTensorSQO<Formalism>>  const & );
template<class Formalism> LCSSQO<Formalism> operator * ( STR<TwoTensorSQO<Formalism>>  const & , LCSSQO<Formalism> const &);
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, STR<SQO<Formalism>> const & );
template<class Formalism> LCSSQO<Formalism> operator * ( STR<SQO<Formalism>> const &, LCSSQO<Formalism> const & );
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, LCSSQO<Formalism> const & );

template<class Formalism> ostream & operator << ( ostream &, LCSSQO<Formalism> const & );


#endif
