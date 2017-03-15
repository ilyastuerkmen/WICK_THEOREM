//#include "StringSQO.cpp"

#include "LCSSQO.h"

#include <iostream>
#include <string>

using namespace std;

int  main() {

SQO<ParticleHole>  i(SQO_Idx_Type::particle, SQO_Type::creation, "i");
SQO<ParticleHole>  i2(SQO_Idx_Type::particle, SQO_Type::annihliation, "i");
SQO<ParticleHole> a2(SQO_Idx_Type::hole, SQO_Type::annihliation, "a");
SQO<ParticleHole> a(SQO_Idx_Type::hole, SQO_Type::creation, "a");
SQO<ParticleHole> j2(SQO_Idx_Type::particle, SQO_Type::annihliation, "j");
SQO<ParticleHole> j(SQO_Idx_Type::particle, SQO_Type::creation, "j");
SQO<ParticleHole> b(SQO_Idx_Type::hole, SQO_Type::creation, "b");
SQO<ParticleHole> b2(SQO_Idx_Type::hole, SQO_Type::annihliation, "b");

//pqrs
SQO<Elementary>  p(SQO_Idx_Type::particle, SQO_Type::creation, "p");
SQO<Elementary> q(SQO_Idx_Type::particle, SQO_Type::creation, "q");
SQO<Elementary> r(SQO_Idx_Type::particle, SQO_Type::annihliation, "r");
SQO<Elementary> s(SQO_Idx_Type::particle, SQO_Type::annihliation, "s");

SQO<Elementary>  p2tmp(SQO_Idx_Type::particle, SQO_Type::creation, "p");
SQO<Elementary> r2tmp(SQO_Idx_Type::particle, SQO_Type::creation, "r");
SQO<Elementary> q2tmp(SQO_Idx_Type::particle, SQO_Type::annihliation, "q");
SQO<Elementary> s2tmp(SQO_Idx_Type::particle, SQO_Type::annihliation, "s");




STR<SQO<ParticleHole>> op1({a2,i,b,j2});
STR<SQO<Elementary>> twobodyop({p,q,s,r});
STR<SQO<Elementary>> twobodyop2({q2tmp,s2tmp,p2tmp,r2tmp});
STR<SQO<Elementary>> twobodyop3({q2tmp,p,r2tmp,s2tmp});



cout << "$$" << twobodyop2 << "$$" << endl;
LCSSQO<Elementary, Elementary> lcssqo(wickexpansion(twobodyop2, Elementary::vacuum));
cout << lcssqo << endl;

//cout << "$$" << op1 << "$$" << endl;
//LCSSQO<ParticleHole, Elementary> lcssqo2(wickexpansion(op1, Elementary::fermi));
//cout << lcssqo2 << endl;


}
