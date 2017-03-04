#include "LCSSQO.h"

template<class Formalism> LCSSQO<Formalism>::LCSSQO() : map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>(), fullcontraction() {}
template<class Formalism> LCSSQO<Formalism>::LCSSQO(initializer_list< pair<STR<SQO<Formalism>>, PFSTT<Formalism>> > il)
  : map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>() {
    for (typename initializer_list<pair<STR<SQO<Formalism>>, PFSTT<Formalism>>>::const_iterator it=il.begin(); it!=il.end(); it++ ) {
      (*this).insert(make_pair((*it).first, (*it).second));
    }
  }
template<class Formalism> LCSSQO<Formalism>::LCSSQO(LCSSQO<Formalism> const & lc)
  : map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>() {
    (*this).fullcontraction = lc.fullcontraction;
    for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
      (*this).insert(make_pair((*it).first, (*it).second));
    }
}
template<class Formalism> PFSTT<Formalism> & LCSSQO<Formalism>::operator[] (STR<SQO<Formalism>> const & str ){
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::iterator it=(*this).begin(); it!=(*this).end(); it++ ) {
    if ( (*it).first == str ) { return (*it).second;}
  }
  PFSTT<Formalism> pf;
  (*this).insert(make_pair(str, pf ));
  return (*(*this).find(str)).second;
}
template<class Formalism> LCSSQO<Formalism> & LCSSQO<Formalism>::operator= ( LCSSQO<Formalism> const & lc ){
  (*this).clear();
  (*this).fullcontraction = lc.fullcontraction;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    (*this).insert(make_pair((*it).first, (*it).second));
  }
  return *this;
}
template<class Formalism> LCSSQO<Formalism> operator + ( LCSSQO<Formalism> const & lc , PFSTT<Formalism>  const & pf) {
  LCSSQO<Formalism> tmp(lc);
  lc.fullcontraction = lc.fullcontraction + pf;
}
template<class Formalism> LCSSQO<Formalism> operator + ( PFSTT<Formalism>  const & pf, LCSSQO<Formalism> const & lc) {
  LCSSQO<Formalism> tmp(lc);
  lc.fullcontraction = lc.fullcontraction + pf;
}
template<class Formalism> LCSSQO<Formalism> operator + ( LCSSQO<Formalism> const & lc , STR<SQO<Formalism>>  const & str ){
  LCSSQO<Formalism> tmp(lc);
  bool tmpbool(false);
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    if ( (*it).first == str ) { (*(tmp.find((*it).first))).second = (*it).second + str._prefactor ; tmpbool = true;  break;}
  }
  if ( tmpbool == false ) {
    PFSTT<Formalism> pf;
    pf.realnumber *= str._prefactor;
    STR<SQO<Formalism>> tmpstr(str);
    tmpstr._prefactor = 1;
    tmp.insert( make_pair( tmpstr, pf ) );
  }
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator + ( STR<SQO<Formalism>>  const & str, LCSSQO<Formalism> const & lc ){
  LCSSQO<Formalism> tmp(lc);
  bool tmpbool(false);
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    if ( (*it).first == str ) { (*(tmp.find((*it).first))).second = (*it).second + str._prefactor ; tmpbool = true;  break;}
  }
  if ( tmpbool == false ) {
    PFSTT<Formalism> pf;
    pf.realnumber *= str._prefactor;
    STR<SQO<Formalism>> tmpstr(str);
    tmpstr._prefactor = 1;
    tmp.insert( make_pair( tmpstr, pf ) );
  }
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator + ( LCSSQO<Formalism> const & llc, LCSSQO<Formalism> const & rlc){
  LCSSQO<Formalism> tmp(llc);
  tmp.fullcontraction = tmp.fullcontraction + rlc.fullcontraction;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it1=rlc.begin(); it1!=rlc.end(); it1++ ) {
    bool tmpbool(false);
    for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it2=llc.begin(); it2!=llc.end(); it2++ ) {
      if ( (*it1).first == (*it2).first ) { (*(tmp.find((*it1).first))).second = (*it2).second + (*it1).second ; tmpbool = true;  break;}
    }
    if (tmpbool == false) { tmp.insert( make_pair((*it1).first, (*it1).second)); }
  }
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const & lc, double  const & d){
  LCSSQO<Formalism> tmp(lc);
  tmp.fullcontraction =  tmp.fullcontraction * d;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second =  (*it).second *  d;
  }
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator * ( double  const & d, LCSSQO<Formalism> const & lc){
  LCSSQO<Formalism> tmp(lc);
  tmp.fullcontraction =  tmp.fullcontraction * d;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second =  (*it).second *  d;
  }
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const & lc, PFSTT<Formalism>  const & pf){
  LCSSQO<Formalism> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction * pf;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second = (*it).second * pf;
  }
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator * ( PFSTT<Formalism>  const & pf, LCSSQO<Formalism> const & lc){
  LCSSQO<Formalism> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction * pf;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second = (*it).second * pf;
  }
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const & lc, STR<TwoTensorSQO<Formalism>>  const & strtt ){
  LCSSQO<Formalism> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction * strtt;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second = (*it).second * strtt;
  }
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator * ( STR<TwoTensorSQO<Formalism>>  const & strtt, LCSSQO<Formalism> const & lc){
  LCSSQO<Formalism> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction * strtt;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second = (*it).second * strtt;
  }
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const & lc , STR<SQO<Formalism>> const & strsqo){
  LCSSQO<Formalism> tmp;
  double tmppre = strsqo._prefactor;
  STR<SQO<Formalism>> tmpstr(strsqo);
  tmpstr._prefactor = 1;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it=lc.begin(); it!=lc.end(); it++  ) {
    tmp.insert(make_pair( (*it).first * tmpstr , (*it).second * tmppre )) ;
  }
  tmp[tmpstr] =  tmp.fullcontraction * tmppre;
  PFSTT<Formalism> tmp2;
  tmp.fullcontraction = tmp2;
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator * ( STR<SQO<Formalism>> const & strsqo, LCSSQO<Formalism> const & lc ){
  LCSSQO<Formalism> tmp;
  double tmppre = strsqo._prefactor;
  STR<SQO<Formalism>> tmpstr(strsqo);
  tmpstr._prefactor = 1;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it=lc.begin(); it!=lc.end(); it++  ) {
    tmp.insert(make_pair( tmpstr * (*it).first ,  (*it).second * tmppre )) ;
  }
  tmp[tmpstr] =  tmp.fullcontraction * tmppre;
  PFSTT<Formalism> tmp2;
  tmp.fullcontraction = tmp2;
  return tmp;
}
template<class Formalism> LCSSQO<Formalism> operator * ( LCSSQO<Formalism> const & llc, LCSSQO<Formalism> const & rlc){
  LCSSQO<Formalism> tmp;
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it1=llc.begin(); it1!=rlc.end(); it1++ ) {
    if(tmp.find((*it1).first) == tmp.end() ) { tmp[(*it1).first] = (*it1).second * rlc.fullcontraction; }
    else { tmp[(*it1).first] = tmp[(*it1).first] +  ((*it1).second * rlc.fullcontraction);  }
    for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it2=rlc.begin(); it2!=llc.end(); it2++ ) {
      if ( it1 == llc.begin() ) {
        if(tmp.find((*it2).first) == tmp.end() ) { tmp[(*it2).first] = llc.fullcontraction * (*it2).second; }
        else { tmp[(*it2).first] = tmp[(*it2).first] + (llc.fullcontraction * (*it2).second);  }
      }
      if( tmp.find( (*it1).first * (*it2).first) == tmp.end() ) { tmp[(*it1).first * (*it2).first] = (*it1).second * (*it2).second ; }
      else{ tmp[(*it1).first * (*it2).first] = tmp[(*it1).first * (*it2).first] + ((*it1).second * (*it2).second) ; }
    }
  }
  tmp.fullcontraction = llc.fullcontraction * rlc.fullcontraction;
  return tmp;
}

template<class Formalism> LCSSQO<Formalism> wickexpansion(STR<SQO<Formalism>> const & str) {
 STR<SQO<Formalism>> tmpstr(str);
 tmpstr.normalproduct();
 LCSSQO<Formalism> tmpresult;
 tmpresult = tmpresult + tmpstr;
 LCSSQO<Formalism> previouscontractions;
 int count = 1;
 for ( typename list<SQO<Formalism>>::const_iterator it1 =str.begin(); it1 !=str.end(); it1++) {
   for ( typename list<SQO<Formalism>>::const_iterator it2 =str.begin(); it2 !=str.end(); it2++) {
       if ( it2 == str.begin() ) { for ( int i=0; i<count; i++) { ++it2;} ; ++count; }
       STR<SQO<Formalism>> tmp(str);
       if ( (*it1).a == SQO_Type::annihliation && (*it2).a == SQO_Type::creation ) {
         typename list<SQO<Formalism>>::iterator it3 = find(tmp.begin(), tmp.end(), *it1);
         it3 = tmp.list<SQO<Formalism>>::erase(it3);
         typename list<SQO<Formalism>>::iterator it4 = find(tmp.begin(), tmp.end(), *it2);
         it4 = tmp.list<SQO<Formalism>>::erase(it4);
         previouscontractions = previouscontractions + tmp;
         PFSTT<Formalism> tmppf;
         TwoTensorSQO<Formalism> tmptt(make_pair((*it1).idx, (*it1).idxtype), make_pair((*it2).idx, (*it1).idxtype));
         tmppf = tmppf + tmptt;
         if ( tmpresult.find(tmp) == tmpresult.end() ) { tmpresult[tmp] = tmppf; }
         else { tmpresult[tmp] =  tmpresult[tmp] + tmppf; }
       }
    }
  }

if ( previouscontractions.size() != 0 ) {
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it1=previouscontractions.begin(); it1!=previouscontractions.end(); it1++  ) {
    tmpresult = tmpresult + wickexpansion((*it1).first);
  }
}
 return tmpresult;
}

template<class Formalism> ostream & operator << ( ostream & o, LCSSQO<Formalism> const & lc){
  for ( typename map< STR<SQO<Formalism>>, PFSTT<Formalism>, STRSQOCompare<Formalism>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    if ( it != lc.begin() ) { o << "+ "; }
    o << (*it).second << "*" << (*it).first;
  }
  return o;
}







template LCSSQO<Elementary>::LCSSQO();
template LCSSQO<Elementary>::LCSSQO(initializer_list< pair<STR<SQO<Elementary>>, PFSTT<Elementary>> >);
template LCSSQO<Elementary>::LCSSQO(LCSSQO<Elementary> const & );
template PFSTT<Elementary> & LCSSQO<Elementary>::operator[] (STR<SQO<Elementary>> const & );
template LCSSQO<Elementary> & LCSSQO<Elementary>::operator= ( LCSSQO<Elementary> const & );
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
template PFSTT<ParticleHole> & LCSSQO<ParticleHole>::operator[] (STR<SQO<ParticleHole>> const & );
template LCSSQO<ParticleHole> & LCSSQO<ParticleHole>::operator= ( LCSSQO<ParticleHole>const & );
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

template LCSSQO<ParticleHole> wickexpansion(STR<SQO<ParticleHole>> const & );
template LCSSQO<Elementary> wickexpansion(STR<SQO<Elementary>> const & );
