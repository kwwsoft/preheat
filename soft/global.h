#ifndef __global_h
#define __global_h
//-----------------------------------------------------------------------------
#define key_nothing  0
#define key_up       1
#define key_down     2
#define key_select   3
#define key_up_long      4
#define key_down_long    5
#define key_select_long  6
//------------------------------
#define duty_min          90
#define duty_max          153
//------------------------------------------------------------------------------
void InitMega();
void ResetTimers();
int My_ADC_Get_Sample();
void My_ShowU();
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#endif