#pragma once

#include "hitable.h"
#include <vector>
#include <memory>

namespace lewis
{
    class Ray;

    class HitableList : public Hitable
    {
    public:
        HitableList(const std::vector<std::shared_ptr<Hitable>>& list)
            : list_{ list }
        {}

        virtual bool Hit(const Ray& r, double tMin,
                         double tMax, HitRecord& rec) const;
    private:
        std::vector<std::shared_ptr<Hitable>> list_;
    };
}