/*************************************************************************
	> File Name: bar.h
	> Author:Feeling 
	> Mail: 741750311@qq.com
	> Created Time: 2018年12月07日 星期五 19时51分06秒
 ************************************************************************/


#ifndef __BAR_H_
#define __BAR_H_
#include "type.h"
#define BAR_LEN_MAX 101
#define COLOR_LEN_MAX 10
//            F  B
#define BLACK "\e[30;40m"
#define RED   "\e[31;40m"
#define GREAN "\e[32;40m"
#define YELLOW "\e[33;40m"
#define BLUE "\e[34;40m"
#define AUBERGINE "\e[35;40m"
#define WHITE "\e[37;40m"



uint16 Pro_Bar_Init(t_ProBarInfo *bar,uint16 argc,const char* argv[]);
void Pro_Bar_Run(t_ProBarInfo *bar);

#endif
