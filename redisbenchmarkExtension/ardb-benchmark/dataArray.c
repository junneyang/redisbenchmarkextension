/***************************************************************************
 *
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @file dataArray.c
 * @author yangjun03(com@baidu.com)
 * @date 2014/03/26 23:29:43
 * @brief
 *
 **/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 9990
#define L 15
static char dataArray[N*2][L];

int dataArrayInit()
{
    FILE *fp=fopen("testData.txt","r");
    int i=0;
    int j=0;
    int cnt=0;
    char cuid[30];
    char x[L];
    char y[L];
    while(fscanf(fp,"%s\t%s\t%s",cuid,x,y)!=EOF)
    {
        strcpy(dataArray[i],x);
        strcpy(dataArray[i+1],y);
        int len_x=strlen(dataArray[i]);
        int len_y=strlen(dataArray[i+1]);
        //printf("%d-%d-%s\t%d-%d-%s\n",sizeof(dataArray[i]),len_x,dataArray[i],sizeof(dataArray[i+1]),len_y,dataArray[i+1]);
        for(j=len_x;j<L-1;j++)
        {
            dataArray[i][j]=' ';
        }
        dataArray[i][j]='\0';
        for(j=len_y;j<L-1;j++)
        {
            dataArray[i+1][j]=' ';
        }
        dataArray[i+1][j]='\0';
        //printf("%d-%d-%s\t%d-%d-%s\n",sizeof(dataArray[i]),len_x,dataArray[i],sizeof(dataArray[i+1]),len_y,dataArray[i+1]);

        i+=2;
        cnt+=1;
    }
    //printf("cnt:%d\n",cnt);
    fclose(fp);

    return 0;
}

int main()
{
    printf("////////////////////////////////////////////////文件解析\n");
    dataArrayInit();
    int i=0;
    for(i=0;i<N*2;i+=2)
    {
        printf("x:%s\ty:%s\n",dataArray[i],dataArray[i+1]);
    }
	printf("////////////////////////////////////////////////文件解析\n");

    printf("////////////////////////////////////////////////随机选取\n");
    srand((int)time(0));
    for(i=0;i<100;i++)
    {
        int index=rand()%N;
        printf("index:%d\t",index);
        printf("x:%s\ty:%s\n",dataArray[index*2],dataArray[index*2+1]);
    }
	printf("////////////////////////////////////////////////随机选取\n");
    return 0;
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
