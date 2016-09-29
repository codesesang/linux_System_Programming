/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "member.h"

void RunAdd()
{
    char name[20];
    int kor,eng,math;
    
    printf("Name Kor Eng Math : ");
    scanf("%s %d %d %d",name,&kor,&eng,&math);
    
    if(-1==AddMember(name,kor,eng,math))
    {
        printf("Error\n");
    }
    else
    {
        printf("Success\n");
    }
    
}

void RunShow()
{
    ShowMember();
}

void RunSave()
{
    char filename[80];
    
    printf("Input Filename : ");
    scanf("%s",filename);
    
    if(-1==SaveMember(filename))
    {
        printf("File Save Error\n");
    }
    
    else
    {
        printf("File Save Success\n");
    }
}

void RunLoad()
{
    char filename[80];
    
    printf("Input Filename : ");
    scanf("%s",filename);
    
    if(-1==LoadMember(filename))
    {
        printf("File Load Error\n");
    }
    else
    {
        printf("File Load Success\n");
    }
}

void RunBest()
{
    
    void BestMember();
}

void Run()
{
    char cmd[20];
    
    IniMember();
    
    while(1)
    {
        printf("# : ");
        scanf("%s",cmd);
       
        
        if(0==strcmp("exit",cmd))
        {
            printf("Good Bye\n");
            break;
        }
        
        else if(0==strcmp("add",cmd))
        {
            RunAdd();
        }
        
        else if(0==strcmp("show",cmd))
        {
            RunShow();
        }
        
        else if(0==strcmp("save",cmd))
        {
            RunSave();
        }
        
        else if(0==strcmp("load",cmd))
        {
            RunLoad();
        }
        
        else if(0==strcmp("best",cmd))
        {
            RunBest();
        }
        
        else
        {
            printf("Unknown Command\n");
        }
    }
}