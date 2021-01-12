#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CError {
public:
    void v_add_error(int i_error_code);
    void v_serialize_error_report();
    string s_translate_code(int i_code);
private:
    vector<int> v_error_code;
};

