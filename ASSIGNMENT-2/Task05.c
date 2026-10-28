#include <stdio.h> 
#include "Task05_tariff.h" 
long compute_bill(int units) 
{ 
long paise = FIXED_CHARGE_PAISE;
int slab2 = 0;
int slab3 = 0;
if (units < 0) return -1L;
if (units > SLAB1_UNITS) 
slab2 = units < SLAB2_UNITS ? units - SLAB1_UNITS : SLAB2_UNITS - SLAB1_UNITS;
if (units > SLAB2_UNITS) 
slab3 = units - SLAB2_UNITS;
paise += (long)slab2 * RATE2_PAISE;
paise += (long)slab3 * RATE3_PAISE;
if (units <= SLAB1_UNITS) 
paise += (long)units * RATE1_PAISE;
else 
paise += (long)SLAB1_UNITS * RATE1_PAISE;
#ifdef DEBUG 
Python Programming Assignment — Student Template
fprintf(stderr, "[DEBUG] units=%d slab2=%d slab3=%d bill_paise=%ld\n",
units, slab2, slab3, paise);
#endif
return paise;
}
File: Task05_main.c
#include <stdio.h>
#include "Task05_tariff.h"
int main(void)
{
int units;
printf("Enter units consumed: ");
if (scanf("%d", &units) != 1 || units < 0) {
fprintf(stderr, "Invalid units.\n");
return 1;
}
long paise = compute_bill(units);
printf("Bill = Rs %ld.%02ld\n", paise / 100, paise % 100);
return 0;
}
