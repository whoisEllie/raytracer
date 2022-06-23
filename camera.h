//
// Created by Ellie Kelemen on 23/06/2022.
//

#ifndef CAMERAH
#define CAMERAH

#include "ray.h"

class camera {
public:
    camera() {
        lowerleftcorner = vec3(-2.0, -1.0, -1.0);
        horizontal = vec3(4.0, 0.0, 0.0);
        vertical = vec3(0.0, 2.0, 0.0);
        origin = vec3(0.0, 0.0, 0.0);
    }
    ray getray(float u, float v) { return ray(origin, lowerleftcorner + u*horizontal + v*vertical - origin); }

    vec3 origin;
    vec3 lowerleftcorner;
    vec3 horizontal;
    vec3 vertical;

};

#endif //CAMERAH
