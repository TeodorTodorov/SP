#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv []){

char buff[1];
int bytes = 0;
do {

bytes = read(0, buff, 1);
write(1, buff,1);
}
while ( bytes > 0 );












return 0;
}
