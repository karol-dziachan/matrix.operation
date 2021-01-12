#include "CError.h"

#include <iostream>
#include <fstream>

using namespace std;

void CError::v_add_error(int i_error_code)
{
    v_error_code.push_back(i_error_code);
}

void CError::v_serialize_error_report()
{

     if(!v_error_code.empty()) {
       


         ofstream fout;
         ifstream fin;
         fin.open("report.txt");
         fout.open("report.txt", ios::app);
         if (fin.is_open()) {

             for (int ii = 0; ii < v_error_code.size(); ii++) {
                 string s_info = s_translate_code(v_error_code[ii]);
                 fout << "\n" << v_error_code[ii] << " - " << s_info;
                 v_error_code.erase(v_error_code.cbegin());
             }

             fout << "\n" << endl << endl;
             
         }

         fin.close();
         fout.close();

     }
}

string CError::s_translate_code(int i_code)
{
    switch (i_code)
    {
    case 100:
        return "During the memory allocate dimensions were wrong. Program took default values. ";
    case 101:
        return "Failed to open file. Program took default value (0) and default dimensions (5x5)"; 
    case 102:
        return "Failed to open file. Program took default value (0) and default dimensions (5x5)";
    case 103:
        return "Not number in file. This expression is default value now (0)";
    case 105:
        return "No enough numbers in file. The program add default value (0) enough times.";
    case 106:
        return "To many numbers in file. The program cut numbers to form a square matrix";
    case 201:
        return "Add is not possible. Action not performed.";
    case 202:
        return "Subtraction is not possible. Action not performed.";
    case 203:
        return "Multiply is not possible. Action not performed.";
    case 204:
        return "Incorrect position. Program returned [0][0]";
    case 205:
        return "Operator=. Same matrix. Action not performed";
    case 206:
        return "Invalid position of row/column. Returned null vector";
    case 207:
        return "The vectors size is not same. Scalar is from the same vector.";
    default: 
        return "Another error";
    }
}