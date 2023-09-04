#if 0

#include <iostream>

using namespace std;

#define MAX 10 

int stack[MAX], top;

int N, M;

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

bool check_sum_matched()
{
    int sum = 0;

    for(int i = 0; i < top; i++)
    {
        sum += stack[i];
    }

    if (sum == M)
        return true;

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

void dice_04(int N)
{
    if (N == 0)
    {
        if (check_sum_matched())
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
        dice_04(N-1);
        pop();
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= 6; i++)
    {
        push(i);
        dice_04(N-1);
        pop();
    }
    
    return 0;
}


#else

#include <cstdio>
#include <iostream>

using namespace std;

int arr[10], N, M;

void output()
{
    for (int i = 1; i <= N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void dice(int step, int sum)
{
    if (step > N)
    {
        if (sum == M)
            output();
        return;
    }
    else if (sum > M)
    {
        return;
    }
    else
    {
        for (int i = 1; i <= 6; i++)
        {
            arr[step] = i;
            dice(step+1, sum +i);
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);

    dice(1, 0);

    return 0;
}

#endif
