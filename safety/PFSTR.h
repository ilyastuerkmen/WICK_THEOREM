#ifndef PFSTR_H
#define PFSTR_H

#include "STR.h"
#include <map>
#include <initializer_list>

  using namespace std;

template<class STR>
class PFSTR : map<STR, double> {
public:

PFSTR();
PFSTR( initializer_list<STR> );
PFSTR( PFSTR<STR> const & );

  
};


#endif 