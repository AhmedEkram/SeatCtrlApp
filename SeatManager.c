/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/15/2020 08:25 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"

static boolean GetMovementStep(SensorPositionType position,SensorWeightType weight,StepMotorStepType * MovementStep);

/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	MultiStateBtnType HeightBtnState;

	/* Data Receive Points */
	Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);

	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
    {
        Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
    }
    else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
    {
        Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
    }
    else
    {
        /*Do Nothing*/
    }

}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	MultiStateBtnType InclineBtnState;

	/* Data Receive Points */
	Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);

	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
    {
        Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
    }
    else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
    {
        Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
    }
    else
    {
        /*Do Nothing*/
    }
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	MultiStateBtnType SlideBtnState;

	/* Data Receive Points */
	Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);

    if(SlideBtnState == MULTI_STATE_BTN_MINUS)
    {
        Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
    }
    else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
    {
        Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
    }
    else
    {
        /*Do Nothing*/
    }
}

/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */

void SeatManager_AutoHeight (void)
{
	SensorPositionType Position;
	SensorWeightType Weight;
	StepMotorStepType step;
    boolean GetMovementStepResult;
	/* Server Call Points */
	Rte_Call_rpHeightSensor_GetPosition(&Position);
	Rte_Call_rpWeightSensor_GetWeight(&Weight);
	GetMovementStepResult = GetMovementStep(Position,Weight,&step);

	if(GetMovementStepResult == TRUE)
    {
        Rte_Call_rpHeightMotor_Move(step);
    }
    else
    {
        /*Do nothing*/
    }
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	SensorPositionType Position;
	SensorWeightType Weight;
	StepMotorStepType step;
    boolean GetMovementStepResult;
	/* Server Call Points */
	Rte_Call_rpSlideSensor_GetPosition(&Position);
	Rte_Call_rpWeightSensor_GetWeight(&Weight);
    GetMovementStepResult = GetMovementStep(Position,Weight,&step);

	if(GetMovementStepResult == TRUE)
    {
        Rte_Call_rpHeightMotor_Move(step);
    }
    else
    {
        /*Do nothing*/
    }

}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	SensorPositionType Position;
	SensorWeightType Weight;
	StepMotorStepType step;
    boolean GetMovementStepResult;
	/* Server Call Points */
	Rte_Call_rpInclineSensor_GetPosition(&Position);
	Rte_Call_rpWeightSensor_GetWeight(&Weight);
    GetMovementStepResult = GetMovementStep(Position,Weight,&step);

	if(GetMovementStepResult == TRUE)
    {
        Rte_Call_rpHeightMotor_Move(step);
    }
    else
    {
        /*Do nothing*/
    }

}

static boolean GetMovementStep(SensorPositionType Position,SensorWeightType Weight,StepMotorStepType * MovementStep)
{
    boolean Result=FALSE;
    /*If false nothing no change need to the movement step*/
    /*If true movement step is required*/

    if(Weight > 100)
    {
        switch(Position)
        {
        case SENSOR_POSITION_STEP_3:
            /*Do nothing*/
            break;
        case SENSOR_POSITION_STEP_2:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_PLUS;
            break;
        case SENSOR_POSITION_STEP_1:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_PLUS;
            break;
        case SENSOR_POSITION_STEP_0:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_PLUS;
            break;
        default:
            /*Do nothing*/
            break;
        }
    }
    else if(Weight > 80 && Weight <= 100)
    {
        switch(Position)
        {
        case SENSOR_POSITION_STEP_3:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_MINUS;
            break;
        case SENSOR_POSITION_STEP_2:
             /*Do nothing*/
        case SENSOR_POSITION_STEP_1:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_PLUS;
            break;
        case SENSOR_POSITION_STEP_0:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_PLUS;
            break;
        default:
            /*Do nothing*/
            break;
        }
    }
    else if(Weight > 60 && Weight <= 80)
    {
        switch(Position)
        {
        case SENSOR_POSITION_STEP_3:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_MINUS;
            break;
        case SENSOR_POSITION_STEP_2:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_MINUS;
            break;
        case SENSOR_POSITION_STEP_1:
             /*Do nothing*/
        case SENSOR_POSITION_STEP_0:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_PLUS;
            break;
        default:
            /*Do nothing*/
            break;
        }
    }
    else if(Weight <= 60)
    {
        switch(Position)
        {
        case SENSOR_POSITION_STEP_3:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_MINUS;
            break;
        case SENSOR_POSITION_STEP_2:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_MINUS;
            break;
        case SENSOR_POSITION_STEP_1:
            Result=TRUE;
            *MovementStep=MOTOR_STEP_MINUS;
            break;
        case SENSOR_POSITION_STEP_0:
             /*Do nothing*/
        default:
            /*Do nothing*/
            break;
        }
    }

    return Result;
}
