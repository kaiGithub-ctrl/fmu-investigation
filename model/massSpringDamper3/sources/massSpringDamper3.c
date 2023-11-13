#include "massSpringDamper3_macros.h"
#include "massSpringDamper3.h"
#include "massSpringDamper3_private.h"

B_massSpringDamper3_T massSpringDamper3_B;
X_massSpringDamper3_T massSpringDamper3_X;
ExtU_massSpringDamper3_T massSpringDamper3_U;
ExtY_massSpringDamper3_T massSpringDamper3_Y;
static RT_MODEL_massSpringDamper3_T massSpringDamper3_M_;
RT_MODEL_massSpringDamper3_T *const massSpringDamper3_M = &massSpringDamper3_M_;
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));
  rtsiSetdX(si, f0);
  massSpringDamper3_derivatives();
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  massSpringDamper3_step();
  massSpringDamper3_derivatives();
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  massSpringDamper3_step();
  massSpringDamper3_derivatives();
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  massSpringDamper3_step();
  massSpringDamper3_derivatives();
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

void massSpringDamper3_step(void)
{
  if (rtmIsMajorTimeStep(massSpringDamper3_M)) {
    if (!(massSpringDamper3_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&massSpringDamper3_M->solverInfo,
                            ((massSpringDamper3_M->Timing.clockTickH0 + 1) *
        massSpringDamper3_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&massSpringDamper3_M->solverInfo,
                            ((massSpringDamper3_M->Timing.clockTick0 + 1) *
        massSpringDamper3_M->Timing.stepSize0 +
        massSpringDamper3_M->Timing.clockTickH0 *
        massSpringDamper3_M->Timing.stepSize0 * 4294967296.0));
    }
  }

  if (rtmIsMinorTimeStep(massSpringDamper3_M)) {
    massSpringDamper3_M->Timing.t[0] = rtsiGetT(&massSpringDamper3_M->solverInfo);
  }

  massSpringDamper3_Y.Output = massSpringDamper3_X.Integrator1_CSTATE;
  massSpringDamper3_B.x = massSpringDamper3_X.Integrator_CSTATE;
  massSpringDamper3_B.x_d = (((0.0 - massSpringDamper3_P.b *
    massSpringDamper3_B.x) - massSpringDamper3_P.k *
    massSpringDamper3_X.Integrator1_CSTATE) + massSpringDamper3_U.Input) * (1.0 /
    massSpringDamper3_P.m);
  if (rtmIsMajorTimeStep(massSpringDamper3_M)) {
    fmu_LogOutput();
  }

  if (rtmIsMajorTimeStep(massSpringDamper3_M)) {
    rt_ertODEUpdateContinuousStates(&massSpringDamper3_M->solverInfo);
    if (!(++massSpringDamper3_M->Timing.clockTick0)) {
      ++massSpringDamper3_M->Timing.clockTickH0;
    }

    massSpringDamper3_M->Timing.t[0] = rtsiGetSolverStopTime
      (&massSpringDamper3_M->solverInfo);

    {
      massSpringDamper3_M->Timing.clockTick1++;
      if (!massSpringDamper3_M->Timing.clockTick1) {
        massSpringDamper3_M->Timing.clockTickH1++;
      }
    }
  }
}

void massSpringDamper3_derivatives(void)
{
  XDot_massSpringDamper3_T *_rtXdot;
  _rtXdot = ((XDot_massSpringDamper3_T *) massSpringDamper3_M->derivs);
  _rtXdot->Integrator1_CSTATE = massSpringDamper3_B.x;
  _rtXdot->Integrator_CSTATE = massSpringDamper3_B.x_d;
}

void massSpringDamper3_initialize(void)
{
  (void) memset((void *)massSpringDamper3_M, 0,
                sizeof(RT_MODEL_massSpringDamper3_T));

  {
    rtsiSetSimTimeStepPtr(&massSpringDamper3_M->solverInfo,
                          &massSpringDamper3_M->Timing.simTimeStep);
    rtsiSetTPtr(&massSpringDamper3_M->solverInfo, &rtmGetTPtr
                (massSpringDamper3_M));
    rtsiSetStepSizePtr(&massSpringDamper3_M->solverInfo,
                       &massSpringDamper3_M->Timing.stepSize0);
    rtsiSetdXPtr(&massSpringDamper3_M->solverInfo, &massSpringDamper3_M->derivs);
    rtsiSetContStatesPtr(&massSpringDamper3_M->solverInfo, (real_T **)
                         &massSpringDamper3_M->contStates);
    rtsiSetNumContStatesPtr(&massSpringDamper3_M->solverInfo,
      &massSpringDamper3_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&massSpringDamper3_M->solverInfo,
      &massSpringDamper3_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&massSpringDamper3_M->solverInfo,
      &massSpringDamper3_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&massSpringDamper3_M->solverInfo,
      &massSpringDamper3_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&massSpringDamper3_M->solverInfo, (&rtmGetErrorStatus
      (massSpringDamper3_M)));
    rtsiSetRTModelPtr(&massSpringDamper3_M->solverInfo, massSpringDamper3_M);
  }

  rtsiSetSimTimeStep(&massSpringDamper3_M->solverInfo, MAJOR_TIME_STEP);
  massSpringDamper3_M->intgData.y = massSpringDamper3_M->odeY;
  massSpringDamper3_M->intgData.f[0] = massSpringDamper3_M->odeF[0];
  massSpringDamper3_M->intgData.f[1] = massSpringDamper3_M->odeF[1];
  massSpringDamper3_M->intgData.f[2] = massSpringDamper3_M->odeF[2];
  massSpringDamper3_M->intgData.f[3] = massSpringDamper3_M->odeF[3];
  massSpringDamper3_M->contStates = ((X_massSpringDamper3_T *)
    &massSpringDamper3_X);
  rtsiSetSolverData(&massSpringDamper3_M->solverInfo, (void *)
                    &massSpringDamper3_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&massSpringDamper3_M->solverInfo, false);
  rtsiSetSolverName(&massSpringDamper3_M->solverInfo,"ode4");
  rtmSetTPtr(massSpringDamper3_M, &massSpringDamper3_M->Timing.tArray[0]);
  massSpringDamper3_M->Timing.stepSize0 = 0.2;
  (void) memset(((void *) &massSpringDamper3_B), 0,
                sizeof(B_massSpringDamper3_T));

  {
    (void) memset((void *)&massSpringDamper3_X, 0,
                  sizeof(X_massSpringDamper3_T));
  }

  massSpringDamper3_U.Input = 0.0;
  massSpringDamper3_Y.Output = 0.0;
  massSpringDamper3_X.Integrator1_CSTATE = massSpringDamper3_P.Integrator1_IC;
  massSpringDamper3_X.Integrator_CSTATE = massSpringDamper3_P.Integrator_IC;
}

void massSpringDamper3_terminate(void)
{
}
