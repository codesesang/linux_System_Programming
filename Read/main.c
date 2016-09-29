/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 3월 15일 (화), 오후 8:13
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/*
 * 
 */
int main(int argc, char** argv) {
    
    int size;
    int total=0;
    int fd;
    char filename[]="main.c";
    char buf[512];
    
    if(-1==(fd=open(filename,O_RDWR)))
    {
        printf("file open error");
        return -1;
    }
    
    while(1)
    {
        size=read(fd,buf,512);
        
        if(size<=0)
            break;
        
        total+=size;
    }
    
    printf("file size : %d\n",total);
    
    close(fd);

    
    return (EXIT_SUCCESS);
}