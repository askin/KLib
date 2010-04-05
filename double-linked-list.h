#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lib {
  char* name;
  int year;
  char* ISBN;
  struct lib* nextName;
  struct lib* nextYear;
} LIBRARY;

typedef struct hd {
  LIBRARY* name;
  LIBRARY* year;
} head;

/**
 * true 1
 * false 0
 */


int
free_book(LIBRARY* book) {
  /**
   * free(book->name);
   * free(book->ISBN);
   */

  free(book);
}
int
add(head* hd, char* ISBN, char* name, int year) {
  LIBRARY* newPtr = (LIBRARY*)malloc(sizeof(LIBRARY));
  LIBRARY* current;
  LIBRARY* prev;
  int stop = 0;

  // create element
  newPtr->name = name;
  newPtr->year = year;
  newPtr->ISBN = ISBN;
  newPtr->nextName = NULL;
  newPtr->nextYear = NULL;

  // empty
  if(hd->name == NULL) {
    hd->name = newPtr;
    hd->year = newPtr;
    return 1;
  }

  // name
  current = hd->name;
  if(strcmp(name, current->name) < 0) {
    newPtr->nextName = current;
    hd->name = newPtr;
    stop = 1;
  } else {
    prev = current;
    current = prev->nextName;
  }

  while(stop != 1) {
    if(current == NULL) {
      prev->nextName = newPtr;
      stop = 1;
    } else if(strcmp(name, current->name) < 0) {
      prev->nextName = newPtr;
      newPtr->nextName = current;
      stop = 1;
    } else {
      prev = current;
      current = prev->nextName;
    }
  }

  // year
  current = hd->year;
  if(year < current->year) {
    newPtr->nextYear = current;
    hd->year = newPtr;
    return 1;
  } else {
    prev = current;
    current = prev->nextYear;
  }

  while(1) {
    if(current == NULL) {
      prev->nextYear = newPtr;
      return 1;
    } else if(year < current->year) {
      prev->nextYear = newPtr;
      newPtr->nextYear = current;
      return 1;
    } else {
      prev = current;
      current = prev->nextYear;
    }
  }
  return 0;
}

void
list_name( head* hd ) {
  int count = 1;
  LIBRARY* lib = hd->name;
  while(lib != NULL) {
    printf("%d. %s %s %d\n", count++, lib->ISBN, lib->name, lib->year);
    lib = lib->nextName;
  }
}

void
list_year( head* hd ) {
  int count = 1;
  LIBRARY* lib = hd->year;
  while(lib != NULL) {
    printf("%d. %s %s %d\n", count++, lib->ISBN, lib->name, lib->year);
    lib = lib->nextYear;
  }
}

int
remove_book( head* hd, char* ISBN) {
  LIBRARY* year;
  LIBRARY* name;
  LIBRARY* temp;

  if(hd->name == NULL) {
    return 0;
  } else {
    name = hd->name;
    year = hd->year;

    if(strcmp(ISBN, hd->name->ISBN) == 0) {
      hd->name = hd->name->nextName;
    } else {
      while(name->nextName != NULL) {
	if(strcmp(name->nextName->ISBN, ISBN) == 0) {
	  name->nextName = name->nextName->nextName;
	} else {
	  name = name->nextName;
	}
      }
    }

    if(strcmp(ISBN, hd->year->ISBN) == 0) {
      temp = hd->year;
      hd->year = hd->year->nextYear;
      free_book(temp);
      return 1;
    } else {
      while(year->nextYear != NULL) {
	if(strcmp(year->nextYear->ISBN, ISBN) == 0) {
	  temp = name->nextYear;
	  year->nextYear = year->nextYear->nextYear;
	  free_book(temp);
	  return 1;
	} else {
	  year = year->nextYear;
	}
      }
    }
  }
  return 0;
}

void
find_name( head* hd, char* name ) {
  LIBRARY* temp = hd->name;

  while(temp != NULL) {
    if(strcmp(temp->name, name) == 0) {
      printf("%s\t %s\t %d\n", temp->ISBN, temp->name, temp->year);
    }
    temp = temp->nextName;
  }
}

void
find_year( head* hd, int year ) {
  LIBRARY* temp = hd->year;

  while(temp != NULL) {
    if(temp->year == year) {
      printf("%s\t %s\t %d\n", temp->ISBN, temp->name, temp->year);
    }
    temp = temp->nextYear;
  }
}

LIBRARY*
find_isbn( head* hd, char* ISBN ) {
  LIBRARY* temp = hd->name;

  while(temp != NULL) {
    if(strcmp(temp->ISBN, ISBN) == 0) {
      return temp;
    }
    temp = temp->nextName;
  }
  return NULL;
}


#endif
