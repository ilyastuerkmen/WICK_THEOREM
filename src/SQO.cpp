#include "SQO.h"

template<class Formalism> SQO<Formalism>::SQO( SQO_Idx_Type const & idxtype, SQO_Type const & ca , string const  & p ) : idxtype(idxtype), a(ca), idx(p) {}
template<class Formalism> SQO<Formalism>::SQO( SQO<Formalism> const & sqo ) : idxtype(sqo.idxtype), a(sqo.a), idx(sqo.idx) {}
ostream & operator << ( ostream & o, SQO<Elementary> const & sqo ) {
  o << "a_{" << sqo.idx << "}" ;
  if ( sqo.a == SQO_Type::creation ) { o << "^{\\dagger}" ;} ;
  return o;
}
ostream & operator << ( ostream & o, SQO<ParticleHole> const & sqo ) {
  o << "b_{" << sqo.idx << "}" ;
  if ( sqo.a == SQO_Type::creation ) { o << "^{\\dagger}" ;} ;

  return o;
}
template<class Formalism> bool operator == ( SQO<Formalism> const & sqo1, SQO<Formalism> const & sqo2 ) {
  return ( (sqo1.idx == sqo2.idx) && (sqo1.a == sqo2.a) && (sqo1.idxtype == sqo2.idxtype) ) ;
}

SQO<ParticleHole> ToParticleHole( SQO<ParticleHole> const & particlehole) {
  return particlehole;
}
SQO<ParticleHole> ToParticleHole( SQO<Elementary> const & elementary) {
  SQO_Type tmpsqotype;
  if ( elementary.idxtype == SQO_Idx_Type::general ) { throw;}
  else if ( elementary.idxtype == SQO_Idx_Type::particle  &&  elementary.a == SQO_Type::annihliation ) { tmpsqotype = SQO_Type::creation;  }
  else if ( elementary.idxtype == SQO_Idx_Type::particle  &&  elementary.a == SQO_Type::creation ) { tmpsqotype = SQO_Type::annihliation;  }
  else if ( elementary.idxtype == SQO_Idx_Type::hole) { tmpsqotype = elementary.a;  }
  SQO<ParticleHole>  tmp(elementary.idxtype, tmpsqotype, elementary.idx);
  return tmp;
}
SQO<Elementary> ToElementary( SQO<ParticleHole> const & particlehole){
  SQO_Type tmpsqotype;
  if ( particlehole.idxtype == SQO_Idx_Type::general ) { throw;}
  else if ( particlehole.idxtype == SQO_Idx_Type::particle  &&  particlehole.a == SQO_Type::annihliation ) { tmpsqotype = SQO_Type::creation;  }
  else if ( particlehole.idxtype == SQO_Idx_Type::particle  &&  particlehole.a == SQO_Type::creation ) { tmpsqotype = SQO_Type::annihliation;  }
  else if ( particlehole.idxtype == SQO_Idx_Type::hole) { tmpsqotype = particlehole.a;  }
  SQO<Elementary>  tmp(particlehole.idxtype, tmpsqotype, particlehole.idx);
  return tmp;
}
SQO<Elementary> ToElementary( SQO<Elementary> const & elementary) {
  return elementary;
}






template SQO<Elementary>::SQO( SQO_Idx_Type const &, SQO_Type const & , string const  & );
template SQO<ParticleHole>::SQO( SQO_Idx_Type const &, SQO_Type const & , string const  & );
template SQO<Elementary>::SQO( SQO<Elementary> const & );
template SQO<ParticleHole>::SQO( SQO<ParticleHole> const & );
template bool operator == ( SQO<Elementary> const &, SQO<Elementary> const & );
template bool operator == ( SQO<ParticleHole> const &, SQO<ParticleHole> const & );
