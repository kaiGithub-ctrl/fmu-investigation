#include "MSD_11_21_23_macros.h"
#include "MSD_11_21_23.h"
#include "MSD_11_21_23_private.h"

B_MSD_11_21_23_T MSD_11_21_23_B;
X_MSD_11_21_23_T MSD_11_21_23_X;
ExtU_MSD_11_21_23_T MSD_11_21_23_U;
ExtY_MSD_11_21_23_T MSD_11_21_23_Y;
static RT_MODEL_MSD_11_21_23_T MSD_11_21_23_M_;
RT_MODEL_MSD_11_21_23_T *const MSD_11_21_23_M = &MSD_11_21_23_M_;
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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));
  rtsiSetdX(si, f0);
  MSD_11_21_23_derivatives();
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  MSD_11_21_23_step();
  MSD_11_21_23_derivatives();
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  MSD_11_21_23_step();
  MSD_11_21_23_derivatives();
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

void MSD_11_21_23_step(void)
{
  if (rtmIsMajorTimeStep(MSD_11_21_23_M)) {
    if (!(MSD_11_21_23_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&MSD_11_21_23_M->solverInfo,
                            ((MSD_11_21_23_M->Timing.clockTickH0 + 1) *
        MSD_11_21_23_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&MSD_11_21_23_M->solverInfo,
                            ((MSD_11_21_23_M->Timing.clockTick0 + 1) *
        MSD_11_21_23_M->Timing.stepSize0 + MSD_11_21_23_M->Timing.clockTickH0 *
        MSD_11_21_23_M->Timing.stepSize0 * 4294967296.0));
    }
  }

  if (rtmIsMinorTimeStep(MSD_11_21_23_M)) {
    MSD_11_21_23_M->Timing.t[0] = rtsiGetT(&MSD_11_21_23_M->solverInfo);
  }

  MSD_11_21_23_Y.Output = MSD_11_21_23_X.Integrator1_CSTATE;
  MSD_11_21_23_B.x = MSD_11_21_23_X.Integrator_CSTATE;
  MSD_11_21_23_B.x_d = (((0.0 - MSD_11_21_23_P.b * MSD_11_21_23_B.x) -
    MSD_11_21_23_P.k * MSD_11_21_23_X.Integrator1_CSTATE) + MSD_11_21_23_U.Input)
    * (1.0 / MSD_11_21_23_P.m);
  if (rtmIsMajorTimeStep(MSD_11_21_23_M)) {
    fmu_LogOutput();
  }

  if (rtmIsMajorTimeStep(MSD_11_21_23_M)) {
    rt_ertODEUpdateContinuousStates(&MSD_11_21_23_M->solverInfo);
    if (!(++MSD_11_21_23_M->Timing.clockTick0)) {
      ++MSD_11_21_23_M->Timing.clockTickH0;
    }

    MSD_11_21_23_M->Timing.t[0] = rtsiGetSolverStopTime
      (&MSD_11_21_23_M->solverInfo);
  }
}

void MSD_11_21_23_derivatives(void)
{
  XDot_MSD_11_21_23_T *_rtXdot;
  _rtXdot = ((XDot_MSD_11_21_23_T *) MSD_11_21_23_M->derivs);
  _rtXdot->Integrator1_CSTATE = MSD_11_21_23_B.x;
  _rtXdot->Integrator_CSTATE = MSD_11_21_23_B.x_d;
}

void MSD_11_21_23_initialize(void)
{
  (void) memset((void *)MSD_11_21_23_M, 0,
                sizeof(RT_MODEL_MSD_11_21_23_T));

  {
    rtsiSetSimTimeStepPtr(&MSD_11_21_23_M->solverInfo,
                          &MSD_11_21_23_M->Timing.simTimeStep);
    rtsiSetTPtr(&MSD_11_21_23_M->solverInfo, &rtmGetTPtr(MSD_11_21_23_M));
    rtsiSetStepSizePtr(&MSD_11_21_23_M->solverInfo,
                       &MSD_11_21_23_M->Timing.stepSize0);
    rtsiSetdXPtr(&MSD_11_21_23_M->solverInfo, &MSD_11_21_23_M->derivs);
    rtsiSetContStatesPtr(&MSD_11_21_23_M->solverInfo, (real_T **)
                         &MSD_11_21_23_M->contStates);
    rtsiSetNumContStatesPtr(&MSD_11_21_23_M->solverInfo,
      &MSD_11_21_23_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&MSD_11_21_23_M->solverInfo,
      &MSD_11_21_23_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&MSD_11_21_23_M->solverInfo,
      &MSD_11_21_23_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&MSD_11_21_23_M->solverInfo,
      &MSD_11_21_23_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&MSD_11_21_23_M->solverInfo, (&rtmGetErrorStatus
      (MSD_11_21_23_M)));
    rtsiSetRTModelPtr(&MSD_11_21_23_M->solverInfo, MSD_11_21_23_M);
  }

  rtsiSetSimTimeStep(&MSD_11_21_23_M->solverInfo, MAJOR_TIME_STEP);
  MSD_11_21_23_M->intgData.y = MSD_11_21_23_M->odeY;
  MSD_11_21_23_M->intgData.f[0] = MSD_11_21_23_M->odeF[0];
  MSD_11_21_23_M->intgData.f[1] = MSD_11_21_23_M->odeF[1];
  MSD_11_21_23_M->intgData.f[2] = MSD_11_21_23_M->odeF[2];
  MSD_11_21_23_M->contStates = ((X_MSD_11_21_23_T *) &MSD_11_21_23_X);
  rtsiSetSolverData(&MSD_11_21_23_M->solverInfo, (void *)
                    &MSD_11_21_23_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&MSD_11_21_23_M->solverInfo, false);
  rtsiSetSolverName(&MSD_11_21_23_M->solverInfo,"ode3");
  rtmSetTPtr(MSD_11_21_23_M, &MSD_11_21_23_M->Timing.tArray[0]);
  MSD_11_21_23_M->Timing.stepSize0 = 0.2;
  (void) memset(((void *) &MSD_11_21_23_B), 0,
                sizeof(B_MSD_11_21_23_T));

  {
    (void) memset((void *)&MSD_11_21_23_X, 0,
                  sizeof(X_MSD_11_21_23_T));
  }

  MSD_11_21_23_U.Input = 0.0;
  MSD_11_21_23_Y.Output = 0.0;
  MSD_11_21_23_X.Integrator1_CSTATE = MSD_11_21_23_P.Integrator1_IC;
  MSD_11_21_23_X.Integrator_CSTATE = MSD_11_21_23_P.Integrator_IC;
}

void MSD_11_21_23_terminate(void)
{
}
