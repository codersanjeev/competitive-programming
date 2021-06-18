class Calculator{
    public int power(int x, int y) throws Exception{
        if(x < 0 || y < 0){
            throw new Exception("n and p should be non-negative");
        }
        else{
            return (int)Math.pow(x,y);
        }
    }
}