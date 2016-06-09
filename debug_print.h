/*******************************************************************************
 * Debug Print
 *
 * Author:
 *  D. Ryan Bartling
 *
 * File Name:
 *  debug_print.h
 *
 * Summary:
 *  Prints columated debug data.
 *
 * Description:
 *  Provides a method to print debug data out in columns with header row.
 *
 ******************************************************************************/

/*******************************************************************************
The MIT License (MIT)
Copyright (c) 2016 David Ryan Bartling
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 *******************************************************************************/

/**
 * Abbreviations Used:
 * DBP - Debug Print
 */

#ifndef DEBUG_PRINT_H    // Guards against multiple inclusion
#define DEBUG_PRINT_H

//
// Section: Included Files
//

#include <stdbool.h>
#include <stdint.h>

//
// Section: Data Types
//

typedef enum
{
    DBP_HEADING,
    DBP_DATA,
    DBP_BOTH
} DBP_PRINT_MODE_T;

//
// Section: Template Module APIs
//

/**
 *
 * @Summary
 *  TODO: Add Summary
 *
 * @Description
 *  TODO: Add Description
 *
 * @Preconditions
 *  TODO: Add Preconditions
 *
 * @Params
 *  TODO: Add Paramaters
 *
 * @Returns
 *  TODO: Add Returns
 *
 * @Comment
 *  TODO: Add Comments
 *
 * @Example
 *   <code>
 *   //TODO: Add Example
 *   </code>
 *
 * @See Also
 *  TODO: Add references to other functions, typedefs, etc.
 *  
 */

void DBP_PrintIntF(const char* header, int32_t data, int8_t verboseLevel);
void DBP_PrintNewLineF(void);
void DBP_PrintStrF(const char* header, const char* data, int8_t verboseLevel);

void DBP_VerboseLevelSet(int8_t verboseLevel);

// Depricated
void DBP_DataNHeaderSet(bool data_nHeader); 
void DBP_PrintModeSet(DBP_PRINT_MODE_T printMode);

#ifdef DBP_DISABLE
#define DBP_DebugPrintInt(a, b, c) ((void)0)
#define DBP_DebugPrintNewLine() ((void)0)
#define DBP_DebugPrintString(a, b, c) ((void)0)
#else
#define DBP_DebugPrintInt(a, b, c) DBP_PrintIntF(a, b, c)
#define DBP_DebugPrintNewLine() DBP_PrintNewLineF()
#define DBP_DebugPrintString(a, b, c) DBP_PrintStrF(a, b, c)
void DBP_HeaderPrefixSet(const char* newPrefix);
#endif

#endif // FILE_NAME_H

//
// End of File
//
