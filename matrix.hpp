#ifndef __MATRIX__
#define __MATRIX__

#include <iostream>

template<typename T, int N>
class MatrixNxN {
private:
    T data[N][N];
public:
    // Constructor
    //~ MatrixNxN() {} default

    // Getter methods
    T get(int row, int col) const {
        return data[row][col];
    }

    // Setter methods
    void set(int row, int col, T value) {
        data[row][col] = value;
    }

    // Matrix addition
    MatrixNxN operator+(const MatrixNxN& other) const {
        MatrixNxN result(0, 0, 0, 0);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.set(i, j, this->get(i, j) + other.get(i, j));
            }
        }
        return result;
    }

    // Matrix multiplication
    MatrixNxN operator*(const MatrixNxN& other) const {
        MatrixNxN result(0, 0, 0, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    result.set(i, j, result.get(i, j) + this->get(i, k) * other.get(k, j));
                }
            }
        }
        return result;
    }

    // Overloading + operator for scalar addition
    MatrixNxN operator+(const T& scalar) const {
        MatrixNxN result(0, 0, 0, 0);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.set(i, j, (this->get(i, j) + scalar) % 31);
            }
        }
        return result;
    }

    // Overloading * operator for scalar multiplication
    MatrixNxN operator*(const T& scalar) const {
        MatrixNxN result(0, 0, 0, 0);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.set(i, j, this->get(i, j) * scalar);
            }
        }
        return result;
    }
    
    // Overloading == operator for matrix comparison
    bool operator==(const MatrixNxN& other) const {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (this->get(i, j) != other.get(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }

    // Overloading != operator for matrix comparison
    bool operator!=(const MatrixNxN& other) const {
        return !(*this == other);
    }

    // Determinant calculation
    T det() const {
        return ((this->get(0, 0) * this->get(1, 1)) - (this->get(0, 1) * this->get(1, 0)));
    }

    // Inverse calculation using extended Euclidean algorithm
    MatrixNxN inverse() const {
        T detInv = this->det().inv();
        MatrixNxN result(
            (this->get(1, 1) * detInv),
            (-this->get(0, 1) * detInv),
            (-this->get(1, 0) * detInv),
            (this->get(0, 0) * detInv)
        );

        return result;
    }
    
    // Overloading << operator for printing
    friend std::ostream& operator<<(std::ostream& os, const MatrixNxN& matrix) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                os << matrix.get(i, j) << " ";
            }
            os << std::endl;
        }
        return os;
    }
    
    //Encryption
    MatrixNxN encrypt(const MatrixNxN& key) const {
		return key*(*this)*(key.inverse());
	}
    
    MatrixNxN decrypt(const MatrixNxN& key) const {
		return (key.inverse())*(*this)*key;
	}
    
	MatrixNxN homohash(int t, int kb, const MatrixNxN& key) const {
		MatrixNxN holder = this->encrypt(key);
		holder = holder.hash();
		return holder.decrypt(key);
	}
};

#endif
