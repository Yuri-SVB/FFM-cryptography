#ifndef __INTEGER__
#define __INTEGER__

#include <iostream>

template <typename T>
class ModInteger {
private:
    T value;

public:
    static const T mod;

    ModInteger(int val = 0) : value(T(val) % mod) {
        if (value < 0) {
            value += mod;
        }
    }

    ModInteger(T val) : value(val % mod) {
        if (value < 0) {
            value += mod;
        }
    }

    T getValue() const {
        return value;
    }

    bool operator<(const ModInteger<T>& other) const {
        return value < other.value;
    }

    ModInteger<T> operator+(const ModInteger<T>& other) const {
        return ModInteger<T>((value + other.value) % mod);
    }

    ModInteger<T> operator++() {
		this->value++;
        return *this;
    }

    ModInteger<T> operator--() {
		this->value++;
        return *this;
    }

    //~ ModInteger<T> operator++(int) {
		
        //~ return ModInteger<T>((value + other.value) % mod);
    //~ }

    ModInteger<T> operator-() const {
        return ModInteger<T>((-value) % mod);
    }

    ModInteger<T> operator-(const ModInteger<T>& other) const {
        return ModInteger<T>((value - other.value + mod) % mod);
    }

    ModInteger<T> operator*(const ModInteger<T>& other) const {
        return ModInteger<T>((value * other.value) % mod);
    }

    ModInteger<T> inv() const {
        T exponent = mod - 2;
        T inverse = 1;
        T base = this->value;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                inverse = (inverse * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return inverse;
    }

    ModInteger<T> operator/(const ModInteger<T>& other) const {
		return *this * other.inv();
	}
	
    ModInteger<T> operator%(const ModInteger<T>& other) const {
		return ModInteger(this->value % other.value);
	}
	
	ModInteger<T>& operator+=(const ModInteger<T>& other) {
    value = value + other.value;
    return *this;
	}
	
	ModInteger<T>& operator-=(const ModInteger<T>& other) {
    value = value - other.value;
    return *this;
	}
	
	operator int() const {
		return this->value.get_ui();
	}
	
    ModInteger<T> operator<<(int other) const {
        return ModInteger<T>((this->value << other) % mod);
    }

    bool operator==(const ModInteger<T>& other) const {
        return value == other.value;
    }

    bool operator!=(const ModInteger<T>& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInteger<T>& mint) {
        return os << mint.value;
    }
};

// Definition of the static member variable
template<typename T>
const T ModInteger<T>::mod = (T(1) << 127) - T(1);
#endif
