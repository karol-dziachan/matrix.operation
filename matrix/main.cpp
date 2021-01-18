#include "CMatrix.h"
#include <iostream>
using namespace std;

int main() {

    //invalid dimension
    //CMatrix<int> matrixerror(1, 0);


    //matrix with not number
    CMatrix<int> matrixtext("matrixtext.txt");
    matrixtext.v_print_debug();
    matrixtext.v_set_dimension(10, 10);
    matrixtext.v_print_debug();
    matrixtext.v_set_dimension(2, 2);
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
    

    cout << "WSAD 1" << endl; 
    CMatrix<int> matrixwsad1("wsad1.txt");
    matrixwsad1.v_print_debug();

   CMatrix<int> matrixwsad2("wsad2.txt");
   matrixwsad2.v_print_debug();
    CMatrix<double> matrixwsaddouble("wsaddouble.txt");
    matrixwsaddouble.v_print_debug();

    CMatrix<float> matrixwsadfloat("wsadfloat.txt");
    matrixwsadfloat.v_print_debug();
    

   /* //not possible multiply
    matrixwsad1 *= matrixwsad2;
    matrixwsad1.v_print_debug();*/
    

    /*
    //not possible add
    matrixwsad1 + matrixwsad2;
    matrixwsad1.v_print_debug();
    
    */
    

 
    /*
    //not possible subtraction
    matrixwsad1 - matrixwsad2;
    matrixwsad1.v_print_debug();*/

    //from Przewo lecture
    CMatrix<int> matrixlecturei("przewowsadint.txt");
    matrixlecturei.v_print_debug();

    CMatrix<int> matrixlectured("przewowsaddouble.txt");
    matrixlectured.v_print_debug();


    CMatrix<int> matrixscalartest("scalar1.txt");
    CMatrix<int> matrixscalartest2("scalar2.txt");

    matrixscalartest.v_print_debug();
    matrixscalartest2.v_print_debug();
   
    cout << matrixscalartest.t_scalar_calculate(matrixscalartest2);

    return 0;
}
