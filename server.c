#include"header.h"
int main()
{
struct sockaddr_in v,v1;
int sfd,len,r,nsfd,i=0;
char s[20];
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
v.sin_addr.s_addr=inet_addr("172.31.39.12");

len=(sizeof(v));
r=bind(sfd,(struct sockaddr*)&v,len);
if(r<0)
{
perror("bind");
return 0;
}
perror("bind");

listen(sfd,5);
perror("listen");


nsfd=accept(sfd,(struct sockaddr*)&v1,&len);
if(nsfd<0)
{
perror("accept");
return 0;
}
perror("accept");

while(1)
{
read(nsfd,s,sizeof(s));
printf("data=%s\n",s);

/*for(i=0;s[i];i++)
{
if(s[i]>='a'&& s[i]<='z')
s[i]=s[i]-32;
}*/
if(strcmp(s,"bye")==0)
 return 0;
printf("enter data\n");
scanf(" %[^\n]s",s);
write(nsfd,s,strlen(s)+1);
}
}

