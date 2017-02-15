#include "STRSQO.h"


template<class SQO>
void STRSQO<SQO>::normalproduct() 
{
  int differencetranspositions = 0;
  int sumtranspositions = 0;
  STRSQO<SQO> creations;
  STRSQO<SQO> annihliations;
  SQO_Type previoussqotype ;
  
  for ( typename STRSQO<SQO>::const_iterator it = (*this).begin(); it != (*this).end(); it++ ) {
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
   
  for ( typename STRSQO<SQO>::const_iterator it = creations.begin(); it != creations.end(); it++ ) { (*this).push_back(*it); }
  for ( typename STRSQO<SQO>::const_iterator it = annihliations.begin(); it != annihliations.end(); it++ ) { (*this).push_back(*it); }
    
  
}

// ********** MAY A FUNCTION NAMED "ALL_EQUAL_STRINGS" WHICH GIVES BACK "EQUAL_STRINGS" **********************
// ***********************************************************************************************************
template<class SQO> 
bool STRSQO<SQO>::operator == ( STRSQO<SQO> & s) { 
  if ( (*this).size() != s.size() ) { return false;}
  else if ( (*this).identical(s) ) { return true;}
  else {
    bool equal(false);
    bool tmpisinequalstrings(false);
    list<STRSQO<SQO>> equalstrings;
    list<STRSQO<SQO>> laststrings;
    list<STRSQO<SQO>> newstrings;
    equalstrings.push_back((*this));
    laststrings.push_back((*this));
    
    while ( laststrings.size() != 0 ) {
      for ( typename  list<STRSQO<SQO>>::iterator it1=laststrings.begin(); it1!=laststrings.end(); it1++) {
	for ( int positionoffirst=1; positionoffirst<(*it1).size(); positionoffirst++ ) {
	  STRSQO<SQO> tmp((*it1));
	  typename  list<SQO>::iterator first = tmp.begin();
	  typename  list<SQO>::iterator second = tmp.begin();
	  ++second;
	  for ( int increment=1; increment<positionoffirst; increment++) { ++first; ++second; }
	  if ( ((*first).idxtype == (*second).idxtype) && ((*first).a != (*second).a) ) {}
	  else {
	    SQO pos1((*first));
	    SQO pos2((*second));
	    first = tmp.list<SQO>::erase(first);
            tmp.list<SQO>::insert(first, pos2);
	    second = tmp.list<SQO>::erase(second);
	    tmp.list<SQO>::insert(second, pos1);
	    tmpisinequalstrings = false;
	    for (  typename  list<STRSQO<SQO>>::const_iterator it2=equalstrings.begin(); it2!=equalstrings.end(); it2++ ) {
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
    
    for ( typename  list<STRSQO<SQO>>::iterator it3=equalstrings.begin(); it3!=equalstrings.end(); it3++) {
      if( s.identical((*it3)) ) { equal = true; break;}
    }
    /*
    cout << "ALL EQUAL STRINGS: " << endl;
    for ( typename  list<STRSQO<SQO>>::iterator it4=equalstrings.begin(); it4!=equalstrings.end(); it4++) {
      cout << (*it4) << endl;
    }
    */
    return equal;
  } 
}


