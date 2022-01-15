#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    ofstream MyFile("RandomNumbersRand.txt");
    vector <float> Xn;


    for (int i = 0; i<1000; i++){
        double teste = (float) rand()/RAND_MAX ;

        Xn.push_back(teste);

        if (Xn.size()<3) continue;
        MyFile << *(Xn.rbegin()+2) <<"\t" << *(Xn.rbegin()+1) << "\t" << Xn.back() << endl;
    }

        MyFile.close();
    return 0;
}