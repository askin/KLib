#include <stdio.h>
#include "double-linked-list.h"

int main() {

  head hd;
  LIBRARY* lib;
  int count = 1;
  hd.name = NULL;
  hd.year = NULL;

  add(&hd, "2121212", "kelebek", 2010);
  add(&hd, "7867667", "osman", 2008);

  printf("Name ____\n");
  list_name( &hd );
  printf("Year ____\n");
  list_year( &hd );

  find_name(&hd, "kamil");
  printf("__\n");
  find_year(&hd, 2012);

  return 0;
}
