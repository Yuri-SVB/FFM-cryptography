#ifndef __ARRAY__
#define __ARRAY__

#include "matrix.hpp"
#include <iostream>

template<typename T, typename I>
class LargeArray {
private:
    T* data;
    int size;

public:
    LargeArray(int arraySize) {
        size = arraySize;
        data = new T[size+1];
    }

    ~LargeArray() {
        delete[] data;
    }

    LargeArray encrypt(const T& S) {
		//~ int sdet = S.det();
		//~ LargeArray ret(sdet?this->size:0);
		LargeArray ret(this->size);
		//~ if (sdet) {
			T S_inv = S.inverse();
			for (int i = 0; i < this->size; i++) {
				ret.setValue(i, S*this->getValue(i)*S_inv);
			}
		//~ }
		return ret;
    }

    LargeArray decrypt(const T& S) {
		//~ int sdet = S.det();
		//~ LargeArray ret(sdet?this->size:0);
		LargeArray ret(this->size);
		//~ if (sdet) {
			T S_inv = S.inverse();
			for (int i = 0; i < this->size; i++) {
				ret.setValue(i, S_inv*this->getValue(i)*S);
			}
		//~ }
		return ret;
    }
    
    int getSize() const {
		return this->size;
	}

    void setValue(int index, T value) {
        if (0 <= index && index < size) {
            data[index] = value;
        } else {
            std::cout << "Error: Index out of bounds." << std::endl;
        }
    }

    T getValue(int index) const {
        if (0 <= index && index < size) {
            return data[index];
        } else {
            std::cout << "Error: Index out of bounds." << std::endl;
            return T(); // Returning a default value in case of error.
        }
    }
    
	void hash(I iterations) {
		I	i, j, jp, jpp, det1, det2, size = this->size;
		for (i = 0; i < iterations; ++i) {
			for (j = 0; j < size; ++j) {
				jp = (j+I(1)) % size;
				jpp = (j+I(2)) % size;
				det1 = this->data[jp].det();
				det1 = det1?det1:I(1);
				det2 = this->data[jpp].det() % size;
				this->data[j] = 
				this->data[j] + 
				this->data[det2]*det1;
			}
		}
	}

    // Overloading == operator for matrix comparison
    bool operator==(const LargeArray& target) const {
		if (this->size != target.size) {
			return false;
		} else {
			for (int i = 0; i < this->size; ++i) {
				if (this->getValue(i) != target.getValue(i)) {
					return false;
				}
			}
		}
		return true;
    }

    // Overloading != operator for matrix comparison
    bool operator!=(const LargeArray& other) const {
        return !(*this == other);
    }

    // Overloading << operator for printing
    friend std::ostream& operator<<(std::ostream& os, const LargeArray& array) {
		for (int i = 0, N = array.getSize(); i < N; ++i) {
			os << array.getValue(i) << std::endl;
		}
        return os;
    }
};

#endif
