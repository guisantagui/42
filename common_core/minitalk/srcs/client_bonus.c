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
    static int bit;
    static unsigned int buffer;

    if (sig == SIGUSR1)
        buffer |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", (unsigned char)buffer);
        bit = 0;
        buffer = 0;
    }
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
    signal(SIGUSR2, handler);
    signal(SIGUSR1, handler);
    if (argc == 3)
        send_argv(argv);
    return (0);
}