/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 3월 22일 (화), 오후 7:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int fd;
    int fd1;
    
    fd=creat("my1.txt",0600);
    
    if(-1==fd)
    {
        printf("file create error\n");
        return -1;
    }
    
    write(fd,"1234",4);
    
    fd1=dup(fd);
    
    write(fd1,"abcd",4);
    
    write(fd,"5678",4);
    
        
    close(fd);
    close(fd1);
    
    return (EXIT_SUCCESS);
}

#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int fd1;
    
    fd=creat("my2.txt",0600);
    
    write(fd,"1234",4);
    
    fd1=dup(fd);
    
    write(fd1,"abcd",4);
    write(fd,"5678",4);
    
    close(fd);
    close(fd1);
    
    return 0;
}