/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 5월 24일 (화), 오후 6:29
 */
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void alarmHandler(int id)
{
    alarm(5);
    printf("alarmHandler    id: %d\n",id);
}

void test1()
{
    int sec=0;
    
    signal(SIGALRM,alarmHandler);
    alarm(5);   //sigAlarm
    
    printf("START\n");
    
    while(1)
    {
        sleep(1);
        
        sec++;
        printf("%dsec\n",sec);
    }
    printf("END ATP\n");
}

void test2()
{
    int sec=0;
    int min=0;
    
    signal(SIGALRM,alarmHandler);
    
    alarm(5);
    
    while(1)
    {
        sec++;
        
        if(60==sec)
        {
            sec=0;
            min++;
        }
        
        sleep(1);
        printf("%02d:%02d\n",min,sec);
    
    }
}


void sigint(int id)
{
    static int i=0;
    
    printf("not use\n");
    
    i++;
    
    if(5==i)
    {
        exit(id);
    }
}

void test3()
{
    int sec=0;
    
    signal(SIGINT,sigint);
    
    while(1)
    {
        sec++;
        
        sleep(1);
        printf("%d\n",sec);
    }
}

int pid;

void myAlram(int id)
{
    printf("MYALRAM\n");
    printf("%d\n",getpid());
    kill(pid,SIGINT);
}

void myHandler(int id)
{
    printf("MYHANDLER\n");
    printf("%d\n",getpid());
}

void test4()
{
    printf("START : %d\n",getpid());
    
    signal(SIGALRM,myAlram);
    alarm(5);
    
    //signal(SIGINT,myHandler);
    
    pid=fork();
    
    if(0==pid)//child
    {
        int i=0;
        printf("START : %d\n",getpid());
        
        for(i=0;i<10;i++)
        {
            sleep(1);
            printf("%d\n",i);
        }
        
        printf("END : %d\n",getpid());
    }
    else//parent
    {
        int state;
        
        
        
        printf("Wating child : %d\n",pid);
        wait(&state);
        printf("End child : %d\n",pid);
    }
    
    printf("END : %d\n",getpid());
}

void Alarm(int id)
{
    printf("Alarm Handler\n");
    kill(pid,SIGINT);
}

void test5()
{
    printf("Main START\n");
    
    signal(SIGALRM,Alarm);
    alarm(5);
    
    pid=fork();
    int i;
    
    if(0==pid)
    {
        for(i=0;i<10;i++)
        {
            sleep(1);
            
            printf("%d\n",i);
        }
        exit(0);
    }
    else
    {
        int state;
        
        printf("Waiting child\n");
        
        wait(&state);
        printf("Main End\n");
    }
}

void test6()
{
    printf("Main START\n");
    
    int pid=fork();
    
    if(0==pid)
    {       
        sleep(5);
        kill(getppid(),SIGINT);
        printf("Child End\n");
    }
    else
    {
        int i;
        
        for(i=0;i<10;i++)
        {
            printf("%d\n",i);
            sleep(1);
        }
        
        printf("Main End\n");
    }
}

void aalarm(int id)
{
    printf("My Alarm\n");
}

void test7()
{
    printf("Main Start\n");
    
    signal(SIGTSTP,aalarm);
    
    
    int pid=fork();
    
    if(0==pid)
    {
        printf("Start Child\n");
        
        sleep(5);
        
        kill(getppid(),SIGTSTP);
        
        printf("End Child\n");
    }
    else
    {
        printf("Pause\n");
        
        pause();
        
        printf("Next Pause\n");
    }
}

void sigtstp(int id)
{
    printf("sigtstp\n");
}

void ssigint(int id)
{
    printf("sigint\n");
}

void test8()
{
    printf("Main Start\n");
    
    signal(SIGTSTP,sigtstp);
    
    pid=fork();
    
    signal(SIGINT,ssigint);
    
    if(0==pid)//child
    {
        printf("Child Start\n");
        
        pause();
                        
        int i;
        for(i=0;i<10;i++)
        {
            printf("%d\n",i);
            sleep(1);
        }
        
        kill(getppid(),SIGINT);
        
        printf("Child End\n");
        
        exit(0);
    }
    else//parent
    {
        printf("Parent Start\n");
        
        int i;
        for(i=0;i<5;i++)
        {
            printf("%d\n",i);
            sleep(1);
        }
        
        kill(pid,SIGTSTP);
        
        pause();
        
        int state;
        wait(&state);
        
        printf("Parent End\n");
    }
}

int main(int argc, char** argv) {

    test8();
    
    return (EXIT_SUCCESS);
}