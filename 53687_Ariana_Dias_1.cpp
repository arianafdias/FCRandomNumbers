#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    unsigned seed =  2147483647;
    unsigned int c = 16807;
    unsigned int p = 4294967295;
    unsigned a0 = 0;
    ofstream MyFile("RandomNumbers.txt");
    vector<unsigned > X;
    vector<double> Xn;
    X.push_back(seed);
    X.push_back(seed);

    for (int i=1; i<=1000; i++)
    {
        unsigned Xi =   (( c*X.back()+a0) % p);
        X.push_back(Xi);

    }

    for (int i = 0; i<X.size(); i++){
        double teste = (double) X[i]/p;

        Xn.push_back(teste);

        if (Xn.size()<3) continue;
        MyFile << *(Xn.rbegin()+2) <<"\t" << *(Xn.rbegin()+1) << "\t" << Xn.back() << endl;
    }

    MyFile.close();
    return 0;
}