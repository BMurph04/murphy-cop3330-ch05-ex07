#include "roots.h"

class BadDiscriminant{};

using namespace std;

int main(){
    double a, b, c, root1, root2;

    cout << "Please enter values a, b, and c for the following quadratic equation: ax^2 + bx + c = 0" << endl;
    cin >> a >> b >> c; //Entering values known to compute two specific roots allows us to check if the program outputs the correct result.

    int valid = result(a, b, c, &root1, &root2);
    if(valid==1){
        cout << "The resulting roots are " << root1 << " and " << root2 << "." << endl;
        return 0;
    }
}

int result(double a, double b, double c, double *root1, double *root2){
    try{
        double discriminant = calcDiscriminant(a, b, c);
       
        *root1 = ( (-1 * b) + sqrt(discriminant) )/ (2 * a);
        *root2 = ( (-1 * b) - sqrt(discriminant) )/ (2 * a);
        return 1;
    }
    catch(BadDiscriminant){
        cout << "No real roots exist for these inputs." << endl; //Ensures that all results are plausible and doesn't allow computation of the square root of negative numbers
        return 0;
    }

}

double calcDiscriminant(double a, double b, double c){
    if( (b*b)-(4*a*c) < 0 ) throw BadDiscriminant{};
    return (b*b) - (4*a*c);
}