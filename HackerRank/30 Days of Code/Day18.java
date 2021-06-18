public class Solution {
    Stack<Character> stackVariable = new Stack<>();
    Queue<Character> queueVariable = new LinkedList<>();
    
    void pushCharacter(char ch){
        stackVariable.push(ch);
    }
    
    void enqueueCharacter(char ch){
        queueVariable.add(ch);
    }
    
    char popCharacter(){
        return stackVariable.pop();
    }
    
    char dequeueCharacter(){
        return queueVariable.remove();
    }