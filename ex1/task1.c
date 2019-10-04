#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

int fd1 = open(argv[1], O_RDONLY);
int fd2 = open(argv[2], O_WRONLY|O_CREAT,777);

const int size = 512;
int bytes = 0;
char buff[size];
if(fd1< 0 | fd2 <0){
write(2, "error", 5);
return -1;
}
do {
bytes = read(fd1, buff, size);
write(fd2, buff, bytes);

}
while(bytes >0 );

return 0;


}
