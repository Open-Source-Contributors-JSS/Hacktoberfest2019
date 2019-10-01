 public static void search(String text, String pattern) 
    { 
        int N = text.length(); 
        int M = pattern.length(); 
  
        //Loop that iterates
        for (int i = 0; i <= N - M; i++) { 
            int j; //checking length
            //check based on the current index if the pattern matches
            for (j = 0; j < M; j++) 
                if (txt.charAt(i + j) != pat.charAt(j)) 
                    break;  //if not equal break the match
              
            if (j == M) //if j of is equal to the length of the pattern 
                System.out.println("Pattern found at index " + i); //then we have found the pattern print it out
        } 
    } 
  
