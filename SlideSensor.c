/**
 *
 * \file SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/17/2020 02:27 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideSensor.h"


/**
 *
 * Runnable SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_GetPosition
 *
 */

void SlideSensor_GetPosition (SensorPositionType* Position)
{
	IoPositionSensorReadingType position;

	/* Server Call Points */
	Rte_Call_rpIOGetSlide_IOGet(&position);

    if(position == 0)
    {
        *Position = SENSOR_POSITION_STEP_0;
    }
    else if(position > 0 && position <= 64)
    {
        *Position = SENSOR_POSITION_STEP_1;
    }
    else if(position > 64 && position <= 192)
    {
        *Position = SENSOR_POSITION_STEP_2;
    }
    else if(position > 192 && position <= 255)
    {
        *Position = SENSOR_POSITION_STEP_3;
    }
    else
    {
        /*Do Nothing*/
    }

}

