#ifndef RTW_HEADER_MSD_11_21_23_private_h_
#define RTW_HEADER_MSD_11_21_23_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "MSD_11_21_23_types.h"

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void MSD_11_21_23_derivatives(void);

#endif
