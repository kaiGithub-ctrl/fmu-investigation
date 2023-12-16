/*
**    SCILAB FMU. Model Exchange version 1.0.
**    Generated by fmu_wrapper toolbox of Xcos with scilab-2024.0.0
**    Date : 13-Dec-2023
**    Author : Kai
**    Model description : i tried so hard
**    Model version : 1.0
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
#define MODEL_IDENTIFIER junk_box_fmu
#define MODEL_GUID "{1fd0349f:18c6644da19:-7f4a}"

/* ---- Define number of model variables and parameters ---- */
#define ALL_REALS 2
#define ALL_INTEGERS 4
#define ALL_BOOLEANS 0
#define ALL_STRINGS 0
#define ALL_STATES 1
#define ALL_EVENTS 0

/* ---- Define non start value references ---- */
#define NON_START_REAL {1}

/* ---- Define inputs/outputs ---- */

/* ---- Define continuous states value references ---- */
#define CONTINUOUS_STATES {0}
#if ALL_STATES > 0
   fmiValueReference sciStates[ALL_STATES] = CONTINUOUS_STATES;
#endif

/* ---- Define continuous state ---- */
#define st_integral_func_5_0 (newInstance->real[0])
#define der_st_integral_func_5_0 (newInstance->real[1])
/* ---- Define integer parameters ---- */
#define input_1_0 (newInstance->integer[0])
#define output_2_1 (newInstance->integer[1])
#define multiplex_4_2 (newInstance->integer[2])
#define output_6_3 (newInstance->integer[3])

/* ---- Define model Instance strings are not supported at the moment in Xcos fmu---- */
typedef struct {
   fmiReal time;
   fmiString GUID;
   fmiString instanceName;
   fmiCallbackFunctions functions;
   fmiBoolean loggingOn;
   fmiBoolean isInstantiated;
   fmiBoolean isInitialized;
   fmiBoolean isTerminated;
   fmiReal *real;
   fmiInteger *integer;
   fmiBoolean *boolean;
   scicos_block block_junk_box_fmu[6];
   fmiBoolean internalEvent[1];
} fmuInstance;

/* ---- Internals functions declaration ---- */
static fmiStatus junk_box_fmu_sciOutputCompute(fmuInstance *, int);
static fmiReal sciGetReal(fmuInstance *, fmiValueReference);
static fmiInteger sciGetInteger(fmuInstance *, fmiValueReference);
static fmiBoolean sciGetBoolean(fmuInstance *, fmiValueReference);
static fmiReal sciGetEvent(fmuInstance *, int);
void set_scicos_time(double);

/* prototype of 'input' (type 0) */
void C2F(input)(int *, int *, double *, double *, double *, int *, double *, \
                int *, double *, int *, double *, int *,int *, int *, \
                double *, int *, double *, int *);

/* prototype of 'output' (type 0) */
void C2F(output)(int *, int *, double *, double *, double *, int *, double *, \
                 int *, double *, int *, double *, int *,int *, int *, \
                 double *, int *, double *, int *);

/* prototype of 'absolute_value' (type 4 - with zcross) */
void absolute_value(scicos_block *, int );

/* prototype of 'multiplex' (type 4) */
void multiplex(scicos_block *, int );

/* prototype of 'integral_func' (type 4) */
void integral_func(scicos_block *, int );

/* ---- General static variables ---- */
static double zero = 0;
static void **junk_box_fmu_block_outtbptr;
static void **work;
static double *args[100];
static int nrd_0 = 0;
static int nrd_1 = 1;
static int nrd_2 = 2;
static double t = 0;
static int mode[] = {0,1,2,3};

/* ---- Initial values ---- */
/* Note that z[]=[z_initial_condition;outtbptr;work]
     outtbptr={0,0,0,0};
     work= {0,0,0,0,0,0};
  */
static double z[]={0,0,0,0,0,0,0,0,0,0};

/* ---- outtb declaration ---- */
static double outtb_1[]={0};
static double outtb_2[]={0,0};
static double outtb_3[]={0};
static double outtb_4[]={0};

/* ---- External simulation function ---- */
static fmiStatus junk_box_fmu_sciOutputCompute(fmuInstance *newInstance, int flag) {
    int nevprt = 1;
    int local_flag, nport, i;
    fmiStatus status = fmiOK;


    /* Get simulation time */
    t = newInstance->time;
