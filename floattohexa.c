#include<stdio.h>
void floattobinary(char a[]);
float atof(char a[]);
float abs(float a);
float pow(int a,int b);
int atoi(char *input);
void floattohexa(char a[]);
void binarytohexa(char a[]);
void doubletohexa(char a[]);

int main(){
char a[]="10.123";
doubletohexa(a);



return 0;
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
printf("%d",binarynum[i]);

        }
    
   
}

float atof(char a[]){//converting a aray to a float
  float rez = 0, fact = 1;
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
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
}

float abs(float a){//function to get absolute value of a number
if(a>=0){return a;}
if(a<0){return -a;}

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

void floattohexa(char a[]){
float x=atof(a);
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

binarytohexa(temp);
    
   
}//

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
for(i=0 ;i<64;i++){//inverting the number
temp[i]=binarynum[i]+'0';
        }
        binarytohexa(temp);
    }