#ifndef STR_H
#define STR_H

#include "SQO.h"
#include "TwoTensorSQO.h"
#include <list>
#include <initializer_list>
  
  using namespace std;

template<class OBJ>
class STR : public list<OBJ> {
public:

STR();
STR( initializer_list<OBJ> );
STR( STR<OBJ> const & );

void normalproduct();
double _prefactor ;
//bool normalproduct;

bool operator == ( STR<OBJ> const & );

private:
bool identical( STR<OBJ> const & ); 

};

template<class OBJ> STR<OBJ>  operator * ( double const &, STR<OBJ> const & );
template<class OBJ> STR<OBJ>  operator * ( STR<OBJ> const &, double const & );
template<class OBJ> STR<OBJ>  operator * ( OBJ const &, STR<OBJ> const & );
template<class OBJ> STR<OBJ>  operator * ( STR<OBJ> const &, OBJ const & );
template<class OBJ> STR<OBJ>  operator * ( STR<OBJ> const & , STR<OBJ> const & );

template<class OBJ>
ostream & operator << ( ostream &, STR<OBJ> const & );



#endif