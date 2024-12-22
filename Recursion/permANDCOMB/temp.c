#include <stdio.h>
 
int main(){
    FILE *fptr,*sptr;
    fptr= fopen("text.txt", "r+");
    sptr= fopen("src.txt", "r+");
    char str[100];
    int class;
    // gets(str);


    //string wise read write
    //get string from file (ptr, number of chars, pointer )
    // fgets(str, 100, sptr);
    //puts char array in destination
    // fputs(1000, fptr);

    // to input other than character or string 
    // fprintf(fptr, "%d", 1000);
    // fprintf(fptr, str);
    

    //get data line wise
    // while (fgets(str, 100, fptr) != NULL)
    // {

    //     printf("%s", str);
    // }
    


    //char wise read write
    char c;
    int i= 0;
    int sp= 0;
    int ln= 0;
    // while ((c = fgetc(sptr)) != EOF) {
    //     // printf("%c", c);

    //     //write characterwise
    //     if(c== ' ') sp++;
    //     if(c== '\n') ln++;
    //     fputc(c, fptr);
    //     str[i]= c;
    //     i++;
    // } 






    //input in a file in a format
    // int n =0;
    // scanf("%d", &n);


    // fprintf(fptr, "name\tclass\n");

    // while(n!= 0){
    //     scanf("%s",str);
    //     scanf("%d", &class);
    //     fprintf(fptr, "%s\t%d\n",str,class);
    //      fwrite(&data, bytesofnumbers, 1,fileptr)
    //     n--;
   
    // }
    // printf("%s", str);

    

    
    fclose(fptr);
}