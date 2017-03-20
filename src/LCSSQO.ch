

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
  tmp.fullcontraction = pf + tmp.fullcontraction ;
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
  tmp.fullcontraction = pf * tmp.fullcontraction ;
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::iterator it=tmp.begin(); it!=tmp.end(); it++ ) {
   (*it).second = pf * (*it).second;
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

template<class T1, class T2, class T3> LCSSQO<T1, T2> EquateIfPossible( LCSSQO<T3, T2> const & lcssqo, T1 const & t1) {
  LCSSQO<T1, T2> tmp;
  tmp.fullcontraction = lcssqo.fullcontraction;
  for ( typename map< STR<SQO<T3>>, PFSTT<T2>, STRSQOCompare<T3>>::const_iterator it1=lcssqo.begin(); it1!=lcssqo.end(); it1++ ) {
    tmp.insert( make_pair( EquateIfPossible((*it1).first, t1) , (*it1).second ));
  }
  return tmp;
}

template<class T1, class T2> LCSSQO<T1, T2> generalizedWickExpansion(STR<SQO<T1>> const & str, T2 const & ref) {
  STR<SQO<T2>> tmpstr(STRToSTR(str, ref));
  LCSSQO<T2, T2>  tmpresult( wickexpansion(tmpstr, ref, PositionOfNextNormalFragment(tmpstr)) );
  return EquateIfPossible(tmpresult, T1::noreference);
}


template<class T1, class T2> LCSSQO<T1, T2> wickexpansion(STR<SQO<T1>> const & str, T2 const & ref, vector<int> const & positionslist) {
LCSSQO<T2, T2> tmpresult;
STR<SQO<T2>> tmpstr(STRToSTR(str, ref));
if ( tmpstr.normalordered() ) { return EquateIfPossible((tmpresult + tmpstr), T1::noreference); }
vector<int> tmplist = positionslist;
if ( tmplist.size() == 0 ) { tmplist.push_back(0); tmplist.push_back(str.size());}
tmpstr.normalproduct();
tmpresult = tmpresult + tmpstr;
LCSSQO<T2, T2> previouscontractions;
vector<int> tmplist3;
if ( tmplist.size() != 1 ) {
  if ( tmplist.size() > 1 ) {
    for ( int i = 1; i<tmplist.size(); i++ ) {

      for ( int firstpos = tmplist[i-1]; firstpos < tmplist[i]; firstpos++ ) {
        for ( int secondpos=firstpos+1; secondpos<str.size(); secondpos++ ) {
          STR<SQO<T2>> tmp(STRToSTR(str, ref));
          typename list<SQO<T2>>::iterator it1 = tmp.begin();
          typename list<SQO<T2>>::iterator it2 = tmp.begin();
            for ( int i=0; i<firstpos; i++ ) { ++it1; }
            for ( int j=0; j<secondpos; j++ ) { ++it2; }
            if ( (*it1).a == SQO_Type::annihliation && (*it2).a == SQO_Type::creation )
            {
              TwoTensorSQO<T2> tmptt(make_pair((*it1).idx, (*it1).idxtype), make_pair((*it2).idx, (*it2).idxtype));
              STR<TwoTensorSQO<T2>> tmpstrtt({tmptt});
              PFSTT<T2> tmppf({tmpstrtt});
              tmppf = tmppf * tmp._prefactor;
              int sumofpos = firstpos + secondpos -1;
              tmppf = tmppf * (( sumofpos % 2  == 0 ) ? 1 : -1);
              tmp._prefactor = 1;
              tmp.list<SQO<T2>>::erase(it1);
              tmp.list<SQO<T2>>::erase(it2);
              if ( tmp.size() == 0 ) {  tmpresult.fullcontraction = tmpresult.fullcontraction + tmppf; }
              else {
                previouscontractions = previouscontractions + tmp;
                previouscontractions[tmp] = tmppf;
                tmp.normalproduct();
                tmppf = tmppf * tmp._prefactor;
                tmp._prefactor = 1;
                if ( tmpresult.find(tmp) == tmpresult.end() ) { tmpresult[tmp] = tmppf; }
                else { tmpresult[tmp] =  tmpresult[tmp] + tmppf; }
              }
            }
          }
      }
      vector<int> tmplist2 = tmplist;
      for ( int j=i; j<tmplist2.size(); j++) { --tmplist2[j]; }
      tmplist3 = tmplist2;
    }

    for ( typename map< STR<SQO<T2>>, PFSTT<T2>, STRSQOCompare<T2>>::const_iterator it1=previouscontractions.begin(); it1!=previouscontractions.end(); it1++  ) {
      LCSSQO<T2, T2> tmpwick = wickexpansion((*it1).first, ref, tmplist3);
      STR<SQO<T2>> strprevious = (*it1).first;
      strprevious.normalproduct();
      tmpwick.erase( tmpwick.find( strprevious ) );
      tmpresult = tmpresult + (  tmpwick * (*it1).second  )  ;
    }
  }
}
return EquateIfPossible(tmpresult, T1::noreference);
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
      if ( (*it).second.size() == 1  && (*it).second.realnumber == 0 ) {
        if (it == lc.begin() && lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0 ) {}
        else if ((*((*it).second.begin())).second > 0) { o << "+";  }
      }
      else if ( it == lc.begin() && lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0 ) {}
      else {o << "+";}

      o << (*it).second << " \\cdot " ;
    }
    o << (*it).first;
  }
  return o;
}
