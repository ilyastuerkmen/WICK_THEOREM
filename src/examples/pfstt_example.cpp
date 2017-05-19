#include "LCSSQO.h"

#include <iostream>

int main() {

  TwoTensorSQO<Elementary> tt1(make_pair("p",SQO_Idx_Type::general), make_pair("q",SQO_Idx_Type::general));
  TwoTensorSQO<Elementary> tt2(make_pair("r",SQO_Idx_Type::general), make_pair("s",SQO_Idx_Type::general));
  TwoTensorSQO<Elementary> tt3(make_pair("t",SQO_Idx_Type::general), make_pair("u",SQO_Idx_Type::general));

  STR<TwoTensorSQO<Elementary>> strtt1({tt1,tt2,tt3});
  STR<TwoTensorSQO<Elementary>> strtt2({tt2,tt3,tt1});

  STR<TwoTensorSQO<Elementary>> strtt3({tt2,tt1});
  PFSTT<Elementary> pfstt1( {strtt1, strtt2} );
  PFSTT<Elementary> pfstt2(pfstt1 + strtt3 + 5.0);

  cout << "pfstt1= " << pfstt1 << endl;
  cout << "pfstt2= " << pfstt2 << endl;
  pfstt1 = (-3.0)*(pfstt1+strtt3);
  cout << "pfstt1= " << pfstt1 << endl;
  cout << "pfstt1 + pfstt2 = " << pfstt1 + pfstt1 << endl;
  cout << "pfstt1 * strtt2 = " << pfstt1 * strtt2 << endl;
  cout << "pfstt1 * pfstt2 = " << pfstt1 * pfstt2 << endl;

}
