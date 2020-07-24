// server.c
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctype.h>

#define PORT 8090

int main()
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	char str[100];
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 };

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

		if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}

	valread = read(new_socket, str, sizeof(str));
	int i = 0;
	int l = strlen(str);
	char str1[10];
	printf("\nString sent by client:%s\n", str);

	while(str[i]){
		str1[i] = toupper(str[i]);
		printf("%c", str1[i]);
		i++;
	}

	send(new_socket, str1, sizeof(str1), 0);
	printf("\nModified string sent to client\n");

	return 0;
}
