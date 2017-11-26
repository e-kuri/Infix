#include "EvalInFix.hpp"

int main()
{
	//InfixToPostFix itop;
    EvalInFix ifx;
    float values[] = {2.4,5.6,4.8,2.0};

    //string s1 = "A*(B+C*D)+E";
    string s1 = "A*(B+C)";
    cout << endl;
    cout << ifx.eval(s1, values) << endl;
    //string s2 ;

    //itop.infix2PosFix(s1,s2);
    //cout << s2 << endl;
	return 0;
}
