#include "CMatrix.h"
#include <iostream>
using namespace std;

int main() {

    //invalid dimension
    //CMatrix<int> matrixerror(1, 0);


    //matrix with not number
    CMatrix<int> matrixtext("matrixtext.txt");
    matrixtext.v_print_debug();

    //not number double
    CMatrix<double> matrixtextdouble("wsaddouble.txt");
    matrixtextdouble.v_print_debug();

    CMatrix<double> matrixtextdouble2("wsaddouble.txt");
    matrixtextdouble2.v_print_debug();

    cout << "MULTIPLICATION:" << endl; 
    matrixtextdouble *= matrixtextdouble2;
    matrixtextdouble.v_print_debug();

    //not exist
    CMatrix<double> matrixnotexist("notexist.txt");
    matrixnotexist.v_print_debug();

    //not enought
    cout << "NOT ENOUGH :" << endl;
    CMatrix<int> matrixnotenough("wsadnotenough.txt");
    matrixnotenough.v_print_debug();

    //to many number
    cout << "TO MANY :" << endl;
    CMatrix<int> matrixtomany("wsadtomany.txt");
    matrixtomany.v_print_debug();

    //not number float
    CMatrix<float> matrixtextfloat("wsadfloat.txt");
    matrixtextfloat.v_print_debug();


    CMatrix<int> matrixwsad1("wsad1.txt");
    matrixwsad1.v_print_debug();
   CMatrix<int> matrixwsad2("wsad2.txt");
   matrixwsad2.v_print_debug();
    CMatrix<double> matrixwsaddouble("wsaddouble.txt");
    matrixwsaddouble.v_print_debug();

    CMatrix<float> matrixwsadfloat("wsadfloat.txt");
    matrixwsadfloat.v_print_debug();

    //not possible multiply
    matrixwsad1 *= matrixwsad2;
    matrixwsad1.v_print_debug();

    //not possible add
    matrixwsad1 + matrixwsad2;
    matrixwsad1.v_print_debug();

    //not possible subtraction
    matrixwsad1 - matrixwsad2;
    matrixwsad1.v_print_debug();

   

    return 0;
}
