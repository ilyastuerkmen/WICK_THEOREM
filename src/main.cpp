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


    SQO<Elementary>  p(SQO_Idx_Type::particle, SQO_Type::creation, "i");
    SQO<Elementary> q(SQO_Idx_Type::particle, SQO_Type::creation, "j");
    SQO<Elementary>  p2(SQO_Idx_Type::hole, SQO_Type::creation, "a");
    SQO<Elementary> q2(SQO_Idx_Type::hole, SQO_Type::creation, "b");
    SQO<Elementary> r(SQO_Idx_Type::particle, SQO_Type::annihliation, "i");
    SQO<Elementary> s(SQO_Idx_Type::particle, SQO_Type::annihliation, "j");
    SQO<Elementary> r2(SQO_Idx_Type::hole, SQO_Type::annihliation, "a");
    SQO<Elementary> s2(SQO_Idx_Type::hole, SQO_Type::annihliation, "b");




vector<SQO<Elementary>> strvec;
strvec.push_back(p);
strvec.push_back(p2);
strvec.push_back(q);
strvec.push_back(q2);
strvec.push_back(s);
strvec.push_back(s2);
strvec.push_back(r);
strvec.push_back(r2);

LCSSQO<Elementary, ParticleHole> allwickterms;
    vector< STR<SQO<Elementary>> > veclc;


    for ( int i=0; i<4; i++ ) {
        for ( int j=0; j<4; j++  ) {
            for ( int k=4; k<8; k++ ) {
                for ( int l=4; l<8; l++ ) {
                    STR<SQO<Elementary>> tmp( {strvec[i], strvec[j], strvec[k], strvec[l] } );
                    veclc.push_back(tmp);
                }
            }
        }
    }
    cout << "ALLTERMS: " << endl;

    for ( int i=0; i<veclc.size(); i++) { cout << veclc[i] << endl; }

    for ( int i=0; i<veclc.size(); i++ ) {
        allwickterms = allwickterms + wickexpansion( veclc[i], ParticleHole::fermi );
    }

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "ALLWICKTERM: " << endl;
    cout << allwickterms << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << allwickterms.cleanUpZero() << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "NONZEROWICKTERMS: " << endl;
    cout << nonzero(allwickterms) << endl;


PFSTT<Elementary> pf;
TwoTensorSQO<Elementary> tt1(make_pair("i", SQO_Idx_Type::hole), make_pair("j", SQO_Idx_Type::particle));
TwoTensorSQO<Elementary> tt2(make_pair("a", SQO_Idx_Type::hole), make_pair("b", SQO_Idx_Type::particle));
TwoTensorSQO<Elementary> tt3(make_pair("k", SQO_Idx_Type::hole), make_pair("c", SQO_Idx_Type::particle));

STR<TwoTensorSQO<Elementary>> strtt1({tt1});
STR<TwoTensorSQO<Elementary>> strtt2({tt1, tt2});
STR<TwoTensorSQO<Elementary>> strtt3({tt1, tt2, tt3});
pf = pf + strtt1 + 2*strtt2 + 0*strtt3;

cout << endl;
cout << endl;
cout << endl;
cout << endl;

cout << pf << endl;
cout << pf.cleanUpZero() << endl;
}
