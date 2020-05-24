#include "ray.h"

namespace lewis
{
    Ray::Ray(const Vec3 &origin, const Vec3 &direction)
        : origin_{ origin },
          direction_{ direction }
    {
    }
}
