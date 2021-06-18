/**
*    Method Name: printArray
*    Print each element of the generic array on a new line. Do not return anything.
*    @param A generic array
**/

public <E> void printArray(E[] arr){
    for(E ele : arr)
        System.out.println(ele);
    
}