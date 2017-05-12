#include "LCSSQO.h"

#include <iostream>

  using namespace std;

int main() {

  SQO<Elementary>  cp(SQO_Idx_Type::general , SQO_Type::creation, "p");
  SQO<Elementary>  aq(SQO_Idx_Type::general , SQO_Type::annihilation, "q");
  SQO<Elementary>  cr(SQO_Idx_Type::general , SQO_Type::creation, "r");
  SQO<Elementary>  as(SQO_Idx_Type::general , SQO_Type::annihilation, "s");

  STR<SQO<Elementary>> strsqo1({cp,aq,cr,as});
  STR<SQO<Elementary>> strsqo2({cp,cr,aq,as});

 cout << "strsqo1:                      " << strsqo1 << endl;
 cout << "strsqo2:                      " << strsqo2 << endl;
 cout << "Is strsqo a normal product?:  " << "strsqo1: " << strsqo1.normalordered() << "   " << "strsqo2: " << strsqo2.normalordered() << endl;
 cout << "Is strsqo1 == strsqo2:        " <<  (strsqo1 == strsqo2) << endl;
 strsqo1.normalproduct();
 cout << "Normal product of strsqo1:    " << strsqo1 << endl;
}
