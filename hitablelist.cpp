#include "hitablelist.h"
#include "vec3.h"
#include "ray.h"

namespace lewis
{
    bool HitableList::Hit(const Ray& r, double tMin,
                      double tMax, HitRecord& rec) const
    {
        HitRecord tempRec;
        bool hitAnything = false;
        double closestSoFar = tMax;
        for (auto i = 0; i < list_.size(); i++)
        {
            if (list_[i]->Hit(r, tMin, closestSoFar, tempRec))
            {
                hitAnything = true;
                closestSoFar = tempRec.t;
                rec = tempRec;
            }
        }
        return hitAnything;
    }
}
