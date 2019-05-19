/*================================
  =            Group 30          =
  ================================*/

#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

typedef struct flexarrayrec *flexarray;

extern flexarray flexarray_append(flexarray f, char *str);
extern flexarray flexarray_free(flexarray f);
extern flexarray flexarray_new();
extern void      flexarray_print(flexarray f);
extern int       is_present(flexarray f, char *str);
extern void      visit(flexarray f, void func(char *str));


#endif