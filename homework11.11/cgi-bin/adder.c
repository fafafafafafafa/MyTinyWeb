/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"

int main(void) {
    char *buf, *p;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1=0, n2=0;
    char *method;

    method = getenv("REQUEST_METHOD");
    /* Extract the two arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
	p = strchr(buf, '&');
	*p = '\0';
	strcpy(arg1, buf);
	strcpy(arg2, p+1);
	//sscanf(buf, "a=%d", &n1);   //homework 11.10
    //sscanf(p+1, "b=%d", &n2);
    n1 = atoi(arg1);
	n2 = atoi(arg2);
    }

    /* Make the response body */
    sprintf(content, "Welcome to add.com: ");
    sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
    sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", 
	    content, n1, n2, n1 + n2);
    sprintf(content, "%sThanks for visiting!\r\n", content);
  
    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    // method HEAD could be seen as simplify case to method GET, which don't need to return msg body
    if(strcasecmp(method, "HEAD")!=0){
        printf("%s\r\n", content);
        
    }else{
        printf("method HEAD we don't send msg body!");
    }
    fflush(stdout);

    exit(0);
}
/* $end adder */
