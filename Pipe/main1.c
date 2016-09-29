/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 5월 31일 (화), 오후 6:13
 */
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */

jmp_buf env;

/////////////////////////////////////////////
void test1()
{
    int i;
    
    for(i=0;i<5;i++)
    {
        printf("test1 : %d\n",i);
        sleep(1);
    }
}

void test2()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("test2 : %d\n",i);
        sleep(1);
    }
    
    printf("==================================\n");
    
    longjmp(env,10);
    
    printf("----------------------------------\n");
}

void Maintest1()
{
    printf("Start Main\n");
    
    if(0!=setjmp(env))
    {
        test1();
        
        exit(1);
    }
    test2();
}
/////////////////////////////////////////////
void test3()
{
    int i;
    
    for(i=0;i<10;i++)
    {
        printf("test3 : %d\n",i);
        sleep(1);
    }
    
    longjmp(env,10);
}

void test4()
{
    int i;
    int sum=0;
    
    for(i=0;i<10;i++)
    {
        sum+=i+1;
    }
    printf("test4 sum : %d\n",sum);
}

void Maintest2()
{
    if(0!=setjmp(env))
    {
        test4();
        
        exit(1);
    }
    
    test3();
}
/////////////////////////////////////////////

void test5()
{
    printf("test5\n");
    
    longjmp(env,0);
}

void Maintest3()
{ 
    int i=0;
    
    printf("Start Main\n");
    
    signal(SIGINT,test5);
    
    if(1==setjmp(env))
        i=0;
  
    while(1)
    {
        printf("%d\n",i);
        sleep(1);
        i++;
    }
}

///////////////////////////////////////////

void test6()
{
    int i;
    int sum=0;
    
    for(i=0;i<10;i++)
    {
        sum+=i+1;
        
        printf("test6 sum : %d\n",sum);
        sleep(1);
    }
    exit(1);
}

void test7()
{
    int i;
    
    for(i=0;i<10;i++)
    {
        printf("test7 : %d\n",i);
        sleep(1);
    }
}

void Maintest4()
{
    signal(SIGINT,test6);
    
    while(1)
    {
        test7();
    }
}

/////////////////////////////////////////////Pipe

int fd[2];

void childProc()
{
    int i;
    int total=0;
    char buf[1024];
    
    for(i=0;i<10;i++)
    {
        total+=i+1;
        memset(buf,0,1024);
        //printf("%d = %d\n",i+1,total);
        
        sprintf(buf,"%d = %d",i+1,total);
        write(fd[1],buf,strlen(buf));
        
        sleep(1);
    }
    printf("Child Total : %d\n",total);
}

void myProc()
{
    int state;
    int i=0;
    char buf[1024];
    //wait(&state);
    
    while(1)
    {
        i++;
        sleep(1);
        
        int n;
        
        memset(buf,0,1024);
        
        n=read(fd[0],buf,1024);
        
        printf("Parent : %d   p : %s\n",i,buf);
    }
    
    printf("End Main\n");
}

void Maintest5()
{
    int pid;
    
    pipe(fd);
    
    printf("Start Main\n");
    
    pid=fork();
    
    if(0==pid)
    {
        childProc();
        exit(0);
    }
    else
    {
        myProc();
    }
}

////////////////////////////////////////////

void chProc()
{
    close(fd[0]);
    
    dup2(fd[1],1);  //1->STDOUT
    
    close(fd[1]);
    
    printf("Hello pipe\n");
    
    printf("Good bye child\n");
}

void paProc()
{
    close(fd[1]);
    
    printf("From Child\n");
    
    char buf[512];
    
    while(1)
    {
        if(0<read(fd[0],buf,512))
        {
            write(STDOUT_FILENO,buf,strlen(buf));  
        }
        else
        {
            break;
        }
    }
    
    printf("End Main\n");
}


///////////////////////////////////////////////////
int main(int argc, char** argv) {
    
    int pid;
    
    pipe(fd);
    
    printf("Main Start\n");
    
    pid=fork();
    
    if(0==pid)
    {
        chProc();
    }
    else
    {
        paProc();
    }
    
    return (EXIT_SUCCESS);
}

