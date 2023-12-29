#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct date date;
struct date {
    int annee;
    int mois;
    int jour;
};

typedef struct Voyageur Voyageur;
struct Voyageur {
    int idVoyageur;
    char nom[50];
    char prenom[50];
};
typedef struct liste_voyageur liste_voyageur;
struct liste_voyageur {
    struct Voyageur Voyageur;
    struct liste_voyageur* suiv;
};

typedef struct Bus Bus;
struct Bus {
    int numero;
    int capacite;
    char destination[100];
    int placesDisponibles;
    liste_voyageur* listeVoyageurs;
};
typedef struct liste_bus liste_bus;
struct liste_bus {
    struct Bus Bus;
    struct liste_bus* suiv;
};

typedef struct Reservation Reservation;
struct Reservation {
    int idReservation;
    liste_voyageur* listeVoyageurs;
    liste_bus* listebus;
    date date;
};
typedef struct liste_reservation liste_reservation;
struct liste_reservation {
    struct Reservation Reservation;
    struct liste_reservation* suiv;
};

void afficher_tous_Bus(liste_bus* lb) {
    liste_bus* aux = lb;
    aux = (liste_bus*)malloc(sizeof(struct liste_bus));
    printf("\n -----Liste des bus : -----\n");
    if(!aux){
        printf("Liste vide! \n");
    }
    else {
    while (aux) {
        printf("Numero Bus : %d, Capacité : %d, Destination : %s, nombre de places disponibles :%d \n", aux->Bus.numero, aux->Bus.capacite, aux->Bus.destination, aux->Bus.placesDisponibles);

        liste_voyageur* courantVoyageur = aux->Bus.listeVoyageurs;
        courantVoyageur = (liste_voyageur*)malloc(sizeof(struct liste_voyageur));
        if(!courantVoyageur)printf("Bus Vide! \n");
        else {
        while (courantVoyageur) {
            printf("les voyageurs de ce bus sont  : %d %s %s\n", courantVoyageur->Voyageur.idVoyageur, courantVoyageur->Voyageur.nom, courantVoyageur->Voyageur.prenom);
            courantVoyageur = courantVoyageur->suiv;
        }
        free(courantVoyageur);
        }
        aux = aux->suiv;
    }
    free(aux);
    }
}



void afficher_tous_Voyageurs(liste_voyageur* lv ) {
   liste_voyageur* aux=lv ;
   aux = (liste_voyageur*)malloc(sizeof(struct liste_voyageur));
    printf("\n -----Liste des voyageurs : -----\n");

    while (aux) {
        printf("ID Voyageur : %d, Nom : %s, Prenom : %s\n", aux->Voyageur.idVoyageur, aux->Voyageur.nom, aux->Voyageur.prenom);
        aux = aux->suiv;
    }
    free(aux);
}
void afficher_toutes_Reservations(liste_reservation* lr) {
    liste_reservation* aux=lr;
    aux = (liste_reservation*)malloc(sizeof(struct liste_reservation));
    printf("\n -----Liste des reservations : -----\n");
    if(!aux)printf("Liste de reservations vide!\n");
    else {
    while (aux){

   printf("ID Reservation: %d, jour: %d, mois: %d, annee: %d\n", aux->Reservation.idReservation, aux->Reservation.date.jour, aux->Reservation.date.mois, aux->Reservation.date.annee);
    liste_voyageur* courantVoyageur = aux->Reservation.listeVoyageurs;
    courantVoyageur = (liste_voyageur*)malloc(sizeof(struct liste_voyageur));
    if(!courantVoyageur)printf("Liste Voyageurs Vide!\n");
    else {
    while (courantVoyageur) {
        printf("les voyageurs qui appartiennent à cette reservation sont  : %d %s %s\n", courantVoyageur->Voyageur.idVoyageur, courantVoyageur->Voyageur.nom, courantVoyageur->Voyageur.prenom);
        courantVoyageur = courantVoyageur->suiv;
    }
    free(courantVoyageur);
    }
     liste_bus *courantBus = aux->Reservation.listebus;
     courantBus = (liste_bus*)malloc(sizeof(struct liste_bus));
     if(!courantBus)printf("Liste Bus Vide!\n");
     else {
    while (courantBus) {
        printf("les bus qui appartiennent a cette reservation sont  : %d %d %s\n", courantBus->Bus.numero, courantBus->Bus.capacite, courantBus->Bus.destination);
        courantBus = courantBus->suiv;
    }
    free(courantBus);
     }
       aux= aux->suiv;

    }
    free(aux);
    }
    }


void afficherDetailsBus(liste_bus* lb,int numero) {
    liste_bus* courant = lb;
    courant = (liste_bus*)malloc(sizeof(struct liste_bus));
    liste_bus* precedent = NULL;

    while (courant && courant->Bus.numero != numero) {
        precedent = courant;
        courant = courant->suiv;
    }
    printf("\nDetails du bus %d sont :\n", courant->Bus.numero);
    printf("Destination : %s\n", courant->Bus.destination);
    printf("Capacite : %d\n", courant->Bus.capacite);
    printf("Places disponibles : %d\n", courant->Bus.placesDisponibles);

    liste_voyageur *courantVoyageur = courant->Bus.listeVoyageurs;
    if(!courantVoyageur)printf("Liste Voyageurs Vide!\n");
    else {
    while (courantVoyageur) {
        printf("les voyageurs de ce bus sont : %s %s\n", courantVoyageur->Voyageur.nom, courantVoyageur->Voyageur.prenom);
        courantVoyageur = courantVoyageur->suiv;
    }
    }
    free(courant);
}
void afficherDetailsReservation(liste_reservation* lr, int idReservation) {
    liste_reservation* courant = lr;
    courant = (liste_reservation*)malloc(sizeof(struct liste_reservation));
    liste_reservation* precedent = NULL;

    while (courant && courant->Reservation.idReservation != idReservation) {
        precedent = courant;
        courant = courant->suiv;
    }

    printf("les details de la Reservation d id  : %d,date:,jour , mois,annee   :%d%d%d, sont\n", courant->Reservation.idReservation, courant->Reservation.date.jour,courant->Reservation.date.mois,courant->Reservation.date.annee);


     liste_voyageur *courantVoyageur = courant->Reservation.listeVoyageurs;
    while (courantVoyageur) {
        printf("les voyageurs qui appartiennent  à cette reservation sont  : %d %s %s\n", courantVoyageur->Voyageur.idVoyageur, courantVoyageur->Voyageur.nom, courantVoyageur->Voyageur.prenom);
        courantVoyageur = courantVoyageur->suiv;
    }
     liste_bus *courantBus = courant->Reservation.listebus;
    while (courantBus) {
        printf("les bus qui appartiennent a cette reservation sont  : %d %d %s\n", courantBus->Bus.numero, courantBus->Bus.capacite, courantBus->Bus.destination);
        courantBus = courantBus->suiv;
    }
    free(courant);
}
void afficherDetailsvoyageur(liste_voyageur* lv ,int idVoyageur) {
    liste_voyageur* courant = lv;
    courant = (liste_voyageur*)malloc(sizeof(struct liste_voyageur));
    liste_voyageur* precedent = NULL;
     while (courant && courant->Voyageur.idVoyageur != idVoyageur) {
        precedent = courant;
        courant = courant->suiv;
    }
     printf("le voyageur d ' idVoyageur : %d,est, Nom : %s, Prenom : %s\n", courant->Voyageur.idVoyageur, courant->Voyageur.nom, courant->Voyageur.prenom);
     free(courant);
}


void ajouter_Voyageur(liste_voyageur* lv)
{
   liste_voyageur* aux=lv;
   aux = (liste_voyageur*) malloc (sizeof(liste_voyageur*));
   liste_voyageur* nouveau;
   nouveau = (liste_voyageur*) malloc (sizeof(liste_voyageur*));

    printf("ID du voyageur : ");
    scanf("%d",&nouveau->Voyageur.idVoyageur);

    printf("Nom du voyageur : ");
    scanf("%s",&nouveau->Voyageur.nom);

    printf("Prenom du voyageur : ");
    scanf("%s",&nouveau->Voyageur.prenom);

    nouveau->suiv = NULL;

    while (aux->suiv)
    {
        aux = aux->suiv;
    }
    aux->suiv=nouveau;
    free(aux);
    free(nouveau);
}

void ajouter_Bus(liste_bus* lb,int numero, char destination[50], int capacite)
{    liste_bus* aux=lb ;
    aux = (liste_bus*) malloc (sizeof(liste_bus*));
     liste_bus* nouveauBus;
    nouveauBus = (liste_bus*)malloc(sizeof(liste_bus));
    nouveauBus->Bus.numero = numero;
    strncpy(nouveauBus->Bus.destination, destination, sizeof(nouveauBus->Bus.destination));
    nouveauBus->Bus.capacite = capacite;
    nouveauBus->Bus.placesDisponibles = capacite;
    nouveauBus->Bus.listeVoyageurs = NULL;
    nouveauBus->suiv = NULL;
     while (aux->suiv)
    {
        aux = aux->suiv;
    }
    aux->suiv=nouveauBus;
    free(aux);
    free(nouveauBus);

}
void creer_nouvelle_reservation(liste_reservation* lr, int idReservation, struct date date)
{
    liste_reservation* aux = lr;
    aux = (liste_reservation*) malloc (sizeof(liste_reservation*));
    liste_reservation* nouvelleReservation;
    nouvelleReservation = (liste_reservation *)malloc(sizeof(liste_reservation));

    nouvelleReservation->Reservation.idReservation = idReservation;
    nouvelleReservation->Reservation.date = date;
    nouvelleReservation->Reservation.listeVoyageurs = NULL;
    nouvelleReservation->Reservation.listebus = NULL;
    nouvelleReservation->suiv = NULL;

    while (aux->suiv)
    {
        aux = aux->suiv;
    }
    aux->suiv = nouvelleReservation;
    free(aux);
    free(nouvelleReservation);
}

void libererMemoireReservation(liste_reservation* reservation) {
    liste_voyageur* courantVoyageur = reservation->Reservation.listeVoyageurs;
    courantVoyageur = (liste_voyageur*) malloc (sizeof(liste_voyageur*));
    liste_voyageur* tempVoyageur ;
    while (courantVoyageur) {
        tempVoyageur = courantVoyageur;
        courantVoyageur = courantVoyageur->suiv;
        free(tempVoyageur);
    }
    free(courantVoyageur);
    free(reservation);
}
void supprimerReservation(liste_reservation* lr, int idReservation) {
    liste_reservation* courant = lr;
    courant = (liste_reservation*) malloc (sizeof(liste_reservation*));
    liste_reservation* precedent = NULL;

    while (courant && courant->Reservation.idReservation != idReservation) {
        precedent = courant;
        courant = courant->suiv;
    }

    if (courant) {
        if (precedent)
         {
            precedent->suiv = courant->suiv;
        }
        else
        {
            lr = courant->suiv;
        }

        libererMemoireReservation(courant);
    }
}
void modifierReservation(liste_reservation* lr, int idReservation , struct date datemodif ) {

    liste_reservation* courant = lr ;
    courant = (liste_reservation*) malloc (sizeof(liste_reservation*));
    liste_reservation* precedent = NULL;

    while (courant && courant->Reservation.idReservation != idReservation) {
        precedent = courant;
        courant = courant->suiv;
    }
    printf("veuillez saisir la nouvelle date");
    scanf("%d",datemodif.jour,"%d",datemodif.mois,"%d",datemodif.annee);
    courant->Reservation.date.jour=datemodif.jour;
    courant->Reservation.date.mois=datemodif.mois;
    courant->Reservation.date.annee=datemodif.annee;

    free(courant);
    }


int verifierDisponibilitePlaces(liste_bus* lb, int idBus) {
   liste_bus* courantBus=lb ;
   courantBus = (liste_bus*) malloc (sizeof(liste_bus*));
    while (courantBus) {
        if (courantBus->Bus.numero == idBus) {
            return courantBus->Bus.placesDisponibles;
        }
        courantBus = courantBus->suiv;
    }
    free(courantBus);
    return -1;
}

bool rechercherReservationParID(liste_reservation* lr, int idReservation) {
   liste_reservation* courant=lr;
   courant = (liste_reservation*) malloc (sizeof(liste_reservation*));
    while (courant) {
        if (courant->Reservation.idReservation == idReservation) {
            free(courant);
            return true;
        }
        courant = courant->suiv;
    }
    free(courant);
    return false;
}
bool rechercherVoyageurParID(liste_voyageur* lv, int idvoyageur) {
    liste_voyageur* courant = lv;
    courant = (liste_voyageur*) malloc (sizeof(liste_voyageur*));
    while (courant) {
        if (courant->Voyageur.idVoyageur == idvoyageur) {
            free(courant);
            return true;
        }
        courant = courant->suiv;
    }
    free(courant);
    return false;
}
bool rechercherbus(liste_bus* lb, int numero) {
    liste_bus* courant = lb;
    courant = (liste_bus*) malloc (sizeof(liste_bus*));
    while (courant) {
        if (courant->Bus.numero == numero) {
            free(courant);
            return true;
        }
        courant = courant->suiv;
    }
    free(courant);
    return false;
}


int login(char username[25], char passwords[25]) {
    if (strcmp(username, "admin") == 0 && strcmp(passwords, "2001009") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int i = 0, count = 0;
    int r;
    char username[25], passwords[25];
    int n;
    liste_voyageur* lv;
    lv = (liste_voyageur*)malloc(sizeof(struct liste_voyageur));
    lv->suiv = NULL;

    liste_bus* lb;
    lb = (liste_bus*)malloc(sizeof(struct liste_bus));
    lb->suiv = NULL;

    liste_reservation* lr;
    lr = (liste_reservation*)malloc(sizeof(struct liste_reservation));
    lr->suiv = NULL;

    printf("\t\t\t\t   ==============================================\n\t\t\t\t    WELCOME TO THE E-Bus-Travel \n\t\t\t\t   ==============================================");
    printf("\t\t\t\t\t\t                                                      \n\t\t\t\tTO ACCESS THE SYSTEM, PLEASE YOU NEED TO LOGIN FIRST \n\t\t\t\t   ==============================================");
    printf("\t\t\t\t\n");

    do {
        printf("\t\t\t\t\t   Enter Your Username:");
        fgets(username, 25, stdin);
        strtok(username, "\n");  // Remove newline
        printf("\n\t\t\t\t\t   Enter Your Password:");
        fgets(passwords, 25, stdin);
        strtok(passwords, "\n");  // Remove newline
        r = login(username, passwords);
        system("cls");
        count++;
        if (r == 1) {
            printf("\t\t\t\t\t\t\t                                   ==============================================\n\t\t\t\t\t\t#ACCESS GRANTED#\n\n\n");
            break;
        } else {
            printf("\n\n\t\t\t   WRONG USERNAME/PASSWORD----------------ACCESS DENIED, TRY AGAIN \n\n\n\n");
        }

    } while (count != 3);

    if (count == 3) {
        printf("\n\n/////ALL LOGIN ATTEMPTS FAILED.....PLEASE RESTART THE PROGRAM/////");
        return 0;
    }

    do {
        printf("(1) creer une nouveau compte voyageur \n(2) ajouter un bus\n(3) creer une nouvelle reservation\n(4) afficher la liste des voyageur\n(5)  afficher la liste des bus\n(6)  afficher la liste des reservations \n(7) afficher le voyageur d'id:\n(8)afficher le bus numero':\n(9)afficher la reservation d'id:\n(10)supprimer une reservation \n(11)modifier une reservation\n(12)verifier les places disponibles dans un bus\n");
        printf("saisir un autre nombre pour quitter\n");
        scanf("%d", &n);
        system("cls");
        switch (n) {
            case 1:
            {
              ajouter_Voyageur(lv) ;

                printf("le voyageur est ajoute a la liste \n");
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);

                break;
            }
            case 2 : {
                int num,cap;
                char desti[50];
                printf("saisir le numero du bus \n");
                scanf("%d",&num);
                printf("saisir la capacite du bus \n");
                scanf("%d",&cap);
                printf("saisir la destination du bus \n");
                scanf("%s",&desti);
                strcat(desti,"\0");
                ajouter_Bus(lb,num,desti,cap );
                printf("le bus est ajoute a la liste \n");
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
            }
            case 3:
              {
                struct date dateajout ;
                struct Reservation aux ;
                int idreservation;
                int a1=0;
                int m1=0;
                int j1=0;
                printf("donner le jour d'ajout\n");
                scanf("%d",&j1);
                printf("donner le mois d'ajout\n");
                scanf("%d",&m1);
                printf("donner l'annee d'ajout\n");
                scanf("%d",&a1);
                dateajout.annee=a1;
                dateajout.mois=m1;
                dateajout.jour=j1;
                printf("donner l id de la reservation");
                scanf("%d",idreservation);
                aux.idReservation=idreservation;
                creer_nouvelle_reservation (lr,idreservation,dateajout)  ;
                 printf("la reservation est ajoutée la liste \n");
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
              }
              case 4:
              {
                printf("voici la liste de tous les voyageurs \n");
                afficher_tous_Voyageurs(lv) ;
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
              }
              case 5:
              {
                printf("voici la liste de tous les bus\n");
                afficher_tous_Bus(lb) ;
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
              }
              case 6:
              {
                printf("voici la liste de toutes les reservations \n");
                afficher_toutes_Reservations(lr);
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
              }
              case 7:
              {
                struct Voyageur voyag;
                bool fl;
                int idvoy;
                printf("donner l id du voyageur que vous souhaitez afficher ces coordonnées");
                scanf("%d",idvoy);
                fl=rechercherVoyageurParID(lv,idvoy);
                if (fl==true)
                {
                voyag.idVoyageur=idvoy;
               afficherDetailsvoyageur(lv,idvoy);
                }
                else
                 { printf("le voyageur est inexistant ");
                }
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
              }
              case 8:
               {
                struct Bus buses;
                bool bl;
                int numero;
                printf("donner le numero du bus que vous souhaitez afficher ces données");
                scanf("%d",numero);
                bl=rechercherbus(lb,numero);
                if (bl==true)
                {
                buses.numero=numero;
              afficherDetailsBus(lb,numero);
                }
                else
                 { printf("le bus est inexistant ");
                }
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
              }
              case 9:
               {
                struct Reservation res;
                bool tr;
                int idreserv;
                printf("donner l id de la reservation que vous souhaitez afficher ces données");
                scanf("%d",idreserv);
                tr=rechercherReservationParID(lr, idreserv);
                if (tr==true)
                {
                res.idReservation=idreserv;
                afficherDetailsReservation(lr,idreserv);
                }
                else
                 { printf("la reservation est inexistante ");
                }

                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
              }
              case 10:
              {
                struct Reservation reservation;
                int idres;
                bool tr1 ;
                printf("donner l id de la reservation que vous souhaitez supprimer");
                scanf("%d",idres);
                tr1=rechercherReservationParID(lr, idres);
                if (tr1==true)
                {
                reservation.idReservation=idres;
                supprimerReservation(lr,idres);
                }
                else
                 { printf("la reservation est inexistante ");
                }
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;

              }
              case 11:
              { struct date datemodif;
                struct Reservation reservation;
                int idres ;
                bool tr2 ;
                printf("donner l id de la reservation que vous souhaitez supprimer");
                scanf("%d",idres);
                tr2=rechercherReservationParID(lr, idres);
                if (tr2==true)
                {
                reservation.idReservation=idres;
                modifierReservation( lr,idres,datemodif);
                }
                else
                 { printf("la reservation est inexistante ");
                }
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;

              }
              case 12 :
              {int a,idb;
              printf("saisir l id du bus ");
              scanf("%d,idb");


            a=verifierDisponibilitePlaces(lr,idb);
                if (a != -1)
                 {
                  printf("Il y a %d places disponibles dans le bus %d.\n",a, idb);

                 }
                 else
                  {
                    printf("Le bus avec l'ID %d n'a pas été trouvé.\n", idb);
                   }
                printf("appuyez sur un autre button pour revenir a la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
        }
}
    } while (n > 0 && n < 13);

    // Free allocated memory before exiting
    free(lv);
    free(lr);
    free(lb);

    return 0;
}
