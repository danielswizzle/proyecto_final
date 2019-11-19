//Contreras Álvarez Rodrigo Daniel
//Grupo 35
//Fundamentos de programación

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esAcuif();

int esAcuifSed();

int main (){
    
    FILE *archivo = NULL;
    char a;
    char roca[50];
    int b;
    char r[3][20]={"Roca ignea","Roca sedimentaria","Roca metamorfica"};
    printf("\t\tAcuíferos\n");
    
    do{
    printf("\nSelecciona un tipo de roca:\n\n");
    printf("a) %s\n",r[0]);
    printf("b) %s\n",r[1]);
    printf("c) %s\n",r[2]);
    printf("Dame tu opción: ");
    setbuf(stdin,NULL);
    scanf("%c",&a);
    
    switch(a){
        case'a':
            printf("\n%s\n",r[0]);
            printf ("Nombre de la roca: ");
            setbuf (stdin, NULL);
            scanf ("%s", roca);
            archivo = fopen ("Coleccion.txt", "w");
            if (esAcuif() == 0){
                printf ("La roca %s permite la creacion de un acuifero", roca);
                fprintf (archivo, "%s\tIgnea\tAcuifero\n", roca);
            }
            else{
                printf ("La roca %s actua como acuitardo", roca);
                fprintf (archivo, "%s\tIgnea\tAcuitardo\n", roca);
            }
            break;
        case'b':
            printf("\n%s\n",r[1]);
            printf ("Nombre de la roca: ");
            setbuf (stdin, NULL);
            scanf ("%s", roca);
            if(esAcuifSed()==0){
                printf("La roca %s permite la creacion de un acuifero", roca);
                fprintf (archivo, "%s\tSedimentaria\tAcuifero\n", roca);
            }
            else{
                printf("La roca %s actua como acuitardo", roca);
                fprintf (archivo, "%s\tSedimentaria\tAcuitardo\n", roca);
            }
            break;
        case'c':
            printf("\n%s\n",r[2]);
            printf ("Nombre de la roca: ");
            setbuf (stdin, NULL);
            scanf ("%s", roca);
            if (esAcuif() == 0){
                printf ("La roca %s permite la creacion de un acuifero", roca);
                fprintf (archivo, "%s\tMetamorfica\tAcuifero\n", roca);
            }
            else{
                printf ("La roca %s actua como acuitardo", roca);
                fprintf (archivo, "%s\tMetamorfica\tAcuitardo\n", roca);
            }
            break;
        default:
            printf("Opcion no valida\n");
    }
        
        printf("\n\n¿Deseas continuar? (1 = Si , Cualquier otro número = No)\n");
        scanf("%d",&b);
    }while(b==1);
    fclose (archivo);
    return 0;
}

int esAcuif(){
    char opc[2];
    printf ("\n\n¿La roca presenta vesiculas y fracturas?(Si/No) ");
    setbuf (stdin, NULL);
    scanf ("%s", opc);
    if (strcmp(opc,"Si") == 0)
        return 0;
    return 1;
}

int esAcuifSed(){
    char opc[2];
    printf("\n\n¿La roca presenta una buena seleccion? (Si/No) ");
    setbuf (stdin, NULL);
    scanf ("%s", opc);
    if (strcmp(opc,"No")==0)
        return 1;
    
    printf("\n\n¿La roca esta bien consolidada? (Si/No) ");
    setbuf (stdin, NULL);
    scanf ("%s", opc);
    if (strcmp(opc,"No")==0)
        return 0;
    return 1;
        
}
