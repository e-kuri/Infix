#include "Stack.hpp"
#include <iostream>
#include <string>
#include <map>
#include <math.h>

class EvalInFix{
private:
  string _inFix;
  string _postFix;
  Stack<char> opStack;  
  
  int prcd(char,char);
  bool isOperator(char);
  bool isOperand(char);
  void inFix2PostFix();
  float doOperation(float a, float b, char oprtr);
public:
  float eval(string,float[]);

};

float EvalInFix::eval(string inFix, float values[]){
  _inFix = inFix;
  inFix2PostFix();
  
  cout << _postFix << endl;

  //Implantar...
  
  /*
  //mapa para guardar los valores
  std::unordered_map<char, float> m;
  const char *cPtr = _inFix.c_str(); 
  int index = 0;
  while (*cPtr != '\0') {
      if(isOperand(*cPtr)){
          if(m.find(*cPtr) == unordered_map::end()){
            m[*cPtr] = values[index];
            index++;
          }
      }
      cPtr++;
  }
  
*/

  int valueIndex = 0;
  Stack<float> operandsStack;
  const char* postFix =_postFix.c_str();
  float result;
  while(*postFix != '\0'){
      while(*postFix != '\0' && !isOperator(*postFix)){
          operandsStack.push(values[valueIndex++]);
          postFix++;
      }
      while(*postFix != '\0' && isOperator(*postFix)){
          opStack.push(*postFix);
          postFix++;
      }
      while(!opStack.isEmpty()){
        float a, b; 
        char oprtr;
        operandsStack.pop(a);
        operandsStack.pop(b);
        opStack.removeTail(oprtr);
        operandsStack.push(doOperation(a, b, oprtr));
      }
  }
  operandsStack.pop(result);
  return result;
}

float EvalInFix::doOperation(float a, float b, char oprtr){
    float result;
    switch(oprtr){
        case '+':
            result = a + b;
            break;
        case '-':
            result = a-b;
            break;
        case '*':
            result = a*b;
            break;
        case '/':
            result = a/b;
            break;
        case '$':
            result = pow(b,a);
            break;
    }
    return result;
}

void EvalInFix::inFix2PostFix(){

  const char *cPtr = _inFix.c_str();
  char aux;
  
  while (*cPtr != '\0') {
    if (isOperand(*cPtr)) { _postFix += *cPtr; }
    else if (isOperator(*cPtr)) {
      while (!opStack.isEmpty() && opStack.top() != '(' && prcd(opStack.top(),*cPtr) <= 0) {
        opStack.pop(aux);
        _postFix += aux;
      }
      opStack.push(*cPtr);
    }
    
    else if (*cPtr == '(') { opStack.push(*cPtr); } 
    else if (*cPtr == ')') {
      while (!opStack.isEmpty()) {
        if (opStack.top() == '(') { opStack.pop(aux); break; }
         opStack.pop(aux);
         _postFix += aux;
      }
    }
    
    
    cPtr++;
  }
  
  while (!opStack.isEmpty()) {
     opStack.pop(aux);
     _postFix += aux;
  }
  
}


bool EvalInFix::isOperator(char character) {
    if (character == '+' || character == '-' || character == '*' || character == '/' || character == '$') {
        return true;
    }
    return false;
}



bool EvalInFix::isOperand(char character) {
    if (!isOperator(character) && character != '(' && character != ')') {
        return true;
    }
    return false;
}



int EvalInFix::prcd(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) { return -1; }
    else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) { return 1; }
    return 0;
}
