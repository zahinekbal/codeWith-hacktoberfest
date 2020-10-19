main()
{
    int high = 100000;
    int low = 0;
    int guess = 1;
    int myguess;
    char reply;

    printf("The Game of 20 Questions\n");
    printf("Think of a number between 0 and %d\n", high);

    while (high > low)
    {
        /* make a guess */
	myguess = (high + low) / 2;
        printf("Guess #%d: Is your number higher than %d? ", 
	   guess++, myguess, high, low);

	/* get your response */
        scanf(" %c",&reply);

        if (reply == 'y')
	    low = myguess = myguess + 1;
	else
	    high = myguess;
    }
    printf("Your number is %d!\n", myguess);
}
