#pragma once

#include "vec3.h"

namespace lewis
{
    class Ray;

    class Camera
    {
    public:
        Camera()
            : origin_{ 0.0, 0.0, 0.0 },
              lowerLeftCorner_{ -2.0, -1.0, -1.0 },
              horizontal_{ 4.0, 0.0, 0.0 },
              vertical_{ 0.0, 2.0, 0.0 }
        {};

        Ray GetRay(double u, double v) const;
    private:
        Vec3 origin_;
        Vec3 lowerLeftCorner_;
        Vec3 horizontal_;
        Vec3 vertical_;
    };
}