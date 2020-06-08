#include "vec3.h"

namespace lewis
{
    inline Vec3& Vec3::operator+=(const Vec3& v)
    {
        this->e_[0] += v[0];
        this->e_[1] += v[1];
        this->e_[2] += v[2];
        return *this;
    }

    inline Vec3& Vec3::operator-=(const Vec3& v)
    {
        this->e_[0] -= v[0];
        this->e_[1] -= v[1];
        this->e_[2] -= v[2];
        return *this;
    }

    inline Vec3& Vec3::operator*=(const Vec3& v)
    {
        this->e_[0] *= v[0];
        this->e_[1] *= v[1];
        this->e_[2] *= v[2];
        return *this;
    }

    inline Vec3& Vec3::operator/=(const Vec3& v)
    {
        this->e_[0] /= v[0];
        this->e_[1] /= v[1];
        this->e_[2] /= v[2];
        return *this;
    }

    inline Vec3& Vec3::operator*=(const double t)
    {
        this->e_[0] *= t;
        this->e_[1] *= t;
        this->e_[2] *= t;
        return *this;
    }

    inline Vec3& Vec3::operator/=(const double t)
    {
        double k = 1.0 / t;

        this->e_[0] *= k;
        this->e_[1] *= k;
        this->e_[2] *= k;
        return *this;
    }

    inline void Vec3::MakeUnitVector()
    {
        double k = 1.0 / sqrt(this->e_[0] * this->e_[0] + this->e_[1] * this->e_[1] + this->e_[2] * this->e_[2]);
        this->e_[0] *= k;
        this->e_[1] *= k;
        this->e_[2] *= k;
    }
}