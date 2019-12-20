/***************************************************
 * writing header file test
 * Modification time:2019.11.1
 * Author: phd1998.wicp.vip
 * *************************************************/

#ifndef _hello_h
#define _hello_h

int c = 10;
#ifndef chg
#define chg(a,b) \
{\
    int temp = *a;\
    *a = *b;\
    *b = temp;\
}
#endif

#endif

