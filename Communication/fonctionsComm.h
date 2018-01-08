/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fonctions.h
 *
 * Created on 9 janvier 2018, 00:20
 */

#ifndef FONCTIONS_H
#define FONCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

int envoi( struct hostent *serveur_host,char *msg,char *ip_serveur,int port);
int reception(struct hostent *host_client,int port,int timeout);


#ifdef __cplusplus
}
#endif

#endif /* FONCTIONS_H */

