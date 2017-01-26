#include<stdio.h>
float binarytofloat(char a[]);
int atoi(char *input);
float pow(int a,int b);
int stringlength(char*str1);
int bintoint(char a[]);

int main(){

char a[]="01000000101000000000000000000000";//5
printf("%0.2f",binarytofloat(a));
	return 0;
}

float binarytofloat(char a[]){
int n,i=1,s;
float sum=0,temp;
char ex[8];
if(a[0]=='0'){s=0;}
else if(a[0]=='1'){s=1;}

	for(n=1;n<9;n++){
     
     ex[n-1]=a[n];

	}
	ex[8]='\0';


int exponent=bintoint(ex);

int power=exponent-127;
for(n=9;n<33;n++){
      temp=(a[n]-'0')*pow(2,-i);
      sum=sum+temp;
      i++;

}
float significand=1+sum+0.00001;


float value=significand*pow(2,power)*pow(-1,s);
return value;




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
int bintoint(char a[]){//function to convert a binary number to a integer

    int size=strlen(a);
    int sum=0,n;
    for(n=0;n<size;n++){
        int power=pow(2,size-(n+1));
        sum=sum+power*(a[n]-'0');
}
return sum;
}