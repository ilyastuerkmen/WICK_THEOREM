#include "LCSSQO.h"

#include <iostream>

  using namespace std;

int main() {

AntisymmetricTwoParticleOperatorExpectationValue i1("a","j","i","b");
AntisymmetricTwoParticleOperatorExpectationValue i2("b","i","a","j");

cout << "i1 = " << i1 << endl;
cout << "i2 = " << i2 << endl;
NParticleAntisymmetricTwoParticleOperatorExpectationValue<Elementary> npi;
npi.push_back(i1, STR<TwoTensorSQO<Elementary>>());
npi.push_back(i2, STR<TwoTensorSQO<Elementary>>());

cout << "npi = " << npi << endl;

}
