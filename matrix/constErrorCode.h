#pragma once
#include<iostream>
using namespace std;
static const int WRONG_DIM = 100; 
static const int WRONG_PATH = 102; 
static const int WRONG_DATA = 103; 
static const int NOT_ENOUGH_DATA = 105; 
static const int TO_MANY_DATA = 106; 
static const int ADD_NOT_POSSIBLE = 201; 
static const int SUB_NOT_POSSIBLE = 202; 
static const int MULT_NOT_POSSIBLE = 203; 
static const int WRONG_POS = 204; 
static const int USELESS_ASSIGNMENT = 205; 
static const int WRONG_POS_VEC = 206; 
static const int WRONG_VEC_SIZES = 207; 
 
static const string sWRONG_DIM = "During the memory allocate dimensions were wrong. Program took default values. ";
static const string sWRONG_PATH = "Failed to open file. Program took default value (0) and default dimensions (5x5)";
static const string sWRONG_DATA = "Not number in file. This expression is default value now (0)";
static const string sNOT_ENOUGH_DATA = "No enough numbers in file.The program add default value(0) enough times.";
static const string sTO_MANY_DATA = "To many numbers in file.The program cut numbers to form a square matrix";
static const string sADD_NOT_POSSIBLE = "Add is not possible. Action not performed.";
static const string sSUB_NOT_POSSIBLE = "Subtraction is not possible. Action not performed.";
static const string sMULT_NOT_POSSIBLE = "Multiply is not possible. Action not performed.";
static const string sWRONG_POS = "Incorrect position. Program returned [0][0]";
static const string sUSELESS_ASSIGNMENT = "Operator=. Same matrix. Action not performed";
static const string sWRONG_POS_VEC = "Invalid position of row/column. Returned null vector";
static const string sWRONG_VEC_SIZES = "The vectors size is not same. Scalar is from the same vector.";
static const string sWRONG_ANOTHER = "Another error";

