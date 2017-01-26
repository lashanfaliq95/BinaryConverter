#include<stdio.h>
 int atoi(char *input) ; 
 int pow(int a,int b);
 void inttobinary(char a[]);
 void inttohexa(char a[]);
 void binarytohexa(char a[]);

int main(){

char a[]="12345678";
inttohexa(a);


	return 0;
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


int pow(int a,int b){//function to get the power
    int n,sum=1;
for(n=1;n<=b;n++){

    sum=sum*a;
}

return sum;
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
void inttohexa(char a[]){

  int integer=atoi(a);
  char binarynum[32],temp1[32],temp2[32];
 temp1[32]='\0';
 temp2[32]='\0';
 binarynum[32]='\0';
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
    temp2[i]=binarynum[j]-'0';
i=i++;

        }
        for(n=0;n<32;n++){
        	printf("%c",temp2[n]);
        }
    }
else{
   int modinteger=-integer;//ignoring the negative value for now
   int  k,n=0,j,carry=1;
   char onesComp[32],twoscomp[32];
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
     temp1[i]=twoscomp[i];}
     }


binarytohexa(temp1);






}