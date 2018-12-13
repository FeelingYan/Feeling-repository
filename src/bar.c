/*************************************************************************
	> File Name: bar.c
	> Author:Feeling 
	> Mail: 741750311@qq.com
	> Created Time: 2018年12月07日 星期五 19时43分14秒
 ************************************************************************/

#include "includes.h"


/*
 *function: Function is used to initialize the progress bar
            include define len color and state
 *parameter:Temporarily no
 *output: if fail return -1,else 0
 *
*/
uint16 Pro_Bar_Init(t_ProBarInfo* bar,uint16 argc,const char* argv[])
{
    printf(GREAN"----   the bar will be staring init!  ----\n"WHITE);
    usleep(500000);

     switch(argc)
    {
        case 1:
        {
            bar->tInfo.uiMaxLen = BAR_LEN_MAX;
            bar->tInfo.ulRate = 10;
            bar->tInfo.ulGross = 4096;
            bar->tInfo.ulExist = 0;
            bar->tInfo.uiPercent = (bar->tInfo.ulExist) / (bar->tInfo.ulGross);

            bar->tShape.ucUnfinChar = '.';
            bar->tShape.ucFinChar = '*';
            
            bar->tColor.ucInitMsg = (uint8* )malloc(COLOR_LEN_MAX);
            bar->tColor.ucUnfinChar = (uint8* )malloc(COLOR_LEN_MAX);
            bar->tColor.ucFinChar = (uint8* )malloc(COLOR_LEN_MAX);
            bar->tColor.ucDownloadMsg = (uint8* )malloc(COLOR_LEN_MAX);
            bar->tColor.ucBrackets = (uint8* )malloc(COLOR_LEN_MAX);
            bar->tColor.ucNumber = (uint8* )malloc(COLOR_LEN_MAX);

            strcpy((char*)bar->tColor.ucInitMsg,GREAN);
            strcpy((char*)bar->tColor.ucUnfinChar,WHITE);
            strcpy((char*)bar->tColor.ucFinChar,BLUE);
            strcpy((char*)bar->tColor.ucDownloadMsg,RED);
            strcpy((char*)bar->tColor.ucBrackets,YELLOW);
            strcpy((char*)bar->tColor.ucNumber,AUBERGINE);
            


            bar->ucbar[0] = '\0';
            default :
                printf("input error\n");
                exit(1);
                break;
        }
     }
    printf("%s""----     the bar init was finish!     ----\n"WHITE,bar->tColor.ucInitMsg);
    printf("\n"); 
    usleep(500000);
    return 0;
}

/*
 * function:Function is used to run the progress_bar,calculate percentage based on rate
 * parameter:structure of the progress bar
 * output:none
 *
 */
void Pro_Bar_Run(t_ProBarInfo* bar)
{
    uint8 i,j = 0;
    printf("%s""----  the progream star to download!  ----\n\n"WHITE,bar->tColor.ucDownloadMsg);
    
    while((bar->tInfo.uiPercent) < (bar->tInfo.uiMaxLen - 1))
    {
        
        printf("\r""%s""["WHITE,bar->tColor.ucBrackets);
        printf("%s""%s"WHITE,bar->tColor.ucFinChar,bar->ucbar);
        for(i = 0 ;i < (bar->tInfo.uiMaxLen - bar->tInfo.uiPercent - 1);i++)
            printf("%s""."WHITE,bar->tColor.ucUnfinChar);
        printf("%s""]""%s""     %d%%"WHITE,bar->tColor.ucBrackets,bar->tColor.ucNumber,bar->tInfo.uiPercent);
        fflush(stdout);

        bar->tInfo.ulExist += bar->tInfo.ulRate;
        bar->tInfo.uiPercent = ((bar->tInfo.ulExist *100) / (bar->tInfo.ulGross));
        if(bar->tInfo.uiPercent >= (bar->tInfo.uiMaxLen - 1 ))
        {
            bar->tInfo.uiPercent = 100;
        }

        while(j <= bar->tInfo.uiPercent)
        {
            bar->ucbar[j] = '*';
            j++;
        }
        bar->ucbar[bar->tInfo.uiPercent + 1] = '\0';
        
        if(bar->tInfo.uiPercent == bar->tInfo.uiMaxLen - 1)
        {
            printf("\r""%s""["WHITE,bar->tColor.ucBrackets);
            printf("%s""%s"WHITE,bar->tColor.ucFinChar,bar->ucbar);
            for(i = 0 ;i < (bar->tInfo.uiMaxLen - bar->tInfo.uiPercent - 1);i++)
                printf("%s""."WHITE,bar->tColor.ucUnfinChar);
            printf("%s""]""%s""     %d%%"WHITE,bar->tColor.ucBrackets,bar->tColor.ucNumber,bar->tInfo.uiPercent);
            fflush(stdout);
        }
        usleep(10000);
    }
    printf("\n\n");
    printf("%s""----     the progream was finished!   ----\n\n"WHITE, bar->tColor.ucDownloadMsg);
    sleep(1);
}


