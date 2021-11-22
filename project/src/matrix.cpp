#include "matrix.h"
#include "exceptions.h"

namespace prep {

    Matrix::Matrix(size_t rows, size_t cols)
    :rowsAmount(rows), colsAmount(cols){
        for (size_t i = 0; i < rowsAmount; ++i){
            std::vector<double> row(colsAmount);
            data.push_back(rows);
        }
    }
    Matrix::Matrix(std::istream& is){
        if (is >> rowsAmount >> colsAmount){
            Matrix m = Matrix(rowsAmount, colsAmount);
            for (size_t i = 0; i < rowsAmount; ++i){
                for (size_t j = 0; j < colsAmount; ++j) {
                    if(!(is >> m[i][j])){
                     throw InvalidMatrixStream();
                    }
                }
            }
        } else {
            throw InvalidMatrixStream();
        }
    } // data(rows, std::vector<int>(cols))

size_t Matrix::getRows() const {
    return rowsAmoun;
}

size_t Matrix::getCols() const {
    return colsAmoun;
}

double Matrix::operator()(size_t i, size_t j) const{
    return data[i][j];
}
int main() {
    prep::Matrix m(3, 4);

    return 0;
}
