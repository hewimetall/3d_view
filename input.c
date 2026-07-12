//
// Numeric input helpers shared by the GUI and headless tests.
//

#include "project.h"

int chrbrk(char simb, const char *str) {
  int err = 1;
  for (const char *p = str; *p != '\0' && err; ++p) {
    if (simb == *p) err = 0;
  }
  return err;
}

double validVal(const char *input) {
  char numbs[] = {'1', '2', '3', '4', '5', '6', '7',
                  '8', '9', '0', '.', '-', '\0'};

  int start = 1;
  int dot = 0;
  int err = 0;
  double res = 0;

  for (const char *p = input; *p && !err; ++p) {
    if (chrbrk(*p, numbs)) err++;
    if (*p == '.' && dot == 0) {
      dot++;
    } else if (*p == '.' && dot > 0) {
      err++;
    } else if (*p == '-' && !start) {
      err++;
    }
    start = 0;
  }

  if (!err) {
    sscanf(input, "%lf", &res);
  }

  return res;
}
