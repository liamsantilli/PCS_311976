#include <iostream>
#include <concepts>
#include <numeric>

template<typename I>
requires std::integral<I>
class rational {
    I num_;
    I den_;

    void simplify() {
        if (den_ == 0) return;
        I common = std::gcd(num_, den_);
        num_ /= common;
        den_ /= common;
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    rational() : num_(0), den_(1) {}
    
    rational(I n, I d) : num_(n), den_(d) {
        simplify();
    }

    I num() const { return num_; }
    I den() const { return den_; }

    

    rational& operator+=(const rational& other) {
        if (den_ == 0 || other.den_ == 0) {
            num_ = (num_ == 0 || other.num_ == 0) ? 0 : 1;
            den_ = 0;
        } else {
            num_ = num_ * other.den_ + other.num_ * den_;
            den_ = den_ * other.den_;
            simplify();
        }
        return *this;
    }

    rational& operator-=(const rational& other) {
        if (den_ == 0 || other.den_ == 0) {
            num_ = 0; den_ = 0;
        } else {
            num_ = num_ * other.den_ - other.num_ * den_;
            den_ = den_ * other.den_;
            simplify();
        }
        return *this;
    }

    rational& operator*=(const rational& other) {
        num_ *= other.num_;
        den_ *= other.den_;
        simplify();
        return *this;
    }

    rational& operator/=(const rational& other) {
        I next_num = num_ * other.den_;
        I next_den = den_ * other.num_;
        num_ = next_num;
        den_ = next_den;
        simplify();
        return *this;
    }

    

    rational operator+(const rational& other) const { rational ret = *this; return ret += other; }
    rational operator-(const rational& other) const { rational ret = *this; return ret -= other; }
    rational operator*(const rational& other) const { rational ret = *this; return ret *= other; }
    rational operator/(const rational& other) const { rational ret = *this; return ret /= other; }
};

template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {
        os << (r.num() == 0 ? "NaN" : "Inf");
    } else {
        os << r.num() << "/" << r.den();
    }
    return os;
}