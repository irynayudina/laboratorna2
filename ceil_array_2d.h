#pragma once
#include "tableCeil.h"
class ceil_array_2d {
private:
    int cols_;
    tableCeil* data_;
public:
    ceil_array_2d()
    {
       
        cols_ = 100;
        if ( cols_ == 0)
        {
            throw exception("Matrix constructor has 0 size");
        }
        data_ = new tableCeil[ cols_];
    }
    ceil_array_2d(int rows, int cols) 
    {
        
        cols_ = cols;
        if ( cols == 0)
        {
            throw exception("Matrix constructor has 0 size");
        }
        data_ = new tableCeil[ cols];
    }
    ~ceil_array_2d()
    {
        delete[] data_;
    }
    tableCeil& operator[] ( unsigned col) 
    {
        if (col >= cols_)
            throw exception("Matrix subscript out of bounds");
        return data_[col];
    }        // Subscript operators often come in pairs
    tableCeil  operator[] (unsigned col) const
    {
        if ( col >= cols_)
            throw exception("const Matrix subscript out of bounds");
        return data_[ col];
    }// Subscript operators often come in pairs
    ceil_array_2d(const ceil_array_2d& m) 
    {
        this->cols_ = m.cols_;
        if (this->data_ != NULL) {
            delete[] this->data_;
        }
        this->data_ = new tableCeil[ cols_];
            for (int j = 0; j < cols_; j++)
            {
                this->data_[ j] = m.data_[ j];
            } 
        
    } 
    ceil_array_2d& operator= (const ceil_array_2d& m) 
    {
        this->cols_ = m.cols_;
        if (this->data_ != NULL) {
            delete[] this->data_;
        }
        this->data_ = new tableCeil[cols_];
        for (int j = 0; j < cols_; j++)
        {
            this->data_[j] = m.data_[j];
        }
        return *this;
    }
};


