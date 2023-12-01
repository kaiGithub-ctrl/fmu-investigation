#ifndef RTW_HEADER_two_MSD_system_h_
#define RTW_HEADER_two_MSD_system_h_
#ifndef two_MSD_system_COMMON_INCLUDES_
#define two_MSD_system_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif

#include "two_MSD_system_types.h"
#include <string.h>

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

typedef struct {
  real_T x1;
  real_T x2;
  real_T x2_c;
  real_T x1_l;
} B_two_MSD_system_T;

typedef struct {
  real_T Integrator1_CSTATE;
  real_T Integrator3_CSTATE;
  real_T Integrator_CSTATE;
  real_T Integrator2_CSTATE;
} X_two_MSD_system_T;

typedef struct {
  real_T Integrator1_CSTATE;
  real_T Integrator3_CSTATE;
  real_T Integrator_CSTATE;
  real_T Integrator2_CSTATE;
} XDot_two_MSD_system_T;

typedef struct {
  boolean_T Integrator1_CSTATE;
  boolean_T Integrator3_CSTATE;
  boolean_T Integrator_CSTATE;
  boolean_T Integrator2_CSTATE;
} XDis_two_MSD_system_T;

#ifndef ODE3_INTG
#define ODE3_INTG

typedef struct {
  real_T *y;
  real_T *f[3];
} ODE3_IntgData;

#endif

typedef struct {
  real_T InputForce;
} ExtU_two_MSD_system_T;

typedef struct {
  real_T Positionx1;
  real_T Positionx2;
  real_T Velocityv1;
  real_T Velocityv2;
} ExtY_two_MSD_system_T;

struct P_two_MSD_system_T_ {
  real_T b1;
  real_T b2;
  real_T k1;
  real_T k2;
  real_T m1;
  real_T m2;
  real_T Integrator1_IC;
  real_T Integrator3_IC;
  real_T Integrator_IC;
  real_T Integrator2_IC;
};

struct tag_RTM_two_MSD_system_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_two_MSD_system_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_two_MSD_system_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[1];
  } Timing;
};

extern P_two_MSD_system_T two_MSD_system_P;
extern B_two_MSD_system_T two_MSD_system_B;
extern X_two_MSD_system_T two_MSD_system_X;
extern ExtU_two_MSD_system_T two_MSD_system_U;
extern ExtY_two_MSD_system_T two_MSD_system_Y;
extern void two_MSD_system_initialize(void);
extern void two_MSD_system_step(void);
extern void two_MSD_system_terminate(void);
extern RT_MODEL_two_MSD_system_T *const two_MSD_system_M;
extern void fmu_LogOutput();

#endif
