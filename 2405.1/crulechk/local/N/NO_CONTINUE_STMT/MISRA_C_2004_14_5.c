// @checker NO_CONTINUE_STMT

int main()
{
	int i;

	for(i = 0; i < 10; i++)  
	{
		if(i == 5)
		{
			continue;	//@violation NO_CONTINUE_STMT         
		}
	}
}

	