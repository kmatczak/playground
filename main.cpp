#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <bitset>
#include <set>
#include <stdint.h>
#include <vector>
#include <algorithm>


typedef struct 
{
    int a;
    char b;
} MYSTRUCT;

/*

typedef int** handle; 

handle alloc_mystruct()
{
 handle h = (int**)malloc(sizeof(handle));
 *h = (int*)malloc(sizeof(MYSTRUCT) * 10) ;

 return h;
}

*/

void move_to_next_el(char** i){ //double pointer because pointers are passed by value
    ++(*i);
}

void move_to_next_el_ref(char*& i){ //reference to pointer - also works!!!
    ++i;
}

void revert_words(char* ws){

   int x=0; 
   int end=strlen(ws)-1;

   for( int y = 0 ; y <= end ; ++y){

        if (ws[y] == ' ' || y == end) {

            int yy = y-1;
 //           printf("x=%u yy=%u\n", x, yy);
           
            while(x<yy){
                ws[x]  = ws[x] ^ ws[yy];
                ws[yy] = ws[x] ^ ws[yy];
                ws[x]  = ws[x] ^ ws[yy];
                
                --yy;
                ++x; 
            }
         
        x=y+1;

        }
   }


}

using namespace std;

int main(int argc, char** argv){
/*
//------------lambda----------------------------
vector<int> v;
v.push_back(1);
v.push_back(2);

for_each(v.begin(), v.end(), [] (int val){ cout << val ; } ) ;




//auto func = [] () { std::cout << "Hello world"; };

//func();

//std::string name;
//std::cin >> name ;

//-----------------------------------------------
*/


//----------- double pointer play -----------

int *p = (int*)malloc(sizeof(int)*4);
int *q = p;

*q = 56; 
*(++q)=72;
*(++q)=38;
*(++q)=44;

//int **pp  = &p;
q=p;

int **qq  = &q;

for (int i =0; i<4 ; ++i){
    
  //  printf("%x\n", p[i]);
  //  printf("%x\n", *pp[i]);
    printf("%x  %d  |  %d \n", q+i, q[i],  *(*qq+i));
    

}


//--------------------------------









/*
//char* p = "QWER";
char str[] = "QWER    12345 asdfghj lkjh4";
char* p = str;

printf("before  %s\n", str);
revert_words(str);
printf("after   %s\n", str);



//printf("%s", data);
uint8_t myRnData[100];


    int rnData = open("/dev/urandom", O_RDONLY);

	for(int j= 0; j < 200 ; ++j){
    	ssize_t res = read(rnData, &myRnData, sizeof (myRnData)) ;
    	if ( res < 0 )   exit(EXIT_FAILURE); 
		
		for (int i=0 ; i<sizeof(myRnData) ; ++i){
		myRnData[i] = (i == sizeof(myRnData)-1) ? '\0' : 32 + myRnData[i] % 90;
		}
    	
		printf("before  %s\n", myRnData);
		revert_words((char*)myRnData);
		printf("after   %s\n", myRnData);
	}

    close(rnData);

*/


/*

int k = 0;
//int length = sizeof(p)/sizeof(p[0);
printf("sizeof p:%u sizeof p[0]:%u\n", sizeof(str), sizeof(p[0]));
//int length = sizeof(str)/sizeof(str[0]);
int length = strlen(str);
printf("length: %u\n",length);

while( k < length ){
    printf("%u: %c %x\n",k, *p, p );
    move_to_next_el(&p);
    //move_to_next_el_ref(p);
    ++k;
}

*/


/*
handle my_h;
my_h = alloc_mystruct();

MYSTRUCT m1 = {1, 'a'};
my_h[0] = m1;

*/







/*
char* ch_arr[]={"sdfsd","sfdfdfgggg", "yryryery"};

char* f;
int no_el = sizeof(ch_arr)/sizeof(char*);
printf("size of array is %d ; size of single pointer:%d ; no of array elements:%d\n", sizeof(ch_arr), sizeof(f), no_el );


for (int i=0; i<no_el; i++){

printf("%s\n", ch_arr[i]);
}


//multidim array of chars

//1
struct person{
    
    char fname[30];
    char lname[30];
};

//struct person people[20];
person* people = (person*)malloc(20*sizeof(person));

printf("people[20] size: %d\n", sizeof(people)   );

for ( int i =0; i < 20 ; i++ ){

strcpy( people[i].fname, "WWW");
strcpy( people[i].lname, "Yerteterte");

printf("fname:%s lname:%s\n", people[i].fname, people[i].lname   );
*/


//===================
/*
char ch_off='0'; 
char ch1='1'; 
char ch2='9'; 
char ch3='8'; 


int i = (ch1-ch_off)*100+ (ch2-ch_off)*10 + (ch3-ch_off); 

printf ("result: %d", i );
*/


//=======revert C string =====
/*

char text[] = "ArtetetGdgfg";

//int length = strlen(text);
int length = sizeof(text)/sizeof(char)-1; //because of ending NULL

printf ("text lenght:%d\n", length);
char *p = text+ length-1;

int index = length-1;
while (index >= 0){

printf ("index: %d %c\n",index,*p);
--index; 
--p;

}
*/

//======= XOR swap ======
/*char a='T';
char b='u';

printf("before a=%c b=%c\n", a,b) ;

a=a^b;
b=b^a;
a=a^b;

printf("after a=%c b=%c\n", a,b) ;

*/


//========================
/*int num=234; 


std::bitset<sizeof(num)*8> x(num); 
std::cout<<"decimal: "<< num << " binary: " <<x << std::endl;

int nz_b=0;

for ( int j =0 ; j<sizeof(num)*8; ++j){
   int mask = 1 << j;
   if ( (num & mask) == mask ) ++nz_b ; 

}


printf ("counted non zero bits: %d \n " , nz_b) ;  
*/

//=========set usage=============
/*int myints[] = {20,10,5,40};
std::set<int> myset(myints,myints+4);

for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it){
    printf ("stored values: %d\n", *it);        
}
*/

//=========set usage=============
/*int myints[] = {20,20,10,5,40};

int length = sizeof(myints)/sizeof(int);
printf ("myints lenght:%d\n", length);

std::multiset<int> myset(myints,myints+5);

for (std::multiset<int>::iterator it = myset.begin(); it != myset.end(); ++it){
    printf ("stored values: %d\n", *it);        
}
*/




/*
//msleep(2500) ;
std::string str=  STRINGFY(GPIO) ;
std::cout << str.c_str() << std::endl;

printf ("mt: %d", mt);
*/


/*
FILE *fp; 
fp=fopen("./main.txt", "w+");
fprintf (fp, "uuuuuuuuuuuuuuuuui%d\n", 78);

fputc ('A', fp);
fputc ('\n', fp);
fclose(fp);
*/
/*
int fp ;
fp=open("./main.txt", O_RDWR) ;
if (NULL == fp) perror ("open error");
if ( 0 > write(fp,"Ottt\n",5) ) perror("write error");
close(fp); 
*/




//char* argvv[0];
//argvv[0] = "" ;

/*
char buffer[255];


snprintf(buffer,255L,"BPLOG_%s_LEVEL_%s", "SYSLOG", "YYY");

buffer[256]='\0';
buffer[257]='y';

std::cout << buffer;
*/

//========= array pointer traversal=============
/*
int myints[] = {20,20,10,5,40};
int length = sizeof(myints)/sizeof(int);

int i=1;
int *p = myints; 
while(i<=length){
    printf("%d:%d \n",i, *p);
    ++p;
    ++i;
}
*/



    



}

