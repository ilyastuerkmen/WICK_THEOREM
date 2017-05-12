#include "LCSSQO.h"

#include <iostream>

  using namespace std;

int main() {

  TwoTensorSQO<Elementary> tt1(make_pair("p",SQO_Idx_Type::general), make_pair("q",SQO_Idx_Type::general));
  TwoTensorSQO<Elementary> tt2(make_pair("r",SQO_Idx_Type::general), make_pair("s",SQO_Idx_Type::general));
  TwoTensorSQO<Elementary> tt3(make_pair("t",SQO_Idx_Type::general), make_pair("u",SQO_Idx_Type::general));

  STR<TwoTensorSQO<Elementary>> strtt1({tt1,tt2,tt3});
  STR<TwoTensorSQO<Elementary>> strtt2({tt2,tt3,tt1});

  cout << "strtt1:                      " <<  strtt1 << endl;
  cout << "strtt2:                      " <<  strtt2 << endl;
  cout << "Is strtt1 == strtt2:         " <<  (strtt1 == strtt2) << endl;
  cout << "tt1*strtt1 = " << tt1*strtt1 << endl;
  cout << "strtt1*strtt2 = " << strtt1*strtt2 << endl; 
}
