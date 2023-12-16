/*
**    Code prototype for standalone use
**    Generated by Code_Generation toolbox of Xcos with scilab-2024.0.0
**    Date : 13-Dec-2023
*/

/* To learn how to use the standalone code, type "./standalone -h" */

/* ---- Headers ---- */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include "scicos_block4.h"
#include "machine.h"
#ifndef max
#define max(a,b) ((a) >= (b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a) <= (b) ? (a) : (b))
#endif

/* ---- Internals functions declaration ---- */
int junk_box_sim(double, double, double, int);

void junk_box_sensor(int *, int *, int *, double *,void *, int *,
   int *,int *, int);

void junk_box_actuator(int *, int *, int *, double *, void *, int *,
   int *,int *,int);

/* prototype of 'absolute_value' (type 4 - with zcross) */
void absolute_value(scicos_block *, int );

/* prototype of 'multiplex' (type 4) */
void multiplex(scicos_block *, int );

/* prototype of 'integral_func' (type 4) */
void integral_func(scicos_block *, int );

/* Code prototype for standalone use  */
int C2F(junk_boxsimblk)(double , double *, double *);
int dset(int *n, double *dx, double *dy, int *incy);
int ode1();
int ode2();
int ode4();

/* Table of constant values */
static int nrd_0 = 0;
static int nrd_1 = 1;
static int nrd_2 = 2;
static int nrd_10 = 10;
static int nrd_11 = 11;
static int nrd_81 = 81;
static int nrd_82 = 82;
static int nrd_84 = 84;
static int nrd_811 = 811;
static int nrd_812 = 812;
static int nrd_814 = 814;

/* Some general static variables */
static double zero=0;
static double w[1];
static int aaa=0, bbb=0;
void **junk_box_block_outtbptr;
/* def continuous state */
double x[]={0};
double xd[]={0};
static int c__1 = 1;
static double c_b14 = 0.;
static int neq=1;

char input[50], output[50],s[1],sf[1],se[1],ss[1],**p;
static double sci_time;
static int errflg = 0;
static char *optarg = NULL ;
static int optind = 1, offset = 0 ;
scicos_block block_junk_box[6];

static double RPAR1[1];
/* def integer parameters */
static int IPAR1[ ] = {
/* Routine name of block: capteur1
 * Gui name of block: INPUTPORTEVTS
 * Compiled structure index: 1
 * Exprs: 1
 * ipar= {1};
 */
1,

/* Routine name of block: actionneur1
 * Gui name of block: OUTPUTPORTEVTS
 * Compiled structure index: 2
 * Exprs: 1
 * ipar= {1};
 */
1,

/* Routine name of block: multiplex
 * Gui name of block: MUX
 * Compiled structure index: 4
 * Exprs: 2
 * ipar= {2};
 */
2,

/* Routine name of block: actionneur2
 * Gui name of block: OUTPUTPORTEVTS
 * Compiled structure index: 6
 * Exprs: 2
 * ipar= {2};
 */
2,

};


static void usage();

/* Main program */
int main(int argc, char *argv[])
{
  double tf=30;
  double dt=0.1;
  double h=0.001;
  int solver=3;
  char * progname = argv[0];
  int c;
  strcpy(input,"");
  strcpy(output,"");
  while ((c = getopt(argc , argv, "i:o:d:t:e:s:hv")) != -1)
    switch (c) {
    case 'i':
      strcpy(input,argv[optind-1]);
      break;
    case 'o':
      strcpy(output,argv[optind-1]);
      break;
    case 'd':
      strcpy(s,argv[optind-1]);
      dt=strtod(s,p);
      break;
    case 't':
      strcpy(sf,argv[optind-1]);
      tf=strtod(sf,p);
      break;
    case 'e':
      strcpy(se,argv[optind-1]);
      h=strtod(se,p);
      break;
    case 's':
      strcpy(ss,argv[optind-1]);
      solver=(int) strtod(ss,p);
      break;
    case 'h':
      usage(progname);
      printf("Options : \n");
      printf("     -h for the help  \n");
      printf("     -v for printing the Scilab Version \n");
      printf("     -i for input file name, by default is Terminal \n");
      printf("     -o for output file name, by default is Terminal \n");
      printf("     -d for the clock period, by default is 0.1 \n");
      printf("     -t for the final time, by default is 30 \n");
      printf("     -e for the solvers step size, by default is 0.001 \n");
      printf("     -s integer parameter for select the numerical solver : \n");
      printf("        1 for Euler's method \n");
      printf("        2 for Heun's method \n");
      printf("        3 (default value) for the Fourth-Order Runge-Kutta (RK4) Formula \n");
      return 0;
      break;
    case 'v':
      printf("Generated by Code_Generation toolbox of Xcos "
             "with scilab-2024.0.0 version \n");
      return 0;
      break;
    case '?':
      errflg++;
      break;
    }
    if (errflg){
      usage(progname);
      return 0;
    }
 
  junk_box_sim(tf,dt,h,solver);
  return 0;
}

static void usage(prog)
       char *prog;
{
  fprintf(stderr, "Usage: %s [-h] [-v] [-i arg] [-o arg] "
                  "[-d arg] [-t arg] [-e arg] [-s arg]\n", prog);
}

/*----------------------------------------  External simulation function */
int junk_box_sim(tf,dt,h,solver)

   double tf,dt,h;
   int solver;
{
  double t;
  int nevprt=1;
  int local_flag;
  int nport;
  int i;
  double *args[100];

  double tout;
  double he=0.1;

  /* Initial values */

  /* Note that z[]=[z_initial_condition;outtbptr;work]
     z_initial_condition={};
     outtbptr={0,0,0,0};
     work={0,0,0,0,0,0};
  */

  double z[]={0,0,0,0,0,0,0,0,0,0};

  /* outtb declaration */
  double outtb_1[]={0};
  double outtb_2[]={0,0};
  double outtb_3[]={0};
  double outtb_4[]={0};

  /* work ptr declaration */
  void **work;

  /* Get work ptr of blocks */
  work = (void **)(z+4);

  /* Get outtbptr ptr of blocks */
  junk_box_block_outtbptr = (void **)(z+0);

  junk_box_block_outtbptr[0] = (void *) outtb_1;
  junk_box_block_outtbptr[1] = (void *) outtb_2;
  junk_box_block_outtbptr[2] = (void *) outtb_3;
  junk_box_block_outtbptr[3] = (void *) outtb_4;


  /* set blk struc. of 'capteur1' (type 0 - blk nb 1 - uid ) */
  block_junk_box[0].type   = 0;
  block_junk_box[0].ztyp   = 0;
  block_junk_box[0].ng     = 0;
  block_junk_box[0].nz     = 0;
  block_junk_box[0].noz    = 0;
  block_junk_box[0].nrpar  = 0;
  block_junk_box[0].nopar  = 0;
  block_junk_box[0].nipar  = 1;
  block_junk_box[0].nin    = 0;
  block_junk_box[0].nout   = 1;
  block_junk_box[0].nevout = 0;
  block_junk_box[0].nmode  = 0;
  if ((block_junk_box[0].evout  = calloc(block_junk_box[0].nevout,sizeof(double)))== NULL) return 0;
  if ((block_junk_box[0].inptr  = malloc(sizeof(double*)*block_junk_box[0].nin))== NULL) return 0;
  if ((block_junk_box[0].insz   = malloc(3*sizeof(int)*block_junk_box[0].nin))== NULL) return 0;
  if ((block_junk_box[0].outsz  = malloc(3*sizeof(int)*block_junk_box[0].nout))== NULL) return 0;
  if ((block_junk_box[0].outptr = malloc(sizeof(double*)*block_junk_box[0].nout))== NULL) return 0;
  block_junk_box[0].outptr[0] = junk_box_block_outtbptr[0];
  block_junk_box[0].outsz[0]  = 1;
  block_junk_box[0].outsz[1]  = 1;
  block_junk_box[0].outsz[2]  = SCSREAL_N;
  block_junk_box[0].z = &(z[0]);
  block_junk_box[0].work = (void **)(((double *)work)+0);

  /* set blk struc. of 'actionneur1' (type 0 - blk nb 2 - uid ) */
  block_junk_box[1].type   = 0;
  block_junk_box[1].ztyp   = 0;
  block_junk_box[1].ng     = 0;
  block_junk_box[1].nz     = 0;
  block_junk_box[1].noz    = 0;
  block_junk_box[1].nrpar  = 0;
  block_junk_box[1].nopar  = 0;
  block_junk_box[1].nipar  = 1;
  block_junk_box[1].nin    = 1;
  block_junk_box[1].nout   = 0;
  block_junk_box[1].nevout = 0;
  block_junk_box[1].nmode  = 0;
  if ((block_junk_box[1].evout  = calloc(block_junk_box[1].nevout,sizeof(double)))== NULL) return 0;
  if ((block_junk_box[1].inptr  = malloc(sizeof(double*)*block_junk_box[1].nin))== NULL) return 0;
  if ((block_junk_box[1].insz   = malloc(3*sizeof(int)*block_junk_box[1].nin))== NULL) return 0;
  block_junk_box[1].inptr[0]  = junk_box_block_outtbptr[1];
  block_junk_box[1].insz[0]   = 2;
  block_junk_box[1].insz[1]   = 1;
  block_junk_box[1].insz[2]   = SCSREAL_N;
  if ((block_junk_box[1].outsz  = malloc(3*sizeof(int)*block_junk_box[1].nout))== NULL) return 0;
  if ((block_junk_box[1].outptr = malloc(sizeof(double*)*block_junk_box[1].nout))== NULL) return 0;
  block_junk_box[1].z = &(z[0]);
  block_junk_box[1].work = (void **)(((double *)work)+1);

  /* set blk struc. of 'absolute_value' (type 4 - blk nb 3 - uid ) */
  block_junk_box[2].type   = 4;
  block_junk_box[2].ztyp   = 1;
  block_junk_box[2].ng     = 1;
  block_junk_box[2].nz     = 0;
  block_junk_box[2].noz    = 0;
  block_junk_box[2].nrpar  = 0;
  block_junk_box[2].nopar  = 0;
  block_junk_box[2].nipar  = 0;
  block_junk_box[2].nin    = 1;
  block_junk_box[2].nout   = 1;
  block_junk_box[2].nevout = 0;
  block_junk_box[2].nmode  = 1;
  if ((block_junk_box[2].evout  = calloc(block_junk_box[2].nevout,sizeof(double)))== NULL) return 0;
  if ((block_junk_box[2].inptr  = malloc(sizeof(double*)*block_junk_box[2].nin))== NULL) return 0;
  if ((block_junk_box[2].insz   = malloc(3*sizeof(int)*block_junk_box[2].nin))== NULL) return 0;
  block_junk_box[2].inptr[0]  = junk_box_block_outtbptr[0];
  block_junk_box[2].insz[0]   = 1;
  block_junk_box[2].insz[1]   = 1;
  block_junk_box[2].insz[2]   = SCSREAL_N;
  if ((block_junk_box[2].outsz  = malloc(3*sizeof(int)*block_junk_box[2].nout))== NULL) return 0;
  if ((block_junk_box[2].outptr = malloc(sizeof(double*)*block_junk_box[2].nout))== NULL) return 0;
  block_junk_box[2].outptr[0] = junk_box_block_outtbptr[2];
  block_junk_box[2].outsz[0]  = 1;
  block_junk_box[2].outsz[1]  = 1;
  block_junk_box[2].outsz[2]  = SCSREAL_N;
  block_junk_box[2].z = &(z[0]);
  block_junk_box[2].work = (void **)(((double *)work)+2);

  /* set blk struc. of 'multiplex' (type 4 - blk nb 4 - uid ) */
  block_junk_box[3].type   = 4;
  block_junk_box[3].ztyp   = 0;
  block_junk_box[3].ng     = 0;
  block_junk_box[3].nz     = 0;
  block_junk_box[3].noz    = 0;
  block_junk_box[3].nrpar  = 0;
  block_junk_box[3].nopar  = 0;
  block_junk_box[3].nipar  = 1;
  block_junk_box[3].nin    = 2;
  block_junk_box[3].nout   = 1;
  block_junk_box[3].nevout = 0;
  block_junk_box[3].nmode  = 0;
  if ((block_junk_box[3].evout  = calloc(block_junk_box[3].nevout,sizeof(double)))== NULL) return 0;
  if ((block_junk_box[3].inptr  = malloc(sizeof(double*)*block_junk_box[3].nin))== NULL) return 0;
  if ((block_junk_box[3].insz   = malloc(3*sizeof(int)*block_junk_box[3].nin))== NULL) return 0;
  block_junk_box[3].inptr[0]  = junk_box_block_outtbptr[0];
  block_junk_box[3].inptr[1]  = junk_box_block_outtbptr[2];
  block_junk_box[3].insz[0]   = 1;
  block_junk_box[3].insz[1]   = 1;
  block_junk_box[3].insz[2]   = 1;
  block_junk_box[3].insz[3]   = 1;
  block_junk_box[3].insz[4]   = SCSREAL_N;
  block_junk_box[3].insz[5]   = SCSREAL_N;
  if ((block_junk_box[3].outsz  = malloc(3*sizeof(int)*block_junk_box[3].nout))== NULL) return 0;
  if ((block_junk_box[3].outptr = malloc(sizeof(double*)*block_junk_box[3].nout))== NULL) return 0;
  block_junk_box[3].outptr[0] = junk_box_block_outtbptr[1];
  block_junk_box[3].outsz[0]  = 2;
  block_junk_box[3].outsz[1]  = 1;
  block_junk_box[3].outsz[2]  = SCSREAL_N;
  block_junk_box[3].z = &(z[0]);
  block_junk_box[3].ipar=&(IPAR1[2]);
  block_junk_box[3].work = (void **)(((double *)work)+3);

  /* set blk struc. of 'integral_func' (type 4 - blk nb 5 - uid ) */
  block_junk_box[4].type   = 4;
  block_junk_box[4].ztyp   = 0;
  block_junk_box[4].ng     = 0;
  block_junk_box[4].nz     = 0;
  block_junk_box[4].noz    = 0;
  block_junk_box[4].nrpar  = 0;
  block_junk_box[4].nopar  = 0;
  block_junk_box[4].nipar  = 0;
  block_junk_box[4].nin    = 1;
  block_junk_box[4].nout   = 1;
  block_junk_box[4].nevout = 0;
  block_junk_box[4].nmode  = 0;
  block_junk_box[4].nx = 1;
  block_junk_box[4].x  = &(x[0]);
  block_junk_box[4].xd = &(xd[0]);
  if ((block_junk_box[4].evout  = calloc(block_junk_box[4].nevout,sizeof(double)))== NULL) return 0;
  if ((block_junk_box[4].inptr  = malloc(sizeof(double*)*block_junk_box[4].nin))== NULL) return 0;
  if ((block_junk_box[4].insz   = malloc(3*sizeof(int)*block_junk_box[4].nin))== NULL) return 0;
  block_junk_box[4].inptr[0]  = junk_box_block_outtbptr[0];
  block_junk_box[4].insz[0]   = 1;
  block_junk_box[4].insz[1]   = 1;
  block_junk_box[4].insz[2]   = SCSREAL_N;
  if ((block_junk_box[4].outsz  = malloc(3*sizeof(int)*block_junk_box[4].nout))== NULL) return 0;
  if ((block_junk_box[4].outptr = malloc(sizeof(double*)*block_junk_box[4].nout))== NULL) return 0;
  block_junk_box[4].outptr[0] = junk_box_block_outtbptr[3];
  block_junk_box[4].outsz[0]  = 1;
  block_junk_box[4].outsz[1]  = 1;
  block_junk_box[4].outsz[2]  = SCSREAL_N;
  block_junk_box[4].z = &(z[0]);
  block_junk_box[4].work = (void **)(((double *)work)+4);

  /* set blk struc. of 'actionneur2' (type 0 - blk nb 6 - uid ) */
  block_junk_box[5].type   = 0;
  block_junk_box[5].ztyp   = 0;
  block_junk_box[5].ng     = 0;
  block_junk_box[5].nz     = 0;
  block_junk_box[5].noz    = 0;
  block_junk_box[5].nrpar  = 0;
  block_junk_box[5].nopar  = 0;
  block_junk_box[5].nipar  = 1;
  block_junk_box[5].nin    = 1;
  block_junk_box[5].nout   = 0;
  block_junk_box[5].nevout = 0;
  block_junk_box[5].nmode  = 0;
  if ((block_junk_box[5].evout  = calloc(block_junk_box[5].nevout,sizeof(double)))== NULL) return 0;
  if ((block_junk_box[5].inptr  = malloc(sizeof(double*)*block_junk_box[5].nin))== NULL) return 0;
  if ((block_junk_box[5].insz   = malloc(3*sizeof(int)*block_junk_box[5].nin))== NULL) return 0;
  block_junk_box[5].inptr[0]  = junk_box_block_outtbptr[3];
  block_junk_box[5].insz[0]   = 1;
  block_junk_box[5].insz[1]   = 1;
  block_junk_box[5].insz[2]   = SCSREAL_N;
  if ((block_junk_box[5].outsz  = malloc(3*sizeof(int)*block_junk_box[5].nout))== NULL) return 0;
  if ((block_junk_box[5].outptr = malloc(sizeof(double*)*block_junk_box[5].nout))== NULL) return 0;
  block_junk_box[5].z = &(z[0]);
  block_junk_box[5].work = (void **)(((double *)work)+5);
  if (strlen(input) > 0)
    aaa=1;
  if (strlen(output)> 0)
    bbb=1;

  /* set initial time */
  t=0.0;

  /* Initialization */

  /* Call of 'capteur1' (type 0 - blk nb 1 - uid ) */
  block_junk_box[0].nevprt = 0;
  local_flag = 4;
  nport = 1;
  junk_box_sensor(&local_flag, &nport, &block_junk_box[0].nevprt, \
                  &t, (SCSREAL_COP *)junk_box_block_outtbptr[0], \
                  &nrd_1, &nrd_1, &nrd_10,aaa);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'actionneur1' (type 0 - blk nb 2 - uid ) */
  block_junk_box[1].nevprt = 0;
  local_flag = 4;
  nport = 1;
  junk_box_actuator(&local_flag, &nport, &block_junk_box[1].nevprt, \
                    &t, (SCSREAL_COP *)junk_box_block_outtbptr[1], \
                    &nrd_2, &nrd_1, &nrd_10,bbb);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
  block_junk_box[2].nevprt = 0;
  local_flag = 4;
  absolute_value(&block_junk_box[2],local_flag);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'multiplex' (type 4 - blk nb 4 - uid ) */
  block_junk_box[3].nevprt = 0;
  local_flag = 4;
  multiplex(&block_junk_box[3],local_flag);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
  block_junk_box[4].nevprt = 0;
  local_flag = 4;
  integral_func(&block_junk_box[4],local_flag);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'actionneur2' (type 0 - blk nb 6 - uid ) */
  block_junk_box[5].nevprt = 0;
  local_flag = 4;
  nport = 2;
  junk_box_actuator(&local_flag, &nport, &block_junk_box[5].nevprt, \
                    &t, (SCSREAL_COP *)junk_box_block_outtbptr[3], \
                    &nrd_1, &nrd_1, &nrd_10,bbb);
  if(local_flag < 0) return(5 - local_flag);

    /* Initial blocks must be called with flag 1 */
    /* Call of 'capteur1' (type 0 - blk nb 1 - uid ) */
    block_junk_box[0].nevprt = 0;
    local_flag = 1;
    nport = 1;
    junk_box_sensor(&local_flag, &nport, &block_junk_box[0].nevprt, \
                    &t, (SCSREAL_COP *)junk_box_block_outtbptr[0], \
                    &nrd_1, &nrd_1, &nrd_10,aaa);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'actionneur1' (type 0 - blk nb 2 - uid ) */
    block_junk_box[1].nevprt = 1;
    local_flag = 1;
    nport = 1;
    junk_box_actuator(&local_flag, &nport, &block_junk_box[1].nevprt, \
                      &t, (SCSREAL_COP *)junk_box_block_outtbptr[1], \
                      &nrd_2, &nrd_1, &nrd_10,bbb);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_box[4].nevprt = 0;
    local_flag = 1;
    integral_func(&block_junk_box[4],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'actionneur2' (type 0 - blk nb 6 - uid ) */
    block_junk_box[5].nevprt = 1;
    local_flag = 1;
    nport = 2;
    junk_box_actuator(&local_flag, &nport, &block_junk_box[5].nevprt, \
                      &t, (SCSREAL_COP *)junk_box_block_outtbptr[3], \
                      &nrd_1, &nrd_1, &nrd_10,bbb);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
    block_junk_box[2].nevprt = 1;
    local_flag = 1;
    absolute_value(&block_junk_box[2],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'multiplex' (type 4 - blk nb 4 - uid ) */
    block_junk_box[3].nevprt = 3;
    local_flag = 1;
    multiplex(&block_junk_box[3],local_flag);
    if(local_flag < 0) return(5 - local_flag);


  while (t < tf) {
    /* */
    sci_time=t;

    /* Output computation */

    /* Blocks activated on the event number 0 */
    /* Call of 'capteur1' (type 0 - blk nb 1 - uid ) */
    block_junk_box[0].nevprt = 0;
    local_flag = 1;
    nport = 1;
    junk_box_sensor(&local_flag, &nport, &block_junk_box[0].nevprt, \
                    &t, (SCSREAL_COP *)junk_box_block_outtbptr[0], \
                    &nrd_1, &nrd_1, &nrd_10,aaa);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'actionneur1' (type 0 - blk nb 2 - uid ) */
    block_junk_box[1].nevprt = 1;
    local_flag = 1;
    nport = 1;
    junk_box_actuator(&local_flag, &nport, &block_junk_box[1].nevprt, \
                      &t, (SCSREAL_COP *)junk_box_block_outtbptr[1], \
                      &nrd_2, &nrd_1, &nrd_10,bbb);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_box[4].nevprt = 0;
    local_flag = 1;
    integral_func(&block_junk_box[4],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'actionneur2' (type 0 - blk nb 6 - uid ) */
    block_junk_box[5].nevprt = 1;
    local_flag = 1;
    nport = 2;
    junk_box_actuator(&local_flag, &nport, &block_junk_box[5].nevprt, \
                      &t, (SCSREAL_COP *)junk_box_block_outtbptr[3], \
                      &nrd_1, &nrd_1, &nrd_10,bbb);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
    block_junk_box[2].nevprt = 1;
    local_flag = 1;
    absolute_value(&block_junk_box[2],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'multiplex' (type 4 - blk nb 4 - uid ) */
    block_junk_box[3].nevprt = 3;
    local_flag = 1;
    multiplex(&block_junk_box[3],local_flag);
    if(local_flag < 0) return(5 - local_flag);


    tout=t;

   /* integrate until the cumulative add of the integration
    * time step doesn't cross the sample time step
    */
    while (tout+h<t+dt){
      switch (solver) {
      case 1:
        ode1(C2F(junk_boxsimblk),tout,h);
        break;
      case 2:
        ode2(C2F(junk_boxsimblk),tout,h);
        break;
      case 3:
        ode4(C2F(junk_boxsimblk),tout,h);
        break;
      default :
        ode4(C2F(junk_boxsimblk),tout,h);
        break;
        }
       tout=tout+h;
    }

    /* integration for the remainder piece of time */
    he=t+dt-tout;
    switch (solver) {
    case 1:
      ode1(C2F(junk_boxsimblk),tout,he);
      break;
    case 2:
      ode2(C2F(junk_boxsimblk),tout,he);
      break;
    case 3:
      ode4(C2F(junk_boxsimblk),tout,he);
      break;
    default :
      ode4(C2F(junk_boxsimblk),tout,he);
      break;
    }

    /* update ptrs of continuous array */
    block_junk_box[4].nx = 1;
    block_junk_box[4].x  = &(x[0]);
    block_junk_box[4].xd = &(xd[0]);

    /* update current time */
    t=t+dt;
  }

 sci_time = tf;

  /* Ending */

  /* Call of 'capteur1' (type 0 - blk nb 1 - uid ) */
  block_junk_box[0].nevprt = 0;
  local_flag = 5;
  nport = 1;
  junk_box_sensor(&local_flag, &nport, &block_junk_box[0].nevprt, \
                  &t, (SCSREAL_COP *)junk_box_block_outtbptr[0], \
                  &nrd_1, &nrd_1, &nrd_10,aaa);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'actionneur1' (type 0 - blk nb 2 - uid ) */
  block_junk_box[1].nevprt = 0;
  local_flag = 5;
  nport = 1;
  junk_box_actuator(&local_flag, &nport, &block_junk_box[1].nevprt, \
                    &t, (SCSREAL_COP *)junk_box_block_outtbptr[1], \
                    &nrd_2, &nrd_1, &nrd_10,bbb);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
  block_junk_box[2].nevprt = 0;
  local_flag = 5;
  absolute_value(&block_junk_box[2],local_flag);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'multiplex' (type 4 - blk nb 4 - uid ) */
  block_junk_box[3].nevprt = 0;
  local_flag = 5;
  multiplex(&block_junk_box[3],local_flag);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
  block_junk_box[4].nevprt = 0;
  local_flag = 5;
  integral_func(&block_junk_box[4],local_flag);
  if(local_flag < 0) return(5 - local_flag);

  /* Call of 'actionneur2' (type 0 - blk nb 6 - uid ) */
  block_junk_box[5].nevprt = 0;
  local_flag = 5;
  nport = 2;
  junk_box_actuator(&local_flag, &nport, &block_junk_box[5].nevprt, \
                    &t, (SCSREAL_COP *)junk_box_block_outtbptr[3], \
                    &nrd_1, &nrd_1, &nrd_10,bbb);
  if(local_flag < 0) return(5 - local_flag);

  return 0;
}

/*----------------------------------------  Lapack messag function */
void C2F(xerbla)(char *SRNAME,int *INFO,long int L)
{
  printf("** On entry to %s, parameter number %d"
         "  had an illegal value\n",SRNAME,*INFO);
}

void set_block_error(int err)
{
  return;
}

int get_phase_simulation()
{
  return 1;
}

void * scicos_malloc(size_t size)
{
  return malloc(size);
}

void scicos_free(void *p)
{
  free(p);
}

double get_scicos_time()
{
  return sci_time;
}

void do_cold_restart()
{
  return;
}

void sciprint (char *fmt)
{
  return;
}

int getopt (int argc, char *argv[], char *optstring)
{
  char *group, option, *sopt;
  int len;
  option = -1;
  optarg = NULL;
  while ( optind < argc )
    { 
      group = argv[optind];
      if ( *group != '-' )
        {
         option = -1;
         optarg = group;
         optind++;
         break;
        }
      len = strlen (group);
      group = group + offset;
      if ( *group == '-' )
        {
         group++;
         offset += 2;
        }
      else
        offset++ ;
      option = *group ;
      sopt = strchr ( optstring, option ) ;
      if ( sopt != NULL )
        {
         sopt++ ;
         if ( *sopt == ':' )
           {
             optarg = group + 1;
             if ( *optarg == '\0' )
                optarg = argv[++optind];
             if ( *optarg == '-' )
                {
                 fprintf ( stderr, "\n%s: illegal option -- %c",
                           argv[0], option );
                 option = '?';
                 break;
                }
             else
                {
                 optind++;
                 offset = 0;
                 break;
                }
           }
         if ( offset >= len )
           {
             optind++;
             offset = 0;
           }
         break;
        }
      else
        {
         fprintf ( stderr, "\n%s: illegal option -- %c", argv[0], option );
         option = '?';
         break;
        }
    }
  return ( option );
}

int C2F(junk_boxsimblk)(t, x, xd)

   double t, *x, *xd;

     /*
      *  !purpose
      *  compute state derivative of the continuous part
      *  !syntax
      *  neq   : integer the size of the  continuous state
      *  t     : current time
      *  x     : double precision vector whose contains the continuous state
      *  xd    : double precision vector, contain the computed derivative
      *  of the state
      */
{
  int phase=2;
  int local_flag;
  int nport;
  int nevprt=1;
  double *args[100];
  dset(&neq, &c_b14,xd , &c__1);

    /* Update xd vector ptr */
    block_junk_box[4].x=&(x[0]);
    block_junk_box[4].xd=&(xd[0]);

    /* Call of 'capteur1' (type 0 - blk nb 1 - uid ) */
    block_junk_box[0].nevprt = 0;
    local_flag = 1;
    nport = 1;
    junk_box_sensor(&local_flag, &nport, &block_junk_box[0].nevprt, \
                    &t, (SCSREAL_COP *)junk_box_block_outtbptr[0], \
                    &nrd_1, &nrd_1, &nrd_10,aaa);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_box[4].nevprt = 0;
    local_flag = 1;
    integral_func(&block_junk_box[4],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_box[4].nevprt = 0;
    local_flag = 0;
    integral_func(&block_junk_box[4],local_flag);
    if(local_flag < 0) return(5 - local_flag);


  return 0;
}

int dset(int *n, double *dx, double *dy, int *incy)
{
    int iMax = 0;
    int i = 0, iy = 0;
    --dy;
    if (*n <= 0) return 0;
    iy = 1;
    if (*incy < 0)
    {
      iy = (-(*n) + 1) * *incy + 1;
    }
    iMax = *n;
    for (i = 1; i <= iMax; ++i)
    {
      dy[iy] = *dx;
      iy += *incy;
    }
    return 0;
}

/* Euler's Method */
int ode1(f,t,h)
  int (*f) ();
  double t, h;
{
  int i;

  /**/
  (*f)(t,x, xd);

  for (i=0;i<neq;i++) {
   x[i]=x[i]+h*xd[i];
  }

  return 0;
}

/* Heun's Method */
int ode2(f,t,h)
  int (*f) ();
  double t, h;
{
  int i;
  double y[1],yh[1],temp,f0[1],th;

  /**/
  memcpy(y,x,neq*sizeof(double));
  memcpy(f0,xd,neq*sizeof(double));

  /**/
  (*f)(t,y, f0);

  /**/
  for (i=0;i<neq;i++) {
    x[i]=y[i]+h*f0[i];
  }
  th=t+h;
  for (i=0;i<neq;i++) {
    yh[i]=y[i]+h*f0[i];
  }
  (*f)(th,yh, xd);

  /**/
  temp=0.5*h;
  for (i=0;i<neq;i++) {
    x[i]=y[i]+temp*(f0[i]+xd[i]);
  }

  return 0;
}

/* Fourth-Order Runge-Kutta (RK4) Formula */
int ode4(f,t,h)
  int (*f) ();
  double t, h;
{
  int i;
  double y[1],yh[1],temp,f0[1],th,th2,f1[1],f2[1];

  /**/
  memcpy(y,x,neq*sizeof(double));
  memcpy(f0,xd,neq*sizeof(double));

  /**/
  (*f)(t,y, f0);

  /**/
  for (i=0;i<neq;i++) {
    x[i]=y[i]+h*f0[i];
  }
  th2=t+h/2;
  for (i=0;i<neq;i++) {
    yh[i]=y[i]+(h/2)*f0[i];
  }
  (*f)(th2,yh, f1);

  /**/
  temp=0.5*h;
  for (i=0;i<neq;i++) {
    x[i]=y[i]+temp*f1[i];
  }
  for (i=0;i<neq;i++) {
    yh[i]=y[i]+(h/2)*f1[i];
  }
  (*f)(th2,yh, f2);

  /**/
  for (i=0;i<neq;i++) {
    x[i]=y[i]+h*f2[i];
  }
  th=t+h;
  for (i=0;i<neq;i++) {
    yh[i]=y[i]+h*f2[i];
  }
  (*f)(th2,yh, xd);

  /**/
  temp=h/6;
  for (i=0;i<neq;i++) {
    x[i]=y[i]+temp*(f0[i]+2.0*f1[i]+2.0*f2[i]+xd[i]);
  }

return 0;
}
