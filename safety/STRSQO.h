#ifndef STRSQO_H
#define STRSQO_H

#include "STR.cpp"

  using namespace std;

template<class SQO>
class STRSQO : public STR<SQO> {
public:


void normalproduct();  
bool operator == ( STRSQO<SQO> & );
};

#endif