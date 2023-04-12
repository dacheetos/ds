#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printUnion(char arr1[][15],char arr2[][15],int m,int n)
{
    FILE *f3;
    f3=fopen("C:/Users/sahil/Desktop/third.txt","w");
    if(f3==NULL){
        printf("File opening error");
        exit(1);
    }
    int i=0,j=0;
    while (i<m && j<n)
    {
        if(strcmp(arr1[i],arr2[j])<0){
            printf("\n%s",arr1[i]);
            fprintf(f3,"\n%s",arr1[i++]);
        }
        else if(strcmp(arr2[j],arr1[i])<0){
            printf("\n%s",arr2[j]);
            fprintf(f3,"\n%s",arr1[j++]);
        }else{
            printf("\n%s",arr2[j]);
            fprintf(f3,"\n%s",arr2[j++]);
            i++;
        }
    }
    while (i<m)
    {
        printf("\n%s",arr1[i]);
        fprintf(f3,"\n%s",arr1[i++]);
    }
    while (j<n)
    {
        printf("\n%s",arr2[j]);
        fprintf(f3,"\n%s",arr2[j++]);
    } 
}
void printIntersection(char arr1[][15],char arr2[][15],int m,int n){
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<m;j++){
            if(strcmp(arr1[i],arr2[j])==0)
            {
                printf("\n%s",arr1[i]);
            }
        }
    }
}
int main()
{
    FILE *f1,*f2;
    char one[15][15],two[15][15];
    int m=0,n=0;
    f1=fopen("C:/Users/sahil/Desktop/first.txt","r");
    f2=fopen("C:/Users/sahil/Desktop/second.txt","r");
    printf("File 1\n");
    while(!feof(f1)){
        fscanf(f1,"%s",one[m++]);
        puts(one[m-1]);
    }
    printf("File 2\n");
    while(!feof(f2)){
        fscanf(f2,"%s",two[n++]);
        puts(two[n-1]);
    }
    printf("UNIQUE USN FROM BOTH FILES\n");
    printUnion(one,two,m,n);
    printf("\nCOMMON USN FROM BOTH FILES\n");
    printIntersection(one,two,m,n);
    fclose(f1);
    fclose(f2);
    return 0;
}