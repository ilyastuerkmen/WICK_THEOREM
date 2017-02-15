#ifndef StringSQO_H
#define StringSQO_H

#include "SQO.h"
#include <list>
#include <initializer_list>
  
  using namespace std;

template<class Formalism>
class StringSQO : public list<SQO<Formalism>> {
public:

StringSQO();
StringSQO( initializer_list<SQO<Formalism>> );
StringSQO( StringSQO<Formalism> const & );

void normalproduct();
double _prefactor ;
//bool normalproduct;

bool operator == ( StringSQO<Formalism> & );

private:
bool identical( StringSQO<Formalism> const & ); 

};

template<class Formalism> StringSQO<Formalism>  operator * ( double const &, StringSQO<Formalism> const & );
template<class Formalism> StringSQO<Formalism>  operator * ( StringSQO<Formalism> const &, double const & );
template<class Formalism> StringSQO<Formalism>  operator * ( SQO<Formalism> const &, StringSQO<Formalism> const & );
template<class Formalism> StringSQO<Formalism>  operator * ( StringSQO<Formalism> const &, SQO<Formalism> const & );
template<class Formalism> StringSQO<Formalism>  operator * ( StringSQO<Formalism> const & , StringSQO<Formalism> const & );

template<class Formalism>
ostream & operator << ( ostream &, StringSQO<Formalism> const & );



#endif