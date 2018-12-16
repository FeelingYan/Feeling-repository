/*************************************************************************
	> File Name: set_bar.h
	> Author: 
	> Mail: 
	> Created Time: 2018年12月16日 星期日 13时11分58秒
 ************************************************************************/

#ifndef _SET_BAR_H
#define _SET_BAR_H

#include "type.h"


void Set_Select(t_ProBarInfo *bar);
void Set_InitC(t_ProBarInfo *bar);
void Set_DownloadC(t_ProBarInfo* bar);
void Set_BarC(t_ProBarInfo *bar);
void Set_BarS(t_ProBarInfo *bar);
void Set_Information(t_ProBarInfo *bar);
uint8 Set_Bar_BrackerC(t_ProBarInfo *bar ,uint8 Parameter);
uint8 Set_Bar_UnfinCharC(t_ProBarInfo *bar ,uint8 Parameter);
uint8 Set_Bar_FinCharC(t_ProBarInfo *bar ,uint8 Parameter);
uint8 Set_Bar_NumberCC(t_ProBarInfo *bar ,uint8 Parameter);

#endif
