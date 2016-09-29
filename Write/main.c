/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 3월 15일 (화), 오후 9:04
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/*
 * 
 */
int main(int argc, char** argv) {

    char src[]="main.c";
    char dst[]="main_1.c";
    char buf[512];
    int size;
    int fd_src;
    int fd_dst;
    
    fd_src=open(src,O_RDONLY);
    fd_dst=open(dst,O_WRONLY|O_CREAT|O_TRUNC,0644);
    
    while(1)
    {
        size=read(fd_src,buf,512);
        
        if(size<=0)
            break;
        write(fd_dst,buf,size);
    }
    
    close(fd_dst);
    close(fd_src);
    
    return (EXIT_SUCCESS);
}