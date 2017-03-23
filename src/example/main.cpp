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



/*
cout << "$$" << twobodyop2 << "$$" << endl;
LCSSQO<Elementary, Elementary> lcssqo(wickexpansion(twobodyop2, Elementary::vacuum));
cout << lcssqo << endl;
LCSSQO<Elementary, Elementary> lcssqo2(generalizedWickExpansion(twobodyop2, Elementary::vacuum));
cout << lcssqo2 << endl;

cout << "$$" << op1 << "$$" << endl;
LCSSQO<ParticleHole, ParticleHole> lcssqo3(wickexpansion(op1, ParticleHole::fermi));
cout << lcssqo3 << endl;
*/

vector<SQO<Elementary>> strvec;
strvec.push_back(p);
strvec.push_back(q);
strvec.push_back(r);
strvec.push_back(s);
strvec.push_back(t);
strvec.push_back(u);
strvec.push_back(v);
strvec.push_back(w);

STR<SQO<Elementary>> strelem({p,q,r,s,t,u,v,w});

//cout << wickexpansion( strelem, Elementary::vacuum ) << endl;


// RANDOM STRINGS NORMAL ORDER WITH AND WITHOUT generalizedWickExpansion
vector<STR<SQO<Elementary>>> allstr;
    
    for ( int i=0; i<strvec.size()-1; i++ ) {
        for ( int j=i; j< strvec.size(); j++ ) {
          vector<SQO<Elementary>> tmp(strvec);
            SQO_Type tmptype = tmp[i].a;
            tmp[i].a = tmp[j].a;
            tmp[j].a = tmptype;
            
            STR<SQO<Elementary>> tmpstr;
            for ( int k=0; k<tmp.size(); k++ ) {
                tmpstr = tmpstr * tmp[k];
            }
            
            allstr.push_back( tmpstr );
            cout << tmpstr << endl;
            cout << wickexpansion( tmpstr, Elementary::vacuum ) << endl;
            cout << endl;
            cout << endl;

      }
    }
    

cout << endl;
cout << endl;
cout << endl;
cout << endl;

for ( int i=0; i< allstr.size(); i++) {
cout <<  "Product<SQOperator>	p" << i << " ;" << endl;
  for ( typename list<SQO<Elementary>>::const_iterator j=allstr[i].begin(); j!=allstr[i].end(); j++ ) {
    if ( (*j).a == SQO_Type::creation ) { cout << "p" << i <<  " *= SQOperator('" << static_cast<char>(toupper( ((*j).idx)[0] )) << "');"  << endl; }
    else { cout << "p" << i <<  " *= SQOperator('" << (*j).idx << "');"  << endl;}
  }

cout << "Term	term" << i << "(p" << i << ");" << endl; ;

cout << "cout << term" << i << "    <<  endl; " << endl;
cout << "cout << term" << i << ".normalOrder() << endl;" << endl;
cout << endl;
}


/*
for ( int i=0; i<1; i++ ) {
  cout << allstr[i] << endl;
  cout << generalizedWickExpansion( allstr[i], Elementary::vacuum ) << endl;
}
*/


}
