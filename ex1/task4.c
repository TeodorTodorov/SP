#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv []){



int sw = 0;
// switch 0 or 2*n for writing to file
// switch 1 or 2*n+1 for writing to standart output
int bytes = 0;
char buff[1];
int fd = open( argv[1], O_WRONLY|O_CREAT);
if(fd < 0 )
{
write(2, "error", 5);
return 1;
}

do{

bytes = read(0,buff,1);
if (sw == 0 ) {
write(fd, buff, 1 );
if ( buff[0] == '\n'){

sw = 1;
}


}
else if (sw == 1 ) {

write(1, buff, 1);
if(buff[0] == '\n')
{
sw = 0;
}
}

}

while(bytes >0);







return 0;
}
