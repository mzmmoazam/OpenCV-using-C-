// CPP program to evaluate a given
// expression where tokens are
// separated by space.
#include <bits/stdc++.h>
using namespace std;


static int pow10[10] = {
    1, 10, 100, 1000, 10000,
    100000, 1000000, 10000000, 100000000, 1000000000};


inline bool checkOperator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/' ? 1 : 0;
}


int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == ')')
        return 4;
    if (op == '!' || op == '@' || op == '#')
        return 3;
    return 0;
}

double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '!':
        return sin(a);
    case '@':
        return cos(a);
    case '#':
        return sqrt(a);
        default:
            return 0;

    }
}



double evaluate(string tokens, double x = 0)
{
    int i = 0;

    stack<double> values;

    stack<double> ops;

    while (i < tokens.length())
    {


        if (tokens[i] == ' ')
        {
            i++;
            continue;
        }
        else if (tokens[i] == 'x')
        {
            values.push(x);
            i++;
            continue;
        }


        else if (tokens[i] == '(')
        {
            ops.push(tokens[i]);
        }

        else if (isdigit(tokens[i]) || tokens[i] == '.')
        {
            double val = 0;
            int decimals = 0;
            bool decFlag = false;

            while (i < tokens.length() &&
                   (isdigit(tokens[i]) || tokens[i] == '.'))
            {

                if (decFlag)
                    decimals++;

                if (tokens[i] == '.')
                    decFlag = !decFlag;
                else
                    val = (val * 10) + (tokens[i] - '0');

                i++;
            }
            values.push(val / pow10[decimals]);

            i--;
        }


        else if (tokens[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {

                char op = ops.top();
                ops.pop();

                double val2 = values.top();
                values.pop();
                if (checkOperator(op))
                {
                    double val1 = values.top();
                    values.pop();

                    values.push(applyOp(val1, val2, op));
                }
                else
                {
                    values.push(applyOp(val2, 0, op));
                }
            }

            if (!ops.empty())
                ops.pop();
        }

        else if (checkOperator(tokens[i]))
        {

            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
            {
                char op = ops.top();
                ops.pop();

                double val2 = values.top();
                values.pop();
                if (checkOperator(op))
                {
                    double val1 = values.top();
                    values.pop();

                    values.push(applyOp(val1, val2, op));
                }
                else
                {
                    values.push(applyOp(val2, 0, op));
                }
            }

            ops.push(tokens[i]);
        }

        else
        {
            char sp_Op = '\0';
            if (!tokens.compare(i, 3, "sin"))
            {
                sp_Op = '!';
            }
            else if (!tokens.compare(i, 3, "cos"))
            {
                sp_Op = '@';
            }
            else if (!tokens.compare(i, 4, "sqrt"))
            {
                sp_Op = '#';
            }

            if (sp_Op != '\0')
            {

                while (!ops.empty() && precedence(ops.top()) >= precedence(sp_Op))
                {
                    char op = ops.top();
                    ops.pop();

                    double val2 = values.top();
                    values.pop();
                    if (checkOperator(op))
                    {
                        double val1 = values.top();
                        values.pop();

                        values.push(applyOp(val1, val2, op));
                    }
                    else
                    {
                        values.push(applyOp(val2, 0, op));
                    }
                }

                ops.push(sp_Op);
                i += 2;
            }
        }
        i++;
    }

    while (!ops.empty())
    {
        char op = ops.top();
        ops.pop();

        double val2 = values.top();
        values.pop();
        if (checkOperator(op))
        {
            double val1 = values.top();
            values.pop();

            values.push(applyOp(val1, val2, op));
        }
        else
        {
            values.push(applyOp(val2, 0, op));
        }
    }

    return values.top();
}

int main()
{
    double x = 0.6;

    cout << evaluate("sin(x)*cos(2*x)+2*x*sqrt(.5/(x+1))", x) << " check " << sin(x) * cos(2 * x) + 2 * x * sqrt(.5 / (x + 1)) << "\n";

    return 0;
}
