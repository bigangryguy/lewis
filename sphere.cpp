#include "sphere.h"
#include "vec3.h"
#include "ray.h"

namespace lewis
{
    bool Sphere::Hit(const lewis::Ray &r, double tMin, double tMax, lewis::HitRecord &rec) const
    {
        const Vec3 oc{ r.Origin() - center_ };
        const double a{ dot(r.Direction(), r.Direction()) };
        const double b{ dot(oc, r.Direction()) };
        const double c{ dot(oc, oc) - radius_ * radius_ };
        const double discriminant{ b*b - a*c };

        if (discriminant > 0)
        {
            double temp{ (-b - sqrt(b*b - a*c)) / a };
            if (temp < tMax && temp > tMin )
            {
                rec.t = temp;
                rec.p = r.PointAtParameter(rec.t);
                rec.normal = (rec.p - center_) / radius_;
                return true;
            }
            temp = (-b + sqrt(b*b - a*c)) / a;
            if (temp < tMax && temp > tMin)
            {
                rec.t = temp;
                rec.p = r.PointAtParameter(rec.t);
                rec.normal = (rec.p - center_) / radius_;
                return true;
            }
        }
        return false;
    }
}