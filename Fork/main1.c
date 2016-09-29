/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 4월 12일 (화), 오후 8:01
 */

#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
/*
 * 
 */
int ChildProc()
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

void test1()
{
    int re;
    int a;
    int b;
    
    printf("Start %d\n",getpid());
    
    re=fork();
    
    if(re==0)
    {
        printf("Child : %d\n",getpid());
        exit(1);
    }
  
    printf("Parent : %d\n",getpid());
    b=wait(&a);
    printf("main end : %d %d\n",a>>8,b);
}

void test2()
{
    int child;
    int b;
    int c;
    int sum;
    
    child=fork();
    if(child==0)
    {
        int sum;
        sum=ChildProc();
        exit(sum);
    }
    printf("Waiting...%d\n",getpid());
    c=wait(&b);
    
    printf("main end %d\n",b>>8);
}



int main(int argc, char** argv) {

    test2();
    
    return (EXIT_SUCCESS);
}

