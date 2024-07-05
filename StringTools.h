/*
 * StringTools.h - a collection of string helping functions because Arduino is SLOW
 */

#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H

 
void StringTools_int2str(int target, char* buff, char len);

void StringTools_float2str(float target, char* buff, char len, char numDec);

#endif