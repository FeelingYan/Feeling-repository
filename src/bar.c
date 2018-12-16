/*************************************************************************
	> File Name: bar.c
	> Author:Feeling 
	> Mail: 741750311@qq.com
	> Created Time: 2018年12月07日 星期五 19时43分14秒
 ************************************************************************/

#include "includes.h"



/*
 *Function:the function is used to init the point of bar
 *input : bar
 *output : NULL
 */
void Memory_Init(t_ProBarInfo *bar)
{
    
    bar->tShape.ucUnfinChar = (uint8*)malloc(SHAPE_LEN_MAX);
    bar->tShape.ucFinChar = (uint8*)malloc(SHAPE_LEN_MAX);
    
    bar->tColor.ucInitMsg = (uint8* )malloc(COLOR_LEN_MAX);
    bar->tColor.ucUnfinChar = (uint8* )malloc(COLOR_LEN_MAX);
    bar->tColor.ucFinChar = (uint8* )malloc(COLOR_LEN_MAX);
    bar->tColor.ucDownloadMsg = (uint8* )malloc(COLOR_LEN_MAX);
    bar->tColor.ucBrackets = (uint8* )malloc(COLOR_LEN_MAX);
    bar->tColor.ucNumber = (uint8* )malloc(COLOR_LEN_MAX);
}


/*
 *function:the function is used to init the default style 
 *input:bar
 *output:NULL
 */
void Default_Style(t_ProBarInfo* bar)
{
    
    bar->tInfo.uiMaxLen = BAR_LEN_MAX;
    bar->tInfo.ulRate = 10;
    bar->tInfo.ulGross = 4096;
    bar->tInfo.ulExist = 0;
    bar->tInfo.uiPercent = (bar->tInfo.ulExist) / (bar->tInfo.ulGross);

    *bar->tShape.ucUnfinChar = '.';
    *bar->tShape.ucFinChar = '*';
    /*
    strcpy((char*)bar->tShape.ucUnfinChar,".");
    strcpy((char*)bar->tShape.ucFinChar,"*");    
*/  
    strcpy((char*)bar->tColor.ucInitMsg,GREAN);
    strcpy((char*)bar->tColor.ucUnfinChar,WHITE);
    strcpy((char*)bar->tColor.ucFinChar,BLUE);
    strcpy((char*)bar->tColor.ucDownloadMsg,RED);
    strcpy((char*)bar->tColor.ucBrackets,YELLOW);
    strcpy((char*)bar->tColor.ucNumber,AUBERGINE);        
}



/*
 *Function:the function used to read the style
 *Parameter:
 *Output:
 */
uint8 Load_Stytle(t_ProBarInfo* bar)
{
    FILE* DataFp = NULL;
    
    DataFp = fopen("data.dat","rw");
    if(DataFp == NULL)
    {
        printf("file was not\n");
        Default_Style(bar);
        Write_Style(bar);
        return false;
    }
    fclose(DataFp);
    Read_Style(bar);
    return true;
}


/*
 *Function:the function is used to init the style of the bar
 *input: destination bar ,source bar
 *output:NULL
 */
void Transfer_Style(t_ProBarInfo* DesBar,t_ProBarInfo* SrcBar)
{ 
    //printf("transfer is being!\n");
    DesBar->tInfo.uiMaxLen = BAR_LEN_MAX;
    DesBar->tInfo.ulRate = SrcBar->tInfo.ulRate;
    DesBar->tInfo.ulGross = SrcBar->tInfo.ulGross;
    DesBar->tInfo.ulExist = SrcBar->tInfo.ulExist;
    DesBar->tInfo.uiPercent = SrcBar->tInfo.uiPercent;
    //printf("copy is begin\n");
    *DesBar->tShape.ucUnfinChar = *SrcBar->tShape.ucUnfinChar;
    *DesBar->tShape.ucFinChar = *SrcBar->tShape.ucFinChar;
    //strcpy((char*)DesBar->tShape.ucUnfinChar,(char*)SrcBar->tShape.ucUnfinChar);
    //strcpy((char*)DesBar->tShape.ucFinChar,(char*)SrcBar->tShape.ucFinChar);    
    
    strcpy((char*)DesBar->tColor.ucInitMsg, (char*)SrcBar->tColor.ucInitMsg);
    strcpy((char*)DesBar->tColor.ucUnfinChar, (char*)SrcBar->tColor.ucUnfinChar);
    strcpy((char*)DesBar->tColor.ucFinChar, (char*)SrcBar->tColor.ucFinChar);
    strcpy((char*)DesBar->tColor.ucDownloadMsg, (char*)SrcBar->tColor.ucDownloadMsg);
    strcpy((char*)DesBar->tColor.ucBrackets, (char*)SrcBar->tColor.ucBrackets);
    strcpy((char*)DesBar->tColor.ucNumber,(char*)SrcBar->tColor.ucNumber);        
    //printf("transfer is over!\n");
}

/*
 *function:Function is used to judge the num of input parameter
 *parameter:argc argv   
 *output:NULL
 */
uint8 Judge_Input(uint16 argc, const char *argv[])
{
    if((argc == 1) || (argc == 2 && (strcmp(argv[1] , "set") == 0)))
        ;
    else  
        return false;
    return true;
}



/*
 *function: Function is used to initialize the progress bar
            include define len color and state
 *parameter:Temporarily no
 *output: if fail return -1,else 0
*/
uint16 Pro_Bar_Init(t_ProBarInfo* bar,uint16 argc,const char* argv[])
{
    t_ProBarInfo DefStyBar;
    
    if(Judge_Input(argc,argv) == 0)
    {
        printf(RED"Input error!!\n");
        printf(RED"Please re-enter\n");
        exit(1);
    }

    printf(GREAN"----   the bar will be staring init!  ----\n"WHITE);
    usleep(500000);

    Memory_Init(&DefStyBar);
    Memory_Init(bar);

    Load_Stytle(&DefStyBar);
 
    switch(argc)
    {
        case 1:
            Transfer_Style(bar,&DefStyBar); 
            bar->ucbar[0] = '\0';
            break;

        case 2:
            Set_Select(&DefStyBar);
            Transfer_Style(bar,&DefStyBar); 
            //printf("%c  %c  \n",*bar->tShape.ucUnfinChar,*bar->tShape.ucFinChar);
            Write_Style(&DefStyBar);
            //printf("set the parameter over!\n"); 
            
            break;

        default :
            printf(RED"Progress bar init error\n");
            exit(1);
            break;
        
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
        
        bar->tInfo.ulExist += bar->tInfo.ulRate;
        bar->tInfo.uiPercent = ((bar->tInfo.ulExist *100) / (bar->tInfo.ulGross));
        if(bar->tInfo.uiPercent >= (bar->tInfo.uiMaxLen - 1 ))
        {
            bar->tInfo.uiPercent = 100;
        }

        while(j <= bar->tInfo.uiPercent)
        {
            bar->ucbar[j] = *bar->tShape.ucFinChar;
            j++;
        }

        bar->ucbar[bar->tInfo.uiPercent + 1] = '\0';
        printf("\r""%s""["WHITE,bar->tColor.ucBrackets);
        printf("%s""%s"WHITE,bar->tColor.ucFinChar,bar->ucbar);
        for(i = 0 ;i < (bar->tInfo.uiMaxLen - bar->tInfo.uiPercent - 1);i++)
            printf("%s""%c"WHITE,bar->tColor.ucUnfinChar,*bar->tShape.ucUnfinChar);
        printf("%s""]""%s""     %d%%"WHITE,bar->tColor.ucBrackets,bar->tColor.ucNumber,bar->tInfo.uiPercent);
        fflush(stdout);
        
        usleep(10000);
    }
    printf("\n\n");
    printf("%s""----     the progream was finished!   ----\n\n"WHITE, bar->tColor.ucDownloadMsg);
    sleep(1);
}


