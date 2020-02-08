// codeup 1918
#include <string>
#include <stack>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
using namespace std;

struct Element
{
    string value;
    bool isSign;
};

map<char, int> signs = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};

float calculate(float first, float second, char sign)
{
    if (sign == '+')
    {
        return first + second;
    }
    else if (sign == '-')
    {
        return first - second;
    }
    else if (sign == '*')
    {
        return first * second;
    }
    else if (sign == '/')
    {
        return first / second;
    }
}

float calPostEquation(queue<Element> q)
{
    stack<float> st;
    while (!q.empty())
    {
        Element top = q.front();
        q.pop();
        if (!st.empty() and top.isSign)
        {
            float second = st.top();
            st.pop();
            float first = st.top();
            st.pop();
            st.push(calculate(first, second, *top.value.c_str())); // should use *
        }
        else
        {
            st.push(stof(top.value));
        }
    }

    return st.top();
}

queue<Element> buildPostEuqation(vector<Element> &equation)
{
    queue<Element> post;
    stack<Element> st;
    for (int i = 0; i < equation.size(); i++)
    {
        if (equation[i].isSign)
        {
            if (!st.empty() and signs.find(*equation[i].value.c_str())->second <= signs.find(*st.top().value.c_str())->second)
            {
                while (!st.empty() and signs.find(*equation[i].value.c_str())->second <= signs.find(*st.top().value.c_str())->second) // clear all signs should have higher priority: 1. */ 2. +- in the front
                {
                    post.push(st.top());
                    st.pop();
                }
            }
            st.push(equation[i]);
        }
        else
        {
            post.push(equation[i]);
        }
    }

    while (!st.empty())
    {
        post.push(st.top());
        st.pop();
    }

    return post;
}

float simpleCalculator(string equation)
{
    // Test cases:
    // 1+3*5/4*8/9*6*2/3/7+3*8/2    = 14.90
    // 12+78/4*6*7/3-12-13-24*25/63 = 160.00
    // 12+781/19*6*7/13-24*25/63    = 135.28
    // 985211*985/211               = 4599207.50
    // 2/3*4                        = 2.67
    // 2*3/49                       = 0.12
    // 5+2*3/49-4/13                = 4.81
    vector<Element> elements;
    string current = "";
    for (int i = 0; i < equation.size(); i++)
    {
        if (signs.find(equation[i]) != signs.end())
        {
            elements.push_back(Element{current, false});
            current = ""; // clear buffed number after push to array
            elements.push_back(Element{string{equation[i]}, true});
        }
        else
        {
            current += equation[i];
        }
    }
    elements.push_back(Element{current, false});

    return calPostEquation(buildPostEuqation(elements));
}

int main()
{
    string input;
    cin >> input;                     // 30/90-26+97-5-6-13/88*6+51/29+79*87+57*92
    cout << fixed << setprecision(2); // set precision to 2
    while (input != "0")
    {
        cout << simpleCalculator(input) << endl; // 12178.21
        cin >> input;
    }
    return 0;
}