

template<class T1, class T2> LCSSQO<T1, T2>::LCSSQO() : map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>(), fullcontraction() {}
template<class T1, class T2> LCSSQO<T1, T2>::LCSSQO(initializer_list< pair<STR<SQO<T1>>, PFSTT<T2>> > il)
  : map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>() {
    for (typename initializer_list<pair<STR<SQO<T1>>, PFSTT<T2>>>::const_iterator it=il.begin(); it!=il.end(); it++ ) {
      (*this).insert(make_pair((*it).first, (*it).second));
    }
  }
template<class T1, class T2> LCSSQO<T1, T2>::LCSSQO(LCSSQO<T1, T2> const & lc)
  : map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>() {
    (*this).fullcontraction = lc.fullcontraction;
    for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
      (*this).insert(make_pair((*it).first, (*it).second));
    }
}
template<class T1, class T2> PFSTT<T2> & LCSSQO<T1, T2>::operator[] (STR<SQO<T1>> const & str ){
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::iterator it=(*this).begin(); it!=(*this).end(); it++ ) {
    if ( (*it).first == str ) { return (*it).second;}
  }
  PFSTT<T2> pf;
  (*this).insert(make_pair(str, pf ));
  return (*(*this).find(str)).second;
}
template<class T1, class T2> LCSSQO<T1, T2> & LCSSQO<T1, T2>::operator= ( LCSSQO<T1, T2> const & lc ){
  (*this).clear();
  (*this).fullcontraction = lc.fullcontraction;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    (*this).insert(make_pair((*it).first, (*it).second));
  }
  return *this;
}
template<class T1, class T2> LCSSQO<T1, T2> operator + ( LCSSQO<T1, T2> const & lc , PFSTT<T2>  const & pf) {
  LCSSQO<T1, T2> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction + pf;
  return tmp;
}

template<class T1, class T2> LCSSQO<T1, T2> operator + ( PFSTT<T2>  const & pf, LCSSQO<T1, T2> const & lc) {
  LCSSQO<T1, T2> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction + pf;
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator + ( LCSSQO<T1, T2> const & lc , STR<SQO<T1>>  const & str ){
  LCSSQO<T1, T2> tmp(lc);
  bool tmpbool(false);
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    if ( (*it).first == str ) { (*(tmp.find((*it).first))).second = (*it).second + str._prefactor ; tmpbool = true;  break;}
  }
  if ( tmpbool == false ) {
    PFSTT<T2> pf;
    pf.realnumber = str._prefactor;
    STR<SQO<T1>> tmpstr(str);
    tmpstr._prefactor = 1;
    tmp.insert( make_pair( tmpstr, pf ) );
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator + ( STR<SQO<T1>>  const & str, LCSSQO<T1, T2> const & lc ){
  LCSSQO<T1, T2> tmp(lc);
  bool tmpbool(false);
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    if ( (*it).first == str ) { (*(tmp.find((*it).first))).second = (*it).second + str._prefactor ; tmpbool = true;  break;}
  }
  if ( tmpbool == false ) {
    PFSTT<T2> pf;
    pf.realnumber *= str._prefactor;
    STR<SQO<T1>> tmpstr(str);
    tmpstr._prefactor = 1;
    tmp.insert( make_pair( tmpstr, pf ) );
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator + ( LCSSQO<T1, T2> const & llc, LCSSQO<T1, T2> const & rlc){
  LCSSQO<T1, T2> tmp(llc);
  tmp.fullcontraction = tmp.fullcontraction + rlc.fullcontraction;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it1=rlc.begin(); it1!=rlc.end(); it1++ ) {
    bool tmpbool(false);
    for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it2=llc.begin(); it2!=llc.end(); it2++ ) {
      if ( (*it1).first == (*it2).first ) { (*(tmp.find((*it1).first))).second = (*it2).second + (*it1).second ; tmpbool = true;  break;}
    }
    if (tmpbool == false) { tmp.insert( make_pair((*it1).first, (*it1).second)); }
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const & lc, double  const & d) {
  LCSSQO<T1, T2> tmp(lc);
  tmp.fullcontraction =  tmp.fullcontraction * d;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second =  (*it).second *  d;
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator * ( double  const & d, LCSSQO<T1, T2> const & lc){
  LCSSQO<T1, T2> tmp(lc);
  tmp.fullcontraction =  tmp.fullcontraction * d;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second =  (*it).second *  d;
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const & lc, PFSTT<T2>  const & pf){
  LCSSQO<T1, T2> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction * pf;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second = (*it).second * pf;
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator * ( PFSTT<T2>  const & pf, LCSSQO<T1, T2> const & lc){
  LCSSQO<T1, T2> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction * pf;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second = (*it).second * pf;
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const & lc, STR<TwoTensorSQO<T2>>  const & strtt ){
  LCSSQO<T1, T2> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction * strtt;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second = (*it).second * strtt;
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator * ( STR<TwoTensorSQO<T2>>  const & strtt, LCSSQO<T1, T2> const & lc){
  LCSSQO<T1, T2> tmp(lc);
  tmp.fullcontraction = tmp.fullcontraction * strtt;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second = (*it).second * strtt;
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const & lc , STR<SQO<T1>> const & strsqo){
  LCSSQO<T1, T2> tmp;
  double tmppre = strsqo._prefactor;
  STR<SQO<T1>> tmpstr(strsqo);
  tmpstr._prefactor = 1;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it=lc.begin(); it!=lc.end(); it++  ) {
    tmp.insert(make_pair( (*it).first * tmpstr , (*it).second * tmppre )) ;
  }
  tmp[tmpstr] =  tmp.fullcontraction * tmppre;
  PFSTT<T2> tmp2;
  tmp.fullcontraction = tmp2;
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator * ( STR<SQO<T1>> const & strsqo, LCSSQO<T1, T2> const & lc ){
  LCSSQO<T1, T2> tmp;
  double tmppre = strsqo._prefactor;
  STR<SQO<T1>> tmpstr(strsqo);
  tmpstr._prefactor = 1;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it=lc.begin(); it!=lc.end(); it++  ) {
    tmp.insert(make_pair( tmpstr * (*it).first ,  (*it).second * tmppre )) ;
  }
  tmp[tmpstr] =  tmp.fullcontraction * tmppre;
  PFSTT<T2> tmp2;
  tmp.fullcontraction = tmp2;
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> operator * ( LCSSQO<T1, T2> const & llc, LCSSQO<T1, T2> const & rlc){
  LCSSQO<T1, T2> tmp;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it1=llc.begin(); it1!=rlc.end(); it1++ ) {
    if(tmp.find((*it1).first) == tmp.end() ) { tmp[(*it1).first] = (*it1).second * rlc.fullcontraction; }
    else { tmp[(*it1).first] = tmp[(*it1).first] +  ((*it1).second * rlc.fullcontraction);  }
    for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it2=rlc.begin(); it2!=llc.end(); it2++ ) {
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

template<class T1, class T2> LCSSQO<T1, T2> wickexpansion(STR<SQO<T1>> const & str, T2 const & ref) {
 T1 t1 = T1::vacuum;
 Ref_State refstate;
 STR<SQO<T1>> tmpstr(str);
 if ( ref == T2::vacuum ) {refstate = Ref_State::vacuum;};
 if ( ref == T2::fermi) {refstate = Ref_State::fermi;};
 tmpstr.normalproduct();
 LCSSQO<T1, T2> tmpresult;
 tmpresult = tmpresult + tmpstr;
 LCSSQO<T1, T2> previouscontractions;

 for ( int firstpos=0; firstpos < str.size(); firstpos++ ) {
   for ( int secondpos=firstpos+1; secondpos<str.size(); secondpos++ ) {
    STR<SQO<T1>> tmp(str);
    typename list<SQO<T1>>::iterator it1 = tmp.begin();
    typename list<SQO<T1>>::iterator it2 = tmp.begin();
    for ( int i=0; i<firstpos; i++ ) { ++it1; }
    for ( int j=0; j<secondpos; j++ ) { ++it2; }
    if (
      (refstate == Ref_State::vacuum && (*it1).a == SQO_Type::annihliation && (*it2).a == SQO_Type::creation )   ||
      (refstate == Ref_State::fermi && (*it1).idxtype == SQO_Idx_Type::hole && (*it2).idxtype == SQO_Idx_Type::hole && (*it1).a == SQO_Type::annihliation && (*it2).a == SQO_Type::creation ) ||
      (refstate == Ref_State::fermi && (*it1).idxtype == SQO_Idx_Type::particle && (*it2).idxtype == SQO_Idx_Type::particle && (*it1).a == SQO_Type::creation && (*it2).a == SQO_Type::annihliation)
    )
    {
        TwoTensorSQO<T2> tmptt(make_pair((*it1).idx, (*it1).idxtype), make_pair((*it2).idx, (*it2).idxtype));
        STR<TwoTensorSQO<T2>> tmpstrtt({tmptt});
        PFSTT<T2> tmppf({tmpstrtt});
        tmppf = tmppf * tmp._prefactor;
        int sumofpos = firstpos + secondpos -1;
        tmppf = tmppf * (( sumofpos % 2  == 0 ) ? 1 : -1);
        tmp._prefactor = 1;
        tmp.list<SQO<T1>>::erase(it1);
        tmp.list<SQO<T1>>::erase(it2);
        if ( tmp.size() == 0 ) {  tmpresult.fullcontraction = tmpresult.fullcontraction + tmppf; }
        else {
          previouscontractions = previouscontractions + tmp;
          previouscontractions[tmp] = tmppf;
          if ( refstate == Ref_State::vacuum ) {
            STR<SQO<Elementary>> tmpelementary(ToSTRElementary(tmp));
            tmpelementary.normalproduct();
            tmp = EquateIfPossible( tmpelementary, t1 );
          }
          else if ( refstate == Ref_State::fermi ) {
            STR<SQO<ParticleHole>> tmpparticlehole(ToSTRParticleHole(tmp));
            tmpparticlehole.normalproduct();
            tmp = EquateIfPossible( tmpparticlehole, t1 );
           }
           tmppf = tmppf * tmp._prefactor;
           tmp._prefactor = 1;
           if ( tmpresult.find(tmp) == tmpresult.end() ) { tmpresult[tmp] = tmppf; }
           else { tmpresult[tmp] =  tmpresult[tmp] + tmppf; }
        }
      }
    }
  }
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it1=previouscontractions.begin(); it1!=previouscontractions.end(); it1++  ) {
      LCSSQO<T1, T2> tmpwick( wickexpansion((*it1).first, ref));
      PFSTT<T2> whatever = ((((*it1).second * tmpwick).fullcontraction) + (tmpresult.fullcontraction));
      tmpresult = tmpresult + (*it1).second*tmpwick;
  }

 return tmpresult;
}

template<class T1, class T2> ostream & operator << ( ostream & o, LCSSQO<T1, T2> const & lc){
  if ( lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0)  {}
  else { o << lc.fullcontraction; }
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    if ((*it).second.size() == 0 ) {
      if ((*it).second.realnumber < 0 ) {
        if ( (*it).second.realnumber == -1 ) { o << "-";}
        else { o << (*it).second.realnumber; }
      }
      if ( (*it).second.realnumber > 0 ) {
        if (it == lc.begin() && lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0 )  {
          if ( (*it).second.realnumber == 1 ) {}
          else {o << (*it).second.realnumber;}
        }
        else {
          if ((*it).second.realnumber == 1 )  { o << "+" ;}
          else {o << "+" << (*it).second.realnumber;  }
        }
      }
    }
    else {
      if ( (*it).second.size() == 1  && (*it).second.realnumber == 0 &&  (*((*it).second.begin())).second > 0 ) {
        if (it == lc.begin() && lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0 ) {}
        else { o << "+";  }
      }
      o << (*it).second << " \\cdot " ;
    }
    o << (*it).first;
  }
  return o;
}
