/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 4월 12일 (화), 오후 9:02
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
 * 
 */

void test()
{
    int pid;
    int param;
    int i,j;
    int childPid[10];
    
    printf("Start\n");
    
    for(i=0;i<10;i++)
    {
        param=rand()%5+1;
        
        pid=fork();
        if(0==pid)
        {
            for(j=0;j<param;j++)
            {
                printf("%d -> I'm Child : %d\n",param,getpid());
                sleep(1);
            }
            printf("%d end\n",i);
            exit(getpid());
        }
        sleep(1);
    }
    
    for(i=0;i<10;i++)
        waitpid(childPid[i],NULL,0);
 
    printf("End\n");
}

int main(int argc, char** argv) {

    test();
    
    return (EXIT_SUCCESS);
}

