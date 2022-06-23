//
// Created by Ellie Kelemen on 21/06/2022.
//

#include <iostream>
#include <fstream>
#include "sphere.h"
#include "camera.h"
#include "hitablelist.h"
#include "ray.h"

vec3 color(const ray& r, hitable *world) {
    hitrecord rec;
    if (world->hit(r, 0.0, MAXFLOAT, rec)) {
        return 0.5*vec3(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);
    }
    vec3 unitdirection = unitvector(r.direction());
    float t = 0.5*(unitdirection.y() + 1.0);
    return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main() {
    int nx = 2000;
    int ny = 1000;
    int ns = 1000;

    std::ofstream output;
    output.open("output.ppm");

    output << "P3\n" << nx << " " << ny << "\n255\n";


    hitable *list[2];
    list[0] = new sphere(vec3(0,0,-1), 0.5);
    list[1] = new sphere(vec3(0, -100.5, -1), 100);
    hitable *world = new hitablelist(list, 2);
    camera cam;

    for (int j = ny-1; j >= 0; j--)  {
        for (int i = 0; i < nx; i++) {
            vec3 col(0, 0, 0);
            for (int s = 0; s < ns; s++) {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);

                ray r = cam.getray(u, v);
                //vec3 p = r.pointatparameter(2.0);
                col += color(r, world);
            }

            col /= float(ns);

            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);

            output << ir << " " << ig << " " << ib << "\n";
        }
    }
}
