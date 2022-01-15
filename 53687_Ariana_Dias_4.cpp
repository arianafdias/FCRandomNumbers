#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    unsigned seed =  2147483647;
    unsigned int c = 16807;
    unsigned int p = 4294967295;
    unsigned int a0 = 0;
    vector<unsigned > X;
    vector<double> Xn;
    X.push_back(seed);
    X.push_back(seed);
    int n = 10000;

    for (int i=1; i<=n; i++)
    {
        unsigned Xi =   (( c*X.back()+a0) % p);
        X.push_back(Xi);

    }

    for (int i = 0; i<X.size(); i++){

        double teste = (double) X[i]/p; //  rand()/RAND_MAX;

        Xn.push_back(teste);

    }

    int sample =  Xn.size();

    double k = 10;
    vector<double> spaces(k+1);
    vector<int> values(k);
    //Xn -> random numbers sequence

    //division of division of spaces
    for (int n = 0; n < k+1 ; ++n) {
        spaces[n] = (double) n/k;
    }
    for (int i = 0; i < sample; ++i) {
        double trial_number = Xn[i];
        for (int j = 0; j < k; ++j) {
            if (spaces[j] < trial_number && trial_number < spaces[j+1]){
                values[j]++;
            }
        }
    }
    for (int i = 0; i < values.size() ; ++i) {
        cout << values[i] << endl;
    }



    double quiSquare;
    for (int i = 0; i < k; ++i) {
        double frac = pow(values[i]-n*(1/k), 2)/(n/k);
        quiSquare += frac;

    }
    cout << quiSquare << endl;


    return 0;
}