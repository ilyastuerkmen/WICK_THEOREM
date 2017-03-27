#ifndef LCSSQO_H
#define LCSSQO_H

#include "PFSTT.h"
#include <type_traits>

  using namespace std;

template<class T1, class T2>
class LCSSQO : public map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>> {
public:

LCSSQO();
LCSSQO( initializer_list< pair<STR<SQO<T1>>, PFSTT<T2>> > );
LCSSQO( LCSSQO<T1,T2> const & );

PFSTT<T2> fullcontraction;

PFSTT<T2> & operator [] ( STR<SQO<T1>> const & ) ;
LCSSQO<T1,T2> & operator = ( LCSSQO <T1,T2> const & );
LCSSQO<T1,T2> cleanUpZero();

};

template<class T1,class T2> LCSSQO<T1,T2> operator + ( LCSSQO<T1,T2> const & , PFSTT<T2>  const & );
template<class T1,class T2> LCSSQO<T1,T2> operator + ( PFSTT<T2>  const &, LCSSQO<T1,T2> const & );
template<class T1,class T2> LCSSQO<T1,T2> operator + ( LCSSQO<T1,T2> const & , STR<SQO<T1>>  const & );
template<class T1,class T2> LCSSQO<T1,T2> operator + ( STR<SQO<T1>>  const & , LCSSQO<T1,T2> const & );
template<class T1,class T2> LCSSQO<T1,T2> operator + ( LCSSQO<T1,T2> const & , LCSSQO<T1,T2> const & );

template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const &, double  const & );
template<class T1, class T2> LCSSQO<T1, T2> operator * ( double  const & , LCSSQO<T1, T2> const &);
template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const &, PFSTT<T2>  const & );
template<class T1, class T2> LCSSQO<T1, T2> operator * ( PFSTT<T2>  const & , LCSSQO<T1, T2> const &);
template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const &, STR<TwoTensorSQO<T2>>  const & );
template<class T1, class T2> LCSSQO<T1, T2> operator * ( STR<TwoTensorSQO<T2>>  const & , LCSSQO<T1, T2> const &);
template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const &, STR<SQO<T1>> const & );
template<class T1, class T2> LCSSQO<T1, T2> operator * ( STR<SQO<T1>> const &, LCSSQO<T1, T2> const & );
template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const &, LCSSQO<T1, T2> const & );

template<class T1, class T2, class T3> LCSSQO<T1, T2> EquateIfPossible( LCSSQO<T3, T2> const &, T1 const & );
template<class T1, class T2> LCSSQO<T1, T2> wickexpansion(STR<SQO<T1>> const & str, T2 const &, vector<int> const & positionslist = vector<int>() );
template<class T1, class T2> LCSSQO<T1, T2> generalizedWickExpansion(STR<SQO<T1>> const & , T2 const & );
template<class T1, class T2> ostream & operator << ( ostream &, LCSSQO<T1, T2> const & );
template<class T1> LCSSQO<T1, ParticleHole> nonzero( LCSSQO<T1, ParticleHole> const & );

#include "LCSSQO.ch"

#endif
