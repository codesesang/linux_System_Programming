/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "member.h"

#define MAX_MEMBER 100

S_MEMBER g_Members[MAX_MEMBER];

void BestMember()
{
    int i;
    int best=g_Members[0].total;
    
    for(i=0;i<MAX_MEMBER;i++)
    {
        if(1==g_Members[i].flag && best<g_Members[i].total)
        {
            best=g_Members[i].total;
        }
    }
     printf("%s %d %d %d %d %d\n",g_Members[i].name,g_Members[i].kor,g_Members[i].eng,g_Members[i].math,g_Members[i].total,g_Members[i].avg);
}

int AddMember(char* name,int kor,int eng,int math)
{
    int i;
    int index=-1;
    
    for(i=0;i<MAX_MEMBER;i++)
    {
        if(-1==g_Members[i].flag)
        {
            index=i;
            break;
        }
    }
    
    if(-1==index)
    {
        return -1;
    }
    
    strcpy(g_Members[i].name,name);
    g_Members[i].kor=kor;
    g_Members[i].eng=eng;
    g_Members[i].math=math;
    g_Members[i].total=kor+eng+math;
    g_Members[i].avg=g_Members[i].total/3.0;
    
    g_Members[i].flag=1;
       
        return 0;
}

int ShowMember()
{
    int i;
    
    for(i=0;i<MAX_MEMBER;i++)
    {
        if(1==g_Members[i].flag)
        {
            printf("%s %d %d %d %d %f\n",g_Members[i].name,g_Members[i].kor,g_Members[i].eng,g_Members[i].math,g_Members[i].total,g_Members[i].avg);
        }
    }
    
    return 0;
}

int LoadMember(char* filename)
{
    int fd;
    
    fd=open(filename,O_RDONLY);
    
    if(-1==fd)
    {
        return -1;
    }
    
    IniMember();
    
    
    while(1)
    {
        S_MEMBER m;
        int len;
        
        len=read(fd,&m,sizeof(S_MEMBER));
        
        if(len<=0)
            break;
        
        AddMember(m.name,m.kor,m.eng,m.math);
    }
    
    close(fd);
    
    return 0;
}

int SaveMember(char* filename)
{
    int i;
    int fd;
    
    fd=open(filename,O_WRONLY|O_CREAT|O_TRUNC,0644);
    
    if(-1==fd)
    {
        return -1;
    }
    
    for(i=0;i<MAX_MEMBER;i++)
    {
        if(1==g_Members[i].flag)
        {
            write(fd,&g_Members[i],sizeof(S_MEMBER));
        }
    }
    
    close(fd);
    
    return 0;
}

int IniMember()
{
    int i=0;
    
    for(i=0;i<MAX_MEMBER;i++)
    {
        g_Members[i].flag=-1;
    }
    
    return 0;
}