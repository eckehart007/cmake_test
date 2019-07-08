// test.cpp

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#ifdef WINDOWS
	#define _WINSOCK_DEPRECATED_NO_WARNINGS
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#pragma comment(lib, "WS2_32.lib")
	#pragma comment(lib, "wsock32.lib")
#else
	#include <sys/socket.h>
	#include <netdb.h>
	#include <arpa/inet.h>
#endif




int main(int argc, char *argv[]) {
    printf("Startup\r\n");

    
#ifdef WINDOWS
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) {
		fprintf(stderr, "WSAStartup failed.\n");
		exit(1);
	}
#endif

	int status;
	struct addrinfo hints;
	struct addrinfo *servinfo;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	//hints.ai_flags = AI_PASSIVE;

	if ((status = getaddrinfo("www.hotmail.com", NULL, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		exit(1);
		freeaddrinfo(servinfo);
	}
	char ipstr[INET6_ADDRSTRLEN];
	void *addr;
	char *ipver;
	struct sockaddr_in *ipv4 = (struct sockaddr_in *)servinfo->ai_addr;
	addr = &(ipv4->sin_addr);
	inet_ntop(servinfo->ai_family, addr, ipstr, sizeof ipstr);
	printf("%s\r\n", ipstr);


#ifdef WINDOWS	
	WSACleanup();
#endif	
    return(0);

}
