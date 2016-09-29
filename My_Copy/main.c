/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 3월 22일 (화), 오후 6:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


/*
 * 
 */
int main(int argc, char** argv) {

    int sfd;
    int dfd;
    int size;
    char buf[512];
    
    sfd=open("main.c",O_RDONLY); // O_RDONLY -> read
    
    if(-1==sfd)
    {
        printf("File Open Error_1\n");
        return -1;
    }
    
    dfd=open("main_1.c",O_WRONLY|O_CREAT|O_TRUNC,0644); // O_WRONLY -> write only O_CREAT -> no exist, do create O_TRUNC -> no exist, do reset
    
    if(-1==dfd)
    {
        printf("File Open Error_2\n");
        return -1;
    }
    
    while(1)
    {
        size=read(sfd,buf,512);
        
        if(size<=0)
            break;
        
        write(dfd,buf,size);
    }
    
    close(dfd);
    close(sfd);
    
    
    return (EXIT_SUCCESS);
}