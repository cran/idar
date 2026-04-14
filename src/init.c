#include <R_ext/RS.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>



/* .C calls */
extern void gowdisC(double *x, double *win, int *type, int *nin, int *pin, double *range2, int *podin, double *tmax, double *tmin, double *res);

/* .Fortran calls */
extern void F77_NAME(mtb)(double *x1, double *y1, double *x2, double *y2, int *l1, int *l2, int *nombresp, int *nsp, double *r, int *nr, int *ltab, double *abu);


static const R_CMethodDef CEntries[] = {
    {"gowdisC", (DL_FUNC) &gowdisC, 10},
    {NULL, NULL, 0}
};

static const R_FortranMethodDef FortranEntries[] = {
    {"mtb", (DL_FUNC) &F77_NAME(mtb), 12},
    {NULL, NULL, 0}
};

void R_init_idar(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, NULL, FortranEntries, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
