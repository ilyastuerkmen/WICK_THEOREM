

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
  (*this).insert(make_pair(str, 0));
  return (*(*this).find(str)).second;
}
template<class Formalism> PFSTT<Formalism> PFSTT<Formalism>::cleanUpZero() {
  typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::iterator it=(*this).begin();
   while ( it!=(*this).end() ) {
     if ( (*it).second == 0 ) {  it = (*this).erase(it); }
     else { it++; }
   }
   return *this;
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
  STR<TwoTensorSQO<Formalism>> tmpstr(str);
  tmpstr._prefactor = 1;
  for (typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it=pf.begin(); it!=pf.end(); it++  ) {
    tmp[(*it).first * tmpstr] = (*it).second * str._prefactor;
  }
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator * ( STR<TwoTensorSQO<Formalism>> const & str, PFSTT<Formalism> const & pf){
  PFSTT<Formalism> tmp;
  STR<TwoTensorSQO<Formalism>> tmpstr(str);
  tmpstr._prefactor = 1;
  for (typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it=pf.begin(); it!=pf.end(); it++  ) {
    tmp[ tmpstr * (*it).first ] = (*it).second * str._prefactor;
  }
  return tmp;
}
template<class Formalism> PFSTT<Formalism> operator * ( PFSTT<Formalism> const & lpf, PFSTT<Formalism> const & rpf ){
  PFSTT<Formalism> tmp;
  tmp.realnumber = lpf.realnumber * rpf.realnumber;
  for (typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it1=lpf.begin(); it1!=lpf.end(); it1++  ) {
    if (rpf.realnumber != 0  ) {
      if(tmp.find((*it1).first) == tmp.end() ) {  tmp[(*it1).first] = ((*it1).second * rpf.realnumber);}
      else { tmp[(*it1).first] += ((*it1).second * rpf.realnumber); }
    }
    for (typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it2=rpf.begin(); it2!=rpf.end(); it2++  ) {
      if ( it1 == lpf.begin() && lpf.realnumber != 0 ) {
        if(tmp.find((*it2).first) == tmp.end() ) {  tmp[(*it2).first] = ((*it2).second * lpf.realnumber);}
        else { tmp[(*it2).first] += ((*it2).second * lpf.realnumber); }
      }
      if ( tmp.find((*it1).first * (*it2).first) == tmp.end() ) { tmp[((*it1).first * (*it2).first)] = ((*it1).second * (*it2).second); }
      else {   tmp[((*it1).first * (*it2).first)] += ((*it1).second * (*it2).second); }
    }
  }
  return tmp;
}

template<class Formalism> ostream & operator << ( ostream & o, PFSTT<Formalism> const & pf ) {
   if ( pf.size() == 0 ) {
     if ( pf.realnumber == 0 ) {}
     else if ( pf.realnumber != 1 ) { o << pf.realnumber;}
   }
   else {
    for ( typename map< STR<TwoTensorSQO<Formalism>> , double, STRTTCompare<Formalism> >::const_iterator it=pf.begin(); it!=pf.end(); it++ ) {
      if ( it == pf.begin()) {
        if ( pf.size() ==1 && pf.realnumber == 0 ) {}
        else { o << "(" ; }
        if ( (*it).second != 1  ) {
          if ( (*it).second == -1 ) { o << "-" ;}
          else { o << (*it).second << " \\cdot " ; }
        }
          o << (*it).first;
      }
      else {
        if ( (*it).second >= 0 ) { o << "+"; }
        if ( (*it).second != 1 ) {
         if ( (*it).second == -1 ) { o << "-" ;}
         else { o << (*it).second << " \\cdot " ;  }
       }
          o << (*it).first;

      }
    }
    if ( pf.realnumber != 0  ) {
      if ( pf.realnumber > 0 ) { o << "+";}
      o << pf.realnumber ;
    }
    if ( pf.size() ==1 && pf.realnumber == 0 ) {}

    else { o << ")" ; }
  }
    return o;
}
