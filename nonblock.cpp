


/* --------- 将socket由阻塞状态 设置为非阻塞状态 ----------- */
#include <sys/socket.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
    int sfd;
    int old_option;
    int new_option;
/*
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("sfd0 = %d \n\n", sfd);

    old_option = fcntl(sfd, F_GETFL);           // 1   #define	O_NONBLOCK	0x0004	（十进制int型数 4）	// no delay 
    printf("sfd1 = %d \n", sfd);
    printf("o_option1 = %d \n\n", old_option);
    new_option = old_option & O_NONBLOCK;       // new_option等于0，就表明sfd是阻塞套接字；注意：这里使用的是运算符 &；
    printf("sfd2 = %d \n", sfd);
    printf("o_option2 = %d \n", old_option);
    printf("new_option1 = %d\n\n\n", new_option);

    new_option = old_option | O_NONBLOCK;    // 2. 通过系统调用fcntl 实现阻塞套接字变为非阻塞套接字；注意这里使用的是 | 运算符，然后再调用fcntl；
    printf("sfd3 = %d \n", sfd);
    printf("o_option3 = %d \n", old_option);
    printf("new_option2 = %d\n\n", new_option);
    fcntl(sfd, F_SETFL, new_option);        // 将new_option 的值设置给 套接字sfd；
    printf("sfd4 = %d \n", sfd);
    printf("o_option4 = %d \n", old_option);
    printf("new_option3 = %d\n\n\n", new_option);

    old_option = fcntl(sfd, F_GETFL);       // 3    // 获取套接字sfd的flag值，即为上一步设置的new_option;
    printf("sfd5 = %d \n", sfd);
    printf("o_option5 = %d \n", old_option);  // 这个old_option获取的即是上一步new_option的值；
    printf("new_option4 = %d\n\n", new_option);
    new_option = old_option & O_NONBLOCK;   // new_option 不等于0，就表明sfd是非阻塞套接字；
    printf("sfd6 = %d \n", sfd);
    printf("o_option6 = %d \n", old_option);
    printf("new_option5 = %d\n\n\n", new_option);
*/
    /* --------- 实质性代码总结： ----------- */
    int get_flag;
    int status;
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    
    get_flag = fcntl(sfd, F_GETFL);   // 1
    status = get_flag & O_NONBLOCK;
    printf("stat = %d \n", status);   //status用来判断套接字是阻塞，还是非阻塞；这个status很特别，先通过fcntl获取flag，然后再和O_NONBlock进行&运算得到；

    new_option = get_flag | O_NONBLOCK;  // 2
    fcntl(sfd, F_SETFL, new_option);

    get_flag = fcntl(sfd, F_GETFL);     // 3
    status = get_flag & O_NONBLOCK;
    printf("stat = %d \n\n", status);
    
    return 0;
}