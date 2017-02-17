#include "PFSTT.h"

template<class Formalism> PFSTT<Formalism>::PFSTT() : map<STR<TwoTensorSQO<Formalism>>, double>() , realnumber(0) {}
template<class Formalism> PFSTT<Formalism>::PFSTT( initializer_list<STR<TwoTensorSQO<Formalism>>> il, double const & rn) 
  : map<STR<TwoTensorSQO<Formalism>>, double>() , realnumber(rn) {
  for ( typename initializer_list<STR<TwoTensorSQO<Formalism>>>::const_iterator it=il.begin(); it!=il.end(); it++ ) {
    double pre = (*it)._prefactor;
    STR<TwoTensorSQO<Formalism>> tmp((*it));
    tmp._prefactor = 1;
    (*this).insert( make_pair(tmp, pre) );
  }
}
template<class Formalism>PFSTT<Formalism>::PFSTT( PFSTT<Formalism> const & pf) {
  (*this)();
  (*this).realnumber = pf.realnumber;
  for ( typename map<STR<TwoTensorSQO<Formalism>>, double>::const_iterator it=pf.begin(); it!=pf.end(); it++ ) {
    (*this).insert( make_pair( (*it).first, (*it).second ) );
  }
}
template<class Formalism> PFSTT<Formalism> & PFSTT<Formalism>::operator = ( PFSTT<Formalism> const & pf ) { (*this)(pf) ; }

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
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double >::const_iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
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
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double >::const_iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
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
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double >::const_iterator it=rpf.begin(); it!=rpf.end(); it++ ) {
    tmp = tmp + (*it).first;  
  }
}

template<class Formalism> ostream & operator << ( ostream & o, PFSTT<Formalism> const & pf ) {
  for ( typename map< STR<TwoTensorSQO<Formalism>> , double >::const_iterator it=pf.begin(); it!=pf.end(); it++ ) { 
    if ( it == pf.begin() ) { o << "( " << (*it).second << "*" << (*it).first; }
    else { o << " + " << (*it).second << "*" << (*it).first; }
  }
  if ( pf.realnumber != 0 ) { o << " + " << pf.realnumber ; }
  o << " )";
  return o;
}
