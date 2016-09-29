/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hisecure
 *
 * Created on 2016년 3월 22일 (화), 오후 7:33
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
    
    fd=creat("1.txt",0600);
    
    if(-1==fd)
    {
        printf("File Create Error\n");
        return -1;
    }
    
    write(fd,"1234567890",10);
    
    lseek(fd,3,SEEK_SET);
    
    write(fd,"a",1);
    
    lseek(fd,-3,SEEK_END);
    
    write(fd,"b",1);
    
    close(fd);
    
    return (EXIT_SUCCESS);
}
