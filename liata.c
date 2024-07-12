#include <stdio.h>
#include <stdlib.h>
///prototypes

void fichierOuvert(FILE **fic,char *fichier);
int compte (FILE *fic,char* chaine,int n);
int change (char *arg);
void affichage(FILE *fic,int L,char *chaine);
int changer (char *arg)	;
void tous ( FILE *fic, char *chaine) ;

//#include "liata.h"

int main(int argc,char *argv[])   	  /// parametre de l'argument dans le commande (argc et argv)
{
	FILE *fic=NULL;					  ///pointeur du fichier qu'on va ouvrir
	char chaine[100];
	int L,n;
	int z;

									 ///appel au fonction

fichierOuvert(&fic,argv[3]);
n=change(argv[2]);
L=compte(fic,chaine,n);
fichierOuvert(&fic,argv[3]);
affichage(fic,L,chaine);
z=changer (argv[2])	;
tous (fic,chaine) ;
	
	return 0;
}

void fichierOuvert(FILE **fic,char *fichier)
{
	*fic=fopen(fichier,"r");
			if (*fic==NULL){
				printf ("Erreur:::\ncommande introuvable!!\n");
				exit (1);
	}
}

int compte (FILE *fic,char* chaine,int n)
{ 
	int L=1;
		while(feof(fic)!=1){
			fgets(chaine,100,fic);
				L++;
			}
				L=L-n;
				fclose(fic);
	
	return L;
}

int change (char *arg)	 ///fonction pour les changements de type char en type int
	{
		int n;
			n=atoi(arg);
	
	return n;
}

void affichage(FILE *fic,int L,char *chaine) ///fonction pour l'affichage des lignes commandees par l'utilisateur (comme dans la commande tail)
	{
		int tail=1;
			while (feof(fic)!=1)
			{
				fgets(chaine,100,fic);
					tail++;
						if (tail>=L){
						printf("%s",chaine);
			}
		}
		fclose(fic);
}

int changer (char *arg)	
	{
		int z;
			z=atoi(arg);	
	return z;
}

void tous ( FILE *fic, char *chaine) 
{
			while (fgets(chaine,100,fic)!=0)
			{
					printf("%s\n",chaine);
			
		feof(fic) ;
			}	
		fclose(fic);
		}

