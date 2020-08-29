ans=1                            //Final answer which will be displayed
  while(b !=0 ) {
     /*Finding the right most digit of ‘b’ in binary form, if it is 1 , then multiply the current value of a  
      in  ans. */
           if(b%2 == 1) {           //as if b%2 == 1,means last /rightmost digit of b in binary form is 1.   
             ans = ans*a ; 
              ans = ans%c;      //at each iteration if value of ans exceeds then reduce it to modulo c. 
           }
   a = a*a;                  // This is explained below
   a %= c;                   //at each iteration if value of a exceeds then reduce it to modulo c. 
   b /= 2;                   //Trim the right-most digit of b in binary form.
}