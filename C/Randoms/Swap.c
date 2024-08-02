void Swap(int *Num1, int *Num2)
{
    int temp = *Num1;
    *Num1    = *Num2;
    *Num2    = temp;
}

void Swap_Pointers(int **ptr_Num1, int **ptr_Num2)  
{
    int *temp = *ptr_Num1;
    *ptr_Num1  = *ptr_Num2;
    *ptr_Num2  = temp;
}
/*
int main()
{
    int x=55, y=11;
    int *ptrX = &x, *ptrY = &y;

    printf("x=%d, y=%d\n",x,y);
    printf("ptrX=%d, ptrY=%d\n",*ptrX,*ptrY);

    Swap(&x,&y);
    Swap_Pointers(&ptrX,&ptrY);
    
    printf("x=%d, y=%d\n",x,y);
    printf("ptrX=%d, ptrY=%d\n",*ptrX,*ptrY);
    return 0;
}
*/