#ifndef PF_H
#define PF_H

#include "STR.h"
#include <map>
#include <initializer_list>

  using namespace std;

template<class STR>
class PF : map<STR, double> {
public:

PF();
PF( initializer_list<STR> );
PF( PF<STR> const & );


};


#endif
