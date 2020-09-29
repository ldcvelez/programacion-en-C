#include "Archivos1.h"

int generarArchivoTXT(t_alumno *alu, const char *nombre,int ce)
{
    int i;
    FILE *fp;
    fp=fopen(nombre,"wt");

    if(fp==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

    fprintf(fp,"NOMBRE\t\tEDAD\t\tFECHA DE NACIMIENTO\n");

    for(i=0;i<ce;i++)
    {
        fprintf(fp,"%s \t %d \t\t %d/%d/%d\n",alu->apyn,alu->edad,alu->fNac);
        alu++;
    }
    return 1;
}


int generarArchivoBIN(const char *nombre1,const char *nombre2)
{
    t_alumno alu1[3]= {{1,"Juan Perez",25,25,12,1995},{8,"Maria Lopez",20,25,10,1990},{12,"Ana Florencia",19,31,01,2000}};
    t_alumno alu2[3]= {{7,"Marcelo Gomez",29,26,10,1995},{15,"Mirtha Gomez",18,23,10,1989},{20,"Ana Lucia",19,31,12,2002}};
    FILE *fp1,*fp2;

    fp1=fopen(nombre1,"wb");
    fp2=fopen(nombre2,"wb");

    if(fp1==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

     if(fp2==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

    fwrite(alu1,sizeof(alu1),1,fp1);
    fwrite(alu2,sizeof(alu2),1,fp2);
    fclose(fp1);
    fclose(fp2);
    return 1;
}


int leerArchivoBIN(const char *nombre)
{
    t_alumno alu;
    FILE *fp;
    fp=fopen(nombre,"rb");

     if(fp==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

    fread(&alu,sizeof(t_alumno),1,fp);
    puts("LEGAJO\tNOMBRE\t\tEDAD\t\tFECHA DE NACIMIENTO\n");

    while(!feof(fp))
    {
        printf("%d \t %s \t %d \t\t %d/%d/%d\n",alu.nlegajo,alu.apyn,alu.edad,alu.fNac);
        fread(&alu,sizeof(t_alumno),1,fp);
    }

    fclose(fp);
    return 1;
}

//int leerArchivoTXT(const char *nombre)
//{
//    char vec[50];
//    t_alumno alu;
//    FILE *fp;
//    fp=fopen(nombre,"rt");
//
//      if(fp==NULL)
//    {
//        printf("Error al abrir el archivo.\n");
//        return -1;
//    }
//
//    while(fgets(vec,50,fp))
//    {
//        parsear(vec,&alu);
//    }
//
//    fclose(fp);
//}

int mergeoArchivos(const char *nombrearch1,const char *nombrearch2,const char *nombrearch3)
{
    t_alumno alu1,alu2;

    FILE *fp1,*fp2,*fp3;

    fp1=fopen(nombrearch1,"rb");
    fp2=fopen(nombrearch2,"rb");
    fp3=fopen(nombrearch3,"wb");

     if(fp1==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

     if(fp2==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

     if(fp3==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

    fread(&alu1,sizeof(t_alumno),1,fp1);
    fread(&alu2,sizeof(t_alumno),1,fp2);

    while(!feof(fp1) && !feof(fp2))
    {
        if(alu1.nlegajo<alu2.nlegajo)
        {
            fwrite(&alu1,sizeof(t_alumno),1,fp3);
            fread(&alu1,sizeof(t_alumno),1,fp1);
        }

        else if(alu1.nlegajo>alu2.nlegajo)
        {
            fwrite(&alu2,sizeof(t_alumno),1,fp3);
            fread(&alu2,sizeof(t_alumno),1,fp2);
        }else
        {
            fwrite(&alu1,sizeof(t_alumno),1,fp3);
            fread(&alu1,sizeof(t_alumno),1,fp1);
            fwrite(&alu2,sizeof(t_alumno),1,fp3);
            fread(&alu2,sizeof(t_alumno),1,fp2);
        }

    }

    while(!feof(fp1))
    {
        fwrite(&alu1,sizeof(t_alumno),1,fp3);
        fread(&alu1,sizeof(t_alumno),1,fp1);
    }

      while(!feof(fp2))
    {
        fwrite(&alu2,sizeof(t_alumno),1,fp3);
        fread(&alu2,sizeof(t_alumno),1,fp2);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 1;
}

