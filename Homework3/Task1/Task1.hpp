#include <iostream>
#include <cmath>
#include <complex>
template <typename T> struct quaternion {
    T x, y, z, w;
    quaternion( T xx = 0, T yy = 0, T zz = 0, T ww = 0) : x(xx), y(yy), z(zz), w(ww) {};
    quaternion operator-() { return quaternion<T> {-x, -y, -z, -w}; }
    quaternion& operator+=(T rhs) { x += rhs; return *this; }
    quaternion& operator+=(quaternion<T> rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w +=rhs.w; return *this; }
    quaternion& operator-=(T rhs) { *this += -rhs; return *this; }
    quaternion& operator-=(quaternion<T> rhs) { *this += -rhs; return *this; }
    quaternion& operator*=(T rhs) { x *= rhs; y *= rhs; z *= rhs; w *= rhs; return *this; }
    quaternion& operator*=(quaternion<T> rhs) { quaternion<T> tmp {
            x * rhs.x - y * rhs.y - z * rhs.z - w * rhs.w,
            x * rhs.y + y * rhs.x + z * rhs.w - w * rhs.z,
            x * rhs.z - y * rhs.w + z * rhs.x + w * rhs.y,
            x * rhs.w + y * rhs.z - z * rhs.y + w * rhs.x
        };
        *this = tmp;
        return *this;
    }
    quaternion& operator/=(T rhs) { *this *= 1 / rhs; return *this; }
    quaternion& operator/=(quaternion<T> rhs) { quaternion<T> tmp(rhs); tmp.inverse(); *this *= tmp;  return *this; }
    quaternion& conj() & { y *= -1; z *= -1; w *= -1; return *this; }
    quaternion& normalize() & { *this /= norm(); return *this; }
    quaternion inverse() { (*this).conj(); *this /= (*this).norm_sq(); return *this; }
    T norm_sq() { return x * x + y * y + z * z + w * w; }
    T norm() { return sqrt(norm_sq); }
    void dump(std::ostream& os) const { os << x << ' ' << y << ' '  << z << ' '  << w;}
};

template <typename T>
bool operator==(quaternion<T> lhs, quaternion<T> rhs) { return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w); }
template <typename T>
bool operator==(quaternion<T> lhs, T rhs) { return (lhs.x == rhs && lhs.y == 0 && lhs.z == 0 && lhs.w == 0);}
template <typename T>
bool operator==(T rhs, quaternion<T> lhs) { return ( lhs.x == rhs && lhs.y == 0 && lhs.z == 0 && lhs.w == 0); }


template <typename T>
quaternion<T> operator+(quaternion<T> lhs, quaternion<T> rhs) { quaternion<T> tmp(lhs); tmp += rhs; return tmp; }
template <typename T>
quaternion<T> operator+(quaternion<T> lhs, T rhs) { quaternion<T> tmp(lhs); tmp += rhs; return tmp; }
template <typename T>
quaternion<T> operator+(T rhs, quaternion<T> lhs) { quaternion<T> tmp(lhs); tmp += rhs; return tmp; }


template <typename T>
quaternion<T> operator-(quaternion<T> lhs, quaternion<T> rhs) { quaternion<T> tmp(lhs); tmp -= rhs; return tmp; }
template <typename T>
quaternion<T> operator-(quaternion<T> lhs, T rhs) { quaternion<T> tmp(lhs); tmp -= rhs; return tmp; }
template <typename T>
quaternion<T> operator-(T rhs, quaternion<T> lhs) { quaternion<T> tmp(lhs); tmp -= rhs; return tmp; }


template <typename T>
quaternion<T> operator*(quaternion<T> lhs, quaternion<T> rhs) { quaternion<T> tmp(lhs); tmp *= rhs; return tmp; }
template <typename T>
quaternion<T> operator*(quaternion<T> lhs, T rhs) { quaternion<T> tmp(lhs); tmp *= rhs; return tmp; }
template <typename T>
quaternion<T> operator*(T rhs, quaternion<T> lhs) { quaternion<T> tmp(lhs); tmp *= rhs; return tmp; }


template <typename T>
quaternion<T> operator/(quaternion<T> lhs, quaternion<T> rhs) { quaternion<T> tmp(lhs); tmp /= rhs; return tmp; }
template <typename T>
quaternion<T> operator/(quaternion<T> lhs, T rhs) { quaternion<T> tmp(lhs); tmp /= rhs; return tmp; }
template <typename T>
quaternion<T> operator/(T rhs, quaternion<T> lhs) { quaternion<T> tmp(lhs); tmp /= rhs; return tmp; }


template <typename T>
std::ostream& operator<<(std::ostream& os, const quaternion<T>& q) {
    q.dump(os);
    return os;
}