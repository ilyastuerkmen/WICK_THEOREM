//#include "StringSQO.cpp"

#include "LCSSQO.h"

#include <iostream>
#include <string>

using namespace std;

int  main() {

SQO<ParticleHole>  a(SQO_Idx_Type::particle, SQO_Type::creation, "a");
SQO<ParticleHole> b(SQO_Idx_Type::hole, SQO_Type::annihliation, "i");
SQO<ParticleHole> c(SQO_Idx_Type::particle, SQO_Type::annihliation, "b");
SQO<ParticleHole> d(SQO_Idx_Type::hole, SQO_Type::creation, "j");
SQO<ParticleHole>  a2(SQO_Idx_Type::hole, SQO_Type::creation, "i");
SQO<ParticleHole> b2(SQO_Idx_Type::hole, SQO_Type::annihliation, "j");
SQO<ParticleHole> c2(SQO_Idx_Type::particle, SQO_Type::annihliation, "a");
SQO<ParticleHole> d2(SQO_Idx_Type::particle, SQO_Type::annihliation, "b");

//pqrs
SQO<Elementary>  p(SQO_Idx_Type::particle, SQO_Type::creation, "p");
SQO<Elementary> q(SQO_Idx_Type::particle, SQO_Type::creation, "q");
SQO<Elementary> r(SQO_Idx_Type::particle, SQO_Type::annihliation, "r");
SQO<Elementary> s(SQO_Idx_Type::particle, SQO_Type::annihliation, "s");

SQO<Elementary>  p2tmp(SQO_Idx_Type::particle, SQO_Type::creation, "p");
SQO<Elementary> r2tmp(SQO_Idx_Type::particle, SQO_Type::creation, "r");
SQO<Elementary> q2tmp(SQO_Idx_Type::particle, SQO_Type::annihliation, "q");
SQO<Elementary> s2tmp(SQO_Idx_Type::particle, SQO_Type::annihliation, "s");


STR<SQO<Elementary>> twobodyop({p,q,s,r});
STR<SQO<Elementary>> twobodyop2({q2tmp,s2tmp,p2tmp,r2tmp});
STR<SQO<Elementary>> twobodyop3({q2tmp,p,r2tmp,s2tmp});



STR<SQO<ParticleHole>> s1({a,b});
STR<SQO<ParticleHole>> s2({a,b,c,a,d});
STR<SQO<ParticleHole>> s3({a,c,b,a,d});
STR<SQO<ParticleHole>> s4({a2,b2,c2,d2});
STR<SQO<ParticleHole>> s5({b2,a2,c2,d2});

pair<string, SQO_Idx_Type> p1( a2.idx , a2.idxtype );
pair<string, SQO_Idx_Type> p2( b2.idx , b2.idxtype );
pair<string, SQO_Idx_Type> p3( c2.idx , d2.idxtype );
pair<string, SQO_Idx_Type> p4( d2.idx , c2.idxtype );

TwoTensorSQO<ParticleHole> ttsqo1(p1,p2);
TwoTensorSQO<ParticleHole> ttsqo2(p2,p1);
TwoTensorSQO<ParticleHole> ttsqo4(p3,p2);
TwoTensorSQO<ParticleHole> ttsqo5(p4,p3);

pair<string, SQO_Idx_Type> e1( q.idx , q.idxtype );
pair<string, SQO_Idx_Type> e2( p.idx , p.idxtype );
pair<string, SQO_Idx_Type> e3( s.idx , s.idxtype );
pair<string, SQO_Idx_Type> e4( r.idx , r.idxtype );
TwoTensorSQO<Elementary> tte1(e1,e2);
TwoTensorSQO<Elementary> tte2(e3,e4);
TwoTensorSQO<Elementary> tte3(e1,e4);
TwoTensorSQO<Elementary> tte4(e3,e2);

STR<TwoTensorSQO<Elementary>> se1({tte1, tte2});
STR<TwoTensorSQO<Elementary>> se2({tte3, tte4});

PFSTT<Elementary> pe1({se1});
PFSTT<Elementary> pe2({se2});

//cout << pe1 << endl;
//cout << pe2 << endl;
//cout <<  pe2 + pe1 << endl;

STR<TwoTensorSQO<ParticleHole>> s6({ttsqo1, ttsqo2});
STR<TwoTensorSQO<ParticleHole>> s7({ttsqo2, ttsqo1});
STR<TwoTensorSQO<ParticleHole>> s8({ttsqo4, ttsqo1, ttsqo2});
STR<TwoTensorSQO<ParticleHole>> s9({ttsqo2, ttsqo5, ttsqo1, ttsqo4});


PFSTT<ParticleHole> pf1({s6,s7});
PFSTT<ParticleHole> pf2({s6,s7}, 3 );
PFSTT<ParticleHole> pf3({s6,s7,s8,s9,s7,s6}, 7 );

pair<STR<SQO<ParticleHole>>, PFSTT<ParticleHole>> pa1(make_pair(s4, pf3));
pair<STR<SQO<ParticleHole>>, PFSTT<ParticleHole>> pa2(make_pair(s5, pf2));

LCSSQO<ParticleHole> lc1({pa1,pa2});

//cout << "HALLO: " << s2 << endl;
//LCSSQO<ParticleHole> lc2 = wickexpansion(s1);
/*
LCSSQO<ParticleHole> lc3 = wickexpansion(s2);
LCSSQO<ParticleHole> lc4 = wickexpansion(s4);
LCSSQO<ParticleHole> lc5 = wickexpansion(s5);
//cout << lc2 << endl;

cout << "$$" << s2 << "$$" <<  endl;
cout << "$$" << lc3 << "$$" <<  endl;

cout << "$$" << s4 << "$$" <<  endl;
cout << "$$" << lc3 << "$$" <<  endl;

cout << "$$" << s5 << "$$" <<  endl;
cout << "$$" << lc3 << "$$" <<  endl;
*/
//STR<SQO<ParticleHole>> s21 = s2 * c2;
//STR<SQO<ParticleHole>> s22 = s21*b;


//LCSSQO<Elementary> lc6 = wickexpansion(s21);
//cout << "$$" << s21 << "$$" <<  endl;
//cout << "$$" << lc6 << "$$" <<  endl;
//LCSSQO<Elementary> lc7 = wickexpansion(s22);
//cout << "$$" << s22 << "$$" <<  endl;
//cout << "$$" << lc7 << "$$" <<  endl;
/*LCSSQO<Elementary> lc8 = wickexpansion(twobodyop, Ref_State::vacuum);
cout << "$$" << twobodyop << "$$" <<  endl;
cout << "$$" << ToSTRParticleHole(twobodyop) << "$$" << endl;
cout << lc8 << endl;


LCSSQO<Elementary> lc9 = wickexpansion(twobodyop, Ref_State::fermi);
cout << "$$" << twobodyop << "$$" <<  endl;
cout << lc9 << endl;

*/
//cout << "$$" << twobodyop2 << "$$" << endl;

cout << wickexpansion(twobodyop2, Ref_State::vacuum) << endl;

//cout << "$$" << twobodyop3 << "$$" << endl;
//cout << wickexpansion(twobodyop3, Ref_State::vacuum) << endl;


/*
cout << "Normalproduct test: " << endl;
cout << "Before:" << endl;
cout << s2 << endl;
s2.normalproduct();
cout << "After: " << endl;
cout << s2 << endl;
cout << "*********************" << endl;
cout << endl;
cout << endl;

STR<SQO<ParticleHole>> tmp;

for ( int i=4; i<10; i++) {
  tmp.list<SQO<ParticleHole>>::clear();
  tmp._prefactor = 1;
  for ( int i=1; i<10; i++) {
   SQO<ParticleHole> s(  SQO_Idx_Type::particle, static_cast<SQO_Type>( rand() % 2), to_string(i) );
   tmp.list<SQO<ParticleHole>>::push_back(s);
  }
  cout << "Random String " << i << " : " << endl;
  cout << tmp << endl;
  tmp.normalproduct();
  cout << tmp << endl;
  cout << endl;
}

cout << "*********************" << endl;
cout << endl;
cout << endl;

double d1=4;
cout << "4*s2" << endl;
cout << d1*s2 << endl;
cout << endl;


cout << "s2*4" << endl;
cout << s2*d1 << endl;
cout << endl;

cout << "c*s2" << endl;
cout << c*s2 << endl;
cout << endl;

cout << "s2*c" << endl;
cout << s2*c << endl;
cout << endl;

cout << "s1*s2" << endl;
cout << s1*s2 << endl;
cout << endl;

cout << "s2*s1" << endl;
cout << s2*s1 << endl;
cout << endl;

cout << "2*s1*3s2" <<endl;
cout << 2.0*s1*3.0*s2 << endl;
cout << endl;

cout << "*********************" << endl;
cout << endl;
cout << endl;


cout << "a==a" << endl;
cout << (a==a) << endl;
cout << "a==b" << endl;
cout << (a==b) << endl;

cout << "s1==s1" <<endl;
cout << (s1==s1) << endl;
cout << "2*s1 == s2" << endl;
//cout << ((2*s1) == s1) << endl;
cout << "s2==s1" << endl;
cout << (s2==s1) << endl;
cout << "s2==s3" << endl;
cout << (s2==s3) << endl;

cout << "STR OUTPUT: " << s4 << endl;
cout << "s4==s5" << endl;
cout << (s4==s5) << endl;

cout << "ttsqo1:  " <<  ttsqo1 << endl;
cout << "ttsqo3:  " <<  ttsqo3 << endl;


cout << "STR OUTPUT TWOTENS: " << s6*s7 << endl;


cout << "PFSTT: " << endl;
cout << "pf1: " << pf1 << endl;
cout << "pf2: " << pf2 << endl;
cout << "pf3: " << pf3 << endl;

cout << endl;
cout << "operator +" << endl;
cout << "pf3 + 3: " << pf3 + 3 << endl;
cout << "pf3 + s8: " << pf3 +s8 << endl;
cout << "pf3 + pf2: " << pf3 +pf2 << endl;

cout << endl;
cout << "operator *" << endl;
cout << "pf3 * 3: " << pf3*3 << endl;
cout << "pf3 * s8: " << pf3*s8 << endl;
cout << "pf3 * pf2: " << pf3*pf2 << endl;

cout << endl;
cout << "LCSSQO" << endl;
cout << "ostream" << endl;


cout << s5 << endl;
cout << s8 << endl;
cout << lc1 << endl;
cout << "operator +" << endl;
cout << lc1 + s5 << endl;
cout << s5+lc1 << endl;
cout << endl;
cout << lc1 + lc1 << endl;
cout << "operator *" << endl;
cout << lc1*5 << endl;
cout << 5*lc1 << endl;
cout << endl;
cout << lc1*s5 << endl;
cout << s5*lc1 << endl;
cout << endl;
cout << lc1*s8 << endl;
cout << s8*lc1 << endl;
cout << endl;

cout << pf2 << endl;
cout << lc1*pf2 << endl;
cout << pf2*lc1 << endl;
cout << endl;
cout << lc1*lc1 << endl;
cout << endl;
*/



}
