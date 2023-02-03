//
// Created by tomas on 2. 2. 2023.
//

#include "MatrixXd.h"
#include <iostream>
#include "Equal.h"
template <class T, unsigned int ROWS, unsigned int COLS>
TJRayTracer::MatrixXd<T,ROWS,COLS>::MatrixXd()
{
    for(std::size_t y=0; y<ROWS; ++y)
    {
        for(std::size_t x=0; x<COLS; ++x)
        {
            _data[x + y*COLS] = 0.0;
        }
    }
}


template<class T, unsigned int ROWS, unsigned int COLS>
T &TJRayTracer::MatrixXd<T, ROWS, COLS>::operator()(unsigned int row, unsigned int col) {
    if(row<ROWS && col<COLS) {
        return _data[col + row*COLS];
    }
    else
    {
        throw std::invalid_argument("Accessing element out of range");
    }
}

template<class T, unsigned int ROWS, unsigned int COLS>
bool TJRayTracer::MatrixXd<T, ROWS, COLS>::operator==(const MatrixXd<T, ROWS, COLS> &other) {
    bool flag = true;
    if ((this != nullptr) && (&other != nullptr) && (ROWS == other.GetRows()) && (COLS == other.GetCols())) {
        for (std::size_t i = 0; i < ROWS * COLS; ++i) {
            if (!equal(_data[i], other.GetData()[i])) {
                flag = false;
            }
        }
    }
    return flag;
}

template<class T, unsigned int ROWS, unsigned int COLS>
bool TJRayTracer::MatrixXd<T, ROWS, COLS>::operator!=(const MatrixXd<T, ROWS, COLS> &other) {
    return !(*this==other);
}

template<class T, unsigned int ROWS, unsigned int COLS>
TJRayTracer::MatrixXd<T,ROWS,COLS> TJRayTracer::MatrixXd<T, ROWS, COLS>::operator*(const MatrixXd<T, ROWS, COLS> &other) const{
    MatrixXd<T, ROWS, COLS> result;
    for (std::size_t i=0; i<ROWS;++i)
    {
        for(std::size_t j=0; j<COLS; ++j)
        {
            for (std::size_t k=0; k<COLS; ++k)
            {
                result(i,j) += _data[k+i*COLS] * other.GetData()[j+k*COLS];
            }
        }
    }
    return result;
}

template<class T, unsigned int ROWS, unsigned int COLS>
TJRayTracer::Point TJRayTracer::MatrixXd<T, ROWS, COLS>::operator*(const TJRayTracer::Point &other) const {
    TJRayTracer::Point result;
    result.x = _data[0+0*COLS]*other.x + _data[1+0*COLS]*other.y + _data[2+0*COLS]*other.z + _data[3+0*COLS]*other.w;
    result.y = _data[0+1*COLS]*other.x + _data[1+1*COLS]*other.y + _data[2+1*COLS]*other.z + _data[3+1*COLS]*other.w;
    result.z = _data[0+2*COLS]*other.x + _data[1+2*COLS]*other.y + _data[2+2*COLS]*other.z + _data[3+2*COLS]*other.w;
    result.w = _data[0+3*COLS]*other.x + _data[1+3*COLS]*other.y + _data[2+3*COLS]*other.z + _data[3+3*COLS]*other.w;
    return result;
}

template<class T, unsigned int ROWS, unsigned int COLS>
void TJRayTracer::MatrixXd<T, ROWS, COLS>::identity() {
    for( std::size_t i = 0; i<ROWS; ++i)
    {
        _data[i+i*COLS] = 1;
    }
}

template<class T, unsigned int ROWS, unsigned int COLS>
void TJRayTracer::MatrixXd<T, ROWS, COLS>::transpose()
{
    for (std::size_t i=0; i<ROWS; ++i)
    {
        for(std::size_t j=0; j<i; ++j)
        {
            std::swap(_data[j + i*COLS],_data[i + j*COLS]);
        }
    }
}

template<class T, unsigned int ROWS, unsigned int COLS>
T* TJRayTracer::MatrixXd<T, ROWS, COLS>::GetData() const{
    static T temp[ROWS*COLS];
    for (std::size_t i=0; i<ROWS;++i)
    {
        for(std::size_t j=0; j<COLS; ++j)
        {
            temp[j + i*COLS] = _data[j + i*COLS];
        }
    }
    return temp;
}

template<class T, unsigned int ROWS, unsigned int COLS>
unsigned int TJRayTracer::MatrixXd<T, ROWS, COLS>::GetRows() const {
    return _rows;
}

template<class T, unsigned int ROWS, unsigned int COLS>
unsigned int TJRayTracer::MatrixXd<T, ROWS, COLS>::GetCols() const {
    return _cols;
}

template<class T, unsigned int ROWS, unsigned int COLS>
TJRayTracer::MatrixXd<T, ROWS, COLS>::MatrixXd(const TJRayTracer::MatrixXd<T, ROWS, COLS> &other) {
    for (std::size_t i=0; i<ROWS;++i)
    {
        for(std::size_t j=0; j<COLS; ++j)
        {
            _data[j + i*COLS] = other.GetData()[j + i*COLS];
        }
    }
}

template<class T, unsigned int ROWS, unsigned int COLS>
double TJRayTracer::MatrixXd<T, ROWS, COLS>::minor(unsigned int row, unsigned int col) {
    return this->template submatrix<double,ROWS-1,COLS-1>(row,col).Determinant();
}

template<class T, unsigned int ROWS, unsigned int COLS>
double TJRayTracer::MatrixXd<T, ROWS, COLS>::cofactor(unsigned int row, unsigned int col) {
    if(COLS==4)
    {
        TJRayTracer::MatrixXd<double,4,4> temp;
        for (std::size_t i=0; i<ROWS;++i)
        {
            for(std::size_t j=0; j<COLS; ++j)
            {
                if(((i+j)%2)!=0)
                {
                    temp(i,j)= -(*this)(i,j);
                }
                else{
                    temp(i,j) = (*this)(i,j);
                }
            }
        }
        return temp.template submatrix<double, 3, 3>(row, col).Determinant();

    }
    if(COLS==3)
    {
        TJRayTracer::MatrixXd<double,3,3> temp;
        for (std::size_t i=0; i<ROWS;++i)
        {
            for(std::size_t j=0; j<COLS; ++j)
            {
                if(((i+j)%2)!=0)
                {
                    temp(i,j)= -(*this)(i,j);
                }
                else{
                    temp(i,j) = (*this)(i,j);
                }
            }
        }
        return temp.template submatrix<double, 2, 2>(row, col).Determinant();

    }
    return -1;
}

template<class T, unsigned int ROWS, unsigned int COLS>
double TJRayTracer::MatrixXd<T, ROWS, COLS>::Determinant() {
    double det = 0;
    if(COLS==2)
    {
        det = (*this)(0,0)*(*this)(1,1) - (*this)(0,1)*(*this)(1,0);
    }
    else if(COLS>=3)
    {
        for (std::size_t i=0;i<COLS;++i)
        {
            det = det + (*this)(0,i)* ((*this).cofactor(0,i));
        }
    }
    return det;
}

template<class T, unsigned int ROWS, unsigned int COLS>
TJRayTracer::MatrixXd<T, ROWS, COLS> TJRayTracer::MatrixXd<T, ROWS, COLS>::inverse() {
    if(equal(this->Determinant(),0))
    {
        throw std::invalid_argument("Bad matrix");
    }
    MatrixXd<T,ROWS,COLS> result;
    for (std::size_t y = 0; y<ROWS; ++y)
    {
        for (std::size_t x = 0; x<COLS; ++x)
        {
            double c = this->cofactor(y,x);
            result(x,y) = c/(this->Determinant());
        }
    }
    return result;
}

template<class T, unsigned int ROWS, unsigned int COLS>
TJRayTracer::Vector TJRayTracer::MatrixXd<T, ROWS, COLS>::operator*(const TJRayTracer::Vector &other) const {
    Vector result;
    result.x = _data[0+0*COLS]*other.x + _data[1+0*COLS]*other.y + _data[2+0*COLS]*other.z + _data[3+0*COLS]*other.w;
    result.y = _data[0+1*COLS]*other.x + _data[1+1*COLS]*other.y + _data[2+1*COLS]*other.z + _data[3+1*COLS]*other.w;
    result.z = _data[0+2*COLS]*other.x + _data[1+2*COLS]*other.y + _data[2+2*COLS]*other.z + _data[3+2*COLS]*other.w;
    result.w = _data[0+3*COLS]*other.x + _data[1+3*COLS]*other.y + _data[2+3*COLS]*other.z + _data[3+3*COLS]*other.w;
    return result;
}


// explicit instantiations
template class TJRayTracer::MatrixXd<double, 4, 4>;
template class TJRayTracer::MatrixXd<double, 3, 3>;
template class TJRayTracer::MatrixXd<double, 2, 2>;
