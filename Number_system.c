#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int cnvrt(char *ex);
void Tohexa(int dec);
static char hex[50],ex[50];

long conv(int oct_num);
long tooctal(int);

int convert (long long bin_num);
long tobinary(int);

static int i,num;

int main(){
    long  binary,octal,bin_num,oct_num;
    int decimal;
    char ex[100];
    int x;
    printf("press, 1 to convert form decimal to binary,octal and hexadecimal  and 2 form  binary to decimal & 3 form octal to decimal '\n' & 4 form hexadecimal to decimal:");
    scanf("%d",&x);

    switch (x){
        case 1:
    
    // decimal number......
    printf("Enter any decimal number:");
    scanf("%d",&decimal);

    // decimal to binary.......
    printf("\n The Binary vaalue is: %ld\n\n ",tobinary(decimal));

    // decimal to octal......
    printf("\n The Octal vaalue is: %d\n\n ",tooctal(decimal));

    // decimal to hexadecimal......
    Tohexa(decimal);
    printf("\n The Hexadecimal value is:");
    for(i=i-1;i>=0;i--)
        printf("%c",hex[i]);
    getc;
        break;

        case 2:
    
    // binary number by user........
    printf("\n\nEnter Binary number(only in form of 0s and 1s) : ");
    scanf("%lld",&bin_num);
    num = convert(bin_num);

    // binary to decimal......
    printf("\n The binary to decimal vaalue is: %d\n ",num);
        break;

        case 3:
    // octal number by user....
    printf("\nEnter the octal number:");
    scanf("%ld",&oct_num);
    num = conv(oct_num);
    // octal to dedimal....
    printf("\n The octal to decimal value is: %ld\n\n",num);
        break;

        case 4:
    // hexa decimal by user...
    printf("\nEnter the hexadecimal number:");
    scanf("%s",ex);

    // hexato decimal number....
    printf("\ndecimal number is:%d",cnvrt(ex));
    break;

    default : ("Wrong input Try again:");
        break;
    return 0;
    }
}


// calc D2B...
long tobinary(int decimal){
    long binary,rem,f=1;
    while(decimal !=0){
        rem = decimal %2;
        binary= binary + rem*f;
        f = f*10;
        decimal=decimal/2;
    }
    return binary;;
    
}



// calc D2O....
long tooctal(int decimal){
    long octal=0,f=1;
    while(decimal !=0){
        octal = octal + (decimal %8)*f;
        decimal=decimal/8;
        f = f*10;
    }
    return octal;;
}



// calc D2H....
void Tohexa(int dec){
    int rem;
    while(dec !=0){
        rem = dec %16;
        if(rem<10)
            rem=rem+48;
        
        else
            rem = rem+55;
        
        hex[i] = rem;
        i++;
        dec=dec/16;
    }
   
}

// calc B2D....
int convert(long long bin_num){
    int num =0,i=0,rem;
    while(bin_num!=0){
        rem = bin_num % 10;
        bin_num = bin_num/10;
        num = num + rem * pow(2,i);
        ++i;
        
    }
    return num;
}

//calc O2D....
long conv(int oct_num){
    int num =0,i=0,rem;
    while(oct_num!=0){
        rem = oct_num % 10;
        oct_num = oct_num/10;
        num = num + rem * pow(8,i);
        ++i;
        
    }
    return num;
}

// calc H2D....
int cnvrt(char *ex){
    int p=0;
    int decimal =0;
    int r,i;

    for (i=strlen(hex)-1;i>=0;--i){
        if(ex[i]=='0' && ex[i]<='9'){
            r = ex[i]-'0';
        }
        else{
            r = ex[i]-'A'+10;
        }
        decimal = decimal + r*pow(16,p);
        ++p;
    }
    return decimal;
}
