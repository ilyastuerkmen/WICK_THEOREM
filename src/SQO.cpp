#include "SQO.h"

template<class Formalism>
SQO<Formalism>::SQO( SQO_Idx_Type const & idxtype, SQO_Type const & ca , string const  & p ) : idxtype(idxtype), a(ca), idx(p) {}

template<class Formalism>
SQO<Formalism>::SQO( SQO<Formalism> const & sqo ) : idxtype(sqo.idxtype), a(sqo.a), idx(sqo.idx) {}

template<class Formalism> ostream & operator << ( ostream & o, SQO<Formalism> const & sqo ) {
  o << "a_{" << sqo.idx << "}" ;
  if ( sqo.a == SQO_Type::creation ) { o << "^{\\dagger}" ;} ;   

  return o;
}


template<class Formalism> 
bool operator == ( SQO<Formalism> const & sqo1, SQO<Formalism> const & sqo2 ) {
  return ( (sqo1.idx == sqo2.idx) && (sqo1.a == sqo2.a) && (sqo1.idxtype == sqo2.idxtype) ) ;
} 

template class SQO<ParticleHole>;
template class SQO<Elementary>;

