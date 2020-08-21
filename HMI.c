/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/12/2020 09:12 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"

static MultiStateBtnType CheckBtnState(Std_ReturnType ReadOperation_status,boolean isUpdated,uint8 PhysicalValue);

/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	uint8 Height;
	uint8 Incline;
	uint8 Slide;
    boolean isUpdated;
    /* Data Receive Points */
    /*Receive data from RTE*/
    /*Height*/
	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	isUpdated = Rte_IsUpdated_rpSeatCtrlData_Height();
	HeightBtnState = CheckBtnState(status,isUpdated,Height);

    /*Incline*/
	status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	isUpdated = Rte_IsUpdated_rpSeatCtrlData_Incline();
    InclineBtnState = CheckBtnState(status,isUpdated,Incline);


    /*Slide*/
	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	isUpdated = Rte_IsUpdated_rpSeatCtrlData_Slide();
    SlideBtnState = CheckBtnState(status,isUpdated,Slide);


	/* Data Send Points */
	/*Provide Data to RTE*/
	Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
}

void HMI_SeatModeChanged (void)
{
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);

    if(SeatModeBtn == SEAT_MODE_BTN_MANUAL)
    {
        SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
    }
    else if(SeatModeBtn == SEAT_MODE_BTN_AUTO)
    {
        SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
    }
    else
    {
        /*Do nothing*/
    }
	/* Mode Switch Points */
	Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);

}

static MultiStateBtnType CheckBtnState(Std_ReturnType ReadOperation_status,boolean isUpdated,uint8 PhysicalValue)
{
    MultiStateBtnType BtnState;

    if( ReadOperation_status == RTE_E_OK || isUpdated == FALSE || PhysicalValue == 0)
    {
        BtnState = MULTI_STATE_BTN_INIT;
    }
    else if(PhysicalValue == 1)
    {
        BtnState = MULTI_STATE_BTN_MINUS;
    }
    else if(PhysicalValue == 2)
    {
        BtnState = MULTI_STATE_BTN_PLUS;
    }
    else
    {
        BtnState = MULTI_STATE_BTN_INIT;
    }

    return BtnState;
}
