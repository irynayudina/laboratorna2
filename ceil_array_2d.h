#pragma once
#include "tableCeil.h"
class ceil_array_2d {
private:
    int rows_, cols_;
    tableCeil* data_;
public:
    ceil_array_2d()
    {
        rows_ = 100;
        cols_ = 100;
        if (rows_ == 0 || cols_ == 0)
        {
            throw exception("Matrix constructor has 0 size");
        }
        data_ = new tableCeil[rows_ * cols_];
    }
    ceil_array_2d(int rows, int cols) 
    {
        rows_ = rows;
        cols_ = cols;
        if (rows == 0 || cols == 0)
        {
            throw exception("Matrix constructor has 0 size");
        }
        data_ = new tableCeil[rows * cols];
    }
    ~ceil_array_2d()
    {
        delete[] data_;
    }
    tableCeil& operator() (unsigned row, unsigned col) 
    {
        if (row >= rows_ || col >= cols_)
            throw exception("Matrix subscript out of bounds");
        return data_[cols_ * row + col];
    }        // Subscript operators often come in pairs
    tableCeil  operator() (unsigned row, unsigned col) const
    {
        if (row >= rows_ || col >= cols_)
            throw exception("const Matrix subscript out of bounds");
        return data_[cols_ * row + col];
    }// Subscript operators often come in pairs
    ceil_array_2d(const ceil_array_2d& m) 
    {
        this->rows_ = m.rows_;
        this->cols_ = m.cols_;
        if (this->data_ != NULL) {
            delete[] this->data_;
        }
        this->data_ = new tableCeil[rows_ * cols_];
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++)
            {
                this->data_[i, j] = m.data_[i, j];
            } 
        }
    } 
    ceil_array_2d& operator= (const ceil_array_2d& m) 
    {
        this->rows_ = m.rows_;
        this->cols_ = m.cols_;
        if (this->data_ != NULL) {
            delete[] this->data_;
        }
        this->data_ = new tableCeil[rows_ * cols_];
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++)
            {
                this->data_[i, j] = m.data_[i, j];
            }
        }
        return *this;
    }
    // ...

};


