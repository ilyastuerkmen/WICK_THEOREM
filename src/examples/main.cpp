//#include "StringSQO.cpp"

#include "LCSSQO.h"

#include <iostream>
#include <string>

using namespace std;

int  main() {
/*
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
SQO<Elementary>  t(SQO_Idx_Type::particle, SQO_Type::creation, "t");
SQO<Elementary> u(SQO_Idx_Type::particle, SQO_Type::annihliation, "u");
SQO<Elementary> v(SQO_Idx_Type::particle, SQO_Type::creation, "v");
SQO<Elementary> w(SQO_Idx_Type::particle, SQO_Type::annihliation, "w");

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
LCSSQO<Elementary, Elementary> lcssqo2(generalizedWickExpansion(twobodyop2, Elementary::vacuum));
cout << lcssqo2 << endl;

cout << "$$" << op1 << "$$" << endl;
LCSSQO<ParticleHole, ParticleHole> lcssqo3(wickexpansion(op1, ParticleHole::fermi));
cout << lcssqo3 << endl;
*/


    //pqrs
    SQO<ParticleHole>  p(SQO_Idx_Type::particle, SQO_Type::creation, "i");
    SQO<ParticleHole> q(SQO_Idx_Type::particle, SQO_Type::creation, "j");
    SQO<ParticleHole> r(SQO_Idx_Type::particle, SQO_Type::annihliation, "k");
    SQO<ParticleHole> s(SQO_Idx_Type::particle, SQO_Type::annihliation, "l");
    
    SQO<ParticleHole>  p2(SQO_Idx_Type::hole, SQO_Type::creation, "a");
    SQO<ParticleHole> q2(SQO_Idx_Type::hole, SQO_Type::creation, "b");
    SQO<ParticleHole> r2(SQO_Idx_Type::hole, SQO_Type::annihliation, "c");
    SQO<ParticleHole> s2(SQO_Idx_Type::hole, SQO_Type::annihliation, "d");
    
    
    
    
    
    
vector<SQO<Elementary>> strvec;
strvec.push_back(p);
strvec.push_back(q);
strvec.push_back(r);
strvec.push_back(s);
strvec.push_back(p2);
strvec.push_back(q2);
strvec.push_back(r2);
strvec.push_back(s2);



    

}
