#include <iostream>
#include<iomanip>
#include "src/CmcMaker.h"

using std::cout;
using std::ios;

int main(){
    CmcMaker* m = new CmcMaker();
    m->generate(10.);
    int mul = m->getMul();
    cout << "CMC Test Program" << "\n";
    cout << "Multiplicity: " << m->getMul() << "\n";
    cout << "ID\t\tpx\t\t\tpy" << "\n";
    for(int i=0; i<=mul; i++){
        cout.unsetf(ios::showpos);
        cout  << i << "\t\t";
        cout.setf(ios::showpos);
        cout << std::setw(6) << m->getPx()[i] << "\t\t" << m->getPy()[i] << "\n";
    }
    return 0;
}