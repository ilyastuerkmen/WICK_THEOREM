#include "LCSSQO.h"

#include <iostream>

  using namespace std;

int main() {

  SQO<Elementary>  ci(SQO_Idx_Type::particle , SQO_Type::creation, "i");
  SQO<Elementary>  aa(SQO_Idx_Type::hole , SQO_Type::annihilation, "a");

  SQO<Elementary>  cpp(SQO_Idx_Type::particle , SQO_Type::creation, "p");
  SQO<Elementary>  cpq(SQO_Idx_Type::particle , SQO_Type::creation, "q");
  SQO<Elementary>  aps(SQO_Idx_Type::particle , SQO_Type::annihilation, "s");
  SQO<Elementary>  apr(SQO_Idx_Type::particle , SQO_Type::annihilation, "r");

  SQO<Elementary>  chp(SQO_Idx_Type::hole , SQO_Type::creation, "p");
  SQO<Elementary>  chq(SQO_Idx_Type::hole , SQO_Type::creation, "q");
  SQO<Elementary>  ahs(SQO_Idx_Type::hole , SQO_Type::annihilation, "s");
  SQO<Elementary>  ahr(SQO_Idx_Type::hole , SQO_Type::annihilation, "r");

  SQO<Elementary>  cb(SQO_Idx_Type::hole , SQO_Type::creation, "b");
  SQO<Elementary>  aj(SQO_Idx_Type::particle , SQO_Type::annihilation, "j");

  vector<STR<SQO<Elementary>>> vectmp;
  STR<SQO<Elementary>> tmp1({cpp,cpq,aps,apr});

  STR<SQO<Elementary>> tmp2({chp,cpq,aps,apr});
  STR<SQO<Elementary>> tmp3({cpp,chq,aps,apr});
  STR<SQO<Elementary>> tmp4({cpp,cpq,ahs,apr});
  STR<SQO<Elementary>> tmp5({cpp,cpq,aps,ahr});

  STR<SQO<Elementary>> tmp6({chp,chq,aps,apr});
  STR<SQO<Elementary>> tmp7({chp,cpq,ahs,apr});
  STR<SQO<Elementary>> tmp8({chp,cpq,aps,ahr});
  STR<SQO<Elementary>> tmp9({cpp,chq,ahs,apr});
  STR<SQO<Elementary>> tmp10({cpp,chq,aps,ahr});
  STR<SQO<Elementary>> tmp11({cpp,cpq,ahs,ahr});

  STR<SQO<Elementary>> tmp12({cpp,chq,ahs,ahr});
  STR<SQO<Elementary>> tmp13({chp,cpq,ahs,ahr});
  STR<SQO<Elementary>> tmp14({chp,chq,aps,ahr});
  STR<SQO<Elementary>> tmp15({chp,chq,ahs,apr});

  STR<SQO<Elementary>> tmp16({chp,chq,ahs,ahr});

  vectmp.push_back(tmp1);
  vectmp.push_back(tmp2);
  vectmp.push_back(tmp3);
  vectmp.push_back(tmp4);
  vectmp.push_back(tmp5);
  vectmp.push_back(tmp6);
  vectmp.push_back(tmp7);
  vectmp.push_back(tmp8);
  vectmp.push_back(tmp9);
  vectmp.push_back(tmp10);
  vectmp.push_back(tmp11);
  vectmp.push_back(tmp12);
  vectmp.push_back(tmp13);
  vectmp.push_back(tmp14);
  vectmp.push_back(tmp15);
  vectmp.push_back(tmp16);

PFSTT<ParticleHole> fullycontracted;
STR<SQO<Elementary>> leftstr({ci,aa});
STR<SQO<Elementary>> rightstr({cb,aj});

for (int i=0; i< vectmp.size(); i++) {
  STR<SQO<ParticleHole>> tmp =  STRToSTR(vectmp[i], ParticleHole::fermi);
  tmp.normalproduct();
  vectmp[i] = STRToSTR(tmp, Elementary::vacuum);
  fullycontracted = fullycontracted + wickexpansion( leftstr*vectmp[i]*rightstr, ParticleHole::fermi).fullcontraction;
  cout << wickexpansion( leftstr*vectmp[i]*rightstr, ParticleHole::fermi).fullcontraction << endl;
}
  cout << fullycontracted << endl;
  cout << usesymmetry(fullycontracted) << endl;
}
