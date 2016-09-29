/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 3월 22일 (화), 오후 7:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void test1(char* src,char* dst)
{
    int size;
    int sfd;
    int dfd;
    char buf[512];
    
    sfd=open(src,O_RDONLY);
    dfd=open(dst,O_WRONLY|O_CREAT|O_TRUNC,0644);
    
    if(-1==sfd)
    {
        printf("file open error_1\n");
        return -1;
    }
    
    if(-1==dfd)
    {
        printf("file open error_2\n");
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
}

void test2()
{
    
}

/*
 * 
 */
int main(int argc, char** argv) {

    test1("main.c","my.c");
    
    return (EXIT_SUCCESS);
}
