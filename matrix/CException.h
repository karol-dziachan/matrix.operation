#pragma once
#include <iostream>
#include <exception>
using namespace std; 
class CException : public exception
{
public: 
	CException(string s_msg) { cout << s_msg << endl;  }
private:
	string s_msg;
};

