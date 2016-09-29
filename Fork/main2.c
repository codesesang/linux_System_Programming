/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 4월 12일 (화), 오후 8:43
 */

#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * 
 */

int MyAdd1()    //1~10 sum return
{
    int sum=0;
    int i;
    
    for(i=0;i<10;i++)
    {
        sum+=i+1;
        printf("child : %d -> %d\n",getpid(),i+1);
        sleep(1);
    }
    
    return sum;
}

int MyAdd2()    //11~20 sum return
{
    int sum=0;
    int i;
    
    for(i=0;i<10;i++)
    {
        sum+=i+11;
        printf("grandchild : %d -> %d\n",getpid(),i+11);
        sleep(1);
    }
    
    return sum;
}

void Test()
{    
    int pid;
    int total;
    int temp;
 
    printf("Start : %d\n",getpid());
        
    pid=fork();
    if(0==pid)
    {
        total=MyAdd1();
        
        pid=fork();
        if(0==pid)
        {
            total=MyAdd2();
            exit(total);
        }
        wait(&temp);
        int a=temp>>8;
        a+=total;
        exit(a);
    }
    wait(&temp);
    printf("Parent : %d sum : %d\n",getpid(),temp>>8);
    printf("End\n");
}


int main(int argc, char** argv) {

    Test();
    
    return (EXIT_SUCCESS);
}

