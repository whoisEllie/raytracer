//
// Created by Ellie Kelemen on 22/06/2022.
//

#ifndef HITABLE_H
#define HITABLE_H

#include "ray.h"

struct hitrecord {
    float t;
    vec3 p;
    vec3 normal;
};

class hitable {
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hitrecord& rec) const = 0;
};

#endif //HITABLE_H
