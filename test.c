
#include <stdio.h>
// int main(int argc, char **argv)
// 	{
//         t_list *ans;
//         int i;
//         i=0;

//         ans=get_coordinate(argc,argv);
//         while(ans->next==NULL)
//         {
//             printf("ans[%d]: %d",i,ans->num );
//             i++;
//             ans=ans->next;
//         }
// 		return (0);
// 	}

void	argc2_set_str(char *str, char *argv)
{
	int j;

	j = 0;
	if (*argv == '-')
	{
		*str = '-';
		str++;
		argv++;
	}
	while (*argv >= '0' && *argv <= '9' && *argv != '\0')
	{
		*str = *argv;
		str++;
		argv++;
	}
	*str = '\0';
	if (*argv == ' ' && *(argv++) != '\0')
		argv++;
}

int main()
{
    char str[15];
    char argv[15]={"1 2 3 4 5"};
    argc2_set_str(str, argv);
    printf("str:%s\n",str);
}