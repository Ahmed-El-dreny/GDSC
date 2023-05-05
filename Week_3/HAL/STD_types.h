/*
 * File:   STD_types.h
 * Author: ahmed
 *
 * Created on April 25, 2023, 3:18 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#define CPU_type 8

#if (CPU_type == 8)
    typedef unsigned char boolean;
    typedef unsigned char uint8;
    typedef unsigned short uint16;
    typedef unsigned int uint32;
    typedef signed char sint8;
    typedef signed short sint16;
    typedef signed int sint32;
    typedef double float32;
    typedef float float16;

#elif (CPU_type == 16)
    typedef unsigned char boolean;
    typedef unsigned char uint8;
    typedef unsigned short uint16;
    typedef unsigned int uint32;
    typedef unsigned long long uint64;
    typedef signed char sint8;
    typedef signed short sint16;
    typedef signed int sint32;
    typedef signed long long sint64;
    typedef double float64;
    typedef float float32;

#elif (CPU_type == 32)
    typedef unsigned char boolean;
    typedef unsigned char uint8;
    typedef unsigned short uint16;
    typedef unsigned int uint32;
    typedef unsigned long long uint64;
    typedef signed char sint8;
    typedef signed short sint16;
    typedef signed int sint32;
    typedef signed long long sint64;
    typedef double float64;
    typedef float float32;

#endif

#define NULL ((void*)0)

#endif	/* STD_TYPES_H */
