#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv [] ){

int printLines = 0;
int printBytes = 0;
int printWords = 0;
for ( int i = 0; i < strlen(argv[1]) ; i++ ){

if( argv[1][i] == 'l') {

printLines = 1;
}
else if ( argv[1][i] == 'w'){
printWords = 1;
}
else if ( argv[1][i] == 'c'){

printBytes = 1;
}

}

for(int i = 2; i < argc; i++){
int totalBytes = 0;
int totalLines = 0;
int totalWords = 0;
int wd = 0;

// if wd = 0 means  prev char is space of new line or begging of files
// if wd is 1 means previous char is not devider
int fd1 = open( argv[i] , O_RDONLY);
if ( fd1 < 0 ) {
write(2, "error", 5);
return 0;
}
const int size = 512;
char buff [512];
int bytes = 0;
do {

bytes = read(fd1, buff , size);
totalBytes += bytes;

for(int i = 0; i < bytes; i++ ){
if ( buff[i] == ' ' ) {
if ( wd == 1){
totalWords++;
wd = 0;
}
}
else if ( buff[i]== '\n'){
if ( wd == 1 ) {
wd = 0 ;
totalWords++;
}
totalLines++;
}
else if ( buff[i] != ' ' && buff[i] != '\n'){
wd = 1;
}
}
}
while( bytes > 0);
printf("%s", argv[i]);
printf(": ");
if ( printLines > 0 ){
printf("%d", totalLines);
printf(" ");
}
if ( printWords > 0 ) {
printf("%d" , totalWords);
printf(" ");
}
if ( printBytes > 0 ) {
printf("%d", totalBytes);
printf("\n");

}
}
return 0;
}
