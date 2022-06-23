//
// Created by Ellie Kelemen on 22/06/2022.
//

#ifndef HITABLELISTH
#define HITABLELISTH

#include "hitable.h"

class hitablelist: public hitable {
public:
    hitablelist() {}
    hitablelist(hitable **l, int n) { list = l; listsize = n; }
    virtual bool hit(const ray& r, float tmin, float tmax, hitrecord& rec) const;
    hitable **list;
    int listsize;
};

bool hitablelist::hit(const ray &r, float tmin, float tmax, hitrecord &rec) const {
    hitrecord temprec;
    bool hitanything = false;
    double closestsofar = tmax;
    for (int i = 0; i < listsize; i++) {
        if (list[i]->hit(r, tmin, closestsofar, temprec)) {
            hitanything = true;
            closestsofar = temprec.t;
            rec = temprec;
        }
    }
    return hitanything;
}

#endif //HITABLELISTH
