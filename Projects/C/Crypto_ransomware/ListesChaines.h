#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef  struct Element {
	char path[5000];
	struct Element* Suivant;
			} Element;

void InsertElt(Element** ListElts,char Path[1000])
{

	Element* nouveau = malloc(sizeof(Element));
	Element* tete = *ListElts;
	Element* prec;
	strcpy(nouveau->path,Path);
	// nouveau->path= strdup(Path);
	nouveau->Suivant = NULL;

	if (tete == NULL ) *ListElts = nouveau ;
	else {	while (tete != NULL) {
		prec = tete;
		tete = tete->Suivant;
					}
		prec->Suivant = nouveau;

		}
				//printf("\nchemin%s\n",Path);
}

int RechercheElt(Element* ListElts , char Path[100])	{

	Element* tete = ListElts;

	while(tete != NULL)
	{
		if (!strcmp(tete->path,Path)) return 1;
		else tete = tete->Suivant;
	}
	return 0;

}


void AffichageElts(Element* ListElts) 		{

	int i=1;
	Element* tete = ListElts;

	if (tete == NULL) printf("La liste est vide .\n");
	else {
		while(tete != NULL)     {
			printf("Element %d : \nPath %s\n\n",i,tete->path);
			i++;
			tete = tete->Suivant ;
		}
	}
}

void SuppElts(Element* ListElts) {

	int i=1;
	Element* tete = ListElts;

	if (tete == NULL) printf("La liste est vide .\n");
	else {  
		while(tete != NULL) {
			remove(tete->path);
			tete = tete->Suivant ;	
		}
	}
}

/*int getType(Element* ListElts,char *Path){
Element* tete = ListElts;
		while(tete != NULL)	{
		if (!strcmp(tete->path,Nom)) return tete->Type ;
		       else tete = tete->Suivant;
					}
		return -1;
                                        }


int getNature(Element* ListElts,char *Nom){
Element* tete = ListElts;
		while(tete != NULL)	{
		if (!strcmp(tete->Nom,Nom)) return tete->Nature ;
		       else tete = tete->Suivant;
					}
		return -1;                                        }*/



