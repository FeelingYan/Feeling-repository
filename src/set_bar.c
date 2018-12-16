/*************************************************************************
	> File Name: set_bar.c
	> Author:Feeling 
	> Mail: 741750311@qq.com
	> Created Time: 2018年12月16日 星期日 13时15分43秒
 ************************************************************************/

#include "includes.h"

/*
 *Function : the function is used to init the color of init Message
 *input : bar
 *output : NULL
 */
void Set_InitC(t_ProBarInfo *bar)
{
    int SetInput = 0;
    uint8 SetState = 1;
    char c = 0;
    while(SetState)
    {
        printf(BLUE"----  Please set the color of init  ----\n"WHITE);
        printf(GREAN"----  1.Black  2.Red  3.Grean  4.Yellow  5.Blue  6.Aubergine  7.White  ----\n"WHITE);
        scanf("%d",&SetInput);
        while((c = getchar()) != EOF && c != '\n');
        c = 0;
        //printf("%d\n",SetInput);
        switch(SetInput)
        {
            case 1:
                strcpy((char*)bar->tColor.ucInitMsg , BLACK);
                break;
            case 2: 
                strcpy((char*)bar->tColor.ucInitMsg , RED);
                break;
            case 3:
                strcpy((char*)bar->tColor.ucInitMsg , GREAN);
                break;
            case 4:
                strcpy((char*)bar->tColor.ucInitMsg , YELLOW);
                break;
            case 5:
                strcpy((char*)bar->tColor.ucInitMsg , BLUE);
                break;
            case 6:
                strcpy((char*)bar->tColor.ucInitMsg , AUBERGINE);
                break;
            case 7:
                strcpy((char*)bar->tColor.ucInitMsg , WHITE);
                break;
            default :
                printf(BLUE"Enter error, Please again\n"WHITE);
                continue;        
        }
        SetState = 0;
    }
}

/*
 *Function : the function is used to init the color of download message
 *input : bar
 *output : NULL
 */
void Set_DownloadC(t_ProBarInfo *bar)
{
    
    int SetInput = 0;
    uint8 SetState = 1;
    char c = 0;
    while(SetState)
    {
        printf(BLUE"----  Please set the color of Download Message  ----\n"WHITE);
        printf(GREAN"----  1.Black  2.Red  3.Grean  4.Yellow  5.Blue  6.Aubergine  7.White  ----\n"WHITE);
        scanf("%d",&SetInput);
        while((c = getchar()) != EOF && c != '\n');
        c = 0;
        
        switch(SetInput)
        {
            case 1:
                strcpy((char*)bar->tColor.ucDownloadMsg , BLACK);
                break;
            case 2: 
                strcpy((char*)bar->tColor.ucDownloadMsg , RED);
                break;
            case 3:
                strcpy((char*)bar->tColor.ucDownloadMsg , GREAN);
                break;
            case 4:
                strcpy((char*)bar->tColor.ucDownloadMsg , YELLOW);
                break;
            case 5:
                strcpy((char*)bar->tColor.ucDownloadMsg , BLUE);
                break;
            case 6:
                strcpy((char*)bar->tColor.ucDownloadMsg, AUBERGINE);
                break;
            case 7:
                strcpy((char*)bar->tColor.ucDownloadMsg , WHITE);
                break;
            default :
                printf(BLUE"Enter error,Please enter again\n"WHITE);
                continue;
                
        }
        SetState = 0;
    }
}

/*
 *Function : the function is used to init the color of bracker in bar
 *input : bar
 *output : NULL
 */
uint8 Set_Bar_BrackerC(t_ProBarInfo *bar, uint8 Parameter)
{
    switch(Parameter)
    {
        case 1:
            strcpy((char*)bar->tColor.ucBrackets, BLACK);
            break;
        case 2: 
            strcpy((char*)bar->tColor.ucBrackets, RED);
            break;
        case 3:
            strcpy((char*)bar->tColor.ucBrackets, GREAN);
            break;
        case 4:
            strcpy((char*)bar->tColor.ucBrackets, YELLOW);
            break;
        case 5:
            strcpy((char*)bar->tColor.ucBrackets, BLUE);
            break;
        case 6:
            strcpy((char*)bar->tColor.ucBrackets, AUBERGINE);
            break;
        case 7:
            strcpy((char*)bar->tColor.ucBrackets, WHITE);
            break;
        default:
            printf(BLUE"Enter error, Please again!\n"WHITE);
            return 1;
    }
    return 0;
}


/*
 *Function : the function is used to init the color of unfinishchar in bar
 *input : bar
 *output : NULL
 */
uint8 Set_Bar_UnfinCharC(t_ProBarInfo *bar , uint8 Parameter)
{
    switch(Parameter)
    {
        case 1:
            strcpy((char*)bar->tColor.ucUnfinChar, BLACK);
            break;
        case 2: 
            strcpy((char*)bar->tColor.ucUnfinChar, RED);
            break;
        case 3:
            strcpy((char*)bar->tColor.ucUnfinChar, GREAN);
            break;
        case 4:
            strcpy((char*)bar->tColor.ucUnfinChar, YELLOW);
            break;
        case 5:
            strcpy((char*)bar->tColor.ucUnfinChar, BLUE);
            break;
        case 6:
            strcpy((char*)bar->tColor.ucUnfinChar, AUBERGINE);
            break;
        case 7:
            strcpy((char*)bar->tColor.ucUnfinChar, WHITE);
            break;
        default:
            printf(BLUE"Enter error, Please again!\n"WHITE);
            return 1;
    }
    return 0;
}

/*
 *Function : the function is used to init the color of finishchar in bar
 *input : bar
 *output : NULL
 */
uint8 Set_Bar_FinCharC(t_ProBarInfo *bar,uint8 Parameter)
{
    switch(Parameter)
    {
        case 1:
            strcpy((char*)bar->tColor.ucFinChar, BLACK);
            break;
        case 2: 
            strcpy((char*)bar->tColor.ucFinChar, RED);
            break;
        case 3:
            strcpy((char*)bar->tColor.ucFinChar, GREAN);
            break;
        case 4:
            strcpy((char*)bar->tColor.ucFinChar, YELLOW);
            break;
        case 5:
            strcpy((char*)bar->tColor.ucFinChar, BLUE);
            break;
        case 6:
            strcpy((char*)bar->tColor.ucFinChar, AUBERGINE);
            break;
        case 7:
            strcpy((char*)bar->tColor.ucFinChar, WHITE);
            break;
        default:
            printf(BLUE"Enter error, Please again!\n"WHITE);
            return 1;
    }
    return 0;
}

/*
 *Function : the function is used to init the color of number in bar
 *input : bar
 *output : NULL
 */
uint8 Set_Bar_NumberC(t_ProBarInfo *bar, uint8 Parameter)
{
    switch(Parameter)
    {
        case 1:
            strcpy((char*)bar->tColor.ucNumber, BLACK);
            break;
        case 2: 
            strcpy((char*)bar->tColor.ucNumber, RED);
            break;
        case 3:
            strcpy((char*)bar->tColor.ucNumber, GREAN);
            break;
        case 4:
            strcpy((char*)bar->tColor.ucNumber, YELLOW);
            break;
        case 5:
            strcpy((char*)bar->tColor.ucNumber, BLUE);
            break;
        case 6:
            strcpy((char*)bar->tColor.ucNumber, AUBERGINE);
            break;
        case 7:
            strcpy((char*)bar->tColor.ucNumber, WHITE);
            break;
        default :
            printf(BLUE"Enter error, Please again!\n"WHITE);
            return 1;
    }
    return 0;
}

/*
 *Function : the function is used to init the color of bar
 *input : bar
 *output : NULL
 */
void Set_BarC(t_ProBarInfo *bar)
{
    int SetInput = 0;
    uint8 SetState = 1;
    char c = 0;
    while(SetState != 0)
    {
        printf(BLUE"----  Please set the color of bar  ----\n"WHITE);
        printf(BLUE"---- The color of bar include bracker unfinishchar finishchar and number  ----\n"WHITE);
        printf(GREAN"----  1.Black  2.Red  3.Grean  4.Yellow  5.Blue  6.Aubergine  7.White  ----\n"WHITE);
        scanf("%d",&SetInput);
        while((c = getchar()) != EOF && c != '\n');
        c = 0;
        if((SetInput >= 1111) && (SetInput < 7777) && 
           ((SetInput/100)%10 <= 7 ) && ((SetInput/10)%10 <= 7) && ((SetInput%10) <= 7) &&
           ((SetInput/100)%10 >= 1 ) && ((SetInput/10)%10 >=1) && ((SetInput%10) >=1))
        {
            //rintf("%d",SetInput);
            if(1 == Set_Bar_BrackerC(bar,(SetInput/1000)))
            {
                printf(BLUE"Set the bracker error!\n"WHITE);
                continue;
            }
            if(1 == Set_Bar_UnfinCharC(bar,(SetInput/100)%10))
            {
                printf(BLUE"Set the unfinishchar error!\n"WHITE);
                continue;
            }
            if(1 == Set_Bar_FinCharC(bar, (SetInput/10)%10))
            {
                printf(BLUE"Set the finishchar error!\n"WHITE);
                continue;
            }
            if(1 == Set_Bar_NumberC(bar,SetInput%10))
            {
                printf(BLUE"Set the number error!\n"WHITE);
                continue;
            }
            SetState = 0;
        }
        else
        {
            printf(BLUE"Enter error,Please again!\n"WHITE);
        }
    }
}

/*
 *Function : the function is used to init the information of bar
 *input : bar
 *output : NULL
 */
void Set_Information(t_ProBarInfo *bar)
{
    int SetInput = 0;
    uint8 SetState = 2;
    char c;
    
    printf(BLUE"----  Please set the information of bar  ----\n"WHITE);
    printf(BLUE"---- The information of bar Rate Gross  ----\n"WHITE);
    
    while(SetState)
    {
        switch(SetState)
        {
            case 1:
                printf(GREAN"----  Please set the Gross(0~9999)  ----\n"WHITE);
                scanf("%d",&SetInput);
                while((c = getchar()) != EOF && c != '\n');
                if((SetInput < 10000) && (SetInput > 0))
                {
                    bar->tInfo.ulGross = SetInput;
                
                }
                else
                {
                    printf(BLUE"Input error,Please enter again\n"WHITE);
                    SetState = 1;
                    continue;
                }
                break;
            case 2:
                printf(GREAN"----  Please set the Rate(0~9999)  ----\n"WHITE);
                scanf("%d",&SetInput);
                while((c = getchar()) != EOF && c != '\n');

                if((SetInput < 10000) && (SetInput > 0))
                {
                    bar->tInfo.ulRate = SetInput;

                }
                else
                {
                    printf(BLUE"Input error,Please enter again\n"WHITE);
                    SetState = 2;
                    continue;
                }
                break;
            default:
                printf(BLUE"Enter error, Please again!\n"WHITE);
                continue;
        }
        SetState--;
    }
}

/*
 *Function : the function is used to init the Shape of bar
 *input : bar
 *output : NULL
 */
void Set_BarS(t_ProBarInfo *bar)
{
    char SetInput;
    uint8 SetState = 2;
    char c = 0;
    printf(BLUE"----  Please set the Shape of bar  ----\n"WHITE);
    printf(BLUE"---- The Shape of bar is unfinishchar finishchar  ----\n"WHITE);

    while(SetState > 0)
    {
        switch(SetState)
        {
            case 1:
                printf(GREAN"----  Please set the the shape of unfinishchar  ----\n"WHITE);
                scanf("%c",&SetInput);
                while((c = getchar()) != EOF && c != '\n');
                c = 0;
                //printf("%c\n",SetInput);
                if((SetInput < 'w') && (SetInput > '!'))
                {
                    *bar->tShape.ucUnfinChar = SetInput;
                }
                else
                {
                    printf(BLUE"Input error,Please enter again\n"WHITE);
                    SetState = 1;
                    continue;
                }
                break;
            case 2:
                printf(GREAN"----  Please set the shape of finishchar  ----\n"WHITE);
                scanf("%c",&SetInput);
                while((c = getchar()) != EOF && c != '\n');
                c = 0;
                //printf("%c\n",SetInput);
                if((SetInput < 'w') && (SetInput > '!'))
                {
                    *bar->tShape.ucFinChar = SetInput;
                }
                else
                {
                    printf(BLUE"Input error,Please enter again\n"WHITE);
                    SetState = 2;
                    continue;
                }
                break;
            default:
                printf(BLUE"Enter error, Please again!\n"WHITE);
                SetState = 2;
                continue;
        }
        SetState--;
    }
}

/*
 *Function : the function is used to set up the interactive interface
 *input : bar
 *output : NULL
 */
void Set_Select(t_ProBarInfo *bar)
{
    int SetTemp;
    uint8 SetState = 1;
    char c;
    while(SetState)
    {
        printf(BLUE"----  Please select the range of set by number  ----\n"WHITE);
        printf(GREAN"----  1.Init    2.Download    3.Bar  4.Information  5.Shape  6.All  ----\n"WHITE);
        scanf("%d",&SetTemp);
        while((c = getchar()) != EOF && c != '\n');

        c = 0;
        switch(SetTemp)
        {
            case 1:
                Set_InitC(bar);
                SetState = 0;
                break;
            case 2:
                Set_DownloadC(bar);
                SetState = 0;
                break;
            case 3:
                Set_BarC(bar);
                SetState = 0;
                break;
            case 4:
                Set_Information(bar);
                SetState = 0;
                break;
            case 5:
                Set_BarS(bar);
                SetState = 0;
                break;
            case 6:
                Set_InitC(bar);
                Set_DownloadC(bar);
                Set_BarC(bar);
                Set_BarS(bar);
                Set_Information(bar);
                SetState = 0;
                break;
            default :
                printf(BLUE"Enter error,Please enter again\n"WHITE);
        }
    }
}
