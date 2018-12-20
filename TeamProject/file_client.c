
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>




void error_handling(char *message); //에러 헨들링

int main(int argc, char* argv[]){ //입력값 1번은 txt파일, 2번은 IP, 3번은 포트를 받을 예정입니다.


int sock;
 struct sockaddr_in serv_addr;
 char message[1000];  //서버에서에 보낼 메세지를 담을 장소
 int str_len;

 int fd;

 if(argc!=4){
  printf("Usage : %s<txt> <IP> <prot>\n", argv[0]);
  exit(1);
 }// 0번에는 컴파일된 프로그램, 1번은 txt파일, 2번은 IP, 3번은 포트가 입력안되었을 때 프린트해주고 종료?

 sock=socket(PF_INET, SOCK_STREAM, 0);
 if(sock == -1)
  error_handling("socket() error");




 memset(&serv_addr, 0, sizeof(serv_addr));
 serv_addr.sin_family=AF_INET;
 serv_addr.sin_addr.s_addr=inet_addr(argv[2]);
 serv_addr.sin_port=htons(atoi(argv[3]));

//소켓 초기화




 if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
  error_handling("connet() error!");

//커넥트 및 오류처리



 str_len=read(sock, message, sizeof(message)); 

//클라이언트에서 준 내용을 message에 받습니다.


 if(str_len==-1)
  error_handling("read() error!");

//오류 처리




 printf("message from server : %s \n", message);

//메세지 출력




 fd=open(argv[1], O_WRONLY |O_CREAT|O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
 if(fd==-1)
  error_handling("open() error!");
 if(write(fd,message,sizeof(message))==-1)
  error_handling("write() error!");
 close(fd); 

//받은 메세지를 txt에 저장




 close(sock); 

//소켓 닫기?
 return 0;
}

void error_handling(char *message)
{
 fputs(message, stderr);
 fputc('\n', stderr);
 exit(1);

}
