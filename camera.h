#pragma once

#include "vec3.h"

namespace lewis
{
    class Ray;

    class Camera
    {
    public:
        Camera()
            : Camera({ 0.0, 0.0, 0.0 },
              { -2.0, -1.0, -1.0 },
              { 4.0, 0.0, 0.0 },
              { 0.0, 2.0, 0.0 })
        {};
        Camera(const Vec3& origin,
               const Vec3& lowerLeftCorner,
               const Vec3& horizontal,
               const Vec3& vertical)
            : origin_{origin},
              lowerLeftCorner_{lowerLeftCorner},
              horizontal_{horizontal},
              vertical_{vertical}
        {};

        Ray GetRay(double u, double v) const;
    private:
        const Vec3 origin_;
        const Vec3 lowerLeftCorner_;
        const Vec3 horizontal_;
        const Vec3 vertical_;
    };
}