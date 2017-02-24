#include "PFSTT.h"

template<class Formalism> PFSTT<Formalism>::PFSTT() : map<STR<TwoTensorSQO<Formalism>>, double, STRTTCompare<Formalism>>() , realnumber(0) {}
template<class Formalism> PFSTT<Formalism>::PFSTT( initializer_list<STR<TwoTensorSQO<Formalism>>> il, double const & rn)
  : map<STR<TwoTensorSQO<Formalism>>, double, STRTTCompare<Formalism>>() , realnumber(rn) {
  for ( typename initializer_list<STR<TwoTensorSQO<Formalism>>>::const_iterator it=il.begin(); it!=il.end(); it++ ) {
    double pre = (*it)._prefactor;
    typename map<STR<TwoTensorSQO<Formalism>>, double, STRTTCompare<Formalism>>::iterator it2 = (*this).find((*it));
    if ( it2 == (*this).end() ) {
      STR<TwoTensorSQO<Formalism>> tmp((*it));
      tmp._prefactor = 1;
      (*this).insert( make_pair(tmp, pre) );
    }
    else {
     (*this)[(*it2).first] += pre;
    }
  }
}
template<class Formalism>PFSTT<Formalism>::PFSTT( PFSTT<Formalism> const & pf) : map<STR<TwoTensorSQO<Formalism>>, double, STRTTCompare<Formalism>>() , realnumber(pf.realnumber) {
  for ( typename map<STR<TwoTensorSQO<Formalism>>, double, STRTTCompare<Formalism>>::const_iterator it=pf.begin(); it!=pf.end(); it++ ) {
    (*this).insert( make_pair( (*it).first, (*it).second ) );
  }
}
template<class Formalism> PFSTT<Formalism> & PFSTT<Formalism>::operator = ( PFSTT<Formalism> const & pf ) {
  (*this).realnumber = pf.realnumber;
  (*this).clear();
   for ( typename map<STR<TwoTensorSQO<Formalism>>, double, STRTTCompare<Formalism>>::const_iterator it=pf.begin(); it!=pf.end(); it++ ) {
    (*this).insert( make_pair( (*it).first, (*it).second ) );
  }
  return (*this);
}
template<class Formalism> double & PFSTT<Formalism>::operator [] ( STR<TwoTensorSQO<Formalism>> const & str ) {
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::iterator it=(*this).begin(); it!=(*this).end(); it++  ) {
    if ( (*it).first == str ) { return (*it).second;}
  }
  throw;
}

template<class Formalism> PFSTT<Formalism> operator + ( PFSTT<Formalism> const & pf, double const & d ) {
  PFSTT<Formalism> tmp(pf);
  tmp.realnumber += d;
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator + ( double const & d, PFSTT<Formalism> const & pf) {
  PFSTT<Formalism> tmp(pf);
  tmp.realnumber += d;
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator + ( PFSTT<Formalism> const & pf, STR<TwoTensorSQO<Formalism>> const & str ) {
  PFSTT<Formalism> tmp(pf);
  bool tmpbool(false);
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism>  >::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
    if ( (*it).first == str ) { (*it).second += str._prefactor; tmpbool = true;  break;}
  }
  if ( tmpbool == false ) {
    double pre = str._prefactor;
    STR<TwoTensorSQO<Formalism>> tmpstr(str);
    tmpstr._prefactor = 1;
    tmp.insert( make_pair( tmpstr, pre ) );
  }
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator + ( STR<TwoTensorSQO<Formalism>> const & str, PFSTT<Formalism> const & pf){
  PFSTT<Formalism> tmp(pf);
  bool tmpbool(false);
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
    if ( (*it).first == str ) { (*it).second += str._prefactor; tmpbool = true;  break;}
  }
  if ( tmpbool == false ) {
    double pre = str._prefactor;
    STR<TwoTensorSQO<Formalism>> tmpstr(str);
    tmpstr._prefactor = 1;
    tmp.insert( make_pair( tmpstr, pre ) );
  }
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator + ( PFSTT<Formalism> const & lpf, PFSTT<Formalism> const & rpf) {
  PFSTT<Formalism> tmp(lpf);
  tmp.realnumber += rpf.realnumber;
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it=rpf.begin(); it!=rpf.end(); it++ ) {
    tmp = tmp + (*it).second*(*it).first;
  }
  return tmp;
}

template<class Formalism> PFSTT<Formalism> operator * ( PFSTT<Formalism> const & pf, double const & d){
  PFSTT<Formalism> tmp(pf);
  tmp.realnumber *= d;
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
    (*it).second *= d;
  }
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator * ( double const & d, PFSTT<Formalism> const & pf) {
  PFSTT<Formalism> tmp(pf);
  tmp.realnumber *= d;
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
    (*it).second *= d;
  }
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator * ( PFSTT<Formalism> const & pf, STR<TwoTensorSQO<Formalism>> const & str){
  PFSTT<Formalism> tmp;
  double invpre = 1/(str._prefactor);
  for (typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it=pf.begin(); it!=pf.end(); it++  ) {
    tmp.insert(make_pair( ((*it).first * (str*invpre)), ((*it).second * str._prefactor) )) ;
  }
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator * ( STR<TwoTensorSQO<Formalism>> const & str, PFSTT<Formalism> const & pf){
  PFSTT<Formalism> tmp;
  double invpre = 1/(str._prefactor);
  for (typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it=pf.begin(); it!=pf.end(); it++  ) {
    tmp.insert(make_pair( ((*it).first * (str*invpre)), ((*it).second * str._prefactor) )) ;
  }
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator * ( PFSTT<Formalism> const & lpf, PFSTT<Formalism> const & rpf ){
  PFSTT<Formalism> tmp;
  tmp.realnumber = lpf.realnumber * rpf.realnumber;
  for (typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it1=lpf.begin(); it1!=lpf.end(); it1++  ) {
    tmp.insert(make_pair( (*it1).first, ((*it1).second * rpf.realnumber) ));
    for (typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it2=rpf.begin(); it2!=rpf.end(); it2++  ) {
      if ( it1 == lpf.begin() ) { tmp.insert(make_pair( (*it2).first, ((*it2).second * lpf.realnumber) )); }
      tmp.insert(make_pair( ((*it1).first * (*it2).first), ((*it1).second * (*it2).second) )) ;
    }
  }

  return tmp;
}

template<class Formalism> ostream & operator << ( ostream & o, PFSTT<Formalism> const & pf ) {
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it=pf.begin(); it!=pf.end(); it++ ) {
    if ( it == pf.begin() ) { o << "(" << (*it).second << "*" << (*it).first; }
    else { o << "+" << (*it).second << "*" << (*it).first; }
  }
  if ( pf.realnumber != 0 ) { o << "+" << pf.realnumber ; }
  o << ")";
  return o;
}


template PFSTT<Elementary>::PFSTT();
template PFSTT<ParticleHole>::PFSTT();
template PFSTT<Elementary>::PFSTT( initializer_list<STR<TwoTensorSQO<Elementary>>>, double const & );
template PFSTT<ParticleHole>::PFSTT( initializer_list<STR<TwoTensorSQO<ParticleHole>>>, double const & );
template PFSTT<Elementary>::PFSTT( PFSTT<Elementary> const & );
template PFSTT<ParticleHole>::PFSTT( PFSTT<ParticleHole> const & );
template PFSTT<Elementary> & PFSTT<Elementary>::operator = ( PFSTT<Elementary> const & );
template PFSTT<ParticleHole> & PFSTT<ParticleHole>::operator = ( PFSTT<ParticleHole> const & );

template ostream & operator << ( ostream &, PFSTT<Elementary> const & );
template ostream & operator << ( ostream &, PFSTT<ParticleHole> const & );
template double & PFSTT<Elementary>::operator [] ( STR<TwoTensorSQO<Elementary>> const & );
template double & PFSTT<ParticleHole>::operator [] ( STR<TwoTensorSQO<ParticleHole>> const & );

template PFSTT<Elementary> operator + ( PFSTT<Elementary> const &, double const & );
template PFSTT<ParticleHole> operator + ( PFSTT<ParticleHole> const &, double const & );
template PFSTT<Elementary> operator + ( double const &, PFSTT<Elementary> const & );
template PFSTT<ParticleHole> operator + ( double const &, PFSTT<ParticleHole> const & );
template PFSTT<Elementary> operator + ( PFSTT<Elementary> const &, STR<TwoTensorSQO<Elementary>> const &);
template PFSTT<ParticleHole> operator + ( PFSTT<ParticleHole> const &, STR<TwoTensorSQO<ParticleHole>> const &);
template PFSTT<Elementary> operator + ( STR<TwoTensorSQO<Elementary>> const &, PFSTT<Elementary> const & );
template PFSTT<ParticleHole> operator + ( STR<TwoTensorSQO<ParticleHole>> const &, PFSTT<ParticleHole> const & );
template PFSTT<Elementary> operator + ( PFSTT<Elementary> const & , PFSTT<Elementary> const &);
template PFSTT<ParticleHole> operator + ( PFSTT<ParticleHole> const & , PFSTT<ParticleHole> const &);

template PFSTT<Elementary> operator * ( PFSTT<Elementary> const &, double const & );
template PFSTT<Elementary> operator * ( double const & , PFSTT<Elementary> const &);
template PFSTT<Elementary> operator * ( PFSTT<Elementary> const &, STR<TwoTensorSQO<Elementary>> const & );
template PFSTT<Elementary> operator * ( STR<TwoTensorSQO<Elementary>> const &, PFSTT<Elementary> const & );
template PFSTT<Elementary> operator * ( PFSTT<Elementary> const &, PFSTT<Elementary> const & );
template PFSTT<ParticleHole> operator * ( PFSTT<ParticleHole> const &, double const & );
template PFSTT<ParticleHole> operator * ( double const & , PFSTT<ParticleHole> const &);
template PFSTT<ParticleHole> operator * ( PFSTT<ParticleHole> const &, STR<TwoTensorSQO<ParticleHole>> const & );
template PFSTT<ParticleHole> operator * ( STR<TwoTensorSQO<ParticleHole>> const &, PFSTT<ParticleHole> const & );
template PFSTT<ParticleHole> operator * ( PFSTT<ParticleHole> const &, PFSTT<ParticleHole> const & );
