#include "STR.h"

template<class T> STRBase<T>::STRBase() : list<T>() , _prefactor(1) {};
template<class T> STRBase<T>::STRBase( initializer_list<T> il) : list<T>(il), _prefactor(1) {}
template<class T> STRBase<T>::STRBase( STRBase<T> const & ssqo) : list<T>(ssqo), _prefactor(ssqo._prefactor) {}
template<class T> bool STRBase<T>::identical( STRBase<T> const & s) {
  if ( (*this).size() != s.size() ) { return false;}
  else {
    bool tmp;
    int count = 0;
    typename STRBase<T>::const_iterator it1 = (*this).begin();
    typename STRBase<T>::const_iterator it2 = s.begin();

    for ( int i = 0; i< (*this).size() ; i++) {
      if( (*it1) == (*it2) ) { ++count; }
      ++it1;
      ++it2;
    }
    return ( ((*this)._prefactor == s._prefactor) && ( count == (*this).size() )  );
  }
}
template<class T> bool STRBase<T>::identical( STRBase<T> const & s) {
  if ( (*this).size() != s.size() ) { return false;}
  else {
    bool tmp;
    int count = 0;
    typename STRBase<T>::const_iterator it1 = (*this).begin();
    typename STRBase<T>::const_iterator it2 = s.begin();

    for ( int i = 0; i< (*this).size() ; i++) {
      if( (*it1) == (*it2) ) { ++count; }
      ++it1;
      ++it2;
    }
    return ( ((*this)._prefactor == s._prefactor) && ( count == (*this).size() )  );
  }
}
template<class T> STR<T> operator * (double const & d, STR<T> const & ssqo ) {
  STR<T> tmp(ssqo);
  tmp._prefactor = d*ssqo._prefactor;
  return tmp;
}
template<class T> STR<T> operator * (STR<T> const & ssqo, double const & d ) {
  STR<T> tmp(ssqo);
  tmp._prefactor = d*ssqo._prefactor;
  return tmp;

}
template<class T> STR<T>  operator * ( T const & sqo, STR<T> const & ssqo) {
   STR<T> tmp(ssqo);
   tmp.list<T>::push_front(sqo);
   return tmp;
}
template<class T> STR<T>  operator * ( STR<T> const & ssqo, T const & sqo) {
   STR<T> tmp(ssqo);
   tmp.list<T>::push_back(sqo);
   return tmp;
}
template<class T> STR<T>  operator * ( STR<T> const & lssqo, STR<T> const & rssqo) {
  STR<T> tmp(lssqo);
  tmp._prefactor *= rssqo._prefactor;
  for ( typename STR<T>::const_iterator it = rssqo.begin(); it != rssqo.end(); it++ ) {
     tmp.list<T>::push_back(*it);
  }
  return tmp;
}
template<class T> ostream & operator << ( ostream & o, STR<T> const & ssqo ){
  o << ssqo._prefactor ;
  for ( typename STR<T>::const_iterator it = ssqo.begin(); it != ssqo.end(); it++ )
    o << *it ;

  return o;
}

template<class Formalism> STR<SQO<Formalism>>::STR(): STRBase<SQO<Formalism>>() {};
template<class Formalism> STR<SQO<Formalism>>::STR( initializer_list<SQO<Formalism>> il) : STRBase<SQO<Formalism>>(il) {}
template<class Formalism> STR<SQO<Formalism>>::STR( STR<SQO<Formalism>> const & st) : STRBase<SQO<Formalism>>(st) {}
template<class Formalism> void STR<SQO<Formalism>>::normalproduct() {
  int differencetranspositions = 0;
  int sumtranspositions = 0;
  STR<SQO<Formalism>> creations;
  STR<SQO<Formalism>> annihliations;
  SQO_Type previoussqotype ;

  for ( typename list<SQO<Formalism>>::const_iterator it = (*this).begin(); it != (*this).end(); it++ ) {
    if ( (*it).a == SQO_Type::creation ) {
      creations.list<SQO<Formalism>>::push_back(*it);
      sumtranspositions += differencetranspositions ;
    }
    else if ( (*it).a == SQO_Type::annihliation ) {
      annihliations.list<SQO<Formalism>>::push_back(*it);
      differencetranspositions += 1;
    }
  };

  (*this).list<SQO<Formalism>>::clear() ;
  (*this)._prefactor = ( sumtranspositions % 2  == 0 ) ? 1 : -1 ;

  for ( typename list<SQO<Formalism>>::const_iterator it = creations.begin(); it != creations.end(); it++ ) { (*this).push_back(*it); }
  for ( typename list<SQO<Formalism>>::const_iterator it = annihliations.begin(); it != annihliations.end(); it++ ) { (*this).push_back(*it); }


}
template<class Formalism> bool STR<SQO<Formalism>>::operator == ( STR<SQO<Formalism>> const & s) {
  if ( (*this).size() != s.size() ) { return false;}
  else if ( (*this).identical(s) ) { return true;}
  else {
    bool equal(false);
    bool tmpisinequalstrings(false);
    list<STR<SQO<Formalism>>> equalstrings;
    list<STR<SQO<Formalism>>> laststrings;
    list<STR<SQO<Formalism>>> newstrings;
    equalstrings.push_back((*this));
    laststrings.push_back((*this));

    while ( laststrings.size() != 0 ) {
      for ( typename  list<STR<SQO<Formalism>>>::iterator it1=laststrings.begin(); it1!=laststrings.end(); it1++) {
	for ( int positionoffirst=1; positionoffirst<(*it1).size(); positionoffirst++ ) {
	  STR<SQO<Formalism>> tmp((*it1));
	  typename  list<SQO<Formalism>>::iterator first = tmp.begin();
	  typename  list<SQO<Formalism>>::iterator second = tmp.begin();
	  ++second;
	  for ( int increment=1; increment<positionoffirst; increment++) { ++first; ++second; }
	  if ( ((*first).idxtype == (*second).idxtype) && ((*first).a != (*second).a) ) {}
	  else {
	    SQO<Formalism> pos1((*first));
	    SQO<Formalism> pos2((*second));
	    first = tmp.list<SQO<Formalism>>::erase(first);
            tmp.list<SQO<Formalism>>::insert(first, pos2);
	    second = tmp.list<SQO<Formalism>>::erase(second);
	    tmp.list<SQO<Formalism>>::insert(second, pos1);
	    tmpisinequalstrings = false;
	    for (  typename  list<STR<SQO<Formalism>>>::const_iterator it2=equalstrings.begin(); it2!=equalstrings.end(); it2++ ) {
	      if ( tmp.identical((*it2)) ) { tmpisinequalstrings = true; break; }
	    }
	    if( tmpisinequalstrings == false ) {
	      equalstrings.push_back(tmp);
	      newstrings.push_back(tmp);
	    }
	  }
	}
      }
      laststrings.clear();
      laststrings.swap(newstrings);
    }

    for ( typename  list<STR<SQO<Formalism>>>::iterator it3=equalstrings.begin(); it3!=equalstrings.end(); it3++) {
      if( (*it3).identical(s) ) { equal = true; break;}
    }
    /*
    cout << "ALL EQUAL STRINGS: " << endl;
    for ( typename  list<STR<SQO>>::iterator it4=equalstrings.begin(); it4!=equalstrings.end(); it4++) {
      cout << (*it4) << endl;
    }
    */
    return equal;
  }
}

template<class Formalism> STR<TwoTensorSQO<Formalism>>::STR() : STRBase<TwoTensorSQO<Formalism>>() {};
template<class Formalism> STR<TwoTensorSQO<Formalism>>::STR( initializer_list<TwoTensorSQO<Formalism>> il) : STRBase<TwoTensorSQO<Formalism>>(il) {}
template<class Formalism> STR<TwoTensorSQO<Formalism>>::STR( STR<TwoTensorSQO<Formalism>> const & st) : STRBase<TwoTensorSQO<Formalism>>(st) {}
template<class Formalism> bool STR<TwoTensorSQO<Formalism>>::operator == ( STR<TwoTensorSQO<Formalism>> const & s ) {
  if ( (*this)._prefactor == (s._prefactor) ) {
    STR<TwoTensorSQO<Formalism>> tmp1((*this));
    STR<TwoTensorSQO<Formalism>> tmp2(s);
    int count = 0;

    typename list<TwoTensorSQO<Formalism>>::iterator it1;

    while ( it1!=tmp1.end() ) {
      count = 0;
      it1 = tmp1.begin();
      for ( typename list<TwoTensorSQO<Formalism>>::iterator it2=tmp2.begin(); it2!=tmp2.end(); it2++ ) {
	if ( (*it1) == (*it2) ) {
	  tmp1.list<TwoTensorSQO<Formalism>>::erase(it1);
	  tmp2.list<TwoTensorSQO<Formalism>>::erase(it2);
	  ++count;
	  break;
	}
      }
      if ( count == 0 ) { return false; }
    }
    return true;
  }
  else { return false;}
}

// ********** MAY A FUNCTION NAMED "ALL_EQUAL_STRINGS" WHICH GIVES BACK "EQUAL_STRINGS" **********************
// ***********************************************************************************************************
