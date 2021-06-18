    Difference(int[] arr){
        elements = new int[arr.length];
        for(int i=0; i<arr.length; i++)
            elements[i] = arr[i];
    }

    void computeDifference(){
        int max = 0;
        for(int i=0; i<elements.length; i++){
            for(int j=i+1; j<elements.length; j++){
                int diff = Math.abs(elements[i]-elements[j]);
                if(diff > max)
                    max = diff;
            }
        }
        maximumDifference = max;
    }