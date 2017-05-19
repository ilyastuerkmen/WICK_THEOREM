

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
template<class T1, class T2> LCSSQO<T1,T2> LCSSQO<T1,T2>::cleanUpZero() {
   (*this).fullcontraction.cleanUpZero();
   typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::iterator it=(*this).begin();
   while( it!=(*this).end() ) {
      (*it).second.cleanUpZero();
      if ( (*it).second.size() == 0 && (*it).second.realnumber == 0 ) { it = (*this).erase(it); }
      else { it++ ;}
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



template<class T1, class T2, class T3> LCSSQO<T1, T2> LCSSQOToLCSSQO( LCSSQO<T3, T2> const & lcssqo, T1 const & t1) {
  LCSSQO<T1, T2> tmp;
  tmp.fullcontraction = lcssqo.fullcontraction;
  for ( typename map< STR<SQO<T3>>, PFSTT<T2>, STRSQOCompare<T3>>::const_iterator it1=lcssqo.begin(); it1!=lcssqo.end(); it1++ ) {
    tmp.insert( make_pair( STRToSTR((*it1).first, t1) , (*it1).second ));
  }
  return tmp;
}
template<class T1, class T2> LCSSQO<T1, T2> generalizedWickExpansion(STR<SQO<T1>> const & str, T2 const & ref) {
  STR<SQO<T2>> tmpstr(STRToSTR(str, ref));
  LCSSQO<T2, T2>  tmpresult( wickexpansion(tmpstr, ref, PositionOfNextNormalFragment(tmpstr)) );
  return LCSSQOToLCSSQO(tmpresult, T1::noreference);
}
template<class T1, class T2> LCSSQO<T1, T2> wickexpansion(STR<SQO<T1>> const & str, T2 const & ref, vector<int> const & positionslist) {
  LCSSQO<T2, T2> tmpresult;                                                                                                 // ERGEBNIS
  STR<SQO<T2>> tmpstr(STRToSTR(str, ref));                                                                                  // Ursprünglicher STR in STR zur Referenz umwandeln
  if ( tmpstr.normalordered() ) { return LCSSQOToLCSSQO((tmpresult + tmpstr), T1::noreference); }                         // Wenn normalgeordnet zuruckgeben
  vector<int> tmplist = positionslist;
  if ( tmplist.size() == 0 ) { tmplist.push_back(0); tmplist.push_back(str.size());}                                        // Default positionlist wird anfang -> 0; ende -> str.size()
  tmpstr.normalproduct();
  tmpresult = tmpresult + tmpstr;                                                                                           // normalgeordneten STR zum Ergebnis
  list< pair< pair<STR<SQO<T2>>,PFSTT<T2>>  , vector<int> > >   previouscontractions;                                   // list< (TwoTensor,STR) , positionsliste >
  vector<int> tmplist3;
  for ( int i = 1; i<tmplist.size(); i++ ) {                                                       //   STR  012 345 6789
    for ( int firstpos = tmplist[i-1]; firstpos < tmplist[i]; firstpos++ ) {                       //        ^   ^   ^        wobei " ^ " stelle von nächsten normalgeordneten fragment
      for ( int secondpos= ( (tmplist[i] - str.size()) ? tmplist[i] : firstpos+1 ) ; secondpos<str.size(); secondpos++ ) {
        STR<SQO<T2>> tmp(STRToSTR(str, ref));
        typename list<SQO<T2>>::iterator it1 = tmp.begin();                                        //   STR   012 345 6789
        typename list<SQO<T2>>::iterator it2 = tmp.begin();                                        //         ^   ^               iterieren
          for ( int i=0; i<firstpos; i++ ) { ++it1; }                                              //         ^    ^
          for ( int j=0; j<secondpos; j++ ) { ++it2; }                                             //         ^     ^
          if ( (*it1).a == SQO_Type::annihilation && (*it2).a == SQO_Type::creation )              //   Wenn an der ersten Position ein vernichter und an der zweiten ein erzeuger ist
          {
            vector<int> tmplist2;
            tmplist2.push_back(firstpos);
            for ( int j=i; j<tmplist.size(); j++) {
               if ( secondpos < tmplist[j] ) { tmplist2.push_back(tmplist[j]-2); }
               else  {tmplist2.push_back(tmplist[j]-1);}
            }                                                   //  tmplist2 (-1,2,5)             ^ ^   ^                                                                                   //  tmplist2 (0,2,5)   //   STR   012 345 6789
            TwoTensorSQO<T2> tmptt(make_pair((*it1).idx, (*it1).idxtype), make_pair((*it2).idx, (*it2).idxtype));
            STR<TwoTensorSQO<T2>> tmpstrtt({tmptt});
            PFSTT<T2> tmppf({tmpstrtt});                                                          //  TwoTensor vorfaktor
            tmppf = tmppf * tmp._prefactor;                                                       //  STR vorfaktor auf Tensor übertragen
            tmp._prefactor = 1;
            int sumofpos = firstpos + secondpos - 1 ;                                             //  Transpositionen um operatoren nach links zu verschieben. Reihenfolge bleibt (-1).
            tmppf = tmppf * (( sumofpos % 2  == 0 ) ? 1 : -1);                                    //  Vorzeichen der permutation
            tmp.list<SQO<T2>>::erase(it1);                                                        //  ersten sqo aus str löschen
            tmp.list<SQO<T2>>::erase(it2);                                                        //  zweiten sqo aus str löschen
            if ( tmp.size() == 0 ) {  tmpresult.fullcontraction = tmpresult.fullcontraction + tmppf; }                  // STR leer, dass voll kontrahiert
            else {
              previouscontractions.push_back( make_pair(make_pair( tmp, tmppf ), tmplist2 ) );                // tmp nicht normalgeordnet in previous
              tmp.normalproduct();
              tmppf = tmppf * tmp._prefactor;
              tmp._prefactor = 1;
              if ( tmpresult.find(tmp) == tmpresult.end() ) { tmpresult[tmp] = tmppf; }                                 // tmp normalgeordnet in Ergebnis
              else { tmpresult[tmp] =  tmpresult[tmp] + tmppf; }
            }
          }
      }
    }
  } // für alle previous wickexpansion aufrufen und  den jeweiligen str im ergebnis löschen, da sonst doppelt
      for ( typename list< pair<pair<STR<SQO<T2>>,PFSTT<T2>>, vector<int>> >::const_iterator it1=previouscontractions.begin(); it1!=previouscontractions.end(); it1++  ) {
      LCSSQO<T2, T2> tmpwick = wickexpansion( ((*it1).first).first, ref, (*it1).second );
      STR<SQO<T2>> strprevious = ((*it1).first).first;
        strprevious.normalproduct();

        tmpwick.erase( tmpwick.find( strprevious ) );
        tmpresult = tmpresult + ( ((*it1).first).second * tmpwick  )  ;
      }

  return LCSSQOToLCSSQO(tmpresult, T1::noreference);
}



template<class T1, class T2> ostream & operator << ( ostream & o, LCSSQO<T1, T2> const & lc){
/*
  if ( lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0)  {}
  else { o << lc.fullcontraction; }
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    if ((*it).second.size() == 0 ) {
      if ((*it).second.realnumber < 0 ) {
        if ( (*it).second.realnumber == -1 ) { o << " - ";}
        else { o << (*it).second.realnumber; }
      }
      if ( (*it).second.realnumber > 0 ) {
        if (it == lc.begin() && lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0 )  {
          if ( (*it).second.realnumber == 1 ) {}
          else {o << (*it).second.realnumber;}
        }
        else {
          if ((*it).second.realnumber == 1 )  { o << " + " ;}
          else {o << "+" << (*it).second.realnumber;  }
        }
      }
    }
    else {
      if ( (*it).second.size() == 1  && (*it).second.realnumber == 0 ) {
        if (it == lc.begin() && lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0 ) {}
        else if ((*((*it).second.begin())).second >= 0) { o << " + ";  }
      }
      else if ( it == lc.begin() && lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0 ) {}
      else {o << " + ";}

      o << (*it).second << " \\cdot " ;
    }
    o << (*it).first;
  }
*/
//FOR TESTWICK
  if ( lc.fullcontraction.size() == 0 && lc.fullcontraction.realnumber == 0)  {}
  else { o << lc.fullcontraction; }
if ( lc.size() == 1 ) { o << (*lc.begin()).first; }
else {
  for ( typename map< STR<SQO<T1>>, PFSTT<T2>, STRSQOCompare<T1>>::const_iterator it=lc.begin(); it!=lc.end(); it++ ) {
    for ( typename map< STR<TwoTensorSQO<T2>> , double, STRTTCompare<T2> >::const_iterator it2=((*it).second).begin(); it2!=((*it).second).end(); it2++ ) {
     if ( it2==((*lc.begin()).second).begin() ) {
        if ( (*it2).second == -1  ) { o << "-" ;}
        o << (*it2).first << " \\cdot " <<(*it).first ;
     }
     else {
      if ( (*it2).second == 1  ) { o << "+" ;}
      if ( (*it2).second == -1  ) { o << "-" ;}
      o << (*it2).first << " \\cdot " << (*it).first ;
      }
    }

if ( (*it).second.realnumber != 0 ) {
if ( (*it).second.realnumber == 1  )  { o << "+" ;}
if ( (*it).second.realnumber == -1  ) { o << "-" ;}
o << (*it).first ;
  }
}
}


  return o;
}


template<class T1> LCSSQO<T1, ParticleHole> nonzero( LCSSQO<T1, ParticleHole> const & lc) {
LCSSQO<T1, ParticleHole> tmp(lc);

  typename map< STR<TwoTensorSQO<ParticleHole>> , double, STRTTCompare<ParticleHole> >::iterator it4=(tmp.fullcontraction).begin();
  while ( it4 != (tmp.fullcontraction).end() ) {
  bool tmpbool(false);
  typename list<TwoTensorSQO<ParticleHole>>::const_iterator it5= ((*it4).first).begin();
    while ( it5!=((*it4).first).end() )  {
        if ( (*it5).idx1.second ==  (*it5).idx2.second  ) {it5++;}
        else { it4 =  (tmp.fullcontraction).erase(it4); tmpbool = true; break; }
    }
    if ( tmpbool == false ) {it4++;}
  }


  typename map< STR<SQO<T1>>, PFSTT<ParticleHole>, STRSQOCompare<T1>>::iterator it=tmp.begin();
    while (it!=tmp.end() ) {
      typename map< STR<TwoTensorSQO<ParticleHole>> , double, STRTTCompare<ParticleHole> >::iterator it2=((*it).second).begin();
        while ( it2!=((*it).second).end() ) {
        bool tmpbool(false);
          typename list<TwoTensorSQO<ParticleHole>>::const_iterator it3= ((*it2).first).begin();
            while ( it3!=((*it2).first).end() )  {
                if ( (*it3).idx1.second ==  (*it3).idx2.second  ) {it3++;}
                else { it2 =  ((*it).second).erase(it2); tmpbool = true; break; }
            }
            if ( tmpbool == false ) {it2++;}
        }
        if ( (*it).second.size() == 0  &&  (*it).second.size() != (*(lc.find( (*it).first ) )).second.size() ) { it = tmp.erase(it) ;}
        else {it++;}

    }

return tmp;
}
