#include<stdio.h>
int stringcompare(char*str1,char*str2);
int stringlength(char*str1);
int atoi(char*input);
float pow(int a,int b);
float inttofloat(char a[]);
int floatoint(char a[]);
int doubletoint(char a[]);
double inttodouble(char a[]);
int bintoint(char a[]);
int hexatoint(char a[]);
char* bintobin(char a[]);
char* hexatohexa(char a[]);
char* inttoint(char a[]);
char* floattofloat(char a[]);
char* doubletodouble(char a[]);
void hexatobin(char a[]);
double floattodouble(char a[]);
float doubletofloat(char a[]);
void inttobinary(char a[]);
void binarytohexa(char a[]);
double binarytodouble(char a[]);





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
    else if(stringcompare(argv[1],d)==0 && stringcompare(argv[2],e)==0 ){//float to double
    	fprintf(stderr,"WARNING: There is a possibility for a precision loss.");
    }
    else if(stringcompare(argv[1],e)==0 && stringcompare(argv[2],d)==0 ){//double to float
    	fprintf(stderr,"WARNING: There is a possibility for a precision loss.");
    }
	else if(stringcompare(argv[1],e)==0 && stringcompare(argv[2],c)==0 ){//double to int
    	fprintf(stderr,"WARNING: There is a possibility for a precision loss.");
    }
    else if(stringcompare(argv[1],d)==0 && stringcompare(argv[2],c)==0 ){//float to int
    	fprintf(stderr,"WARNING: There is a possibility for a precision loss.");
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


int stringcompare(char*str1,char*str2){//checking if two string are equal

   int c = 0;
 
   while (str1[c] == str2[c]) {
      if (str1[c] == '\0' || str2[c] == '\0')
         break;
      c++;
   }
 
   if (str1[c] == '\0' && str2[c] == '\0')
      return 0;
   else
      return -1;
}


int atoi(char *input){//converting a array to a integer

int sum=0,temp,n,sign=1,i=0;
 if(input[0]=='-') {//if the string has a negative number first character shoul be '-'
    sign=-1;
    i++;
 }
for(n=i;input[n]!='\0';++n){


    temp=input[n]-'0';//getting the number in array not ascii value
    sum=sum*10+temp;
}
return sign*sum;
}


float pow(int a,int b){//function to get the power
    int n;
    float sum=1;
if(b>0){//if exponent is postive  
for(n=1;n<=b;n++){

    sum=sum*a;
}return sum;}
else if(b==0){return 1;}//if exponent is zero
else if(b<0){//if negative
   return (1.0/a)*(pow(a,b+1)); 
            }
}

float inttofloat(char a[]){//function to convert int to float

 float x=atoi(a);
 return x;
}


int floatoint(char a[]){//function to convert float to int

  int x=atoi(a);
  return x;

}


int bintoint(char a[]){//function to convert a binary number to a integer

    int size=strlen(a);
    int sum=0,n;
    for(n=0;n<size;n++){
        int power=pow(2,size-(n+1));
        sum=sum+power*(a[n]-'0');
}
return sum;
}


char* bintobin(char a[]){//function to convert binary to binary
	
	return a;
}


char* hexatohexa(char a[]){//function to convert hexadecimal to hexadecimal
    
  return a;
}


char* inttoint(char a[]){//function to convert integer to integer

return a;
}


char* floattofloat(char a[]){//funtion to convert float to float

return a;
}

char* doubletodouble(char a[]){//function to convert double to double

return a;
}

void hexatobin(char a[]){//A void funtion to convert hexa to binary
int n=0;
while(a[n]!= '\0'){
         switch(a[n]){

             case '0': printf("0000"); break;
             case '1': printf("0001"); break;
             case '2': printf("0010"); break;
             case '3': printf("0011"); break;
             case '4': printf("0100"); break;
             case '5': printf("0101"); break;
             case '6': printf("0110"); break;
             case '7': printf("0111"); break;
             case '8': printf("1000"); break;
             case '9': printf("1001"); break;
             case 'A': printf("1010"); break;
             case 'B': printf("1011"); break;
             case 'C': printf("1100"); break;
             case 'D': printf("1101"); break;
             case 'E': printf("1110"); break;
             case 'F': printf("1111"); break;
             case 'a': printf("1010"); break;
             case 'b': printf("1011"); break;
             case 'c': printf("1100"); break;
             case 'd': printf("1101"); break;
             case 'e': printf("1110"); break;
             case 'f': printf("1111"); break;

             }
             n++;
         }
}

int doubletoint(char a[]){//funtion to convert double to int
  int x=atoi(a);
  return x;
}
double inttodouble(char a[]){//funtion to convert int to double
 double x=atoi(a);
 return x;

}

double floattodouble(char a[]){//funtion to convert float to double
	double x=atoi(a);
	return x;
}

float doubletofloat(char a[]){//function to convert double to float
	float x=atoi(a);
	return x;
}

void inttobinary(char a[]){//function to convert int to binary
  int integer=atoi(a);
  int binarynum[32];

if(integer>=0){//for positive integers
    int  k,n=0,j;
       while(integer!=0) {//getting the binary part

           binarynum[n]=integer%2;
           integer=integer/2;
           n++;
    }
    for(k=n;k<32;k++){//filling the rest of the array with zeros
        binarynum[k]=0;
    }
int i=0;
   for(j = 31 ;j>=0;j--){//inverting the number
printf("%d",binarynum[j]);
i=i++;

        }
    }
else{
   int modinteger=-integer;//ignoring the negative value for now
   int  k,n=0,j,carry=1;
   int onesComp[32],twoscomp[32];
    while(modinteger!=0) {//getting the binary part
        binarynum[n]=modinteger%2;
        modinteger=modinteger/2;
        n++;
    }
    for(k=n;k<32;k++){//filling the rest of the array with zeros
        binarynum[k]=0;
    }
int i=0;
   for(j = 31 ;j>=0;j--){//inverting the number and converting to ones complement
      if(binarynum[j]==1)
        {onesComp[i]=0;}
        else if(binarynum[j]==0)
        {onesComp[i]=1;}
         i=i++;
       }

    for(i=31;i>=0;i--){//converting to twos complement
        if(onesComp[i]==1 && carry==1)
        {twoscomp[i] =0;}
        else if(onesComp[i]==0 && carry==1)
        {twoscomp[i] = 1;
          carry = 0;}
        else
        {twoscomp[i] = onesComp[i]; }
             }

for(i=0;i<32;i++){
     printf("%d",twoscomp[i]);}
     }
}

void binarytohexa(char a[]){//function to convert  binary to hexa
    int n,i=0,z=0;
   while(a[i]!='\0'){
       char c[4];//array to get 4 digits sepearately
      int k=0;
    for(n=i;n<4+i;n++){//getting 4 digits to a seperate array
     c[k]=a[n];
       k++; 
   }
         i=i+4;//to make next array after 4 digits

     int x=atoi(c);

        switch(x){
        case      0: printf("0"); break;
        case      1: printf("1"); break;
        case     10: printf("2"); break;
        case     11: printf("3"); break;
        case    100: printf("4"); break;
        case    101: printf("5"); break;
        case    110: printf("6"); break;
        case    111: printf("7"); break;
        case   1000: printf("8"); break;
        case   1001: printf("9"); break;
        case   1010: printf("A"); break;
        case   1011: printf("B"); break;
        case   1100: printf("C"); break;
        case   1101: printf("D"); break;
        case   1110: printf("E"); break;
        case   1111: printf("F"); break;

        }
    }
}


int hexatoint(char a[]){//funtion to convert hexa decimals to integers
  int n,sum=0,temp;
  
  int length=stringlength(a);//as it can be 8 digit or 16 digit
for(n=0;n<length;n++){
    if((a[n]>='A' && a[n]<='F')||(a[n]>='a' && a[n]<='f')){//if it has a letter
     switch(a[n]){
     case 'a':
     case 'A': a[n]=10 ; break;
     case 'b':
     case 'B': a[n]=11 ; break;
     case 'c':
     case 'C': a[n]=12 ; break;
     case 'd':
     case 'D': a[n]=13 ; break;
     case 'e':
     case 'E': a[n]=14 ; break;
     case 'f':
     case 'F': a[n]=15 ; break;
         }
     int z=length-(n+1);
     temp=(a[n])*pow(16,z);
     sum=sum+temp;

   }
 else{//if it has a number
     int z=length-(n+1);
     temp=(a[n]-'0')*pow(16,z);
     sum=sum+temp;
     }
   }
   return sum;
}

float binarytofloat(char a[]){
   int n,i=1,s;
   float sum=0,temp;
   char ex[8];
 if(a[0]=='0'){s=0;}//checking if number is postive
 else if(a[0]=='1'){s=1;}//checking if number is negative

	for(n=1;n<9;n++){//getting the exponent part to a array
       ex[n-1]=a[n];
   }
	ex[8]='\0';


int exponent=bintoint(ex);//converting the exponent part to a int

int power=exponent-127;
 for(n=9;n<33;n++){//getting the significand part as a fraction
      temp=(a[n]-'0')*pow(2,-i);
      sum=sum+temp;
      i++;

  }
float significand=1+sum+0.00001;
float value=significand*pow(2,power)*pow(-1,s);
return value;
}

double binarytodouble(char a[]){//function to convert binary to double
int n,i=1,s;
double sum=0,temp;
char ex[11];
if(a[0]=='0'){s=0;}
else if(a[0]=='1'){s=1;}

	for(n=1;n<12;n++){//getting the exponent to a different array
     
     ex[n-1]=a[n];

	}
	ex[11]='\0';

int exponent=bintoint(ex);//converting the exponent to a integer

int power=exponent-1023;
for(n=12;n<65;n++){//getting the siginificand as a fraction
      temp=(a[n]-'0')*pow(2,-i);
      sum=sum+temp;
      i++;
}
double significand=1+sum;
double value=significand*pow(2,power)*pow(-1,s);
return value;
}

void inttohexa(char a[]){//first convert the int to binary and then the binary to hexa decimal
int integer=atoi(a);
  char binarynum[32],temp [32];

if(integer>=0){//for positive integers
    int  k,n=0,j;
       while(integer!=0) {//getting the binary part

           binarynum[n]=integer%2;
           integer=integer/2;
           n++;
    }
    for(k=n;k<32;k++){//filling the rest of the array with zeros
        binarynum[k]=0;
    }
int i=0;
   for(j = 31 ;j>=0;j--){//inverting the number
     temp[i]=binarynum[j]+'0';
i=i++;
     }
     

     temp[32]='\0';
     binarytohexa(temp);////using the function to convert the binary value to hexadecimal
    }
else{
   int modinteger=-integer;//ignoring the negative value for now
   int  k,n=0,j,carry=1;
   int onesComp[32],twoscomp[32];
    while(modinteger!=0) {//getting the binary part
        binarynum[n]=modinteger%2;
        modinteger=modinteger/2;
        n++;
    }
    for(k=n;k<32;k++){//filling the rest of the array with zeros
        binarynum[k]=0;
    }
int i=0;
   for(j = 31 ;j>=0;j--){//inverting the number and converting to ones complement
      if(binarynum[j]==1)
        {onesComp[i]=0;}
        else if(binarynum[j]==0)
        {onesComp[i]=1;}
         i=i++;
       }

    for(i=31;i>=0;i--){//converting to twos complement
        if(onesComp[i]==1 && carry==1)
        {twoscomp[i] =0;}
        else if(onesComp[i]==0 && carry==1)
        {twoscomp[i] = 1;
          carry = 0;}
        else
        {twoscomp[i] = onesComp[i]; }
             }

for(i=0;i<32;i++){
    temp[i]=twoscomp[i]+'0';}
     temp[32]='\0';
binarytohexa(temp);//using the function to convert the binary value to hexadecimal

     }
}