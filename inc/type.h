/*************************************************************************
	> File Name: type.h
	> Author:Feeling 
	> Mail: 741750311@qq.com
	> Created Time: 2018年12月07日 星期五 19时43分14秒
 ************************************************************************/

#ifndef __TYPE_H_
#define __TYPE_H_

#define false 0
#define true 1
#define BAR_LEN_MAX 101
#define COLOR_LEN_MAX 10
#define SHAPE_LEN_MAX 1
typedef unsigned char uint8;
typedef signed int sint8;
typedef unsigned int uint16;
typedef signed int sint16;
typedef unsigned long int uint32;
typedef signed long int sint32;


/*
 * The structure used for encapsulating all
 * the items associated with a color
 */
typedef struct
{
    //
    // The color of init message.
    // 
    uint8 *ucInitMsg;

    //
    // The chars of unfinishing in progress bar.
    //
    uint8 *ucUnfinChar;

    //
    // The char of finishing in progress bar.
    //
    uint8 *ucFinChar;

    //
    // The color of download message.
    //
    uint8 *ucDownloadMsg;

    //
    // The color of brackets
    //
    uint8 *ucBrackets;

    //
    // The color of num
    //
    uint8 *ucNumber;
}t_BarColorInfo;

/*
 *
 *
 */
typedef struct
{
    //
    // The shape of unfinishing char.
    //
    uint8 *ucUnfinChar;

    //
    // The shape of finish char.
    //
    uint8 *ucFinChar;

}t_BarShapeInfo;

/*
 * The structure use for encapsulating all
 * the item associated with size of bar.
 */
typedef struct
{
    //
    // The max length of the bar.
    //
    uint16 uiMaxLen;
    
    //
    // The bar rate,and the units is 'kb'
    //
    uint32 ulRate;
    
    //
    // The bar total download required
    //
    uint32 ulGross;

    //
    // The bar download the existing size
    // 
    uint32 ulExist;

    //
    // The bar download percentage
    //
    uint16 uiPercent;

}t_BarSizeInfo;


/*
 * The structure used for encapsulating all 
 * the items associated with a bar.
 */
typedef struct
{
    //
    // The color of the bar.
    //
    t_BarColorInfo tColor;

    //
    // The size of the bar.
    //
    t_BarSizeInfo tInfo;

    //
    // The shape of the bar.
    //
    t_BarShapeInfo tShape;

    //
    // The buffer of bar.
    //
    uint8 ucbar[BAR_LEN_MAX];
}t_ProBarInfo;






#endif
