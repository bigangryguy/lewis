#pragma once

#include "vec3.h"

namespace lewis
{
    class Ray
    {
    private:
        const Vec3 origin_;
        const Vec3 direction_;
    public:
        Ray() = delete;
        Ray(const Vec3 &origin, const Vec3 &direction);

        Vec3 Origin() const { return origin_; }
        Vec3 Direction() const { return direction_; }
        Vec3 PointAtParameter(double t) const { return origin_ + t * direction_; }
    };
}
