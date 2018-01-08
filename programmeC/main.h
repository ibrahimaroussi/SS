#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

void verifyArgs(char * tab[]);
int IsValidIp(char* szIP);
void generateTab(int taille, char * ip, char ** newTab);
void afficherTab(char ** tab,int taille);

#endif // MAIN_H_INCLUDED
