#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

#define BUF_SIZE 10000




void error_handling(char *message);




int main(int argc, char *argv[]) // txt파일, 포트를 입력받습니다.
{
 int serv_sock;
 int clnt_sock;
   
 struct sockaddr_in serv_addr;
 struct sockaddr_in clnt_addr;
 socklen_t clnt_addr_size;

 int fd;
 char buf[BUF_SIZE];
 
 fd=open(argv[1], O_RDONLY);
 if( fd==-1 )
  error_handling("open() error!");
 if( read(fd,buf,sizeof(buf))==-1)
  error_handling("read() error!");
 close(fd);

//txt파일에서 적혀있는 문자들을 받아옵니다.




 if(argc!=3){
  printf("Usage : %s<txt>  <port>\n", argv[0]);
  exit(1);
 }

//커맨드라인에서 제대로 못 받았을 경우 종료.
 
 serv_sock=socket(PF_INET, SOCK_STREAM, 0);
 if(serv_sock == -1)
  error_handling("socket() error");




 memset(&serv_addr, 0, sizeof(serv_addr));
 serv_addr.sin_family=AF_INET;
 serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
 serv_addr.sin_port=htons(atoi(argv[2]));

// 소켓 초기화




 if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
  error_handling("bind() error");

//바인딩 및 오류처리




 if(listen(serv_sock, 5)==-1)
  error_handling("listen() error");

//리슨(대기상태) 및 오류처리




 clnt_addr_size=sizeof(clnt_addr);
 clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);
 if(clnt_sock==-1)
  error_handling("accept() error");

//클라이언트와 접속 및 실패시 오류


 write(clnt_sock, buf, sizeof(buf));

//buf에 저장되있던 내용은 클라이언트에 보냅니다


 close(clnt_sock);
 close(serv_sock);

//모든 소켓 닫기
 return 0;
}

void error_handling(char *message)
{
 fputs(message, stderr);
 fputc('\n',stderr);
 exit(1);
}
