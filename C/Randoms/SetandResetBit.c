#define RESET  0
#define SET    1
#define TOGGLE 2

static void SetBit(int *num, int bit)
{
    *num |= (1 << bit);
}

static void ResetBit(int *num, int bit)
{
    *num &= ~(1 << bit);
}

static void toggleBit(int *num, int bit)
{
    *num ^= (1 << bit);
}

void SetandResetBit(int *Num, int Bit, int SetResetToggle)
{
    switch (SetResetToggle)
    {
    case SET:
        SetBit(Num, Bit);
        break;

    case RESET:
        ResetBit(Num, Bit);
        break;

    case TOGGLE:
        toggleBit(Num, Bit);
        break;

    default:
    /*INVALID*/
        break;
    }
}

/*
int main()
{
    int x=5; // 0101
    int bit=1; //
    SetandResetBit(&x, 0, 2);
    printf("%d\n",x);
    return 0;
}
*/