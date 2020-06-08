#pragma once

#include "hitable.h"

namespace lewis
{
    class Ray;

    class Sphere : public Hitable
    {
    public:
        Sphere(Vec3 center, double radius)
            : center_{ center },
              radius_{ radius }
        {}

        bool Hit(const Ray& r, double tMin, double tMax, HitRecord& rec) const override;
    private:
        Vec3 center_;
        double radius_;
    };
}