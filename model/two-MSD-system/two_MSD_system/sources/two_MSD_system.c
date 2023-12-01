#include "two_MSD_system_macros.h"
#include "two_MSD_system.h"
#include "rtwtypes.h"
#include "two_MSD_system_private.h"
#include <string.h>

B_two_MSD_system_T two_MSD_system_B;
X_two_MSD_system_T two_MSD_system_X;
ExtU_two_MSD_system_T two_MSD_system_U;
ExtY_two_MSD_system_T two_MSD_system_Y;
static RT_MODEL_two_MSD_system_T two_MSD_system_M_;
RT_MODEL_two_MSD_system_T *const two_MSD_system_M = &two_MSD_system_M_;
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));
  rtsiSetdX(si, f0);
  two_MSD_system_derivatives();
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  two_MSD_system_step();
  two_MSD_system_derivatives();
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  two_MSD_system_step();
  two_MSD_system_derivatives();
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

void two_MSD_system_step(void)
{
  real_T x2_c_tmp;
  real_T x2_c_tmp_0;
  real_T x2_c_tmp_1;
  real_T x2_c_tmp_2;
  if (rtmIsMajorTimeStep(two_MSD_system_M)) {
    if (!(two_MSD_system_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&two_MSD_system_M->solverInfo,
                            ((two_MSD_system_M->Timing.clockTickH0 + 1) *
        two_MSD_system_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&two_MSD_system_M->solverInfo,
                            ((two_MSD_system_M->Timing.clockTick0 + 1) *
        two_MSD_system_M->Timing.stepSize0 +
        two_MSD_system_M->Timing.clockTickH0 *
        two_MSD_system_M->Timing.stepSize0 * 4294967296.0));
    }
  }

  if (rtmIsMinorTimeStep(two_MSD_system_M)) {
    two_MSD_system_M->Timing.t[0] = rtsiGetT(&two_MSD_system_M->solverInfo);
  }

  two_MSD_system_Y.Positionx1 = two_MSD_system_X.Integrator1_CSTATE;
  two_MSD_system_Y.Positionx2 = two_MSD_system_X.Integrator3_CSTATE;
  two_MSD_system_B.x1 = two_MSD_system_X.Integrator_CSTATE;
  two_MSD_system_Y.Velocityv1 = two_MSD_system_B.x1;
  two_MSD_system_B.x2 = two_MSD_system_X.Integrator2_CSTATE;
  two_MSD_system_Y.Velocityv2 = two_MSD_system_B.x2;
  x2_c_tmp = two_MSD_system_P.k2 * two_MSD_system_X.Integrator3_CSTATE;
  x2_c_tmp_0 = two_MSD_system_P.b2 * two_MSD_system_B.x1;
  x2_c_tmp_1 = two_MSD_system_P.k2 * two_MSD_system_X.Integrator1_CSTATE;
  x2_c_tmp_2 = two_MSD_system_P.b2 * two_MSD_system_B.x2;
  two_MSD_system_B.x2_c = ((((x2_c_tmp_1 + two_MSD_system_U.InputForce) -
    x2_c_tmp) - x2_c_tmp_2) + x2_c_tmp_0) * (1.0 / two_MSD_system_P.m2);
  two_MSD_system_B.x1_l = (((((x2_c_tmp - two_MSD_system_P.b1 *
    two_MSD_system_B.x1) - x2_c_tmp_0) - two_MSD_system_P.k1 *
    two_MSD_system_X.Integrator1_CSTATE) - x2_c_tmp_1) + x2_c_tmp_2) * (1.0 /
    two_MSD_system_P.m1);
  if (rtmIsMajorTimeStep(two_MSD_system_M)) {
    fmu_LogOutput();
  }

  if (rtmIsMajorTimeStep(two_MSD_system_M)) {
    rt_ertODEUpdateContinuousStates(&two_MSD_system_M->solverInfo);
    if (!(++two_MSD_system_M->Timing.clockTick0)) {
      ++two_MSD_system_M->Timing.clockTickH0;
    }

    two_MSD_system_M->Timing.t[0] = rtsiGetSolverStopTime
      (&two_MSD_system_M->solverInfo);
  }
}

void two_MSD_system_derivatives(void)
{
  XDot_two_MSD_system_T *_rtXdot;
  _rtXdot = ((XDot_two_MSD_system_T *) two_MSD_system_M->derivs);
  _rtXdot->Integrator1_CSTATE = two_MSD_system_B.x1;
  _rtXdot->Integrator3_CSTATE = two_MSD_system_B.x2;
  _rtXdot->Integrator_CSTATE = two_MSD_system_B.x1_l;
  _rtXdot->Integrator2_CSTATE = two_MSD_system_B.x2_c;
}

void two_MSD_system_initialize(void)
{
  (void) memset((void *)two_MSD_system_M, 0,
                sizeof(RT_MODEL_two_MSD_system_T));

  {
    rtsiSetSimTimeStepPtr(&two_MSD_system_M->solverInfo,
                          &two_MSD_system_M->Timing.simTimeStep);
    rtsiSetTPtr(&two_MSD_system_M->solverInfo, &rtmGetTPtr(two_MSD_system_M));
    rtsiSetStepSizePtr(&two_MSD_system_M->solverInfo,
                       &two_MSD_system_M->Timing.stepSize0);
    rtsiSetdXPtr(&two_MSD_system_M->solverInfo, &two_MSD_system_M->derivs);
    rtsiSetContStatesPtr(&two_MSD_system_M->solverInfo, (real_T **)
                         &two_MSD_system_M->contStates);
    rtsiSetNumContStatesPtr(&two_MSD_system_M->solverInfo,
      &two_MSD_system_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&two_MSD_system_M->solverInfo,
      &two_MSD_system_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&two_MSD_system_M->solverInfo,
      &two_MSD_system_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&two_MSD_system_M->solverInfo,
      &two_MSD_system_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&two_MSD_system_M->solverInfo, (&rtmGetErrorStatus
      (two_MSD_system_M)));
    rtsiSetRTModelPtr(&two_MSD_system_M->solverInfo, two_MSD_system_M);
  }

  rtsiSetSimTimeStep(&two_MSD_system_M->solverInfo, MAJOR_TIME_STEP);
  two_MSD_system_M->intgData.y = two_MSD_system_M->odeY;
  two_MSD_system_M->intgData.f[0] = two_MSD_system_M->odeF[0];
  two_MSD_system_M->intgData.f[1] = two_MSD_system_M->odeF[1];
  two_MSD_system_M->intgData.f[2] = two_MSD_system_M->odeF[2];
  two_MSD_system_M->contStates = ((X_two_MSD_system_T *) &two_MSD_system_X);
  rtsiSetSolverData(&two_MSD_system_M->solverInfo, (void *)
                    &two_MSD_system_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&two_MSD_system_M->solverInfo, false);
  rtsiSetSolverName(&two_MSD_system_M->solverInfo,"ode3");
  rtmSetTPtr(two_MSD_system_M, &two_MSD_system_M->Timing.tArray[0]);
  two_MSD_system_M->Timing.stepSize0 = 6.0;
  (void) memset(((void *) &two_MSD_system_B), 0,
                sizeof(B_two_MSD_system_T));

  {
    (void) memset((void *)&two_MSD_system_X, 0,
                  sizeof(X_two_MSD_system_T));
  }

  two_MSD_system_U.InputForce = 0.0;
  (void)memset(&two_MSD_system_Y, 0, sizeof(ExtY_two_MSD_system_T));
  two_MSD_system_X.Integrator1_CSTATE = two_MSD_system_P.Integrator1_IC;
  two_MSD_system_X.Integrator3_CSTATE = two_MSD_system_P.Integrator3_IC;
  two_MSD_system_X.Integrator_CSTATE = two_MSD_system_P.Integrator_IC;
  two_MSD_system_X.Integrator2_CSTATE = two_MSD_system_P.Integrator2_IC;
}

void two_MSD_system_terminate(void)
{
}
