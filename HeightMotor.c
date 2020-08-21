/**
 *
 * \file HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/17/2020 02:07 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HeightMotor.h"


/**
 *
 * Runnable HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Move
 *
 */

void HeightMotor_Move (StepMotorStepType step)
{
	if(step == MOTOR_STEP_PLUS)
    {
       Rte_Call_rpIOSetHeight_IOSetForward();
    }
    else if(step == MOTOR_STEP_MINUS)
    {
       Rte_Call_rpIOSetHeight_IOSetReverse();
    }
    else
    {
        /*Do Nothing*/
    }

}

