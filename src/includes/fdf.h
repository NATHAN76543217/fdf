#ifndef FDF_H
# define FDF_H

# define ISO 1
# define TRUE_ISO 2
# define SUCCESS 0
# define FAILURE 1

#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "mlx.h"

typedef int     fdf_type;

typedef struct  s_camera
{
    int projection;
}               t_camera;

typedef struct  s_fdf {
    char    *filename;
    t_camera    camera;
}               t_fdf;

typedef struct  s_point {
    fdf_type     x;
    fdf_type     y;
    fdf_type     z;
}               t_point;
#endif