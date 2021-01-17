#pragma once
#include <iostream>
#include "const.h"
#include<vector>
#include<fstream>
#include "CError.h"
#include "CException.h"
using namespace std;

template <typename T>
class CMatrix
{
public:
    CMatrix();
    CMatrix(int i_x, int i_y);
    CMatrix(string s_path);
    ~CMatrix();
    void v_set_dimension(int i_x, int i_y);
    void v_allocate_space(int i_x, int i_y);
    void v_deallocate_space();
    bool v_add(CMatrix& pc_other);
    void operator+(CMatrix& pc_other);
    bool v_subtraction( CMatrix& c_other);
    void operator-( CMatrix& pc_other);
    bool v_multiply( CMatrix& pc_other);
    void operator*=( CMatrix& pc_other);
    bool v_multiply_by_number(T t_number);
    void operator*=(T t_number);
    void operator=( CMatrix<T>& pc_other);
    T operator()(int i_this_x, int i_this_y);
    void v_set_value_at(T t_value, int i_this_x, int i_this_y);
    vector<T> v_create_vector_row(int i_pos);
    vector<T> v_create_vector_col(int i_pos);
    T i_scalar_calculate(vector<T> vec1, vector<T> vec2);
    void v_transposition();
    void v_fill_matrix(T t_value);
    void v_print_debug();
    T t_get_elem(int i_get_x, int i_get_y);
    T t_parse( string c_open);
private:
    T** pt_matrix;
    int i_cols;
    int i_rows;
    void v_set_dim_x(int i_new_x) { i_cols = i_new_x; }
    void v_set_dim_y(int i_new_y) { i_rows = i_new_y; }
    int i_get_dim_x() { return i_cols; }
    int i_get_dim_y() { return i_rows; }
    vector<string> s_split(string s_row);
    bool b_contains(string s_value, char c_elem);
    bool b_contains_not_number( string s_value);
    T  b_convert_int(string s_value);
    int  i_convert_numeral(char c_value);
    T  b_convert_double_float( string s_value);
    T i_pow(int i_pow, int i_base);
    CError* c_error;
};


using namespace std;

template <typename T>
void CMatrix<T> ::v_allocate_space(int i_x, int i_y)
{
    if(i_x <= 0 || i_y <= 0) {
        c_error->v_add_error(100);
        i_x = DEFAULT_DIM;
        i_y = DEFAULT_DIM;
    }

    pt_matrix = new T * [i_x];

    for (int ii = 0; ii < i_x; ii++)
        pt_matrix[ii] = new T[i_y];

    v_set_dim_x(i_x);
    v_set_dim_y(i_y);

    v_fill_matrix(DEFAULT_ALLOCATE_VALUE);
}

template <typename T>
void CMatrix<T> ::v_deallocate_space()
{
    for (int ii = 0; ii < i_cols; ii++)
        delete pt_matrix[ii];
    delete pt_matrix;
}
template <typename T>
CMatrix<T> ::CMatrix()
{
    c_error = new CError();
    v_allocate_space(DEFAULT_DIM, DEFAULT_DIM);
}


template <typename T>
CMatrix<T> ::CMatrix(int i_x, int i_y)
{
    c_error = new CError();
    v_allocate_space(i_x, i_y);
}

template <typename T>
CMatrix<T> :: ~CMatrix()
{
   v_deallocate_space();
   c_error->v_serialize_error_report();
    if(c_error != NULL) delete c_error;
}




template <typename T>
CMatrix<T> ::CMatrix(string s_path) {
    c_error = new CError();



    int i_how_many_rows = 0;
    int i_how_many_cols;
    vector<T> v_row;
    vector<string> v_tmp;

 ifstream reader(s_path);
 if (reader.is_open()) {
     char row[10000];
     while (reader.getline(row, 10000)) {
         v_tmp = s_split(row);
         i_how_many_rows++;


         for (int ii = 0; ii < v_tmp.size(); ii++)
             v_row.push_back(t_parse(v_tmp[ii]));

     }

     i_how_many_cols = v_tmp.size();

     if (i_how_many_cols * i_how_many_rows > v_row.size())
     {
         int i_counter = v_row.size();
         c_error->v_add_error(105);
         for (int ii = i_counter; ii < i_how_many_cols * i_how_many_rows; ii++)
             v_row.push_back(DEFAULT_VALUE);
     }

     if (i_how_many_cols* i_how_many_rows < v_row.size())
     {
         int i_counter = v_row.size();
         c_error->v_add_error(106);
         for (int ii = i_how_many_cols * i_how_many_rows; ii > i_counter; ii--)
             v_row.pop_back();
     }


     v_allocate_space(i_how_many_cols, i_how_many_rows);
     int i_open = 0;


     for (int ii = 0; ii < i_rows; ii++) {
         for (int ij = 0; ij < i_cols; ij++) {
             pt_matrix[ij][ii] = v_row[i_open];
             i_open += 1;
         }
     }

 }
 else
    {
        c_error->v_add_error(101);
        v_allocate_space(DEFAULT_DIM, DEFAULT_DIM);
    }

    reader.close();
}




template <typename T>
vector<string> CMatrix<T> :: s_split(string s_row)
{
    string s_tmp;
    vector<string> v_tmp;
    for(int ii = 0 ; ii < s_row.size(); ii++)
        if(s_row[ii] != ' ') {
            s_tmp.push_back(s_row[ii]);
        }
        else
        {
            if (!b_contains(s_tmp, ' '))
                v_tmp.push_back(s_tmp);
            s_tmp= "";
        }

    if(!b_contains(s_tmp, ' '))
     v_tmp.push_back(s_tmp);

    return v_tmp;
}

template <typename T>
void CMatrix<T> ::v_set_dimension(int i_x, int i_y)
{
    CMatrix<T> c_helper(i_x, i_y);
    
    for (int ii = 0; ii < i_x; ii++)
        for (int ij = 0; ij < i_y; ij++)
            if (ii < i_cols && ii < i_x && ij < i_y && ij < i_rows)
                c_helper.pt_matrix[ii][ij] = pt_matrix[ii][ij];

    v_deallocate_space();
    v_allocate_space(i_x, i_y);


    for (int ii = 0; ii < i_x; ii++)
        for (int ij = 0; ij < i_y; ij++)
            pt_matrix[ii][ij] =  c_helper.pt_matrix[ii][ij];
}

template <typename T>
T CMatrix<T> ::t_parse(string c_open)
{
    if(b_contains_not_number(c_open)) {
        c_error->v_add_error(103);
        return DEFAULT_VALUE;
    }

    if(b_contains(c_open, '.') || b_contains(c_open, ','))
        return b_convert_double_float(c_open);
    else
        return b_convert_int(c_open);
}

template <typename T>
bool CMatrix<T> :: b_contains(string s_value, char c_elem)
{
    for(int ii = 0 ; ii < s_value.size(); ii++)
        if(s_value[ii] == c_elem)
            return true;

        return false;
}

template <typename T>
bool CMatrix<T> :: b_contains_not_number(string s_value) {
    for (char ii : s_value)
        if (((int) ii < 48 || (int) ii > 57) && (int) ii != 44 && (int) ii != 46)
            return true;


        return false;

}

template <typename T>
T CMatrix<T> :: b_convert_int(string s_value)
{
    T t_tmp = 0;
    int i_size = s_value.size();

    for(int ii = 0 ; ii < i_size; ii++) {
        t_tmp += (i_convert_numeral(s_value[ii]) * i_pow(s_value.size() - 1 -ii, 10));
    }

    return t_tmp;

}

template<typename T>
T CMatrix<T> ::  b_convert_double_float(string s_value)
{
    return atof(s_value.c_str());
}


/*
template <>
float CMatrix<float> ::b_convert_double_float(string s_value)
{
    return atof(s_value.c_str());
}*/


template <typename T>
T CMatrix<T> :: i_pow(int i_pow, int i_base)
{

    T i_result = 1;
    if(i_pow == 1)
        return i_base;
    for(int ii = 0 ; ii < i_pow; ii++)
        i_result *= i_base;


    return i_result;

}

template<typename T>
int CMatrix<T> ::i_convert_numeral(char c_value)
{
    switch (c_value)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;

    }
}

template <typename T>
void CMatrix<T> ::v_fill_matrix(T t_value)
{
    for (int ii = 0; ii < i_cols; ii++) {
        for (int ij = 0; ij < i_rows; ij++) {
            pt_matrix[ii][ij] = t_value;
        }
    }
}


template <typename T>
void CMatrix<T> ::v_print_debug()
{
    for (int ii = 0; ii < i_rows; ii++)
    {
        cout << endl;
        for (int ij = 0; ij < i_cols; ij++)
            cout << pt_matrix[ij][ii] << " ";
    }

    cout << endl;
}

template <typename T>
bool CMatrix<T> ::v_add(CMatrix& pc_other)
{
    if (i_cols != pc_other.i_cols || i_rows != pc_other.i_rows)
    {
        c_error->v_add_error(201);
        return false;
    }



    for (int ii = 0; ii < i_rows; ii++)
        for (int ij = 0; ij < i_cols; ij++)
            pt_matrix[ii][ij] = pt_matrix[ii][ij] + pc_other.pt_matrix[ii][ij];

    return true;
}

template<typename T>
void CMatrix<T> ::operator+(CMatrix<T>& pc_other) {
   if(!v_add(pc_other));
    throw CException(c_error->s_last_error());
}

template <typename T>
T CMatrix<T> ::t_get_elem(int i_get_x, int i_get_y) {

    if (i_get_x >= i_cols || i_get_x >= i_cols) {
        c_error->v_add_error(204);
        return pt_matrix[0][0];
    }

    return   pt_matrix[i_get_x][i_get_y];
}


template <typename T>
bool CMatrix<T> ::v_subtraction(CMatrix<T>& pc_other)
{
    if (i_cols != pc_other.i_cols || i_rows != pc_other.i_rows)
    {
        c_error->v_add_error(202);
        return false;
    }

    for (int ii = 0; ii < i_rows; ii++)
        for (int ij = 0; ij < i_cols; ij++)
            pt_matrix[ii][ij] = pt_matrix[ii][ij] - pc_other.pt_matrix[ii][ij];

    return true;
}

template<typename T>
void CMatrix<T> ::operator-(CMatrix<T>& pc_other) {
  if(!v_subtraction(pc_other))
      throw CException(c_error->s_last_error());
}


template <typename T>
bool CMatrix<T> ::v_multiply(CMatrix<T>& pc_other)
{
    if (i_rows != pc_other.i_cols)
    {
        c_error->v_add_error(203);
        return false;
    }


    CMatrix<T> c_result(i_cols, pc_other.i_rows);

    c_result.v_fill_matrix(DEFAULT_ALLOCATE_VALUE);

    for (int ii = 0; ii < c_result.i_rows; ii++)
        for (int ij = 0; ij < c_result.i_rows; ij++)
            for (int ik = 0; ik < i_cols; ik++)
                c_result.pt_matrix[ii][ij] += (pt_matrix[ik][ij] * pc_other.pt_matrix[ii][ik]);



    v_deallocate_space();
    v_allocate_space(i_cols, i_rows);

    for (int ii = 0; ii < i_rows; ii++)
        for (int ij = 0; ij < i_cols; ij++)
            pt_matrix[ii][ij] = c_result.pt_matrix[ii][ij];

    return true; 
}

template<typename T>
void CMatrix<T> ::operator*=( CMatrix<T>& pc_other) {
    if(!v_multiply(pc_other))
        throw CException(c_error->s_last_error());
}


template<typename T>
void CMatrix<T> ::operator=(CMatrix<T>& pc_other) {
    if (this == &pc_other)
    {
        c_error->v_add_error(205);
        return;
    }

    v_deallocate_space();
    v_allocate_space(i_cols, i_rows);

    for (int ii = 0; ii < i_cols; ii++)
        for (int ij = 0; ij < i_rows; ij++)
            pt_matrix[ii][ij] = pc_other.pt_matrix[ii][ij];
}

template <typename T>
bool CMatrix<T> ::v_multiply_by_number(T t_number)
{
    for (int ii = 0; ii < i_rows; ii++)
        for (int ij = 0; ij < i_cols; ij++)
            pt_matrix[ii][ij] = pt_matrix[ii][ij] * t_number;

    return true; 
}

template<typename T>
void CMatrix<T> ::operator*=(T t_number) {
    if(!v_multiply_by_number(t_number))
        throw CException(c_error->s_last_error());
}

template<typename T>
T CMatrix<T> ::operator()(int i_this_x, int i_this_y) {
    if (i_this_x >= i_cols || i_this_y >= i_rows) {
        c_error->v_add_error(204);
        return pt_matrix[0][0];
    }

    return pt_matrix[i_this_x][i_this_y];
}

template<typename T>
vector<T> CMatrix<T> ::v_create_vector_row(int i_pos)
{
    if(i_pos >= i_rows)
    {
        vector<T> v_null;
        c_error->v_add_error(206);
        return v_null;
    }

    vector<T> vec;

    for (int ii = 0; ii < i_cols; ii++)
        vec.push_back(pt_matrix[ii][i_pos]);

    return vec;

}

template<typename T>
vector<T> CMatrix<T> ::v_create_vector_col(int i_pos)
{
    if(i_pos >= i_cols)
    {
        vector<T> v_null;
        c_error->v_add_error(206);
        return v_null;
    }

    vector<T> vec;

    for (int ii = 0; ii < i_cols; ii++)
        vec.push_back(pt_matrix[i_pos][ii]);

    return vec;
}

template <typename T>
void CMatrix<T> ::v_set_value_at(T t_value, int i_this_x, int i_this_y)
{
    if (i_this_x >= i_cols || i_this_y >= i_rows)
    {
        c_error->v_add_error(204);
        i_this_y = DEFAULT_VALUE;
        i_this_x = DEFAULT_VALUE;
    }

    pt_matrix[i_this_x][i_this_y] = t_value;
}

template <typename T>
T CMatrix<T> :: i_scalar_calculate(vector<T> vec1, vector<T> vec2)
{
    if(vec1.size() != vec2.size())
    {
        c_error->v_add_error(207);
        vec2 = vec1;
    }

    T t_tmp = 0;

    for(int ii =0 ; ii<vec1.size(); ii++)
        t_tmp+=(vec1[ii]*vec2[ii]);


    return t_tmp;
}

template <typename T>
void CMatrix<T> ::v_transposition()
{
    int ix = i_rows;
    int iy = i_cols;
    CMatrix<T> c_helper(ix, iy);

    for(int ii = 0 ; ii < i_cols; ii++)
        for(int ij = 0 ; ij < i_rows; ij++)
            c_helper.pt_matrix[ij][ii] = pt_matrix[ii][ij];


    v_deallocate_space();
    v_allocate_space(i_rows, i_cols);



    for (int ii = 0; ii < ix; ii++)
        for (int ij = 0; ij < iy; ij++)
            pt_matrix[ii][ij] = c_helper.pt_matrix[ii][ij];


}