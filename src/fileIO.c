/*************************************************************************
	> File Name: fileIO.c
	> Author:Feeling 
	> Mail: 741750311@qq.com
	> Created Time: 2018年12月15日 星期六 22时56分07秒
 ************************************************************************/

#include "includes.h"



/*
 *Function:the function is used to read the infomantion from data.dat file
 *input : bar
 *output :NULL
 */
void Read_Style(t_ProBarInfo* DesBar)
{ 
    FILE* DataFp = NULL;

    // printf("read the file\n");
    DataFp = fopen("data.dat","r+");
    
    if(DataFp == NULL)
    {
        printf("Open file fail!\n");
        exit(1);
    }

    fread(&DesBar->tInfo.uiMaxLen, sizeof(DesBar->tInfo.uiMaxLen), 1, DataFp);
    fread(&DesBar->tInfo.ulRate, sizeof(DesBar->tInfo.ulRate), 1, DataFp);
    fread(&DesBar->tInfo.ulGross, sizeof(DesBar->tInfo.ulGross), 1, DataFp);
    fread(&DesBar->tInfo.ulExist, sizeof(DesBar->tInfo.ulExist), 1, DataFp);
    fread(&DesBar->tInfo.uiPercent, sizeof(DesBar->tInfo.uiPercent), 1, DataFp);
  
    fread(DesBar->tShape.ucUnfinChar, sizeof(DesBar->tShape.ucUnfinChar), 1, DataFp);
    fread(DesBar->tShape.ucFinChar, sizeof(DesBar->tShape.ucFinChar), 1, DataFp);

    fread(DesBar->tColor.ucInitMsg, sizeof(DesBar->tColor.ucInitMsg), 1, DataFp);
    fread(DesBar->tColor.ucUnfinChar, sizeof(DesBar->tColor.ucUnfinChar), 1, DataFp);
    fread(DesBar->tColor.ucFinChar, sizeof(DesBar->tColor.ucFinChar), 1, DataFp);
    fread(DesBar->tColor.ucDownloadMsg, sizeof(DesBar->tColor.ucDownloadMsg), 1, DataFp);
    fread(DesBar->tColor.ucBrackets, sizeof(DesBar->tColor.ucBrackets), 1, DataFp);
    fread(DesBar->tColor.ucNumber, sizeof(DesBar->tColor.ucNumber), 1, DataFp);
 
    fclose(DataFp);
    //printf("read is over\n");   
} 



/*
 *Function:the function is used to write the informantion to data.dat file
 *Parameter:bar
 *Output:NULL
 */
void Write_Style(t_ProBarInfo* DesBar)
{ 
    FILE* DataFp=NULL;
    //printf("write the file\n");
    DataFp = fopen("data.dat","w");

    fwrite(&DesBar->tInfo.uiMaxLen, sizeof(DesBar->tInfo.uiMaxLen), 1, DataFp);
    fwrite(&DesBar->tInfo.ulRate, sizeof(DesBar->tInfo.ulRate), 1, DataFp);
    fwrite(&DesBar->tInfo.ulGross, sizeof(DesBar->tInfo.ulGross), 1, DataFp);
    fwrite(&DesBar->tInfo.ulExist, sizeof(DesBar->tInfo.ulExist), 1, DataFp);
    fwrite(&DesBar->tInfo.uiPercent, sizeof(DesBar->tInfo.uiPercent), 1, DataFp);

    fwrite(DesBar->tShape.ucUnfinChar, sizeof(DesBar->tShape.ucUnfinChar), 1, DataFp);
    fwrite(DesBar->tShape.ucFinChar, sizeof(DesBar->tShape.ucFinChar), 1, DataFp);
    
    fwrite(DesBar->tColor.ucInitMsg, sizeof(DesBar->tColor.ucInitMsg), 1, DataFp);
    fwrite(DesBar->tColor.ucUnfinChar, sizeof(DesBar->tColor.ucUnfinChar), 1, DataFp); 
    fwrite(DesBar->tColor.ucFinChar, sizeof(DesBar->tColor.ucFinChar), 1, DataFp);
    fwrite(DesBar->tColor.ucDownloadMsg, sizeof(DesBar->tColor.ucDownloadMsg), 1, DataFp);
    fwrite(DesBar->tColor.ucBrackets, sizeof(DesBar->tColor.ucBrackets), 1, DataFp);
    fwrite(DesBar->tColor.ucNumber, sizeof(DesBar->tColor.ucNumber), 1, DataFp);

    fclose(DataFp);
}
