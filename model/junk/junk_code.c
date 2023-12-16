/*
**    SCILAB Computational function
**    Generated by Code_Generation toolbox of Xcos with scilab-2024.0.0
**    Date : 13-Dec-2023
*/

/* ---- Headers ---- */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "machine.h" 
#include "scicos.h" 
#include "scicos_malloc.h" 
#include "scicos_free.h" 
#ifndef max
#define max(a,b) ((a) >= (b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a) <= (b) ? (a) : (b))
#endif

/* prototype of 'absolute_value' (type 4 - with zcross) */
void absolute_value(scicos_block *, int );

/* prototype of 'multiplex' (type 4) */
void multiplex(scicos_block *, int );

/* prototype of 'integral_func' (type 4) */
void integral_func(scicos_block *, int );

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

/*---------------------------------------- Block Computational function */ 
int  junk_code(scicos_block *block, int flag)
{
  /* declaration of local variables for that block struct */
  double* z      = block->z;
  void **ozptr   = block->ozptr;
  void **oparptr = block->oparptr;
  int nopar      = block->nopar;
  double* x      = block->x;
  double* xd     = block->xd;
  double* res    = block->res;
  void** u       = block->inptr;
  void** y       = block->outptr;
  int nevprt     = block->nevprt;
  double* rpar   = block->rpar;
  int nrpar      = block->nrpar;
  int* ipar      = block->ipar;
  int nipar      = block->nipar;
  double* g      = block->g;
  int* mode      = block->mode;
  void **work    = block->work;

  double t     = get_scicos_time();
  int    phase = get_phase_simulation();

  int kf = 0;
  int i = 0;
  int* reentryflag = NULL;

  double *args[100];
  int local_flag;
  int nport;
  void **junk_code_block_outtbptr;
  scicos_block *block_junk_code;

  /*  work of blocks are catenated at the end of z */
  work = (void **)(z+0);

  /*  junk_code_block_outtbptr is catenated at the end of oz */
  junk_code_block_outtbptr = (void **)(ozptr+0);

  /* struct of all blocks are stored in work of that block struct */
  block_junk_code=(scicos_block*) *block->work;

  /* Copy inputs in the block outtb */
  memcpy(*(junk_code_block_outtbptr+0),*(u+0),1*sizeof(double));

  if (flag != 4 && flag != 6 && flag != 5){
    reentryflag=(int*) ((scicos_block *)(*block->work)+6);
    if (*reentryflag==0){
      *reentryflag=1;

      /* set blk struc. of 'capteur1' (type 0 - blk nb 1 - uid ) */
      block_junk_code[0].outptr[0] = junk_code_block_outtbptr[0];
      block_junk_code[0].z         = &(z[0]);
      block_junk_code[0].x         = &(zero);
      block_junk_code[0].xd        = w;
      block_junk_code[0].g         = &(zero);
      block_junk_code[0].work      = (void **)(((double *)work)+0);

      /* set blk struc. of 'actionneur1' (type 0 - blk nb 2 - uid ) */
      block_junk_code[1].inptr[0]  = junk_code_block_outtbptr[1];
      block_junk_code[1].z         = &(z[0]);
      block_junk_code[1].x         = &(zero);
      block_junk_code[1].xd        = w;
      block_junk_code[1].g         = &(zero);
      block_junk_code[1].work      = (void **)(((double *)work)+1);

      /* set blk struc. of 'absolute_value' (type 4 - blk nb 3 - uid ) */
      block_junk_code[2].inptr[0]  = junk_code_block_outtbptr[0];
      block_junk_code[2].outptr[0] = junk_code_block_outtbptr[2];
      block_junk_code[2].z         = &(z[0]);
      block_junk_code[2].x         = &(zero);
      block_junk_code[2].xd        = w;
      block_junk_code[2].g         = &(g[0]);
      block_junk_code[2].mode      = &(mode[0]);
      block_junk_code[2].work      = (void **)(((double *)work)+2);

      /* set blk struc. of 'multiplex' (type 4 - blk nb 4 - uid ) */
      block_junk_code[3].inptr[0]  = junk_code_block_outtbptr[0];
      block_junk_code[3].inptr[1]  = junk_code_block_outtbptr[2];
      block_junk_code[3].outptr[0] = junk_code_block_outtbptr[1];
      block_junk_code[3].z         = &(z[0]);
      block_junk_code[3].x         = &(zero);
      block_junk_code[3].xd        = w;
      block_junk_code[3].g         = &(zero);
      block_junk_code[3].ipar      = &(ipar[2]);
      block_junk_code[3].work      = (void **)(((double *)work)+3);

      /* set blk struc. of 'integral_func' (type 4 - blk nb 5 - uid ) */
      block_junk_code[4].inptr[0]  = junk_code_block_outtbptr[0];
      block_junk_code[4].outptr[0] = junk_code_block_outtbptr[3];
      block_junk_code[4].z         = &(z[0]);
      block_junk_code[4].x         = &(x[0]);
      block_junk_code[4].g         = &(zero);
      block_junk_code[4].work      = (void **)(((double *)work)+4);

      /* set blk struc. of 'actionneur2' (type 0 - blk nb 6 - uid ) */
      block_junk_code[5].inptr[0]  = junk_code_block_outtbptr[3];
      block_junk_code[5].z         = &(z[0]);
      block_junk_code[5].x         = &(zero);
      block_junk_code[5].xd        = w;
      block_junk_code[5].g         = &(zero);
      block_junk_code[5].work      = (void **)(((double *)work)+5);
    }
  }

  if (flag == 0) { /* Continuous state computation */
    /* Update xd vector ptr */
    block_junk_code[4].xd=&(xd[0]);

    /* Call of 'capteur1' (type 0 - blk nb 1 - uid ) */
    block_junk_code[0].nevprt = 0;
    local_flag = 1;
    nport = 1;
    junk_code_sensor(&local_flag, &nport, &block_junk_code[0].nevprt, \
                     &t, (SCSREAL_COP *)junk_code_block_outtbptr[0], \
                     &nrd_1, &nrd_1, &nrd_10,aaa);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_code[4].nevprt = 0;
    local_flag = 1;
    integral_func(&block_junk_code[4],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_code[4].nevprt = 0;
    local_flag = 0;
    integral_func(&block_junk_code[4],local_flag);
    if(local_flag < 0) return(5 - local_flag);

  }
  else if (flag == 1) { /* Output computation */
    switch (nevprt) {
      case 0 : /* Blocks activated on the event number 0 */
        /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
        block_junk_code[4].nevprt = 0;
        local_flag = 1;
        integral_func(&block_junk_code[4],local_flag);
        if(local_flag < 0) return(5 - local_flag);
    
        /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
        block_junk_code[2].nevprt = 1;
        local_flag = 1;
        absolute_value(&block_junk_code[2],local_flag);
        if(local_flag < 0) return(5 - local_flag);
    
        /* Call of 'multiplex' (type 4 - blk nb 4 - uid ) */
        block_junk_code[3].nevprt = 3;
        local_flag = 1;
        multiplex(&block_junk_code[3],local_flag);
        if(local_flag < 0) return(5 - local_flag);
    
      break;

    }
  }
  else if (flag == 9) { /* Update zero crossing surfaces */
    /* Update g vector ptr */
    block_junk_code[2].g=&(g[0]);

    /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
    block_junk_code[2].nevprt = 1;
    local_flag = 1;
    absolute_value(&block_junk_code[2],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
    block_junk_code[2].nevprt = 1;
    local_flag = 9;
    absolute_value(&block_junk_code[2],local_flag);
    if(local_flag < 0) return(5 - local_flag);

  }
  else if (flag == 4) { /* Initialization */
    if ((*block->work=scicos_malloc(sizeof(scicos_block)*6+sizeof(int)))== NULL) return 0;
    reentryflag=(int*) ((scicos_block *)(*block->work)+6);
    *reentryflag=0;
    block_junk_code=(scicos_block*) *block->work;

    /* set blk struc. of 'capteur1' (type 0 - blk nb 1 - uid ) */
    block_junk_code[0].type   = 0;
    block_junk_code[0].ztyp   = 0;
    block_junk_code[0].ng     = 0;
    block_junk_code[0].nx     = 0;
    block_junk_code[0].x      = &(zero);
    block_junk_code[0].xd     = w;
    block_junk_code[0].g      = &(zero);
    block_junk_code[0].nz     = 0;
    block_junk_code[0].noz    = 0;
    block_junk_code[0].nrpar  = 0;
    block_junk_code[0].nopar  = 0;
    block_junk_code[0].nipar  = 1;
    block_junk_code[0].nin    = 0;
    block_junk_code[0].nout   = 1;
    block_junk_code[0].nevout = 0;
    block_junk_code[0].nmode  = 0;
    if ((block_junk_code[0].evout  = calloc(block_junk_code[0].nevout,sizeof(double)))== NULL) return 0;
    if ((block_junk_code[0].insz   = malloc(3*sizeof(int)*block_junk_code[0].nin))== NULL) return 0;
    if ((block_junk_code[0].inptr  = malloc(sizeof(void *)*block_junk_code[0].nin))== NULL) return 0;
    if ((block_junk_code[0].outsz  = malloc(3*sizeof(int)*block_junk_code[0].nout))== NULL) return 0;
    if ((block_junk_code[0].outptr = malloc(sizeof(void*)*block_junk_code[0].nout))== NULL) return 0;
    block_junk_code[0].outptr[0] = junk_code_block_outtbptr[0];
    block_junk_code[0].outsz[0]  = 1;
    block_junk_code[0].outsz[1]  = 1;
    block_junk_code[0].outsz[2]  = SCSREAL_N;
    block_junk_code[0].z         = &(z[0]);
    block_junk_code[0].work      = (void **)(((double *)work)+0);
    block_junk_code[0].nevprt    = nevprt;

    /* set blk struc. of 'actionneur1' (type 0 - blk nb 2 - uid ) */
    block_junk_code[1].type   = 0;
    block_junk_code[1].ztyp   = 0;
    block_junk_code[1].ng     = 0;
    block_junk_code[1].nx     = 0;
    block_junk_code[1].x      = &(zero);
    block_junk_code[1].xd     = w;
    block_junk_code[1].g      = &(zero);
    block_junk_code[1].nz     = 0;
    block_junk_code[1].noz    = 0;
    block_junk_code[1].nrpar  = 0;
    block_junk_code[1].nopar  = 0;
    block_junk_code[1].nipar  = 1;
    block_junk_code[1].nin    = 1;
    block_junk_code[1].nout   = 0;
    block_junk_code[1].nevout = 0;
    block_junk_code[1].nmode  = 0;
    if ((block_junk_code[1].evout  = calloc(block_junk_code[1].nevout,sizeof(double)))== NULL) return 0;
    if ((block_junk_code[1].insz   = malloc(3*sizeof(int)*block_junk_code[1].nin))== NULL) return 0;
    if ((block_junk_code[1].inptr  = malloc(sizeof(void *)*block_junk_code[1].nin))== NULL) return 0;
    block_junk_code[1].inptr[0]  = junk_code_block_outtbptr[1];
    block_junk_code[1].insz[0]   = 2;
    block_junk_code[1].insz[1]   = 1;
    block_junk_code[1].insz[2]   = SCSREAL_N;
    if ((block_junk_code[1].outsz  = malloc(3*sizeof(int)*block_junk_code[1].nout))== NULL) return 0;
    if ((block_junk_code[1].outptr = malloc(sizeof(void*)*block_junk_code[1].nout))== NULL) return 0;
    block_junk_code[1].z         = &(z[0]);
    block_junk_code[1].work      = (void **)(((double *)work)+1);
    block_junk_code[1].nevprt    = nevprt;

    /* set blk struc. of 'absolute_value' (type 4 - blk nb 3 - uid ) */
    block_junk_code[2].type   = 4;
    block_junk_code[2].ztyp   = 1;
    block_junk_code[2].ng     = 1;
    block_junk_code[2].nx     = 0;
    block_junk_code[2].x      = &(zero);
    block_junk_code[2].xd     = w;
    block_junk_code[2].g      = &(g[0]);
    block_junk_code[2].mode   = &(mode[0]);
    block_junk_code[2].nz     = 0;
    block_junk_code[2].noz    = 0;
    block_junk_code[2].nrpar  = 0;
    block_junk_code[2].nopar  = 0;
    block_junk_code[2].nipar  = 0;
    block_junk_code[2].nin    = 1;
    block_junk_code[2].nout   = 1;
    block_junk_code[2].nevout = 0;
    block_junk_code[2].nmode  = 1;
    if ((block_junk_code[2].evout  = calloc(block_junk_code[2].nevout,sizeof(double)))== NULL) return 0;
    if ((block_junk_code[2].insz   = malloc(3*sizeof(int)*block_junk_code[2].nin))== NULL) return 0;
    if ((block_junk_code[2].inptr  = malloc(sizeof(void *)*block_junk_code[2].nin))== NULL) return 0;
    block_junk_code[2].inptr[0]  = junk_code_block_outtbptr[0];
    block_junk_code[2].insz[0]   = 1;
    block_junk_code[2].insz[1]   = 1;
    block_junk_code[2].insz[2]   = SCSREAL_N;
    if ((block_junk_code[2].outsz  = malloc(3*sizeof(int)*block_junk_code[2].nout))== NULL) return 0;
    if ((block_junk_code[2].outptr = malloc(sizeof(void*)*block_junk_code[2].nout))== NULL) return 0;
    block_junk_code[2].outptr[0] = junk_code_block_outtbptr[2];
    block_junk_code[2].outsz[0]  = 1;
    block_junk_code[2].outsz[1]  = 1;
    block_junk_code[2].outsz[2]  = SCSREAL_N;
    block_junk_code[2].z         = &(z[0]);
    block_junk_code[2].work      = (void **)(((double *)work)+2);
    block_junk_code[2].nevprt    = nevprt;

    /* set blk struc. of 'multiplex' (type 4 - blk nb 4 - uid ) */
    block_junk_code[3].type   = 4;
    block_junk_code[3].ztyp   = 0;
    block_junk_code[3].ng     = 0;
    block_junk_code[3].nx     = 0;
    block_junk_code[3].x      = &(zero);
    block_junk_code[3].xd     = w;
    block_junk_code[3].g      = &(zero);
    block_junk_code[3].nz     = 0;
    block_junk_code[3].noz    = 0;
    block_junk_code[3].nrpar  = 0;
    block_junk_code[3].nopar  = 0;
    block_junk_code[3].nipar  = 1;
    block_junk_code[3].nin    = 2;
    block_junk_code[3].nout   = 1;
    block_junk_code[3].nevout = 0;
    block_junk_code[3].nmode  = 0;
    if ((block_junk_code[3].evout  = calloc(block_junk_code[3].nevout,sizeof(double)))== NULL) return 0;
    if ((block_junk_code[3].insz   = malloc(3*sizeof(int)*block_junk_code[3].nin))== NULL) return 0;
    if ((block_junk_code[3].inptr  = malloc(sizeof(void *)*block_junk_code[3].nin))== NULL) return 0;
    block_junk_code[3].inptr[0]  = junk_code_block_outtbptr[0];
    block_junk_code[3].inptr[1]  = junk_code_block_outtbptr[2];
    block_junk_code[3].insz[0]   = 1;
    block_junk_code[3].insz[1]   = 1;
    block_junk_code[3].insz[2]   = 1;
    block_junk_code[3].insz[3]   = 1;
    block_junk_code[3].insz[4]   = SCSREAL_N;
    block_junk_code[3].insz[5]   = SCSREAL_N;
    if ((block_junk_code[3].outsz  = malloc(3*sizeof(int)*block_junk_code[3].nout))== NULL) return 0;
    if ((block_junk_code[3].outptr = malloc(sizeof(void*)*block_junk_code[3].nout))== NULL) return 0;
    block_junk_code[3].outptr[0] = junk_code_block_outtbptr[1];
    block_junk_code[3].outsz[0]  = 2;
    block_junk_code[3].outsz[1]  = 1;
    block_junk_code[3].outsz[2]  = SCSREAL_N;
    block_junk_code[3].z         = &(z[0]);
    block_junk_code[3].ipar      = &(ipar[2]);
    block_junk_code[3].work      = (void **)(((double *)work)+3);
    block_junk_code[3].nevprt    = nevprt;

    /* set blk struc. of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_code[4].type   = 4;
    block_junk_code[4].ztyp   = 0;
    block_junk_code[4].ng     = 0;
    block_junk_code[4].nx     = 1;
    block_junk_code[4].x      = &(x[0]);
    block_junk_code[4].g      = &(zero);
    block_junk_code[4].nz     = 0;
    block_junk_code[4].noz    = 0;
    block_junk_code[4].nrpar  = 0;
    block_junk_code[4].nopar  = 0;
    block_junk_code[4].nipar  = 0;
    block_junk_code[4].nin    = 1;
    block_junk_code[4].nout   = 1;
    block_junk_code[4].nevout = 0;
    block_junk_code[4].nmode  = 0;
    if ((block_junk_code[4].evout  = calloc(block_junk_code[4].nevout,sizeof(double)))== NULL) return 0;
    if ((block_junk_code[4].insz   = malloc(3*sizeof(int)*block_junk_code[4].nin))== NULL) return 0;
    if ((block_junk_code[4].inptr  = malloc(sizeof(void *)*block_junk_code[4].nin))== NULL) return 0;
    block_junk_code[4].inptr[0]  = junk_code_block_outtbptr[0];
    block_junk_code[4].insz[0]   = 1;
    block_junk_code[4].insz[1]   = 1;
    block_junk_code[4].insz[2]   = SCSREAL_N;
    if ((block_junk_code[4].outsz  = malloc(3*sizeof(int)*block_junk_code[4].nout))== NULL) return 0;
    if ((block_junk_code[4].outptr = malloc(sizeof(void*)*block_junk_code[4].nout))== NULL) return 0;
    block_junk_code[4].outptr[0] = junk_code_block_outtbptr[3];
    block_junk_code[4].outsz[0]  = 1;
    block_junk_code[4].outsz[1]  = 1;
    block_junk_code[4].outsz[2]  = SCSREAL_N;
    block_junk_code[4].z         = &(z[0]);
    block_junk_code[4].work      = (void **)(((double *)work)+4);
    block_junk_code[4].nevprt    = nevprt;

    /* set blk struc. of 'actionneur2' (type 0 - blk nb 6 - uid ) */
    block_junk_code[5].type   = 0;
    block_junk_code[5].ztyp   = 0;
    block_junk_code[5].ng     = 0;
    block_junk_code[5].nx     = 0;
    block_junk_code[5].x      = &(zero);
    block_junk_code[5].xd     = w;
    block_junk_code[5].g      = &(zero);
    block_junk_code[5].nz     = 0;
    block_junk_code[5].noz    = 0;
    block_junk_code[5].nrpar  = 0;
    block_junk_code[5].nopar  = 0;
    block_junk_code[5].nipar  = 1;
    block_junk_code[5].nin    = 1;
    block_junk_code[5].nout   = 0;
    block_junk_code[5].nevout = 0;
    block_junk_code[5].nmode  = 0;
    if ((block_junk_code[5].evout  = calloc(block_junk_code[5].nevout,sizeof(double)))== NULL) return 0;
    if ((block_junk_code[5].insz   = malloc(3*sizeof(int)*block_junk_code[5].nin))== NULL) return 0;
    if ((block_junk_code[5].inptr  = malloc(sizeof(void *)*block_junk_code[5].nin))== NULL) return 0;
    block_junk_code[5].inptr[0]  = junk_code_block_outtbptr[3];
    block_junk_code[5].insz[0]   = 1;
    block_junk_code[5].insz[1]   = 1;
    block_junk_code[5].insz[2]   = SCSREAL_N;
    if ((block_junk_code[5].outsz  = malloc(3*sizeof(int)*block_junk_code[5].nout))== NULL) return 0;
    if ((block_junk_code[5].outptr = malloc(sizeof(void*)*block_junk_code[5].nout))== NULL) return 0;
    block_junk_code[5].z         = &(z[0]);
    block_junk_code[5].work      = (void **)(((double *)work)+5);
    block_junk_code[5].nevprt    = nevprt;

    /* Call of 'capteur1' (type 0 - blk nb 1 - uid ) */
    block_junk_code[0].nevprt = 0;
    local_flag = 4;
    nport = 1;
    junk_code_sensor(&local_flag, &nport, &block_junk_code[0].nevprt, \
                     &t, (SCSREAL_COP *)junk_code_block_outtbptr[0], \
                     &nrd_1, &nrd_1, &nrd_10,aaa);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'actionneur1' (type 0 - blk nb 2 - uid ) */
    block_junk_code[1].nevprt = 0;
    local_flag = 4;
    nport = 1;
    junk_code_actuator(&local_flag, &nport, &block_junk_code[1].nevprt, \
                       &t, (SCSREAL_COP *)junk_code_block_outtbptr[1], \
                       &nrd_2, &nrd_1, &nrd_10,bbb);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
    block_junk_code[2].nevprt = 0;
    local_flag = 4;
    absolute_value(&block_junk_code[2],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'multiplex' (type 4 - blk nb 4 - uid ) */
    block_junk_code[3].nevprt = 0;
    local_flag = 4;
    multiplex(&block_junk_code[3],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_code[4].nevprt = 0;
    local_flag = 4;
    integral_func(&block_junk_code[4],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'actionneur2' (type 0 - blk nb 6 - uid ) */
    block_junk_code[5].nevprt = 0;
    local_flag = 4;
    nport = 2;
    junk_code_actuator(&local_flag, &nport, &block_junk_code[5].nevprt, \
                       &t, (SCSREAL_COP *)junk_code_block_outtbptr[3], \
                       &nrd_1, &nrd_1, &nrd_10,bbb);
    if(local_flag < 0) return(5 - local_flag);

    /* initial blocks must be called with flag 1 */
    /* Call of 'capteur1' (type 0 - blk nb 1 - uid ) */
    block_junk_code[0].nevprt = 0;
    local_flag = 1;
    nport = 1;
    junk_code_sensor(&local_flag, &nport, &block_junk_code[0].nevprt, \
                     &t, (SCSREAL_COP *)junk_code_block_outtbptr[0], \
                     &nrd_1, &nrd_1, &nrd_10,aaa);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_code[4].nevprt = 0;
    local_flag = 1;
    integral_func(&block_junk_code[4],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
    block_junk_code[2].nevprt = 1;
    local_flag = 1;
    absolute_value(&block_junk_code[2],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'multiplex' (type 4 - blk nb 4 - uid ) */
    block_junk_code[3].nevprt = 3;
    local_flag = 1;
    multiplex(&block_junk_code[3],local_flag);
    if(local_flag < 0) return(5 - local_flag);

  }
  else if (flag == 5) { /* Ending */
    block_junk_code=*block->work;

    /* set blk struc. of 'capteur1' (type 0 - blk nb 1 - uid ) */
    block_junk_code[0].outptr[0] = junk_code_block_outtbptr[0];
    block_junk_code[0].z=&(z[0]);
    block_junk_code[0].work=(void **)(((double *)work)+0);

    /* set blk struc. of 'actionneur1' (type 0 - blk nb 2 - uid ) */
    block_junk_code[1].inptr[0]  = junk_code_block_outtbptr[1];
    block_junk_code[1].z=&(z[0]);
    block_junk_code[1].work=(void **)(((double *)work)+1);

    /* set blk struc. of 'absolute_value' (type 4 - blk nb 3 - uid ) */
    block_junk_code[2].inptr[0]  = junk_code_block_outtbptr[0];
    block_junk_code[2].outptr[0] = junk_code_block_outtbptr[2];
    block_junk_code[2].z=&(z[0]);
    block_junk_code[2].work=(void **)(((double *)work)+2);

    /* set blk struc. of 'multiplex' (type 4 - blk nb 4 - uid ) */
    block_junk_code[3].inptr[0]  = junk_code_block_outtbptr[0];
    block_junk_code[3].inptr[1]  = junk_code_block_outtbptr[2];
    block_junk_code[3].outptr[0] = junk_code_block_outtbptr[1];
    block_junk_code[3].z=&(z[0]);
    block_junk_code[3].ipar=&(ipar[2]);
    block_junk_code[3].work=(void **)(((double *)work)+3);

    /* set blk struc. of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_code[4].inptr[0]  = junk_code_block_outtbptr[0];
    block_junk_code[4].outptr[0] = junk_code_block_outtbptr[3];
    block_junk_code[4].z=&(z[0]);
    block_junk_code[4].work=(void **)(((double *)work)+4);

    /* set blk struc. of 'actionneur2' (type 0 - blk nb 6 - uid ) */
    block_junk_code[5].inptr[0]  = junk_code_block_outtbptr[3];
    block_junk_code[5].z=&(z[0]);
    block_junk_code[5].work=(void **)(((double *)work)+5);

    /* Call of 'capteur1' (type 0 - blk nb 1 - uid ) */
    block_junk_code[0].nevprt = 0;
    local_flag = 5;
    nport = 1;
    junk_code_sensor(&local_flag, &nport, &block_junk_code[0].nevprt, \
                     &t, (SCSREAL_COP *)junk_code_block_outtbptr[0], \
                     &nrd_1, &nrd_1, &nrd_10,aaa);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'actionneur1' (type 0 - blk nb 2 - uid ) */
    block_junk_code[1].nevprt = 0;
    local_flag = 5;
    nport = 1;
    junk_code_actuator(&local_flag, &nport, &block_junk_code[1].nevprt, \
                       &t, (SCSREAL_COP *)junk_code_block_outtbptr[1], \
                       &nrd_2, &nrd_1, &nrd_10,bbb);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'absolute_value' (type 4 - blk nb 3 - uid  - with zcross) */
    block_junk_code[2].nevprt = 0;
    local_flag = 5;
    absolute_value(&block_junk_code[2],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'multiplex' (type 4 - blk nb 4 - uid ) */
    block_junk_code[3].nevprt = 0;
    local_flag = 5;
    multiplex(&block_junk_code[3],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'integral_func' (type 4 - blk nb 5 - uid ) */
    block_junk_code[4].nevprt = 0;
    local_flag = 5;
    integral_func(&block_junk_code[4],local_flag);
    if(local_flag < 0) return(5 - local_flag);

    /* Call of 'actionneur2' (type 0 - blk nb 6 - uid ) */
    block_junk_code[5].nevprt = 0;
    local_flag = 5;
    nport = 2;
    junk_code_actuator(&local_flag, &nport, &block_junk_code[5].nevprt, \
                       &t, (SCSREAL_COP *)junk_code_block_outtbptr[3], \
                       &nrd_1, &nrd_1, &nrd_10,bbb);
    if(local_flag < 0) return(5 - local_flag);

    for (kf = 0; kf < 6; ++kf) {
      if (block_junk_code[kf].insz!=NULL) {
        free(block_junk_code[kf].insz);
      }else {
        break;
      }
      if (block_junk_code[kf].outsz!=NULL){
        free(block_junk_code[kf].outsz);
      }else {
        break;
      }
      if (block_junk_code[kf].nopar!=0){
        if (block_junk_code[kf].oparptr!=NULL){
          free(block_junk_code[kf].oparptr);
        }else {
          break;
        }
        if (block_junk_code[kf].oparsz!=NULL){
          free(block_junk_code[kf].oparsz);
        }else {
          break;
        }
        if (block_junk_code[kf].opartyp!=NULL){
          free(block_junk_code[kf].opartyp);
        }else {
          break;
        }
      }
      if (block_junk_code[kf].noz!=0){
        if (block_junk_code[kf].ozptr!=NULL){
          free(block_junk_code[kf].ozptr);
        }else {
          break;
        }
        if (block_junk_code[kf].ozsz!=NULL){
          free(block_junk_code[kf].ozsz);
        }else {
          break;
        }
        if (block_junk_code[kf].oztyp!=NULL){
          free(block_junk_code[kf].oztyp);
        }else {
          break;
        }
      }
      if (block_junk_code[kf].evout!=NULL){
        free(block_junk_code[kf].evout);
      }else {
        break;
      }
    }
    scicos_free(block_junk_code);
  }

  memcpy(*(y+0),*(junk_code_block_outtbptr+1),2*sizeof(double));
  memcpy(*(y+1),*(junk_code_block_outtbptr+3),1*sizeof(double));
  return 0;

} /* junk_code */