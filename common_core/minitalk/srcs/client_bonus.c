#include "../ft_printf/ft_printf.h"
#include "../ft_printf/libft/libft.h"
#include <signal.h>

void    send_char(int pid, unsigned char oct)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if ((oct & (1 << bit)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        bit++;
        usleep(1000);
    }
}

void    handler(int sig)
{
    if (sig == SIGUSR1)
        ft_printf("\033[0;32mMessage received!\033[0m\n");
}

void    send_argv(char **argv)
{
    int pid;
    int i;

    pid = ft_atoi(argv[1]);
    i = 0;
    while (argv[2][i])
    {
        send_char(pid, (unsigned char)argv[2][i]);
        i++;
    }
    send_char(pid, (unsigned char)'\n');
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        signal(SIGUSR2, handler);
        signal(SIGUSR1, handler);
        send_argv(argv);
    }
    return (0);
}