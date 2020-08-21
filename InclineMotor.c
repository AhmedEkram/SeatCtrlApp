/**
 *
 * \file InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/17/2020 02:07 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Move
 *
 */

void InclineMotor_Move (StepMotorStepType step)
{
    if(step == MOTOR_STEP_PLUS)
    {
       Rte_Call_rpIOSetIncline_IOSetForward();
    }
    else if(step == MOTOR_STEP_MINUS)
    {
       Rte_Call_rpIOSetIncline_IOSetReverse();
    }
    else
    {
        /*Do Nothing*/
    }

}

