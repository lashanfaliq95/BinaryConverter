#include<stdio.h>
int hexatoint(char a[]);
int atoi(char *input) ; 
float pow(int a,int b);
int stringlength(char*str1);


int main(){

char a[]="abCD";
 printf("%d",hexatoint(a));

	return 0;
}

int hexatoint(char a[]){
  int n,sum=0,temp;
  
  int length=stringlength(a);
for(n=0;n<length;n++){
    if((a[n]>='A' && a[n]<='F')||(a[n]>='a' && a[n]<='f')){
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
 else{
     int z=length-(n+1);
     temp=(a[n]-'0')*pow(16,z);
     sum=sum+temp;



 }
}
   return sum;
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
if(b>0){    
for(n=1;n<=b;n++){

    sum=sum*a;
}return sum;}
else if(b==0){return 1;}
else if(b<0){


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
