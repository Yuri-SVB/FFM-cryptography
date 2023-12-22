#ifndef __POLYNOMIAL__
#define __POLYNOMIAL__

#include <iostream>

template <typename T, int DPO>	//degree plus one
class ModPolynomial {
private:
    T value[DPO];

public:
    static const T mod;
	
	ModPolynomial(){	
	}
	
    ModPolynomial(T val[DPO]){		 
		for(int i = 0; i<DPO; ++i){
			value[i] = val[i] % mod;
			if(value[i] < 0){
				value[i] += mod;
			}
		}
    }
    //~ T getValue() const {
        //~ return value;
    //~ }

    //~ bool operator<(const ModPolynomial<T, DPO>& other) const {
        //~ return value < other.value;
    //~ }

    ModPolynomial<T, DPO> operator+(const ModPolynomial<T, DPO>& other) const {
		ModPolynomial<T, DPO> sum;
		
        for (int i = 0; i < DPO; i++) {
            sum.value[i] = value[i]  + other.value[i];
        }

        return ModPolynomial<T, DPO>(sum);
    }

    //~ ModPolynomial<T, DPO> operator++() {
		//~ this->value++;
        //~ return *this;
    //~ }

    //~ ModPolynomial<T, DPO> operator--() {
		//~ this->value++;
        //~ return *this;
    //~ }

    //~ ModPolynomial<T, DPO> operator++(int) {
		
        //~ return ModPolynomial<T, DPO>((value + other.value) % mod);
    //~ }

    //~ ModPolynomial<T, DPO> operator-() const {
        //~ return ModPolynomial<T, DPO>((-value) % mod);
    //~ }

    //~ ModPolynomial<T, DPO> operator-(const ModPolynomial<T, DPO>& other) const {
        //~ return ModPolynomial<T, DPO>((value - other.value + mod) % mod);
    //~ }
	
    ModPolynomial<T, DPO> operator*(const ModPolynomial<T, DPO>& other) const {
		ModPolynomial<T, DPO> product;
        for (int i = 0; i < DPO; i++) {
			product.value[i] = 0;
            for (int j = 0; j <= i; j++) {
                product.value[i] += value[j] * other.value[i-j];
            }
        }

        return ModPolynomial<T, DPO>(product);
    }

    //~ ModPolynomial<T, DPO> inv() const {
        //~ T exponent = mod - 2;
        //~ T inverse = 1;
        //~ T base = this->value;
        //~ while (exponent > 0) {
            //~ if (exponent % 2 == 1) {
                //~ inverse = (inverse * base) % mod;
            //~ }
            //~ base = (base * base) % mod;
            //~ exponent /= 2;
        //~ }
        //~ return inverse;
    //~ }
	
	ModPolynomial<T, DPO> operator/(const ModPolynomial<T, DPO>& divisor) const {
		ModPolynomial<T, DPO> quocient, temp2;
		ModPolynomial<T, DPO> temp = *this;
		typename ModPolynomial<T, DPO>::Iter i = temp.poly.begin();
		typename ModPolynomial<T, DPO>::constIter j = divisor.poly.begin();
		int resultSize = 0;

		if (temp.poly.size() < 2) {
			if (i->pow >= j->pow) {
				quocient.value[i->pow - j->pow] = i->coef / j->coef;
				temp = temp - quocient * divisor;
			}
			else {
				quocient.value[0] = 0;
			}
		} else {
			while (true) {
				if (i->pow >= j->pow) {
					quocient.value[i->pow - j->pow] = i->coef / j->coef;
					if (quocient.poly.size() < DPO) {
						temp2 = quocient;
					} else {
						temp2 = quocient;
						resultSize = quocient.poly.size();
						for (int k = DPO; k != resultSize; k--) {
							temp2.value[k - 1] = 0;
						}
					}
					temp = temp - temp2 * divisor;             
				}
				else
					break;

				++i;
				if (i == temp.poly.end())
					break;
			}
		}

		return ModPolynomial<T, DPO>(quocient);
	}

	
    ModPolynomial<T, DPO> operator<<(int other) const {
        return ModPolynomial<T, DPO>((this->value << other) % mod);
    }

    bool operator==(const ModPolynomial<T, DPO>& other) const {
        return value == other.value;
    }

    bool operator!=(const ModPolynomial<T, DPO>& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const ModPolynomial<T, DPO>& mint) {
        return os << mint.value;
    }
};

#endif
