#include "LCSSQO.h"

#include <iostream>
#include <string>

using namespace std;

int  main() {

    SQO<Elementary>     sqo1(SQO_Idx_Type::general , SQO_Type::creation, "p");
    SQO<ParticleHole>   sqo2(SQO_Idx_Type::particle, SQO_Type::annihilation, "q");
    cout << "sqo1: " << sqo1 << "      sqo2: " << sqo2 << endl;

}
