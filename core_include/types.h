#pragma once
#ifndef _types_h
#define	_types_h


// These are easy types. If its an unsigned type then its a zone, aisle, bay, den. If its a signed type then we just add an 's to the end. zones, aisles, bays, den. 
// There are hardly any signed types doe.

typedef unsigned long zone;
typedef unsigned int aisle;
typedef unsigned short bay;
typedef unsigned char den;


typedef long zones;
typedef int aisles;
typedef short bays;
typedef char dens;

typedef unsigned int size;


// We leave pare to support the Illeshian language and compiler. The only languages I will support is pure c, nasm, and Illeshian.
#define bool den
#define pare den

#define true    1
#define false   0

#define NULL	0
#define nulled	0




#endif
