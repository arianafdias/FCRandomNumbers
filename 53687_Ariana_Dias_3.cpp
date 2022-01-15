#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    ofstream MyFile("RandomNumbersCircle.txt");
    vector <float> X;
    vector <float> Y;


    for (int i = 0; i<1000; i++){
        double r = (float) rand()/RAND_MAX ;
        double thetha = (float) rand()/RAND_MAX;
        double x =sqrt(r) * sin(2*M_PI*thetha);
        double y = sqrt(r) * cos(2*M_PI*thetha);
        X.push_back(x);
        Y.push_back(y);
        MyFile << X.back() << "\t"<<Y.back()<< endl;
    }

        MyFile.close();
    return 0;
}