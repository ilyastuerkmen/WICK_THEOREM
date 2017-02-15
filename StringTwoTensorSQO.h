#ifndef StringTwoTensorSQO_H
#define StringTwoTensorSQO_H

#include "TwoTensorSQO.h"
#include <initializer_list>

  using namespace std;
  
template<class TwoTensorSQO>
class  StringTwoTensorSQO : list<TwoTensorSQO> {
public:

StringTwoTensorSQO();
StringTwoTensorSQO( initializer_list<TwoTensorSQO> );
StringTwoTensorSQO( StringTwoTensorSQO<TwoTensorSQO> const & );

double _prefactor;
bool operator == ( StringTwoTensorSQO<TwoTensorSQO> const & );

}

template<class TwoTensorSQO> StringSQO<TwoTensorSQO>  operator * ( double const &, StringTwoTensorSQO<TwoTensorSQO> const & );
template<class TwoTensorSQO> StringSQO<TwoTensorSQO>  operator * ( StringTwoTensorSQO<TwoTensorSQO> const &, double const & );
template<class TwoTensorSQO> StringSQO<TwoTensorSQO>  operator * ( TwoTensorSQO<TwoTensorSQO> const &, StringTwoTensorSQO<TwoTensorSQO> const & );
template<class TwoTensorSQO> StringSQO<TwoTensorSQO>  operator * ( StringTwoTensorSQO<TwoTensorSQO> const &, TwoTensorSQO<TwoTensorSQO> const & );
template<class TwoTensorSQO> StringSQO<TwoTensorSQO>  operator * ( StringTwoTensorSQO<TwoTensorSQO> const & , StringTwoTensorSQO<TwoTensorSQO> const & );

template<class TwoTensorSQO>
ostream & operator << ( ostream &, StringSQO<TwoTensorSQO> const & );







#endif