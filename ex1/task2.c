#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int args, char* argv [] ) {

const int size = 512;
int bytes = 0;
for( int i = 1; i <args; i++ ){

int fd1 = open( argv[i], O_RDONLY);
char buff [size];
if ( fd1< 0 ) {

write(2, "error", 5);
}
do {
bytes = read(fd1, buff, size);
write(1, buff, bytes);
}
while (bytes >0);
}
return 0;
}
