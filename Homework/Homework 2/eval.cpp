//
//  main.cpp
//  No.5
//
//  Created by Gautam Anand on 4/29/23.
//
//declarations of any additional functions you might have written
//         to help you evaluate an expression

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int precedence(char Operator) //order for the precedence of each symbol, default return value is zero
{
    if (Operator == '!')
    {
        return 2;
    }
    else if(Operator == '&')
    {
        return 1;
    }
    else if(Operator == '^')
    {
        return 0;
    }
    return 0;
}
bool convert(string infix, string& postfix) //converts a string fron infix to postfix, if valid return true, if not return false
{
    string infix_nospace = "";
    for(int z = 0; z < infix.length(); z++)
    {
        if(infix[z] != ' ')
        {
            infix_nospace += infix[z]; //create a string without spaces
        }
    }
    postfix = "";
    stack<char> operatorStack;
    while(!operatorStack.empty())//want to clear up th eoperatorStack before doing anythign with it.
    {
        operatorStack.pop();
    }
    for(int i = 0; i < infix_nospace.length(); i++) //for every element in the infix with no spaces, do something, depending on the case
    {
        switch (infix_nospace[i])
        {
            case 'T':
            case 'F':
                postfix += infix_nospace[i]; //add to postfix, if case true or false chars
                break;
            case '(':
            {
                if(infix_nospace[i+1] == ')') //check if there is nothign inside a paranthesis, if so return false
                {
                    return false;
                }
                    
                operatorStack.push(infix_nospace[i]);
                break;
            }
            case ')':
            {
                if(infix_nospace[i] == ')' && operatorStack.empty()) //check if first element in the array is ), or if there are no matching parantheses
                {
                    return false;
                }
                while(operatorStack.top() != '(')
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                    if(operatorStack.empty())
                    {
                        return false;
                    }
                }
                if(!operatorStack.empty())
                operatorStack.pop();
                break;
            }
                
            case '&':
            case '^':
                if(infix_nospace[0] ==  '^' || infix_nospace[0] == '&') //check if & or ^ are the first operator in the infix string, if so return false
                {
                    return false;
                }
                if(!operatorStack.empty() && operatorStack.top() == '(' && (infix_nospace[i-1] != 'T' && infix_nospace[i-1] != 'F')) //check if there is a letter before the ^ and & operator, if not return false;
                {
                    return false;
                }
            case '!':
                while(!operatorStack.empty() && operatorStack.top() != '(' && precedence(infix_nospace[i]) < precedence(operatorStack.top()))
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                if(infix_nospace[i] == '!' && (i == infix_nospace.length() ||infix_nospace[i+1] == ')' ))
                {
                    return false; //check if ! is the last item in the string, or if its before a closing parantheses, if so return false;
                }
                operatorStack.push(infix_nospace[i]);
                break;
            case ' ':
                break;
                
            default:
                return false;
        }
    }
   while(!operatorStack.empty()) //pop off all the operators into the postfix while the stack is not empty.
   {
       postfix+=operatorStack.top();
       operatorStack.pop();
   }
    return true;
}
char apply_operator(char operand1, char operand2, char oper) //helper function that does the operation for you, and returns '0' if invalid arguments/input was passed
{
    if((operand1 != 'T' && operand1 != 'F') || ( operand2 != 'T' && operand2 != 'F'))
    {
        return '0';
    }
    if(oper == '&')
    {
        if(operand1 == 'T' && operand2 == 'T')
        {
            return 'T';
        }
        else
            return 'F';
    }
    else if(oper == '^')
    {
        if(operand1 != operand2)
        {
            return 'T';
        }
        else
            return 'F';
    }
    return '0';
}
 int evaluate(string infix, string& postfix, bool& result) //evaluates the expression
 {
     if(!convert(infix, postfix))
     {
         result = false; //return false if not able to convert properly
         return 1;
     }
     stack<char> operandStack; //create a stack
     while(!operandStack.empty())
     {
         operandStack.pop();//make sure stack is empty
     }
     for(int i = 0; i < postfix.length(); i ++)
     {
         if(postfix[i] == 'T' || postfix[i] == 'F') //push onto the operand stack
         {
             operandStack.push(postfix[i]);
         }
         else
         {
             if(postfix[i] == '!') // special case if the opeartor is !
             {
                 if(operandStack.empty())
                 {
                     result = false;
                     return 1;
                 }
                 char operand_exc = operandStack.top();
                 operandStack.pop();
                 if(operand_exc=='T') //evaluate the expression
                 {
                     operandStack.push('F');
                 }
                 else if(operand_exc == 'F')
                 {
                     operandStack.push('T');
                 }
                 else
                 {
                     result = false;
                     return 1;
                 }
                 
             }
             else //operator is & or ^
             {
                 if(operandStack.empty())
                 {
                     result = false;
                     return 1;
                 }
                 char operand2 = operandStack.top();
                 operandStack.pop();
                 if(operandStack.empty())
                 {
                     result = false;
                     return 1;
                 }
                 char operand1 = operandStack.top();
                 operandStack.pop();
                 char c = apply_operator(operand1, operand2, postfix[i]);
                 if(c == '0')
                 {
                     result = false; // if opeartor can't be applied properly then result false, and return 1
                     return 1;
                 }
                 operandStack.push(c); //push operator onto the stack
             }
            

         }
     }
     if(operandStack.size() == 1) //check if there is only one element in teh operand stack
     {
         if(operandStack.top() == 'T') //if t return t and result is true
         {
             result = true;
         }
         else
         result = false; //else return false, and return 0 since the postfix was valid
         return 0;
     }
     
     else //else return 1, and result = false
     {
         result = false;
         return 1;
     }
 }



int main() {

    string pf;
           bool answer;
           assert(evaluate("T^ F", pf, answer) == 0  &&  pf == "TF^"  &&  answer);
           assert(evaluate("T^", pf, answer) == 1);
           assert(evaluate("F F", pf, answer) == 1);
           assert(evaluate("TF", pf, answer) == 1);
           assert(evaluate("()", pf, answer) == 1);
           assert(evaluate("()T", pf, answer) == 1);
           assert(evaluate("T(F^T)", pf, answer) == 1);
           assert(evaluate("T(&T)", pf, answer) == 1);
           assert(evaluate("(T&(F^F)", pf, answer) == 1);
           assert(evaluate("T|F", pf, answer) == 1);
           assert(evaluate("", pf, answer) == 1);
           assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0
                                  &&  pf == "FF!TF&&^"  &&  !answer);
           assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
           assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
           cout << "Passed all tests" << endl;
}
