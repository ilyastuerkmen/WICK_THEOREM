#include "LCSSQO.h"

template<class Formalism> LCSSQO<Formalism>::LCSSQO() : map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare>() {}
template<class Formalism> LCSSQO<Formalism>::LCSSQO(initializer_list< pair<STR<SQO<Formalism>>, PFSTT<Formalism>> > il)
  : map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare>() {
    for (typename initializer_list<pair<STR<SQO<Formalism>>, PFSTT<Formalism>>>::const_iterator it=il.begin(); it!=il.end(); it++ ) {
      (*this).push_back(*it);
    }
  }
template<class Formalism> LCSSQO<Formalism>::LCSSQO(LCSSQO<Formalism> const & lc)
  : map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare>() {
    for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
      (*this).push_back(*it);
    }
}
template<class Formalism> double & LCSSQO<Formalism>::operator[] (STR<SQO<Formalism>> const & ){}
template<class Formalism> LCSSQO<Formalism> & LCSSQO<Formalism>::operator= ( PFSTT<Formalism> const & ){}
template<class Formalism> LCSSQO<Formalism> operator + ( LCSSQO<Formalism> const & , STR<SQO<Formalism>>  const & ){}
template<class Formalism> LCSSQO<Formalism> operator + ( STR<SQO<Formalism>>  const & , LCSSQO<Formalism> const & ){}
template<class Formalism> LCSSQO<Formalism> operator + ( LCSSQO<Formalism> const & , LCSSQO<Formalism> const & ){}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, double  const & ){}
template<class Formalism> LCSSQO<Formalism> operator * ( double  const & , LCSSQO<Formalism> const &){}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, PFSTT<Formalism>  const & ){}
template<class Formalism> LCSSQO<Formalism> operator * ( PFSTT<Formalism>  const & , LCSSQO<Formalism> const &){}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, STR<TwoTensorSQO<Formalism>>  const & ){}
template<class Formalism> LCSSQO<Formalism> operator * ( STR<TwoTensorSQO<Formalism>>  const & , LCSSQO<Formalism> const &){}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, STR<SQO<Formalism>> const & ){}
template<class Formalism> LCSSQO<Formalism> operator * ( STR<SQO<Formalism>> const &, LCSSQO<Formalism> const & ){}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const &, LCSSQO<Formalism> const & ){}
template<class Formalism> ostream & operator << ( ostream &, LCSSQO<Formalism> const & ){}







template LCSSQO<Elementary>::LCSSQO();
template LCSSQO<Elementary>::LCSSQO(initializer_list< pair<STR<SQO<Elementary>>, PFSTT<Elementary>> >);
template LCSSQO<Elementary>::LCSSQO(LCSSQO<Elementary> const & );
template double & LCSSQO<Elementary>::operator[] (STR<SQO<Elementary>> const & );
template LCSSQO<Elementary> & LCSSQO<Elementary>::operator= ( PFSTT<Elementary> const & );
template LCSSQO<Elementary> operator + ( LCSSQO<Elementary> const & , STR<SQO<Elementary>>  const & );
template LCSSQO<Elementary> operator + ( STR<SQO<Elementary>>  const & , LCSSQO<Elementary> const & );
template LCSSQO<Elementary> operator + ( LCSSQO<Elementary> const & , LCSSQO<Elementary> const & );
template LCSSQO<Elementary> operator * ( LCSSQO<Elementary> const &, double  const & );
template LCSSQO<Elementary> operator * ( double  const & , LCSSQO<Elementary> const &);
template LCSSQO<Elementary> operator * ( LCSSQO<Elementary> const &, PFSTT<Elementary>  const & );
template LCSSQO<Elementary> operator * ( PFSTT<Elementary>  const & , LCSSQO<Elementary> const &);
template LCSSQO<Elementary> operator * ( LCSSQO<Elementary> const &, STR<TwoTensorSQO<Elementary>>  const & );
template LCSSQO<Elementary> operator * ( STR<TwoTensorSQO<Elementary>>  const & , LCSSQO<Elementary> const &);
template LCSSQO<Elementary> operator * ( LCSSQO<Elementary> const &, STR<SQO<Elementary>> const & );
template LCSSQO<Elementary> operator * ( STR<SQO<Elementary>> const &, LCSSQO<Elementary> const & );
template LCSSQO<Elementary> operator * ( LCSSQO<Elementary> const &, LCSSQO<Elementary> const & );
template ostream & operator << ( ostream &, LCSSQO<Elementary> const & );
template LCSSQO<ParticleHole>::LCSSQO() ;
template LCSSQO<ParticleHole>::LCSSQO(initializer_list< pair<STR<SQO<ParticleHole>>, PFSTT<ParticleHole>> >) ;
template LCSSQO<ParticleHole>::LCSSQO(LCSSQO<ParticleHole> const & ) ;
template double & LCSSQO<ParticleHole>::operator[] (STR<SQO<ParticleHole>> const & );
template LCSSQO<ParticleHole> & LCSSQO<ParticleHole>::operator= ( PFSTT<ParticleHole> const & );
template LCSSQO<ParticleHole> operator + ( LCSSQO<ParticleHole> const & , STR<SQO<ParticleHole>>  const & );
template LCSSQO<ParticleHole> operator + ( STR<SQO<ParticleHole>>  const & , LCSSQO<ParticleHole> const & );
template LCSSQO<ParticleHole> operator + ( LCSSQO<ParticleHole> const & , LCSSQO<ParticleHole> const & );
template LCSSQO<ParticleHole> operator * ( LCSSQO<ParticleHole> const &, double  const & );
template LCSSQO<ParticleHole> operator * ( double  const & , LCSSQO<ParticleHole> const &);
template LCSSQO<ParticleHole> operator * ( LCSSQO<ParticleHole> const &, PFSTT<ParticleHole>  const & );
template LCSSQO<ParticleHole> operator * ( PFSTT<ParticleHole>  const & , LCSSQO<ParticleHole> const &);
template LCSSQO<ParticleHole> operator * ( LCSSQO<ParticleHole> const &, STR<TwoTensorSQO<ParticleHole>>  const & );
template LCSSQO<ParticleHole> operator * ( STR<TwoTensorSQO<ParticleHole>>  const & , LCSSQO<ParticleHole> const &);
template LCSSQO<ParticleHole> operator * ( LCSSQO<ParticleHole> const &, STR<SQO<ParticleHole>> const & );
template LCSSQO<ParticleHole> operator * ( STR<SQO<ParticleHole>> const &, LCSSQO<ParticleHole> const & );
template LCSSQO<ParticleHole> operator * ( LCSSQO<ParticleHole> const &, LCSSQO<ParticleHole> const & );
template ostream & operator << ( ostream &, LCSSQO<ParticleHole> const & );
