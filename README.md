# debug_print
Used to print data in columns with headers to stdout.

## Use example

Sprinkle the calls to DBP_DebugPrint___() throughout your code to output organized data.

The example below shows what the typical output looks like and then shows the code that would generate that output.

### Output

When the code first runs you get this:
| Loops | Sensor_Reading | 
| --- | --- |
|1|42|
|2|42|
|3|42|
|...|...|
|100|42|

Then when the user presses the button, you get this:
| Loops | Sensor_Reading | More_Calculations |
| --- | --- | --- |
|1|42|4242|
|2|42|4242|
|...|...|...|
|100|42|4242|


### Code
```c
#include "debug_print/debug_print.h"
#include <stdint.h>

uint16_t ResultGet(uint16_t num)
{
    uint16_t result = Calculations(num)
    DBP_DebugPrintInt("Calculations", result, 2);
    result = MoreCalculation(result)
    DBP_DebugPrintInt("More_Calculations", result, 1);
    return result;
}

void main(void)
{
    SYS_Initialize();
    
    // Print column headers
    DBP_DataNHeaderSet(0);
    
    // Higher is more verbose 0 prints only 0, 1 prints 1 and 0, etc.
    DBP_VerboseLevelSet(0);
    
    uint16_t loops = 0;
    
    while(1)
    {
        if(ButtonIsPressed())
        {
            // Can change verbose level at run time if need be.
            // In this example now "More_Calculations" column is added.
            DBP_VerboseLevelSet(1);
            
            // If you change the verbose level, you should print the headers again.
            DBP_DataNHeaderSet(0);
            
            loops = 0; // reset
            while(ButtonIsPressed());
        }
        
        DBP_DebugPrintInt("Loops", loops, 0);
        uint16_t data = SensorReadingGet();
        DBP_DebugPrintInt("Sensor_Reading", data, 0);
        
        data = ResultGet(data);
        DoSomthingWithTheResults(data);
        
        if(100 > loops) // Lets only print 100 lines of data
        {
            // Negative Verbose levels are mean you don't want any data printed.
            DBP_VerboseLevelSet(-1);
            loops = 0;
        }
        
        // At the end of the while(1), switch to printing data
        // Now each new pass through the code will print new data
        DBP_DataNHeaderSet(1);
        
        loops++;
    }
}
```

