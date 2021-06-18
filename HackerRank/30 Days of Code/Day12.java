class Student extends Person
{
	private int[] testscores;
    Student(String firstName, String lastName ,int id, int testScores[])
    {
        super(firstName,lastName,id);
        testscores= new int [testScores.length];
        for(int i=0;i<testScores.length;i++)
            testscores[i]=testScores[i];
    }
    char calculate()
    {   int avg=0;
        for(int i=0;i<testscores.length;i++)
            avg+=testscores[i];
         avg=avg/testscores.length;
        return(avg> 89 ?'O': avg>79 ? 'E' : avg > 69 ? 'A' : avg > 54 ? 'P' :avg > 39 ? 'D' : 'T' );
    }
}