#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix() {
    rowN = 1; colN = 1;  data=new float[1] {0.0f};
}

Matrix::Matrix(const int rN, const int cN){
    rowN = rN; colN = cN; data = new float[rN * cN] {0.0f};
}

Matrix::Matrix(const Matrix& srcMatrix){
    rowN = srcMatrix.rowN; colN = srcMatrix.colN; data = new float[srcMatrix.rowN * srcMatrix.colN];
    copy(srcMatrix.data, srcMatrix.data + rowN * colN, data);
}

Matrix::Matrix(const int rN, const int cN, const float* srcPtr){
    rowN=rN; colN = cN; data = new float[rN * cN];
    copy(srcPtr, srcPtr + rN * cN, data);
}

const float* Matrix::getData() const {
    return data;
}

int Matrix::getRowN() const {
    return rowN;
}

int Matrix::getColN() const {
    return colN;
}

void Matrix::print() const {
    for (int i = 0; i < rowN; i++) {
        for (int j = 0; j < colN; j++)
            cout << setw(4) << data[i * colN + j];
        cout << "\n";
    }
}

Matrix Matrix::transpose() {
    Matrix result(colN, rowN);
    for (int i = 0; i < rowN; i++) {
        for (int j = 0; j < colN; j++) {
            result.data[j * rowN + i] = data[i * colN + j];
        }
    }
    return result;
}

Matrix Matrix::operator+(const Matrix& rhsMatrix) const {
    Matrix result(rowN, colN);
    for (int i = 0; i < rowN * colN; i++) {
        result.data[i] = data[i] + rhsMatrix.data[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& rhsMatrix) const {
    Matrix result(rowN, colN);
    for (int i = 0; i < rowN * colN; i++) {
        result.data[i] = data[i] - rhsMatrix.data[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& rhsMatrix) const {
    Matrix result(rowN, colN);
    for (int i = 0; i < rowN * colN; i++) {
        result.data[i] = data[i] * rhsMatrix.data[i];
    }
    return result;
}

float Matrix::operator()(const int r, const int c) const {
    return data[r * colN + c];
}

Matrix& Matrix::operator=(const Matrix& rhsMatrix) {
    if (this != &rhsMatrix) {
        delete[] data;
        rowN = rhsMatrix.rowN;
        colN = rhsMatrix.colN;
        data = new float[rowN * colN];
        copy(rhsMatrix.data, rhsMatrix.data + rowN * colN, data);
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& rhsMatrix) {
    for (int i = 0; i < rowN * colN; i++) {
        data[i] += rhsMatrix.data[i];
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhsMatrix) {
    for (int i = 0; i < rowN * colN; i++) {
        data[i] -= rhsMatrix.data[i];
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& rhsMatrix) {
    for (int i = 0; i < rowN * colN; i++) {
        data[i] *= rhsMatrix.data[i];
    }
    return *this;
}

int Matrix::operator==(const Matrix& rhsMatrix) const {
    return equal(data, data + rowN * colN, rhsMatrix.data);
}

int Matrix::operator!=(const Matrix& rhsMatrix) const {
    return !(*this == rhsMatrix);
}


ostream& operator<<(ostream& out, const Matrix& srcMatrix) {
    for (int i = 0; i < srcMatrix.getRowN(); i++) {
        for (int j = 0; j < srcMatrix.getColN(); j++)
            out << setw(4) << srcMatrix(i, j);
        out << "\n";
    }
    return out;
}
