#ifndef SQO_H
#define SQO_H

#include "SQOEnumClasses.h"
#include <iostream>

  using namespace std;

template<class Formalism>
class SQO {
public:

SQO( SQO_Idx_Type const  &, SQO_Type const &, string const  &) ;
SQO( SQO<Formalism> const &);

string idx;
SQO_Type a;
SQO_Idx_Type idxtype;  

};

template<class Formalism> 
bool operator == ( SQO<Formalism> const &, SQO<Formalism> const & );

template<class Formalism>
ostream & operator << ( ostream & , SQO<Formalism> const & );

#endif



