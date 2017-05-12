#include "LCSSQO.h"

#include <iostream>
#include <string>

int main() {

  SQO<Elementary>  cp(SQO_Idx_Type::general , SQO_Type::creation, "p");
  SQO<Elementary>  aq(SQO_Idx_Type::general , SQO_Type::annihilation, "q");
  SQO<Elementary>  cr(SQO_Idx_Type::general , SQO_Type::creation, "r");
  SQO<Elementary>  as(SQO_Idx_Type::general , SQO_Type::annihilation, "s");

  STR<SQO<Elementary>> strsqo1({cp,aq,cr,as});
  STR<SQO<Elementary>> strsqo2({cp,cr,aq,as});

  cout << "5*strsqo1  = " << 5*strsqo1 << endl;
  cout << "strsqo1*aq = " << strsqo1*aq << endl;
  cout << "strsqo1*strsqo2 = " << strsqo1*strsqo2 << endl;

}
