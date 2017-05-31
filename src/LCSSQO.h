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

template<class T1, class T2, class T3> LCSSQO<T1, T2> LCSSQOToLCSSQO( LCSSQO<T3, T2> const &, T1 const & );
template<class T1, class T2> LCSSQO<T1, T2> wickexpansion(STR<SQO<T1>> const & str, T2 const &, vector<int> const & positionslist = vector<int>() );
template<class T1, class T2> LCSSQO<T1, T2> generalizedWickExpansion(STR<SQO<T1>> const & , T2 const & );
template<class T1, class T2> ostream & operator << ( ostream &, LCSSQO<T1, T2> const & );
template<class T1, class T2> LCSSQO<T1, T2> nonzero( LCSSQO<T1, T2> const & );
template<class T1> PFSTT<T1> usesymmetry(PFSTT<T1> const &  );


class AntisymmetricTwoParticleOperatorExpectationValue {
  public:
  string p;
  string q;
  string r;
  string s;
  AntisymmetricTwoParticleOperatorExpectationValue( string const & p, string const & q, string const & r, string const & s) : p(p), q(q), r(r), s(s) {}
};

template<class T1> class NParticleAntisymmetricTwoParticleOperatorExpectationValue : public vector< pair< AntisymmetricTwoParticleOperatorExpectationValue, STR<TwoTensorSQO<T1>> > > {};
ostream & operator << ( ostream & o, AntisymmetricTwoParticleOperatorExpectationValue const & ev) {
  o <<  "\\langle " << ev.p << ev.q << " |\\hat{g}| " << ev.r << ev.s << " \\rangle_{A}" ;
  return o;
}

template<class T1> ostream & operator << ( ostream & o, NParticleAntisymmetricTwoParticleOperatorExpectationValue<T1> const & ev) {
  o << ev[0].second << ev[0].first;
  for ( int i=1 ; i< ev.size(); i++) {
    if (ev[i].second._prefactor > 0) {o << "+";}
    o << ev[i].second << ev[i].first
    ;
  }
  return o;
}
template<class T1> NParticleAntisymmetricTwoParticleOperatorExpectationValue<T1>  antisymmetricExpectationValue(PFSTT<T1> const &);

#include "LCSSQO.ch"

#endif
