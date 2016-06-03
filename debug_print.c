/*******************************************************************************
 * Debug Print
 *
 * Author:
 *  D. Ryan Bartling
 *
 * File Name:
 *  debug_print.c
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

//
// Section: Included Files
//

#include "debug_print.h"
#include "fast_int_to_str/fast_int_to_str.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

//
// Section: Constants
//

#define PREFIX_LENGTH (16)
#define PREFIX_MAX (PREFIX_LENGTH - 1)

//
// Section: Global Variable Declarations
//

// Verbose level of debug print.
// Any debug message equal to this value or less will be printed.
// -1 so debug output is off by default.
int8_t DBP_verboseness = -1;

// When 1, data will get printed.
// When 0, header label will get printed.
bool DBP_dataNHeader = 0;

char DBP_headerPrefix[PREFIX_LENGTH];

//
// Section: Debug Print APIs
//

void DBP_PrintIntF(const char* header, int32_t data, int8_t verboseLevel)
{
    char str[13];
    FAST_IntToStr(str, data);
    DBP_PrintStrF(header, str, verboseLevel);
}

void DBP_PrintNewLineF(void)
{
    int8_t verboseLevel = 0;
    if (verboseLevel <= DBP_verboseness)
    {
        printf("\r\n");
    }
}

void DBP_PrintStrF(const char* header, const char* data, int8_t verboseLevel)
{
    if (verboseLevel <= DBP_verboseness)
    {
        if (false == DBP_dataNHeader)
        {
            printf("%s%s ", DBP_headerPrefix, header);
        }
        else if (true == DBP_dataNHeader)
        {
            printf("%s ", data);
        }
    }
}

void DBP_VerboseLevelSet(int8_t verboseLevel)
{
    DBP_verboseness = verboseLevel;
}

void DBP_DataNHeaderSet(bool data_nHeader)
{
    DBP_dataNHeader = data_nHeader;
}

void DBP_HeaderPrefixSet(const char* newPrefix)
{
    strncpy(DBP_headerPrefix, newPrefix, PREFIX_MAX);
}

//
// End of File
//
