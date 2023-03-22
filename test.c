

int main(int argc, char **argv)
	{
        t_list *ans;
        int i;
        i=0;
        
        ans=get_coordinate(argc,argv);
        while(ans->next==NULL)
        {
            printf("ans[%d]: %d",i,ans->num );
            i++;
            ans=ans->next;
        }
		return (0);
	}