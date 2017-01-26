#include<stdio.h>
int stringcompare(char*str1,char*str2){//checking if two string are equal

int size=sizeof(str1);
int n;
for(n=0;n<size;n++){
     if(str1[n]==str2[n]){
        continue;
     }
    else{return 1;}

}
return 0;
}

int stringlength(char*str1){//checking the length of the string

    int n=0;
    while(str1[n]!='\0'){
        n++;

    }
return n;

}


int main(int argc,char**argv){
    char a[]="-H";
    char b[]="-B";
    char c[]="-I";
    char d[]="-F";
    char e[]="-D";
	if(argc!=4){//error if the number of arguments are wrong
		fprintf(stderr,"ERROR: The number of arguments is wrong. \n");
        fprintf(stderr," Usage: ./binconvert -<input format> -<output format> <input> " );
        return -1;
         }
    else if(stringcompare(argv[1],a)!=0 && stringcompare(argv[1],b)!=0 && stringcompare(argv[1],c)!=0 && stringcompare(argv[1],d)!=0 && stringcompare(argv[1],e)!=0 ){//error if input arguments is wrong
       fprintf(stderr,"ERROR: The input argument is wrong. \n Possible input arguments are -B, -H, -I, -F and -D.");
       return -1;}
    else if(stringcompare(argv[2],a)!=0 && stringcompare(argv[2],b)!=0 && stringcompare(argv[2],c)!=0 && stringcompare(argv[2],d)!=0 && stringcompare(argv[2],e)!=0 ){//error if ouput argument is wrong
       fprintf(stderr,"ERROR: The output argument is wrong. \n possible output arguments are -B, -H, -I, -F and -D.");
       return -1;}
    else if(stringcompare(argv[1],b)==0 && stringlength(argv[3])!=32 && stringlength(argv[3])!=64 ){//error if there in a invalid no of digits inputed for binary
    	fprintf(stderr,"ERROR: The input size is wrong.");
    	return -1;
        }
    else if(stringcompare(argv[1],a)==0 && stringlength(argv[3])!=8 && stringlength(argv[3])!=16 ){//error if there in a invalid no of digits inputed for hexadecimal
    	fprintf(stderr,"ERROR: The input size is wrong.");
    	return -1;}
    else if(stringcompare(argv[1],c)==0 && stringlength(argv[3])!=8  ){//error if there in a invalid no of digits inputed for integer
    	fprintf(stderr,"ERROR: The input size is wrong.");
    	return -1;}
	
	
	return 0;
}

