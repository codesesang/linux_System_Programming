/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   member.h
 * Author: hisecure
 *
 * Created on 2016년 3월 29일 (화), 오후 6:38
 */

#ifndef MEMBER_H
#define MEMBER_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct S_M
    {
        char name[20];
        int kor;
        int eng;
        int math;
        int total;
        float avg;
        
        int flag;  //-1->Not Use 1->Use
    }S_MEMBER;
    
    
    int AddMember(char* name,int kor,int eng,int math);
    int ShowMember();
    int LoadMember(char* filename);
    int SaveMember(char* filename);
    int IniMember();
    void BestMember();

#ifdef __cplusplus
}
#endif

#endif /* MEMBER_H */

