/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fonctions.h
 * Author: macbookpro
 *
 * Created on 9 janvier 2018, 00:38
 */

#ifndef FONCTIONS_H
#define FONCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

void afficherTab(char ** tab,int taille);
int rendreMajoritaire(int t[], int N);
int OM(int m,char * leader,int val, char ** listeProc);
 void getIpAddr(char IPAddr[16]);
 void delElement(char ** tab,char * element);

#ifdef __cplusplus
}
#endif

#endif /* FONCTIONS_H */

