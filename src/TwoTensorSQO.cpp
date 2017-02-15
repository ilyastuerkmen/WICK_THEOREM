#include "TwoTensorSQO.h"

template<class Formalism> 
TwoTensorSQO<Formalism>::TwoTensorSQO( pair<string, SQO_Idx_Type> const & p1, pair<string, SQO_Idx_Type> const & p2 ) 
  : idx1(p1), idx2(p2) {}

template<class Formalism> 
TwoTensorSQO<Formalism>::TwoTensorSQO( TwoTensorSQO<Formalism> const & ttsqo ) 
  : idx1(ttsqo.idx1), idx2(ttsqo.idx2) {}

template<class Formalism> 
bool operator == ( TwoTensorSQO<Formalism> const & ttsqo1, TwoTensorSQO<Formalism> const & ttsqo2 ) 
{ 
  string tmp1(ttsqo1.idx1.first);
  tmp1 += ttsqo1.idx2.first;
  
  string tmp2(ttsqo2.idx1.first);
  tmp2 += ttsqo2.idx2.first;
  
  sort(tmp1.begin(), tmp1.end());
  sort(tmp2.begin(), tmp2.end());
  
  return ( tmp1 == tmp2 ); 
  
}


inline ostream & operator << ( ostream & o , TwoTensorSQO<Elementary> const & ttsqo ) {
  o << "\\delta_{" << ttsqo.idx1.first << ttsqo.idx2.first << "}" ;
  return o;
}


inline ostream & operator << ( ostream & o , TwoTensorSQO<ParticleHole> const & ttsqo ) {
  o << "\\gamma_{" << ttsqo.idx1.first << ttsqo.idx2.first << "}" ;
  return o;
}

