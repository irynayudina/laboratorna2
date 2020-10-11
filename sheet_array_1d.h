#pragma once
#include "sheet.h"
#include "ceil_array_2d.h"
class sheet_array_1d
{
private:
    int rows_;
    ceil_array_2d* data_;
public:
    sheet_array_1d()
    {
        rows_ = 100;
        if (rows_ == 0 )
        {
            throw exception("Matrix constructor has 0 size");
        }
        data_ = new ceil_array_2d[rows_];
    }
    sheet_array_1d(int rows)
    {
        rows_ = rows;
        
        if (rows == 0 )
        {
            throw exception("Matrix constructor has 0 size");
        }
        data_ = new ceil_array_2d[rows ];
    }
    ~sheet_array_1d()
    {
        delete[] data_;
    }
    ceil_array_2d& operator[] (unsigned row)
    {
        if (row >= rows_)
            throw exception("Matrix subscript out of bounds");
        return data_[row];
    }
    ceil_array_2d  operator[] (unsigned row) const
    {
        if (row >= rows_ )
            throw exception("const Matrix subscript out of bounds");
        return data_[row ];
    }
    sheet_array_1d(const sheet_array_1d& m)
    {
        this->rows_ = m.rows_;
        if (this->data_ != NULL) {
            delete[] this->data_;
        }
        this->data_ = new ceil_array_2d[rows_];
        for (int i = 0; i < rows_; i++) 
        {
                this->data_[i] = m.data_[i];
            
        }
    }
    sheet_array_1d& operator= (const sheet_array_1d& m)
    {
        this->rows_ = m.rows_;
        if (this->data_ != NULL) {
            delete[] this->data_;
        }
        this->data_ = new ceil_array_2d[rows_];
        for (int i = 0; i < rows_; i++) {
            
                this->data_[i] = m.data_[i];
            
        }
        return *this;
    }
};

