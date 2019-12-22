#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define sendrecvflag 0
File *fp1;
// funtion to clear buffer
void clearBuf(char* b)
{
int i;
for (i = 0; i < 32; i++)
b[i] = '\0';
}
// function for decryption
char Cipher(char ch)
{
return ch ^ 'S';
}
// function to receive file
int recvFile(char* buf, int s)
{
int i;
char ch;
for (i = 0; i < s; i++) {
ch = buf[i];
ch = Cipher(ch);
if (ch == EOF)
return 1;
else{
fp1=fopen("result.txt","a");
fputs(ch,fp1);
fclose(fp1);
fp=fopen("result.txt","a");
fputs(ch,fp);
fclose(fp);fp=fopen("result.txt","a");
fputs(ch,fp);
fclose(fp);fp=fopen("result.txt","a");
fputs(ch,fp);
fclose(fp);printf("%c", ch);
}
}
return 0;
}
// driver code
int main()
{
int sockfd, nBytes;
struct sockaddr_in addr_con;
int addrlen = sizeof(addr_con);
addr_con.sin_family = AF_INET;
addr_con.sin_port = htons(15050);
addr_con.sin_addr.s_addr = inet_addr("127.0.0.1");
char net_buf[32];
FILE* fp;
// socket()
sockfd = socket(AF_INET, SOCK_DGRAM,
0);
if (sockfd < 0)
printf("\nfile descriptor not received!!\n");
else
printf("\nfile descriptor %d received\n", sockfd);
while (1) {
printf("\nPlease enter file name to receive:\n");
scanf("%s", net_buf);
sendto(sockfd, net_buf, 32,
0, (struct sockaddr*)&addr_con,
addrlen);
printf("\n---------Data Received---------\n");
while (1) {
// receive
clearBuf(net_buf);
nBytes = recvfrom(sockfd, net_buf, 32,
0, (struct sockaddr*)&addr_con,
&addrlen);
// process
if (recvFile(net_buf, 32)) {
break;
}
}
printf("\n-------------------------------\n");
}
return 0;
}
