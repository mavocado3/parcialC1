#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define MAX_USUARIOS 10
#define MAX_COMMENTS 5
int main()
{
    int init;
    eUsuarios usuarios[MAX_USUARIOS];

    char opcion;
    int indice;
    int resultEmpty;
    int i,j;

    init = initArray(usuarios, MAX_USUARIOS);
    if(init != 0)
    {
        printf("Hubo un error");
    }

    do
    {
        opcion = mostrarMenu("1-ALTA\n2-MODIFICAR\n3-BAJA\n4-NUEVO COMENTARIO5\n5-NUEVO ME GUSTA\n6-INFORMAR\n7-LISTAR\n8-SALIR\n",'1', '8');
        system("cls");
        switch(opcion)
        {
            case '1':
                indice = obtenerEspacioLibre(usuarios, MAX_USUARIOS);
                if(indice != -1)
                {
                    agregarUsuario(usuarios, MAX_USUARIOS, indice, MAX_COMMENTS );
                }
                else
                {
                    printf("No hay mas lugar\n");
                }
                printf("Nombre: %s\nNick: %s\nClave: %s\nEmail: %s\nisEmpty: %d\n", usuarios[indice].nombre,usuarios[indice].nick,usuarios[indice].claveAcceso,usuarios[indice].email, usuarios[indice].isEmpty);
                for(i=0;i<MAX_COMMENTS;i++)
                {
                    printf("isEmpty: %d\n",usuarios[indice].misComentarios[i].isEmpty);
                }
                system("pause");
                system("cls");
                break;
            case '2':
                resultEmpty = isEmpty(usuarios, MAX_USUARIOS);
                if(resultEmpty == 0)
                {
                    modificar(usuarios, MAX_USUARIOS);
                }
                else
                {
                    printf("Esta vacio");
                }
                system("pause");
                system("cls");
                break;
            case '3':
                resultEmpty = isEmpty(usuarios, MAX_USUARIOS);
                if(resultEmpty == 0)
                {
                    borrar(usuarios, MAX_USUARIOS);
                }
                else
                {
                    printf("Esta vacio");
                }
                system("pause");
                system("cls");
                break;
            case '4':
                resultEmpty = isEmpty(usuarios, MAX_USUARIOS);
                if(resultEmpty == 0)
                {
                    agregarComentario(usuarios,MAX_USUARIOS, MAX_COMMENTS);
                    /*for(i=0;i<MAX_USUARIOS; i++)
                    {
                        for(j=0;j<MAX_COMMENTS;j++)
                        {
                            if(usuarios[i].isEmpty == 0 && usuarios[i].misComentarios[j].isEmpty == 0)
                            {
                                printf("\nnick: %s\nidcomentario: %d\nme gusta: %d\ncomentario:\n\t%s\n", usuarios[i].nick, usuarios[i].misComentarios[j].idComentario, usuarios[i].misComentarios[j].meGusta, usuarios[i].misComentarios[j].texto);
                            }
                        }
                    }*/
                }
                else
                {
                    printf("Esta vacio");
                }
                system("pause");
                system("cls");
                break;
            case '5':
                resultEmpty = isEmpty(usuarios, MAX_USUARIOS);
                if(resultEmpty == 0)
                {
                    printf("ALGO TIEnE");
                }
                else
                {
                    printf("Esta vacio");
                }
                system("pause");
                system("cls");
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
        }
    }while(opcion!='8');


    return 0;
}
