#include "fdf.h"

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point project(t_point p, t_fdf *fdf)
{
    if (fdf->camera.projection == ISO)
        iso(&p.x, &p.y, p.z);
    return p;
}