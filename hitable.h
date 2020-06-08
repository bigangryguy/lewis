#pragma once

#include "vec3.h"

namespace lewis
{
    class Ray;

    struct HitRecord
    {
        double t;
        Vec3 p;
        Vec3 normal;
    };

    class Hitable
    {
    public:
        virtual bool Hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
    };
}