#include<stdio.h>

void inttobinary(char a[]);
int atoi(char *input);
void inttohexa(char a[]);
void binarytohexa(char a[]);
float bintofloat(char a[]);
int bintoint(char a[]);
float powneg(int a,int b);
int pow(int a,int b);
float MyPow(int a,int b);

int main(){
char a[]="11111000111110001111100011111000";

printf("%f",powneg(10,-8)*powneg(10,-8));
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
void binarytohexa(char a[]){
    int n,i=0,z=0;

   while(a[i]!='\0'){
        char c[4];
      int k=0;
    for(n=i;n<4+i;n++){

        c[k]=a[n];
       k++;

    }
 i=i+4;

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

int bintoint(char a[]){//function to convert a binary number to a integer

    int size=strlen(a);
    int n,sum;
   
    for(n=0;n<size;n++){
        int power=pow(2,size-(n+1));
        sum=sum+power*(a[n]-'0');
}
return sum;
}




float bintofloat(char a[]){//didnt work
    int n,s;
    char ex[8],sig[23];
    if(a[0]=1){s=1;}
    else {s=0;}
    for(n=1;n<9;n++){
      ex[n-1]=a[n];

    }
    int exponent=bintoint(ex);
   int power=exponent-127;
    sig[0]=1;
    for(n=9;n<32;n++){
      sig[n-8]=a[n];

    }
    
    int significand=bintoint(sig);
     
    float y=powneg(2,power);
    float z=powneg(10,-23);
    int j=pow(-1,s);
    float x=y*z*j*significand;

return x;

}



float powneg(int a,int b){//function to get the power
    int n;
    float sum=1;
  if(b>0){  
for(n=1;n<b;n++){

    sum=sum*a;
}return sum;}
else if(b==0){return 1;}


else if(b<0){  for(n=1;n<-b;n++){
             sum=sum/a;
}  return sum; }

}
int pow(int a,int b){//function to get the power
    int n,sum=1;
     if(b==0){return 1;}

for(n=1;n<=b;n++){

    sum=sum*a;
}

return sum;
}
float MyPow(int a,int b){
      if(b<0)      
        return (1.0/a)*(MyPow(a,b+1)); 
      else if(b==0)
        return 1;
      else if(b==1)
        return a;
      else
        return a*MyPow(a,b-1);
    }
