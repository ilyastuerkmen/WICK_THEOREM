#ifndef STR_H
#define STR_H

#include "SQO.h"
#include "TwoTensorSQO.h"
#include <list>
#include <initializer_list>

  using namespace std;

template<class T> class STRBase : public list<T> {
public:
  STRBase();
  STRBase( initializer_list<T> );
  STRBase( STRBase<T> const & );
  double _prefactor ;
  bool identical( STRBase<T> const & );
};

template<class T> class STR {};

template<class Formalism>class STR<SQO<Formalism>> : public STRBase<SQO<Formalism>> {
public:
  STR<SQO<Formalism>>();
  STR<SQO<Formalism>>( initializer_list<SQO<Formalism>> );
  STR(STR<SQO<Formalism>> const &);
  void normalproduct();
  bool operator == ( STR<SQO<Formalism>> const & );
};

template<class Formalism> class STR<TwoTensorSQO<Formalism>> : public STRBase<TwoTensorSQO<Formalism>>{
public:
  STR<TwoTensorSQO<Formalism>>();
  STR<TwoTensorSQO<Formalism>>( initializer_list<TwoTensorSQO<Formalism>> );
  STR(STR<TwoTensorSQO<Formalism>> const &);
  bool operator == ( STR<TwoTensorSQO<Formalism>> const & );
};

template<class T> STR<T>  operator * ( double const &, STR<T> const & );
template<class T> STR<T>  operator * ( STR<T> const &, double const & );
template<class T> STR<T>  operator * ( T const &, STR<T> const & );
template<class T> STR<T>  operator * ( STR<T> const &, T const & );
template<class T> STR<T>  operator * ( STR<T> const & , STR<T> const & );

template<class T> ostream & operator << ( ostream &, STR<T> const & );

#endif
