
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   if (s.empty()) return -1;
   else return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if (s.empty()) return -1;
   int currmin = s.top();
   s.pop();
   int removed = s.top();
   s.pop();
   if (!s.empty()) {
        if (minEle==removed) minEle = s.top();   
   }
   return removed;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if (s.empty()) {
       s.push(x);
       s.push(x);
       minEle = x;
       return;
   }
   if (x>=minEle) {
       s.push(x);
       s.push(minEle);
   }
   else {
       s.push(x);
       minEle = x;
       s.push(x);
   }
}