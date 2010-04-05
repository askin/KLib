/*
 * cookie.h
 * Under GPL v3.0
 * Askin Yollu - askin@askin.ws
 * http://askin.ws
 */

#ifndef __KELEBEK_COOKIE
#define __KELEBEK_COOKIE
#include <stdio.h>

/**
 * Prototypes
 */
char my_getchar( void );

/**
 * Implementation
 */

/**
 * getchar fonksiyonu kullanildigi zaman, sonda kalan bir satir sonu karakteri
 * bir sonraki getchar fonksiyonunu etkiler
 * bu fonksiyon sadece ilk karakterin alinmasini ve
 *    sonrasinde gelecek fonksiyonlarin etkilenmemesini saglar
 */

char my_getchar( void ) {
  char readedchar;
  char tmpchar;

  readedchar = getchar();

  if(readedchar != '\n') {
    do {
      tmpchar = getchar();
    } while (tmpchar != '\n');
  }

  return readedchar;
}



#endif
