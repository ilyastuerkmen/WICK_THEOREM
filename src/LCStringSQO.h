#ifndef LCStringSQO_H
#define LCStringSQO_H

#include "StringSQO.h"
#include <map>

  using namespace std;

template<class Formalism>
class LCStringSQO : public map<StringSQO<Formalism>, PrefactorSSQO<Formalism>> {
public:

};



#endif