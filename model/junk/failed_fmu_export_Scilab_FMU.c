/*
**    SCILAB FMU. Model Exchange version 1.0.
**    Generated by fmu_wrapper toolbox of Xcos with scilab-2024.0.0
**    Date : 13-Dec-2023
**    Author : 
**    Model description : 
**    Model version : 
*/

/* ---- c include files ---- */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include "scicos_block4.h"
#include "scicos.h"
#include "machine.h"
#ifndef max
#define max(a,b) ((a) >= (b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a) <= (b) ? (a) : (b))
#endif

/* ---- Include FMI header files ---- */
#include "fmiModelFunctions.h"

/* ---- Define model GUID and IDENTIFIER ---- */
#define MODEL_IDENTIFIER failed_fmu_export
#define MODEL_GUID "{648a68b9:18c59b9e096:-7fb6}"

/* ---- Define number of model variables and parameters ---- */
#define ALL_REALS 10
#define ALL_INTEGERS 2
#define ALL_BOOLEANS 0
#define ALL_STRINGS 0
#define ALL_STATES 2
#define ALL_EVENTS 0

/* ---- Define non start value references ---- */
#define NON_START_REAL {1,3}

/* ---- Define inputs/outputs ---- */

/* ---- Define continuous states value references ---- */
#define CONTINUOUS_STATES {0,2}
#if ALL_STATES > 0
   fmiValueReference sciStates[ALL_STATES] = CONTINUOUS_STATES;
#endif
