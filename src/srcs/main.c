#include "fdf.h"

int init_camera(t_fdf *fdf)
{
    fdf->camera.projection = ISO;
    return SUCCESS;
}

int main(int ac, char **av)
{
    t_fdf fdf;

    if (ac != 2)
    {
        ft_printf("Bad arguments:\n\t%s filename\n", av[0]);
        return FAILURE;
    }
    fdf.filename = av[1];
    init_camera(&fdf);
    return SUCCESS;
}