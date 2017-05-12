#include "LCSSQO.h"

#include <iostream>
#include <string>

using namespace std;

int  main() {

  TwoTensorSQO<Elementary> tt1(make_pair("p",SQO_Idx_Type::general), make_pair("q",SQO_Idx_Type::general));
  cout << "tt1: " << tt1 << endl;
}
