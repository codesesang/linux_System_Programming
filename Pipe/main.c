/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 5월 31일 (화), 오후 7:08
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int fd[2];

void parent()
{
    char buf[1024];
    
    memset(buf,0,1024);
    ///////////////////////////////    OK READ
    read(fd[0],buf,1024);
    ///////////////////////////////
    
    printf("%s\n",buf);
    
    //memset(buf,0,1024);
//    strcpy(buf,"haha");
    
//    write(fd[1],buf,strlen(buf));

}

void child()
{
    char buf[1024];
    
    memset(buf,0,1024);
    strcpy(buf,"OK");
    
    ////////////////////////////// OK WRITE
    write(fd[1],buf,strlen(buf));
    ////////////////////////////////
    
    //memset(buf,0,1024);
//    read(fd[0],buf,1024);
    
//    printf("%s\n",buf);
}

int main(int argc, char** argv) {

    int pid;
    
    pipe(fd);
    
    printf("Main Start\n");
    
    pid=fork();
    
    if(0==pid)
    {
        child();
        exit(1);
    }
    else
    {
        parent();
    }
    
    return (EXIT_SUCCESS);
}

