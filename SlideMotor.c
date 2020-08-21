/**
 *
 * \file SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/17/2020 02:07 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideMotor.h"


/**
 *
 * Runnable SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Move
 *
 */

void SlideMotor_Move (StepMotorStepType step)
{
    if(step == MOTOR_STEP_PLUS)
    {
       Rte_Call_rpIOSetSlide_IOSetForward();
    }
    else if(step == MOTOR_STEP_MINUS)
    {
       Rte_Call_rpIOSetSlide_IOSetReverse();
    }
    else
    {
        /*Do Nothing*/
    }

}

