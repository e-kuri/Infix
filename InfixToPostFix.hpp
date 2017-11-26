#include "Stack.hpp"
#include <iostream>
#include <string>


class InfixToPostFix{
  Stack<char> opStack;  
  int prcd(char,char);
  bool isOperator(char);
  bool isOperand(char);
public:
  void infix2PosFix(string, string&);
};


void InfixToPostFix::infix2PosFix(string inFix, string & postFix){

  const char *cPtr = inFix.c_str();
  char aux;
  
  while (*cPtr != '\0') {
    if (isOperand(*cPtr)) { postFix += *cPtr; }
    else if (isOperator(*cPtr)) {
      while (!opStack.isEmpty() && opStack.top() != '(' && prcd(opStack.top(),*cPtr) <= 0) {
        opStack.pop(aux);
        postFix += aux;
      }
      opStack.push(*cPtr);
    }
    
    else if (*cPtr == '(') { opStack.push(*cPtr); } 
    else if (*cPtr == ')') {
      while (!opStack.isEmpty()) {
        if (opStack.top() == '(') { opStack.pop(aux); break; }
         opStack.pop(aux);
         postFix += aux;
      }
    }
    
    
    cPtr++;
  }
  
  while (!opStack.isEmpty()) {
     opStack.pop(aux);
     postFix += aux;
  }
  
}


bool InfixToPostFix::isOperator(char character) {
    if (character == '+' || character == '-' || character == '*' || character == '/') {
        return true;
    }
    return false;
}



bool InfixToPostFix::isOperand(char character) {
    if (!isOperator(character) && character != '(' && character != ')') {
        return true;
    }
    return false;
}



int InfixToPostFix::prcd(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) { return -1; }
    else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) { return 1; }
    return 0;
}
