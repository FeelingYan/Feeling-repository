/*************************************************************************
	> File Name:main.c
	> Author:Feeling 
	> Mail: 741750311@qq.com
	> Created Time: 2018年12月07日 星期五 19时48分30秒
 ************************************************************************/



#include "includes.h"



int main (int argc,const char*argv[])
{
    t_ProBarInfo bar;

    Pro_Bar_Init(&bar,argc,argv);
    Pro_Bar_Run(&bar);

    printf("I am Feeling\n");
    return 0;
}
