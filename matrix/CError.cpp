#include "CError.h"
#include "constErrorCode.h"
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

string CError::s_last_error()
{
    return s_translate_code(v_error_code.back());
}

string CError::s_translate_code(int i_code)
{
    switch (i_code)
    {
    case WRONG_DIM:
        return sWRONG_DIM;
    case WRONG_PATH:
        return sWRONG_PATH;
    case WRONG_DATA:
        return sWRONG_DATA;
    case NOT_ENOUGH_DATA:
        return sNOT_ENOUGH_DATA;
    case TO_MANY_DATA:
        return sTO_MANY_DATA;
    case ADD_NOT_POSSIBLE:
        return sADD_NOT_POSSIBLE;
    case SUB_NOT_POSSIBLE:
        return sSUB_NOT_POSSIBLE;
    case MULT_NOT_POSSIBLE:
        return sMULT_NOT_POSSIBLE;
    case WRONG_POS:
        return sWRONG_POS;
    case USELESS_ASSIGNMENT:
        return sUSELESS_ASSIGNMENT;
    case WRONG_POS_VEC:
        return sWRONG_POS_VEC;
    case WRONG_VEC_SIZES:
        return sWRONG_VEC_SIZES;
    default:
        return sWRONG_ANOTHER;
    }
}