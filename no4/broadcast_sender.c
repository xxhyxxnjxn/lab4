/*20153292 JeongHyeonjin*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define bIP "255.255.255.255"

int main(int argc,char *argv[]){
	int sock;
	struct sockaddr_in bAddr;
	unsigned short bPort;
	char *buf;
	int broadcastPermission;
	unsigned int bufLen;

	if(argc<3){
		fprintf(stderr,"Usage: udp_client %s<SERVER IP> <ECHO STRING>\n",argv[0]);
		exit(1);
	}

	bPort=atoi(argv[1]);
	buf=argv[2];

	if((sock=socket(AF_INET, SOCK_DGRAM,IPPROTO_UDP))<0){
		perror("socket() failed");
		exit(1);
	}

	broadcastPermission=1;
	if(setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void *) &broadcastPermission, sizeof(broadcastPermission))<0){
		perror("setsockopt() failed");
		exit(1);
	}

	memset(&bAddr,0,sizeof(bAddr));
	bAddr.sin_family=AF_INET;
	bAddr.sin_addr.s_addr=inet_addr(bIP);
	bAddr.sin_port=htons(bPort);

	bufLen=strlen(buf);
	if(sendto(sock,buf,bufLen,0,(struct sockaddr *) &bAddr, sizeof(bAddr))!=bufLen){
		perror("Number of bytes transmitted incorrec");
		exit(1);
	}

	return 0;
}
