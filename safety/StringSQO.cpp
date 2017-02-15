#include "StringSQO.h"

template<class Formalism>
StringSQO<Formalism>::StringSQO() 
  : list<SQO<Formalism>>() , _prefactor(1) {}; 

template<class Formalism>
StringSQO<Formalism>::StringSQO( initializer_list<SQO<Formalism>> il)
  : list<SQO<Formalism>>(il), _prefactor(1) {}

template<class Formalism>
StringSQO<Formalism>::StringSQO( StringSQO<Formalism> const & ssqo)
  : list<SQO<Formalism>>(ssqo), _prefactor(ssqo._prefactor) {}

template<class Formalism>
void StringSQO<Formalism>::normalproduct() 
{
  int differencetranspositions = 0;
  int sumtranspositions = 0;
  StringSQO<Formalism> creations;
  StringSQO<Formalism> annihliations;
  SQO_Type previoussqotype ;
  
  for ( typename StringSQO<Formalism>::const_iterator it = (*this).begin(); it != (*this).end(); it++ ) {
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
   
  for ( typename StringSQO<Formalism>::const_iterator it = creations.begin(); it != creations.end(); it++ ) { (*this).push_back(*it); }
  for ( typename StringSQO<Formalism>::const_iterator it = annihliations.begin(); it != annihliations.end(); it++ ) { (*this).push_back(*it); }
    
  
}
  
template<class Formalism> 
bool StringSQO<Formalism>::identical( StringSQO<Formalism> const & s) { 
  if ( (*this).size() != s.size() ) { return false;}
  else {
    bool tmp;
    int count = 0;
    typename StringSQO<Formalism>::const_iterator it1 = (*this).begin();
    typename StringSQO<Formalism>::const_iterator it2 = s.begin();
  
    for ( int i = 0; i< (*this).size() ; i++) {
      if( (*it1) == (*it2) ) { ++count; }
      ++it1;
      ++it2;
    }
    return ( ((*this)._prefactor == s._prefactor) && ( count == (*this).size() )  );
  }
}  

// ********** MAY A FUNCTION NAMED "ALL_EQUAL_STRINGS" WHICH GIVES BACK "EQUAL_STRINGS" **********************
// ***********************************************************************************************************
template<class Formalism> 
bool StringSQO<Formalism>::operator == ( StringSQO<Formalism> & s) { 
  if ( (*this).size() != s.size() ) { return false;}
  else if ( (*this).identical(s) ) { return true;}
  else {
    bool equal(false);
    bool tmpisinequalstrings(false);
    list<StringSQO<Formalism>> equalstrings;
    list<StringSQO<Formalism>> laststrings;
    list<StringSQO<Formalism>> newstrings;
    equalstrings.push_back((*this));
    laststrings.push_back((*this));
    
    while ( laststrings.size() != 0 ) {
      for ( typename  list<StringSQO<Formalism>>::iterator it1=laststrings.begin(); it1!=laststrings.end(); it1++) {
	for ( int positionoffirst=1; positionoffirst<(*it1).size(); positionoffirst++ ) {
	  StringSQO<Formalism> tmp((*it1));
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
	    for (  typename  list<StringSQO<Formalism>>::const_iterator it2=equalstrings.begin(); it2!=equalstrings.end(); it2++ ) {
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
    
    for ( typename  list<StringSQO<Formalism>>::iterator it3=equalstrings.begin(); it3!=equalstrings.end(); it3++) {
      if( s.identical((*it3)) ) { equal = true; break;}
    }
    /*
    cout << "ALL EQUAL STRINGS: " << endl;
    for ( typename  list<StringSQO<Formalism>>::iterator it4=equalstrings.begin(); it4!=equalstrings.end(); it4++) {
      cout << (*it4) << endl;
    }
    */
    return equal;
  } 
}

  

template<class Formalism>
StringSQO<Formalism> operator * (double const & d, StringSQO<Formalism> const & ssqo ) { 
  StringSQO<Formalism> tmp(ssqo);
  tmp._prefactor = d*ssqo._prefactor;
  return tmp;
  
} 
  
template<class Formalism>
StringSQO<Formalism> operator * (StringSQO<Formalism> const & ssqo, double const & d ) { 
  StringSQO<Formalism> tmp(ssqo);
  tmp._prefactor = d*ssqo._prefactor;
  return tmp;
  
}   
    
template<class Formalism> 
StringSQO<Formalism>  operator * ( SQO<Formalism> const & sqo, StringSQO<Formalism> const & ssqo) {
   StringSQO<Formalism> tmp(ssqo);
   tmp.list<SQO<Formalism>>::push_front(sqo);
   return tmp;
}

template<class Formalism> 
StringSQO<Formalism>  operator * ( StringSQO<Formalism> const & ssqo, SQO<Formalism> const & sqo) {
   StringSQO<Formalism> tmp(ssqo);
   tmp.list<SQO<Formalism>>::push_back(sqo);
   return tmp;
}
  
template<class Formalism> 
StringSQO<Formalism>  operator * ( StringSQO<Formalism> const & lssqo, StringSQO<Formalism> const & rssqo) {
  StringSQO<Formalism> tmp(lssqo);
  tmp._prefactor *= rssqo._prefactor;
  for ( typename StringSQO<Formalism>::const_iterator it = rssqo.begin(); it != rssqo.end(); it++ ) {
     tmp.list<SQO<Formalism>>::push_back(*it);
  }
  return tmp;
}


template<class Formalism>
ostream & operator << ( ostream & o, StringSQO<Formalism> const & ssqo ) 
{
  o << ssqo._prefactor ;
  for ( typename StringSQO<Formalism>::const_iterator it = ssqo.begin(); it != ssqo.end(); it++ )
    o << *it ;
  
  return o;
}




template class SQO<ParticleHole>;
template ostream & operator << ( ostream &, StringSQO<ParticleHole> const & );

template class SQO<Elementary>;
template ostream & operator << ( ostream & , StringSQO<Elementary> const & );





