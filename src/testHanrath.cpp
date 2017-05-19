#include "LCSSQO.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int  main() {

    string ops = "abcdefghijklmnopqrstuvwxyz"; //  max 26 operators

    unsigned int count= 0;
    int maxnumberoftests;
    string whichtest;
    cout << "How many wick expansions should be done?" << endl;
    cin >> maxnumberoftests;
    cout << endl;
    cout << "Do you want to test wick or generalizedwick?" << endl;
    cin >> whichtest;
    cout << endl;

    fstream f;
    fstream g;
    f.open("mytest", ios::out);
    g.open("NormalOrder_Test.C", ios::out);

    g << "#include \"Term.H\" " << endl;
    g << endl;
    g << "   using namespace std;   " << endl;
    g << endl;
    g << "int main()" << endl;
    g << "{" << endl;
    g << endl;


    for ( int numberoftests=0; numberoftests<maxnumberoftests; numberoftests++ ) {
        vector<SQO<Elementary>> strvec;
        for ( int sizeofstring=0; sizeofstring < (rand() % 24 + 2); sizeofstring++ ) {
            string index;
            index += ops[sizeofstring];
            SQO<Elementary> tmp(SQO_Idx_Type::particle, static_cast<SQO_Type>(rand() % 2), index );
            strvec.push_back(tmp);
        }

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
                f << tmpstr << endl;
                if ( whichtest == "wick") {f << wickexpansion( tmpstr, Elementary::vacuum ) << endl;}
                else if (whichtest == "generalizedwick"){ f << generalizedWickExpansion( tmpstr, Elementary::vacuum ) << endl;}
                f << endl;
                f << endl;
            }
        }

        for ( unsigned int i=0; i<allstr.size(); i++) {
            g <<  "Product<SQOperator>	p" << count << " ;" << endl;
            for ( typename list<SQO<Elementary>>::const_iterator j=allstr[i].begin(); j!=allstr[i].end(); j++ ) {
                if ( (*j).a == SQO_Type::creation ) { g << "p" << count <<  " *= SQOperator('" << static_cast<char>(toupper( ((*j).idx)[0] )) << "');"  << endl; }
                else { g << "p" << count <<  " *= SQOperator('" << (*j).idx << "');"  << endl;}
            }
            g << "Term	term" << count << "(p" << count << ");" << endl; ;
            g << "cout << term" << count << "    <<  endl; " << endl;
            g << "cout << term" << count << ".normalOrder() << endl;" << endl;
            g << "cout << endl;" <<endl;
            g << "cout << endl;" <<endl;
            g << endl;
            g << endl;
            ++count;
        }
    }

    g << "return 0; " << endl;
    g << "}" << endl;

    f.close();
    g.close();

    return 0;

}
