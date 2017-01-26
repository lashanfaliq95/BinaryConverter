#include<stdio.h>
float hexatofloat(char a[]);
float binarytofloat(char a[]);
int bintoint(char a[]);
float pow(int a,int b);
int stringlength(char*str1);
double binarytodouble(char a[]);
double hexatodouble(char a[]);
int main(){
char a[]="4025824F6598E10D";
printf("%lf",hexatodouble(a));

	return 0;
}

float hexatofloat(char a[]){//A void funtion to convert hexa to binary
int n=0,i=0;
int size=strlen(a);
char c[64],temp[64];
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
             n=n+4;
             i++;
         }
c[size*4]='\0';
for(n=0;n<size*4;n++){
temp[n]=c[n]+'0';

}

binarytofloat(temp);
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

int bintoint(char a[]){//function to convert a binary number to a integer

    int size=strlen(a);
    int sum=0,n;
    for(n=0;n<size;n++){
        int power=pow(2,size-(n+1));
        sum=sum+power*(a[n]-'0');
}
return sum;
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

int stringlength(char*str1){//checking the length of the string

    int n=0;
    while(str1[n]!='\0'){
        n++;

    }
return n;

}

double hexatodouble(char a[]){//A void funtion to convert hexa to binary
int n=0,i=0;

char c[64],temp[64];
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
             n=n+4;
             i++;
         }
c[64]='\0';
for(n=0;n<64;n++){
temp[n]=c[n]+'0';


}

binarytodouble(temp);
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