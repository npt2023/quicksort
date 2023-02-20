#ifndef HELPER_H
#define HELPER_H

typedef char Decimal; // A Decimal variable may be 0-9

/* Implement HelperObject as a pointer to an incomplete structure */

typedef struct helper_s *HelperObject;

/* Some functions creating and initializing the ADT */

HelperObject create(void);
void initialize(HelperObject s, const char *pos, Decimal val);
void uninitialize(HelperObject s);
void run(HelperObject s);
Decimal Dec(int i);

#endif
