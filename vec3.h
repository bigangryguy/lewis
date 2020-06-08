#pragma once

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

namespace lewis
{
	class Vec3
	{
	private:
		double e_[3];
	public:
        Vec3(double e0, double e1, double e2)
            : e_{e0, e1, e2}
        {
        }
		Vec3() : Vec3(0.0, 0.0, 0.0) {}

		inline double x() const { return e_[0]; }
		inline double y() const { return e_[1]; }
		inline double z() const { return e_[2]; }
		inline double r() const { return e_[0]; }
		inline double g() const { return e_[1]; }
		inline double b() const { return e_[2]; }

		inline const Vec3& operator+() const { return *this; }
		inline Vec3 operator-() const { return {-e_[0], -e_[1], -e_[2]}; }
		inline double operator[](int i) const { return e_[i]; }
		inline double& operator[](int i) { return e_[i]; }

		inline Vec3& operator+=(const Vec3& v2);
		inline Vec3& operator-=(const Vec3& v2);
		inline Vec3& operator*=(const Vec3& v2);
		inline Vec3& operator/=(const Vec3& v2);
		inline Vec3& operator*=(double t);
		inline Vec3& operator/=(double t);

		inline double Length() const
		{
			return sqrt(e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2]);
		}

		inline double SquaredLength() const
		{
			return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2];
		}

		inline void MakeUnitVector();
	};

    typedef std::vector<std::vector<Vec3>> Vec3Matrix;

    inline std::istream& operator>>(std::istream& is, Vec3& t)
    {
        is >> t[0] >> t[1] >> t[2];
        return is;
    }

    inline std::ostream& operator<<(std::ostream& os, const Vec3& t)
    {
        os << t[0] << " " << t[1] << " " << t[2];
        return os;
    }

    inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
    {
        return {v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]};
    }

    inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
    {
        return {v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]};
    }

    inline Vec3 operator*(const Vec3& v1, const Vec3& v2)
    {
        return {v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]};
    }

    inline Vec3 operator/(const Vec3& v1, const Vec3& v2)
    {
        return {v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]};
    }

    inline Vec3 operator*(double t, const Vec3& v)
    {
        return {t * v[0], t * v[1], t * v[2]};
    }

    inline Vec3 operator/(Vec3 v, double t)
    {
        return {v[0] / t, v[1] / t, v[2] / t};
    }

    inline Vec3 operator*(const Vec3& v, double t)
    {
        return {t * v[0], t * v[1], t * v[2]};
    }

    inline double dot(const Vec3& v1, const Vec3& v2)
    {
        return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    }

    inline Vec3 Cross(const Vec3& v1, const Vec3& v2)
    {
        return {v1[1] * v2[2] - v1[2] * v2[1],
                -(v1[0] * v2[2] - v1[2] * v2[0]),
                v1[0] * v2[1] - v1[1] * v2[0]};
    }

    inline Vec3 UnitVector(Vec3 v)
    {
        return v / v.Length();
    }
}