#include "camera.h"
#include "ray.h"

namespace lewis
{
    Ray Camera::GetRay(double u, double v) const
    {
        return Ray{ origin_, lowerLeftCorner_ + u * horizontal_ + v * vertical_ - origin_ };
    }
}