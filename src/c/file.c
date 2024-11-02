#include<stdio.h>
#include<stdlib.h>
int copyfile(const char* inputfile,const char* outputfile)
{
    FILE *fp1,*fp2;
    char c;
    if((fp1 = fopen(inputfile,"rb")) == NULL)
    return -1;
    if((fp2 = fopen(outputfile,"wb")) == NULL)
    return -1;
    c = fgetc(fp1);
    while(!feof(fp1))
    {
        fputc(c,fp2);
        c = fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
    return 1;
}
int main()
{
    char *inputfile,*outputfile;
    if(copyfile(inputfile,outputfile) == -1)
    printf("copy file unsuccess!\n");
    else 
    printf("copy file success!\n");
    return 0;
}