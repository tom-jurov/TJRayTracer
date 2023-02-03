//
// Created by tomas on 2. 2. 2023.
//

#ifndef TJRAYTRACER_MATRIXXD_H
#define TJRAYTRACER_MATRIXXD_H
#include "Point.h"
namespace TJRayTracer {
    template <class T, unsigned int ROWS, unsigned int COLS>
    class MatrixXd {
    public:
        MatrixXd();
        MatrixXd(const MatrixXd<T,ROWS,COLS> &other);
        bool operator==(const MatrixXd<T,ROWS,COLS> &other);
        bool operator!=(const MatrixXd<T,ROWS,COLS> &other);
        MatrixXd<T, ROWS, COLS> operator*(const MatrixXd<T,ROWS,COLS> &other) const;
        Point operator*(const Point &other) const;
        Vector operator*(const Vector &other) const;
        T& operator()(unsigned int row, unsigned int col);
        void identity();
        void transpose();
        T* GetData() const;
        double Determinant();
        unsigned int GetRows() const;
        unsigned int GetCols() const;
    public:
        template<class U, unsigned int U_ROWS, unsigned int U_COLS>
        MatrixXd<U,U_ROWS,U_COLS> submatrix(unsigned int row, unsigned int col);
        double minor(unsigned int row, unsigned int col);
        double cofactor(unsigned int row, unsigned int col);
        MatrixXd<T, ROWS, COLS> inverse();
    private:
        T _data[ROWS*COLS];
        unsigned int _rows = ROWS;
        unsigned int _cols = COLS;
    };

    template<class T, unsigned int ROWS, unsigned int COLS>
    template<class U, unsigned int U_ROWS, unsigned int U_COLS>
    TJRayTracer::MatrixXd<U, U_ROWS, U_COLS> TJRayTracer::MatrixXd<T, ROWS, COLS>::submatrix(unsigned int row, unsigned int col) {
        MatrixXd<U, U_ROWS, U_COLS> result;
        std::size_t k = 0;
        std::size_t l = 0;
        for (std::size_t i=0; i<ROWS;++i)
        {
            k=0;
            for(std::size_t j=0; j<COLS; ++j)
            {
                if(j!=col && i!=row) {
                    result(l,k) = _data[j + i * COLS];
                    k++;
                }
            }
            if(i!=row)
                l++;
        }
        return result;
    }
}

#endif //TJRAYTRACER_MATRIXXD_H
