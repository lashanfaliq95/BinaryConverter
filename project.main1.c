#include<stdio.h>
int stringcompare(char*str1,char*str2);
int stringlength(char*str1);
long long atoi(char*input);
float pow(int a,int b);
int floatoint(char a[]);
int doubletoint(char a[]);
double inttodouble(char a[]);
long int bintoint(char a[]);
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
float binarytofloat(char a[]);
void inttohexa(char a[]);
double atof(char a[]);
float abs(float a);
void floattobinary(char a[]);
void doubletobin(char a[]);
void floattohexa(char a[]);
void doubletohexa(char a[]);
float hexatofloat(char a[]);
double hexatodouble(char a[]);
int errorint(char a[]);
int errorfloat(char a[]);
int positionerror(char a[],char x[]);


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
    
    else if(stringcompare(argv[1],d)==0 && stringcompare(argv[2],e)==0 ){//float to double
    	if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
     else{ fprintf(stderr, "ERROR: This conversion is not possible." );}
    }
    else if(stringcompare(argv[1],e)==0 && stringcompare(argv[2],d)==0 ){//double to float
    	if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
     else{ fprintf(stderr, "ERROR: This conversion is not possible." );}
    }
	  else if(stringcompare(argv[1],e)==0 && stringcompare(argv[2],c)==0 ){//double to int
    	if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
    else{ fprintf(stderr, "ERROR: This conversion is not possible." );}
    }


    else if(stringcompare(argv[1],b)==0 && stringcompare(argv[2],b)==0){//binary to binary
     if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
     else{fprintf(stdout, "%s",bintobin(argv[3]) );}
    }
    else if(stringcompare(argv[1],b)==0 && stringcompare(argv[2],a)==0){//binary to hexa
            if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
                else{ binarytohexa(argv[3]);}

    }
    else if(stringcompare(argv[1],b)==0 && stringcompare(argv[2],c)==0){//binary to int
     if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
     else if(bintoint(argv[3])==-1 || stringlength(argv[3])==64){fprintf(stderr, "ERROR: This conversion is not possible." );}//to make sure it doesnt overfloaw
     else{ fprintf(stdout,"%d",bintoint(argv[3]) );}
    }
    else if(stringcompare(argv[1],b)==0 && stringcompare(argv[2],d)==0){//binary to float
            if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
           else if(stringlength(argv[3])==64){fprintf(stderr, "ERROR: This conversion is not possible." );}//as float is represented by 32 bit only
          else{  fprintf(stdout, "%0.2f",binarytofloat(argv[3]) );}

    }
    else if(stringcompare(argv[1],b)==0 && stringcompare(argv[2],e)==0){//binary to double
           if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
          else if(stringlength(argv[3])==32){fprintf(stderr, "ERROR: This conversion is not possible." );}//double is represented by 64 bit
              else{fprintf(stdout, "%0.6f",binarytodouble(argv[3]) );}
    }
    else if(stringcompare(argv[1],a)==0 && stringcompare(argv[2],a)==0){//hexa to hexa
      if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
      else{fprintf(stdout, "%s",hexatohexa(argv[3]) );}
    }    
    else if(stringcompare(argv[1],a)==0 && stringcompare(argv[2],b)==0){//hexa to binary
     if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
     else{hexatobin(argv[3]);}
    }
    else if(stringcompare(argv[1],a)==0 && stringcompare(argv[2],c)==0){//hexa to int
      if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
      else if(stringlength(argv[3])==16 || hexatoint(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );}//int is represented by 32 bit
      else {fprintf(stdout, "%d",hexatoint(argv[3]) );}
    }
    else if(stringcompare(argv[1],a)==0 && stringcompare(argv[2],d)==0){//hexa to float
      if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
      else if(stringlength(argv[3])==16){fprintf(stderr, "ERROR: This conversion is not possible." );}//float represented by 32 bits
      else{ fprintf(stdout, "%0.2f",hexatofloat(argv[3]) );}
    }
    else if(stringcompare(argv[1],a)==0 && stringcompare(argv[2],e)==0){//hexa to double
      if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
      else if(stringlength(argv[3])==8){fprintf(stderr, "ERROR: This conversion is not possible." );}//double represented by 64 bits
      else{ fprintf(stdout, "%0.6f",hexatodouble(argv[3]) );}
    }
    else if(stringcompare(argv[1],c)==0 && stringcompare(argv[2],c)==0){//integer to integer
     if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
     else if(errorint(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );}//if the integer is not more than the max 32 bit value
     else{   fprintf(stdout, "%s",inttoint(argv[3]));}
     }
    else if(stringcompare(argv[1],c)==0 && stringcompare(argv[2],b)==0){//integer to binary
     if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
     else if(errorint(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );}
     else{inttobinary(argv[3]);}
     }
    else if(stringcompare(argv[1],c)==0 && stringcompare(argv[2],a)==0){//integer to hexa
      if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
    else if(errorint(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );}
    else{inttohexa(argv[3]);}
    }
    else if(stringcompare(argv[1],c)==0 && stringcompare(argv[2],d)==0){//integer to float
    if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
    else if(errorint(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );}
    else{fprintf(stdout, "%0.2f",(float)atoi(argv[3]) );}
    }
    else if(stringcompare(argv[1],c)==0 && stringcompare(argv[2],e)==0){//integer to double
    if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
    else{fprintf(stderr, "ERROR: This conversion is not possible." );}//can convert 32 bit to 64 bit
    }
    else if(stringcompare(argv[1],d)==0 && stringcompare(argv[2],d)==0 ){//float to float
       if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
     else  if(errorfloat(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );}//if the float value exceeds the max possible value 
      else{ fprintf(stdout, "%0.2f",atof(argv[3]));}
    }
    else if(stringcompare(argv[1],d)==0 && stringcompare(argv[2],c)==0 ){//float to int
      if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
    else  if(errorfloat(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );} //if the float value exceeds the max possible value
    else if(errorint(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );} //if the out put int exced the max vlue
    else{ fprintf(stderr,"WARNING: There is a possibility for a precision loss.");
      fprintf(stdout, "%d",(int)atof(argv[3]) ); }
    }
     else if(stringcompare(argv[1],d)==0 && stringcompare(argv[2],a)==0 ){//float to hexa
      if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
       else  if(errorfloat(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );} //if the float value exceeds the max possible value
       else{  floattohexa(argv[3]);}
     }
     else if(stringcompare(argv[1],d)==0 && stringcompare(argv[2],b)==0 ){//float to binary
    if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
    else  if(errorfloat(argv[3])==-1){fprintf(stderr, "ERROR: This conversion is not possible." );} //if the float value exceeds the max possible value
   else{floattobinary(argv[3]);}
   }
    else if(stringcompare(argv[1],e)==0 && stringcompare(argv[2],e)==0 ){//double to double
       if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
    else{ fprintf(stdout, "%0.6lf",atof(argv[3]) );}
    }
   else if(stringcompare(argv[1],e)==0 && stringcompare(argv[2],b)==0 ){//double to binary
       if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
     else{ doubletobin(argv[3]);}
   }
   else if(stringcompare(argv[1],e)==0 && stringcompare(argv[2],a)==0 ){//double to hexa
        if(positionerror(argv[3],argv[1])!=-1){fprintf(stderr, "ERROR: Input format error at location %d.",positionerror(argv[3],argv[1]));}//checking the position of wrong input
      else{doubletohexa(argv[3]);}
   }
   return 0;
}
int positionerror(char a[],char x[]){//to check if there is a wrong value in input
  int size=strlen(a);
  int n;
  if(stringcompare(x,"-H")==0){//if the input is a hexadecimal
for(n=0;n<size;n++){
if(a[n]=='0' || a[n]=='1' || a[n]=='2' || a[n]=='3' || a[n]=='4'|| a[n]=='5' || a[n]=='6' || a[n]=='7' || a[n]=='8' ||a[n]=='9' ||
  a[n]=='a'|| a[n]=='b'|| a[n]=='c'|| a[n]=='d' || a[n]=='e'|| a[n]=='f' || a[n]=='A' || a[n]=='B'|| a[n]=='C'|| a[n]=='D'|| a[n]=='E'|| a[n]=='F'){
  continue;
}
else{return n;}
}
}
else if(stringcompare(x,"-B")==0){//if input is binary
 for(n=0;n<size;n++){
  if(a[n]=='0' || a[n]=='1' ){
    continue;
  }
  else{return n;}

 }
}
else if(stringcompare(x,"-I")==0){//if input is int
int count=0;
 for(n=1;n<size;n++){//to check if there is a - value inside the number
  if(a[n]=='-'){count++ ; continue;}
 if(count>0){return n-1; }
 }
 
 for(n=0;n<size;n++){
    if(a[n]=='0' || a[n]=='1' || a[n]=='2' || a[n]=='3' || a[n]=='4' || a[n]=='5' || a[n]=='6' || a[n]=='7' || a[n]=='8' || a[n]=='9' || a[n]=='-'){
    continue;
  }
  
  else{return n;}

 }
}

else if(stringcompare(x,"-F")==0 || stringcompare(x,"-D")==0){//if input is float or double
int count=0;
 for(n=1;n<size;n++){//to check if there is a - value inside the number
  if(a[n]=='-'){count++ ; continue;}
 if(count>0){return n-1; }
 }
 for(n=0;n<size;n++){//to check if there is more than 1 .  inside the number
  if(a[n]=='.'){count++ ; continue;}
 if(count>1){return n-1; }
 }
 
 for(n=0;n<size;n++){
    if(a[n]=='0' || a[n]=='1' || a[n]=='2' || a[n]=='3' || a[n]=='4' || a[n]=='5' || a[n]=='6' || a[n]=='7' || a[n]=='8' || a[n]=='9' || a[n]=='-' || a[n]=='.'){
    continue;
  }
  
  else{return n;}

 }
}

return -1;

}

 int errorint(char a[]){//to check if the integer is more than the max 32 bit value
 long long val=atof(a);
   long long max=2147483648LL;
   signed long long min=-2147483649LL;
        if(val>=max || val<=min ){
          return -1;
        }
        else {return 0;}}
int errorfloat(char a[]){
  double val=atof(a); 
  double max=3.40282*pow(10,38);
  double min=-3.40282*pow(10,38);

if(val>max || val<min ){
  return -1;}

else{return 0;}}

        

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


long long  atoi(char *input){//converting a array to a integer

long long  sum=0,temp,n,sign=1,i=0;
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

double atof(char a[]){//converting a aray to a float
  double rez = 0, fact = 1;
  if (*a == '-'){//checking if negative
    *a++;
    fact = -1;
  };
  for (int point_seen = 0; *a; *a++){
    if (*a == '.'){//to check the pont at we find the decimal
      point_seen = 1; 
      continue;
    };
    int d = *a - '0';
    if (d >= 0 && d <= 9){
      if (point_seen) fact /= 10;
      rez = rez * 10 + (double)d;
    };
  };
  return rez * fact;
}


int floatoint(char a[]){//function to convert float to int

  int x=atoi(a);
  return x;

}


long int bintoint(char a[]){//function to convert a binary number to a integer

    int size=strlen(a);
   if(size==32 && a[0]=='1'){return -1;}//to prevent the integer overflowing 
   else{ long int sum=0,n;
    for(n=0;n<size;n++){
        int power=pow(2,size-(n+1));
        sum=sum+power*(a[n]-'0');

}
return sum;}
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

             case '0': fprintf(stdout,"0000"); break;
             case '1': fprintf(stdout,"0001"); break;
             case '2': fprintf(stdout,"0010"); break;
             case '3': fprintf(stdout,"0011"); break;
             case '4': fprintf(stdout,"0100"); break;
             case '5': fprintf(stdout,"0101"); break;
             case '6': fprintf(stdout,"0110"); break;
             case '7': fprintf(stdout,"0111"); break;
             case '8': fprintf(stdout,"1000"); break;
             case '9': fprintf(stdout,"1001"); break;
             case 'A': fprintf(stdout,"1010"); break;
             case 'B': fprintf(stdout,"1011"); break;
             case 'C': fprintf(stdout,"1100"); break;
             case 'D': fprintf(stdout,"1101"); break;
             case 'E': fprintf(stdout,"1110"); break;
             case 'F': fprintf(stdout,"1111"); break;
             case 'a': fprintf(stdout,"1010"); break;
             case 'b': fprintf(stdout,"1011"); break;
             case 'c': fprintf(stdout,"1100"); break;
             case 'd': fprintf(stdout,"1101"); break;
             case 'e': fprintf(stdout,"1110"); break;
             case 'f': fprintf(stdout,"1111"); break;

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
fprintf(stdout,"%d",binarynum[j]);
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
     fprintf(stdout,"%d",twoscomp[i]);}
     }
}

void binarytohexa(char a[]){//function to convert  binary to hexa
    int n,i=0,z=0;
    fprintf(stdout,"0x");
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
        case      0: fprintf(stdout,"0"); break;
        case      1: fprintf(stdout,"1"); break;
        case     10: fprintf(stdout,"2"); break;
        case     11: fprintf(stdout,"3"); break;
        case    100: fprintf(stdout,"4"); break;
        case    101: fprintf(stdout,"5"); break;
        case    110: fprintf(stdout,"6"); break;
        case    111: fprintf(stdout,"7"); break;
        case   1000: fprintf(stdout,"8"); break;
        case   1001: fprintf(stdout,"9"); break;
        case   1010: fprintf(stdout,"A"); break;
        case   1011: fprintf(stdout,"B"); break;
        case   1100: fprintf(stdout,"C"); break;
        case   1101: fprintf(stdout,"D"); break;
        case   1110: fprintf(stdout,"E"); break;
        case   1111: fprintf(stdout,"F"); break;

        }
    }
}


int hexatoint(char a[]){//funtion to convert hexa decimals to integers
  int n,sum=0,temp;
  
  int length=stringlength(a);//as it can be 8 digit 
  if((a[0]>'7' && a[0]<='9') || (a[0]>='a' && a[0]<='f') ||(a[0]>='A' && a[0]<='F')  && length==8){return -1;}//to see if overflows
for(n=0;n<length;n++){
    if((a[n]>='A' && a[n]<='F')||(a[n]>='a' && a[n]<='f')){//if it has a letter
      int z=length-(n+1);
     switch(a[n]){
     case 'a':
     case 'A':  temp=10*pow(16,z); break;
     case 'b':
     case 'B':  temp=11*pow(16,z); break;
     case 'c':
     case 'C':  temp=12*pow(16,z); break;
     case 'd':
     case 'D':  temp=13*pow(16,z); break;
     case 'e':
     case 'E':  temp=14*pow(16,z); break;
     case 'f':
     case 'F':  temp=15*pow(16,z); break;
         }
   
    
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

float binarytofloat(char a[]){//function to convert a binary number to float
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

void floattobinary(char a[]){//function to conver float to binary
     float x=atof(a);
   char  binarynum[32];
   int count=0,n,i=1,j,integer;
   if(x>=0){binarynum[0]=0;}
   else{binarynum[0]=1;}
  if(x>1 || x<-1){//if abs value of x is more than 1
   while(abs(x)>=2){// to get the count or how many times u divide
   x=abs(x)/2;
   count++; }
    integer=count+127;//getting the exponent
}
else if((x<1 && x>0) || (x<0 && x>-1)){//to check if abs of x is less than a
   	
  while(abs(x)<1){//to find how many times we multipied by 2 to get a value more than 1
     x=abs(x)*2;
     count++;
            }
          integer=127-count;   
        }
 else if(x==0){integer=0;}//if x is zero whole binary is zero
 else if(x==1){integer=127;}//if x is 1 exponent is 127
 
float siginificand=abs(x)-1;//to get the siginificand part

 int k=siginificand*1000000000;

  for(n=9;n<33;n++){//filling up the significand 
  	
  	int z=pow(2,-i)*1000000000;
  	if(z==0){binarynum[n]=0;}
  	else if(k/z==1){binarynum[n]=1; k=k%z;}
   else{binarynum[n]=0;}
      i++;
    
  }
n=8;
       while(integer!=0) {//converting exponent to binary

           binarynum[n]=integer%2;
           integer=integer/2;
           n--;
    }
    for(k=n;k>0;k--){//filling the rest of the array with zeros
        binarynum[k]=0;
    }

   for(i=0 ;i<32;i++){//inverting the number
fprintf(stdout,"%d",binarynum[i]);

        }
    
   
}

void doubletobin(char a[]){//function to convert double to binary *final digits not the same

double x=atof(a);
   char  binarynum[64];
   int count=0,n,i=1,j,integer;
   if(x>=0){binarynum[0]=0;}
   else{binarynum[0]=1;}
  if(x>1 || x<-1){
   while(abs(x)>=2){// to get the count or how many times u divide
   x=abs(x)/2;
   count++; }
    integer=count+1023;//getting the exponent
}
else if((x<1 && x>0) || (x<0 && x>-1)){
   	
  while(abs(x)<1){//to find how many times we multipied by 2 to get a value more than 1
     x=abs(x)*2;
     count++;
            }
          integer=1023-count;   
        }
 else if(x==0){integer=0;}
 else if(x==1){integer=1023;}
 
double siginificand=abs(x)-1;//to get the siginificand part

 int k=siginificand*1000000000;

  for(n=12;n<64;n++){//filling up the significand 
  	
  	int z=pow(2,-i)*1000000000;
  	if(z==0){binarynum[n]=0;}
  	else if(k/z==1){binarynum[n]=1; k=k%z;}
   else{binarynum[n]=0;}
      i++;
    
  }
n=11;
       while(integer!=0) {//converting exponent to binary

           binarynum[n]=integer%2;
           integer=integer/2;
           n--;
    }
    for(k=n;k>0;k--){//filling the rest of the array with zeros
        binarynum[k]=0;
    }
for(i=0 ;i<64;i++){//inverting the number
fprintf(stdout,"%d",binarynum[i]);

        }
    }

void floattohexa(char a[]){//function to convert float to hexa
float x=atof(a);//first you convert it to binary
   char  binarynum[32],temp[32];
   int count=0,n,i=1,j,integer;
   if(x>=0){binarynum[0]=0;}
   else{binarynum[0]=1;}
  if(x>1 || x<-1){//if abs value of x is more than 1
   while(abs(x)>=2){// to get the count or how many times u divide
   x=abs(x)/2;
   count++; }
    integer=count+127;//getting the exponent
}
else if((x<1 && x>0) || (x<0 && x>-1)){//to check if abs of x is less than a
   	
  while(abs(x)<1){//to find how many times we multipied by 2 to get a value more than 1
     x=abs(x)*2;
     count++;
            }
          integer=127-count;   
        }
 else if(x==0){integer=0;}//if x is zero whole binary is zero
 else if(x==1){integer=127;}//if x is 1 exponent is 127
 
float siginificand=abs(x)-1;//to get the siginificand part

 int k=siginificand*1000000000;

  for(n=9;n<33;n++){//filling up the significand 
  	
  	int z=pow(2,-i)*1000000000;
  	if(z==0){binarynum[n]=0;}
  	else if(k/z==1){binarynum[n]=1; k=k%z;}
   else{binarynum[n]=0;}
      i++;
    
  }
n=8;
       while(integer!=0) {//converting exponent to binary

           binarynum[n]=integer%2;
           integer=integer/2;
           n--;
    }
    for(k=n;k>0;k--){//filling the rest of the array with zeros
        binarynum[k]=0;
    }
binarynum[32]='\0';
for(n=0;n<32;n++){
temp[n]=binarynum[n]+'0';
}

binarytohexa(temp);//now you convert the binay value to hexa
       
}

void doubletohexa(char a[]){//function to convert double to binary *final digits not the same

double x=atof(a);
   char  binarynum[64],temp[64];
   int count=0,n,i=1,j,integer;
   if(x>=0){binarynum[0]=0;}
   else{binarynum[0]=1;}
  if(x>1 || x<-1){
   while(abs(x)>=2){// to get the count or how many times u divide
   x=abs(x)/2;
   count++; }
    integer=count+1023;//getting the exponent
}
else if((x<1 && x>0) || (x<0 && x>-1)){
   	
  while(abs(x)<1){//to find how many times we multipied by 2 to get a value more than 1
     x=abs(x)*2;
     count++;
            }
          integer=1023-count;   
        }
 else if(x==0){integer=0;}
 else if(x==1){integer=1023;}
 
double siginificand=abs(x)-1;//to get the siginificand part

 int k=siginificand*1000000000;

  for(n=12;n<64;n++){//filling up the significand 
  	
  	int z=pow(2,-i)*1000000000;
  	if(z==0){binarynum[n]=0;}
  	else if(k/z==1){binarynum[n]=1; k=k%z;}
   else{binarynum[n]=0;}
      i++;
    
  }
n=11;
       while(integer!=0) {//converting exponent to binary

           binarynum[n]=integer%2;
           integer=integer/2;
           n--;
    }
    for(k=n;k>0;k--){//filling the rest of the array with zeros
        binarynum[k]=0;
    }
for(i=0 ;i<64;i++){
temp[i]=binarynum[i]+'0';
        }
        binarytohexa(temp);
    }

float hexatofloat(char a[]){// funtion to convert hexa to float only possible for 8 digit hexa decimal
int n=0,i=0;
char c[32],temp[32];//as the binary reperestntaion of a float has 32 bits 
while(a[i]!= '\0'){
         switch(a[i]){

             case '0': c[n]=0,c[n+1]=0,c[n+2]=0,c[n+3]=0; break;
             case '1': c[n]=0,c[n+1]=0,c[n+2]=0,c[n+3]=1; break;
             case '2':  c[n]=0,c[n+1]=0,c[n+2]=1,c[n+3]=0; break;
             case '3': c[n]=0,c[n+1]=0,c[n+2]=1,c[n+3]=1; break;
             case '4': c[n]=0,c[n+1]=1,c[n+2]=0,c[n+3]=0; break;
             case '5':c[n]=0,c[n+1]=1,c[n+2]=0,c[n+3]=1; break;
             case '6': c[n]=0,c[n+1]=1,c[n+2]=1,c[n+3]=0; break;
             case '7':c[n]=0,c[n+1]=1,c[n+2]=1,c[n+3]=1; break;
             case '8': c[n]=1,c[n+1]=0,c[n+2]=0,c[n+3]=0; break;
             case '9': c[n]=1,c[n+1]=0,c[n+2]=0,c[n+3]=1; break;
             case 'a':
             case 'A': c[n]=1,c[n+1]=0,c[n+2]=1,c[n+3]=0; break;
             case 'b':
             case 'B':c[n]=1,c[n+1]=0,c[n+2]=1,c[n+3]=1; break;
             case 'c':
             case 'C': c[n]=1,c[n+1]=1,c[n+2]=0,c[n+3]=0; break;
             case 'd':
             case 'D':c[n]=1,c[n+1]=1,c[n+2]=0,c[n+3]=1; break;
             case 'e':
             case 'E':c[n]=1,c[n+1]=1,c[n+2]=1,c[n+3]=0; break;
             case 'f':
             case 'F':c[n]=1,c[n+1]=1,c[n+2]=1,c[n+3]=1; break;
             

             }
             n=n+4;//as we get 4 values for array each time 
             i++;
         }
c[32]='\0';
for(n=0;n<32;n++){
temp[n]=c[n]+'0';

}

binarytofloat(temp);
}

double hexatodouble(char a[]){// funtion to convert hexa to double only true for 16 digit hexadecimal
int n=0,i=0;

char c[64],temp[64];//binary conversion of hexa has 64 bits
while(a[i]!= '\0'){
         switch(a[i]){

             case '0': c[n]=0,c[n+1]=0,c[n+2]=0,c[n+3]=0; break;
             case '1': c[n]=0,c[n+1]=0,c[n+2]=0,c[n+3]=1; break;
             case '2':  c[n]=0,c[n+1]=0,c[n+2]=1,c[n+3]=0; break;
             case '3': c[n]=0,c[n+1]=0,c[n+2]=1,c[n+3]=1; break;
             case '4': c[n]=0,c[n+1]=1,c[n+2]=0,c[n+3]=0; break;
             case '5':c[n]=0,c[n+1]=1,c[n+2]=0,c[n+3]=1; break;
             case '6': c[n]=0,c[n+1]=1,c[n+2]=1,c[n+3]=0; break;
             case '7':c[n]=0,c[n+1]=1,c[n+2]=1,c[n+3]=1; break;
             case '8': c[n]=1,c[n+1]=0,c[n+2]=0,c[n+3]=0; break;
             case '9': c[n]=1,c[n+1]=0,c[n+2]=0,c[n+3]=1; break;
             case 'a':
             case 'A': c[n]=1,c[n+1]=0,c[n+2]=1,c[n+3]=0; break;
             case 'b':
             case 'B':c[n]=1,c[n+1]=0,c[n+2]=1,c[n+3]=1; break;
             case 'c':
             case 'C': c[n]=1,c[n+1]=1,c[n+2]=0,c[n+3]=0; break;
             case 'd':
             case 'D':c[n]=1,c[n+1]=1,c[n+2]=0,c[n+3]=1; break;
             case 'e':
             case 'E':c[n]=1,c[n+1]=1,c[n+2]=1,c[n+3]=0; break;
             case 'f':
             case 'F':c[n]=1,c[n+1]=1,c[n+2]=1,c[n+3]=1; break;
             

             }
             n=n+4;//again each time we get 4 values for array c
             i++;
         }
    c[64]='\0';
    for(n=0;n<64;n++){
      temp[n]=c[n]+'0';
     }
binarytodouble(temp);
}