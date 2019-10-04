#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main( int argc, char* argv []){

int fd1 = open( argv[1], O_RDONLY);
int fd2 = open( argv[2], O_WRONLY|O_CREAT, 777);
if ( fd1 < 0 | fd2 <0){

write(2, "error", 5);

}
int bytes = 0;
char buff [1];
char line [62];
char newLine[1] ;
newLine[0] = '\n';
char longestDigitSequence [62];
int longestDigitSeqFreePosPointer = 0;
int  LineLastPointer= 0;
int insert = 1;
// insert is 1 if we have not start seq
// insert is 0 if we started a seq

do {

bytes = read(fd1, buff, 1);
if ( bytes > 0 ){
line[LineLastPointer] = buff[0];
LineLastPointer++;
if ( buff[0] == '\n'){
	
	if(line[LineLastPointer - 2] == '$'){
		write(1, line, LineLastPointer );
	}
	else {
		for( int i = 0; i < LineLastPointer; i++){
			if(insert == 1 && line[i] <= '9' && line[i] >= 0){
			insert = 0;
			}
			if ( insert == 0 && line[i] <='9' && line[i] >= 0 ){
			longestDigitSequence[longestDigitSeqFreePosPointer] = line[i];
			longestDigitSeqFreePosPointer++;

			}
			else if ( insert == 0 && !(line[i] <='9' && line[i] >=0)) {
				insert = 3;

			}
			}
		 write( fd2, longestDigitSequence, longestDigitSeqFreePosPointer  );
			write(fd2, newLine, 1);
		} 

	
longestDigitSeqFreePosPointer = 0;
LineLastPointer = 0;

insert = 1;
}

}


}
while(bytes >0);



return 0;
}
