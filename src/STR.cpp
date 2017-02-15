#include "STR.h"

template<class OBJ>
STR<OBJ>::STR() 
  : list<OBJ>() , _prefactor(1) {}; 

template<class OBJ>
STR<OBJ>::STR( initializer_list<OBJ> il)
  : list<OBJ>(il), _prefactor(1) {}

template<class OBJ>
STR<OBJ>::STR( STR<OBJ> const & ssqo)
  : list<OBJ>(ssqo), _prefactor(ssqo._prefactor) {}
  
template<class OBJ> 
bool STR<OBJ>::identical( STR<OBJ> const & s) { 
  if ( (*this).size() != s.size() ) { return false;}
  else {
    bool tmp;
    int count = 0;
    typename STR<OBJ>::const_iterator it1 = (*this).begin();
    typename STR<OBJ>::const_iterator it2 = s.begin();
  
    for ( int i = 0; i< (*this).size() ; i++) {
      if( (*it1) == (*it2) ) { ++count; }
      ++it1;
      ++it2;
    }
    return ( ((*this)._prefactor == s._prefactor) && ( count == (*this).size() )  );
  }
}  

template<class OBJ>
STR<OBJ> operator * (double const & d, STR<OBJ> const & ssqo ) { 
  STR<OBJ> tmp(ssqo);
  tmp._prefactor = d*ssqo._prefactor;
  return tmp;
  
} 
  
template<class OBJ>
STR<OBJ> operator * (STR<OBJ> const & ssqo, double const & d ) { 
  STR<OBJ> tmp(ssqo);
  tmp._prefactor = d*ssqo._prefactor;
  return tmp;
  
}   
    
template<class OBJ> 
STR<OBJ>  operator * ( OBJ const & sqo, STR<OBJ> const & ssqo) {
   STR<OBJ> tmp(ssqo);
   tmp.list<OBJ>::push_front(sqo);
   return tmp;
}

template<class OBJ> 
STR<OBJ>  operator * ( STR<OBJ> const & ssqo, OBJ const & sqo) {
   STR<OBJ> tmp(ssqo);
   tmp.list<OBJ>::push_back(sqo);
   return tmp;
}
  
template<class OBJ> 
STR<OBJ>  operator * ( STR<OBJ> const & lssqo, STR<OBJ> const & rssqo) {
  STR<OBJ> tmp(lssqo);
  tmp._prefactor *= rssqo._prefactor;
  for ( typename STR<OBJ>::const_iterator it = rssqo.begin(); it != rssqo.end(); it++ ) {
     tmp.list<OBJ>::push_back(*it);
  }
  return tmp;
}


template<class OBJ>
ostream & operator << ( ostream & o, STR<OBJ> const & ssqo ) 
{
  o << ssqo._prefactor ;
  for ( typename STR<OBJ>::const_iterator it = ssqo.begin(); it != ssqo.end(); it++ )
    o << *it ;
  
  return o;
}


template<class SQO>
void STR<SQO>::normalproduct() 
{
  int differencetranspositions = 0;
  int sumtranspositions = 0;
  STR<SQO> creations;
  STR<SQO> annihliations;
  SQO_Type previoussqotype ;
  
  for ( typename STR<SQO>::const_iterator it = (*this).begin(); it != (*this).end(); it++ ) {
    if ( (*it).a == SQO_Type::creation ) {
      creations.list<SQO>::push_back(*it);
      sumtranspositions += differencetranspositions ;
    }
    else if ( (*it).a == SQO_Type::annihliation ) {
      annihliations.list<SQO>::push_back(*it);
      differencetranspositions += 1;
    } 
  };
  
  (*this).list<SQO>::clear() ;
  (*this)._prefactor = ( sumtranspositions % 2  == 0 ) ? 1 : -1 ;
   
  for ( typename STR<SQO>::const_iterator it = creations.begin(); it != creations.end(); it++ ) { (*this).push_back(*it); }
  for ( typename STR<SQO>::const_iterator it = annihliations.begin(); it != annihliations.end(); it++ ) { (*this).push_back(*it); }
    
  
}

// ********** MAY A FUNCTION NAMED "ALL_EQUAL_STRINGS" WHICH GIVES BACK "EQUAL_STRINGS" **********************
// ***********************************************************************************************************


template<>
inline bool STR<SQO<Elementary>>::operator == ( STR<SQO<Elementary>> const & s) { 
  if ( (*this).size() != s.size() ) { return false;}
  else if ( (*this).identical(s) ) { return true;}
  else {
    bool equal(false);
    bool tmpisinequalstrings(false);
    list<STR<SQO<Elementary>>> equalstrings;
    list<STR<SQO<Elementary>>> laststrings;
    list<STR<SQO<Elementary>>> newstrings;
    equalstrings.push_back((*this));
    laststrings.push_back((*this));
    
    while ( laststrings.size() != 0 ) {
      for ( typename  list<STR<SQO<Elementary>>>::iterator it1=laststrings.begin(); it1!=laststrings.end(); it1++) {
	for ( int positionoffirst=1; positionoffirst<(*it1).size(); positionoffirst++ ) {
	  STR<SQO<Elementary>> tmp((*it1));
	  typename  list<SQO<Elementary>>::iterator first = tmp.begin();
	  typename  list<SQO<Elementary>>::iterator second = tmp.begin();
	  ++second;
	  for ( int increment=1; increment<positionoffirst; increment++) { ++first; ++second; }
	  if ( ((*first).idxtype == (*second).idxtype) && ((*first).a != (*second).a) ) {}
	  else {
	    SQO<Elementary> pos1((*first));
	    SQO<Elementary> pos2((*second));
	    first = tmp.list<SQO<Elementary>>::erase(first);
            tmp.list<SQO<Elementary>>::insert(first, pos2);
	    second = tmp.list<SQO<Elementary>>::erase(second);
	    tmp.list<SQO<Elementary>>::insert(second, pos1);
	    tmpisinequalstrings = false;
	    for (  typename  list<STR<SQO<Elementary>>>::const_iterator it2=equalstrings.begin(); it2!=equalstrings.end(); it2++ ) {
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
    
    for ( typename  list<STR<SQO<Elementary>>>::iterator it3=equalstrings.begin(); it3!=equalstrings.end(); it3++) {
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


template<>
inline bool STR<SQO<ParticleHole>>::operator == ( STR<SQO<ParticleHole>> const & s) { 
  if ( (*this).size() != s.size() ) { return false;}
  else if ( (*this).identical(s) ) { return true;}
  else {
    bool equal(false);
    bool tmpisinequalstrings(false);
    list<STR<SQO<ParticleHole>>> equalstrings;
    list<STR<SQO<ParticleHole>>> laststrings;
    list<STR<SQO<ParticleHole>>> newstrings;
    equalstrings.push_back((*this));
    laststrings.push_back((*this));
    
    while ( laststrings.size() != 0 ) {
      for ( typename  list<STR<SQO<ParticleHole>>>::iterator it1=laststrings.begin(); it1!=laststrings.end(); it1++) {
	for ( int positionoffirst=1; positionoffirst<(*it1).size(); positionoffirst++ ) {
	  STR<SQO<ParticleHole>> tmp((*it1));
	  typename  list<SQO<ParticleHole>>::iterator first = tmp.begin();
	  typename  list<SQO<ParticleHole>>::iterator second = tmp.begin();
	  ++second;
	  for ( int increment=1; increment<positionoffirst; increment++) { ++first; ++second; }
	  if ( ((*first).idxtype == (*second).idxtype) && ((*first).a != (*second).a) ) {}
	  else {
	    SQO<ParticleHole> pos1((*first));
	    SQO<ParticleHole> pos2((*second));
	    first = tmp.list<SQO<ParticleHole>>::erase(first);
            tmp.list<SQO<ParticleHole>>::insert(first, pos2);
	    second = tmp.list<SQO<ParticleHole>>::erase(second);
	    tmp.list<SQO<ParticleHole>>::insert(second, pos1);
	    tmpisinequalstrings = false;
	    for (  typename  list<STR<SQO<ParticleHole>>>::const_iterator it2=equalstrings.begin(); it2!=equalstrings.end(); it2++ ) {
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
    
    for ( typename  list<STR<SQO<ParticleHole>>>::iterator it3=equalstrings.begin(); it3!=equalstrings.end(); it3++) {
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


template<>
inline bool STR<TwoTensorSQO<Elementary>>::operator == ( STR<TwoTensorSQO<Elementary>> const & s ) { 
  if ( (*this)._prefactor == (s._prefactor) ) {
    STR<TwoTensorSQO<Elementary>> tmp1((*this));
    STR<TwoTensorSQO<Elementary>> tmp2(s);
    int count = 0;
  
    typename list<TwoTensorSQO<Elementary>>::iterator it1;
  
    while ( it1!=tmp1.end() ) {
      count = 0;
      it1 = tmp1.begin();
      for ( typename list<TwoTensorSQO<Elementary>>::iterator it2=tmp2.begin(); it2!=tmp2.end(); it2++ ) {
	if ( (*it1) == (*it2) ) { 
	  tmp1.list<TwoTensorSQO<Elementary>>::erase(it1);
	  tmp2.list<TwoTensorSQO<Elementary>>::erase(it2);
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

template<>
inline bool STR<TwoTensorSQO<ParticleHole>>::operator == ( STR<TwoTensorSQO<ParticleHole>> const & s ) { 
  if ( (*this)._prefactor == (s._prefactor) ) {
    STR<TwoTensorSQO<ParticleHole>> tmp1((*this));
    STR<TwoTensorSQO<ParticleHole>> tmp2(s);
    int count = 0;
  
    typename list<TwoTensorSQO<ParticleHole>>::iterator it1;
  
    while ( it1!=tmp1.end() ) {
      count = 0;
      it1 = tmp1.begin();
      for ( typename list<TwoTensorSQO<ParticleHole>>::iterator it2=tmp2.begin(); it2!=tmp2.end(); it2++ ) {
	if ( (*it1) == (*it2) ) { 
	  tmp1.list<TwoTensorSQO<ParticleHole>>::erase(it1);
	  tmp2.list<TwoTensorSQO<ParticleHole>>::erase(it2);
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




