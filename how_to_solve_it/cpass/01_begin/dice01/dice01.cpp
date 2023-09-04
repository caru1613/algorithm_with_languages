#if 1

#include <iostream>

using namespace std;

#define MAX 5

int stack[MAX], top;

bool empty()
{
    return top == 0;
}

bool full()
{
    return top == MAX;
}

void push(int val)
{
    if (full())
    {
        cout << "Full" << endl;
        return;
    }

    stack[top++] = val;
}

void pop()
{
    if (empty())
    {
        cout << "Empty" << endl;
        return;
    }

    --top;
}

int get_top_index()
{
    return top;
}

int get_top_val()
{
    return stack[top-1];
}

bool check_in_order()
{
    for(int i = 0; i < top; i++)
    {
        for(int j = i+1; j < top; j++)
        {
            if (stack[i] > stack[j]) 
            {
                return false;
            }
        }
    }

    return true;
}

bool check_duplicated()
{
    for(int i = 0; i < top; i++)
    {
        for(int j = i+1; j < top; j++)
        {
            //cout << stack[i] <<  ":" << stack[j] << endl;
            if (stack[i] == stack[j]) 
            {
                return true;
            }
        }
    }

    return false;
}

void print_stack_val()
{
    for(int i = 0; i < top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void dice_01(int N)
{
    if (N == 0)
    {
        print_stack_val();
        return;
    }

    for( int i = 1; i <= 6; i++)
    {
        push(i);
        dice_01(N-1);
        pop();
    }
}

void dice_02(int N)
{
    if (N == 0)
    {
        if (check_in_order())
            print_stack_val();
        return;
    }

    for( int i = 1; i <= 6; i++)
    {
        push(i);
        dice_02(N-1);
        pop();
    }
}

void dice_03(int N)
{
    if (N == 0)
    {
        if (!check_duplicated())
        {
            //cout << "Not duplicated" << endl;
            print_stack_val();
        }
#if 0
        else
        {
           // cout << "duplicated" << endl;
        }
#endif
        return;
    }

    for( int i = 1; i <= 6; i++)
    {
        push(i);
        dice_03(N-1);
        pop();
    }
}


int main()
{
    int N, M;

    cin >> N >> M;
    switch (M)
    {
    case 1:
        for (int i = 1; i <= 6; i++)
        {
            push(i);
            dice_01(N-1);
            pop();
        }
        break;
    case 2:
        for (int i = 1; i <= 6; i++)
        {
            push(i);
            dice_02(N-1);
            pop();
        }
        break;
    case 3:
        for (int i = 1; i <= 6; i++)
        {
            push(i);
            dice_03(N-1);
            pop();
        }
        break;
    default:
        break;
    }
    
    return 0;
}


#else

#include <cstdio>
#include <iostream>

using namespace std;

int arr[10] = {1}, N, M;
int chk[10];

void output()
{
    for (int i = 1; i <= N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void dice1(int step)
{
    if (step > N)
    {
        output();
        return;
    }

    for (int i = 1; i <= 6; i++) {
        arr[step] = i;
        dice1(step+1);
    }
}

void dice2(int step)
{
    if (step > N)
    {
        output();
        return;
    }

    for (int i = arr[step-1]; i <= 6; i++) {
        arr[step] = i;
        dice2(step+1);
    }
}

void dice3(int step)
{
    if (step > N)
    {
        output();
        return;
    }

    for (int i = 1; i <= 6; i++) {
        if(chk[i] == 1)
            continue;
        chk[i] = 1;
        arr[step] = i;
        dice3(step+1);
        chk[i] = 0;
    }
}

int main()
{
    scanf("%d%d", &N, &M);

    if(M == 1)
        dice1(1);
    else if (M == 2)
        dice2(1);
    else
        dice3(1);

    return 0;
}

#endif
