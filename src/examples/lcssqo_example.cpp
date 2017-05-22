#include "LCSSQO.h"

#include <iostream>

  using namespace std;

int main() {

  SQO<Elementary>  cp(SQO_Idx_Type::general , SQO_Type::creation, "p");
  SQO<Elementary>  aq(SQO_Idx_Type::general , SQO_Type::annihilation, "q");
  SQO<Elementary>  cr(SQO_Idx_Type::general , SQO_Type::creation, "r");
  SQO<Elementary>  as(SQO_Idx_Type::general , SQO_Type::annihilation, "s");
  SQO<Elementary>  ap(SQO_Idx_Type::general , SQO_Type::annihilation, "p");
  SQO<Elementary>  cs(SQO_Idx_Type::general , SQO_Type::creation, "s");
  SQO<Elementary>  cq(SQO_Idx_Type::general , SQO_Type::creation, "q");

  STR<SQO<Elementary>> strsqo1({cp,aq,cr,as});
  STR<SQO<Elementary>> strsqo2({cp,cr,aq,as});

  TwoTensorSQO<Elementary> tt1(make_pair("p",SQO_Idx_Type::general), make_pair("q",SQO_Idx_Type::general));
  TwoTensorSQO<Elementary> tt2(make_pair("r",SQO_Idx_Type::general), make_pair("s",SQO_Idx_Type::general));
  TwoTensorSQO<Elementary> tt3(make_pair("t",SQO_Idx_Type::general), make_pair("u",SQO_Idx_Type::general));

  STR<TwoTensorSQO<Elementary>> strtt1({tt1,tt2,tt3});
  STR<TwoTensorSQO<Elementary>> strtt2({tt2,tt3,tt1});
  STR<TwoTensorSQO<Elementary>> strtt3({tt2,tt1});

  PFSTT<Elementary> pfstt1( {strtt1, strtt2} );
  PFSTT<Elementary> pfstt2(pfstt1 + strtt3 + 5.0);

  LCSSQO<Elementary, Elementary> lcssqo1({make_pair(strsqo1,pfstt1), make_pair(strsqo2,pfstt2)});
  LCSSQO<Elementary, Elementary> lcssqo2(wickexpansion(strsqo1, Elementary::vacuum));
  cout << "lcssqo1= " << lcssqo1 << endl;
  cout << "pfstt2+lcssqo1= " << pfstt2+lcssqo1 << endl;
  cout << "lcssqo2=" << lcssqo2 << endl;
  cout << "nonzero(lcssqo2): " << nonzero(lcssqo2) << endl;
  cout << "lcssqo1*lcssqo2= " << lcssqo1*lcssqo2 << endl;
}
