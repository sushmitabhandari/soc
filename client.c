#include"header.h"
int main()
{
struct sockaddr_in v;
int sfd,len,r;
char s[20],s1[20];
sfd=socket(AF_INET,SOCK_STREAM,0);
if(sfd<0)
{
perror("socket");
return 0;
}
perror("socket");
printf("sfd=%d\n",sfd);


v.sin_family=AF_INET;
v.sin_port=htons(3000);
v.sin_addr.s_addr=inet_addr("127.0.0.1");

len=(sizeof(v));
r=connect(sfd,(struct sockaddr*)&v,len);
if(r<0)
{
perror("connect");
return 0;
}
perror("connect");



while(1)
{
printf("enter data\n");
scanf(" %[^\n]s",s);
write(sfd,s,strlen(s)+1);
//bzero(s,sizeof(s));

read(sfd,s,sizeof(s));
printf("data=%s\n",s);

if(strcmp(s,"bye")==0)
 return 0;
}
}
