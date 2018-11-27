

import junit.framework.Assert;
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String[][] urls = new String[10][2];
	   urls[0][0] = "http://www.google.com";
	   urls[1][0] = "https://www.google.com";
	   urls[2][0] = "ftp://www.google.com";
	   urls[3][0] = "ftps://www.google.com";
	   urls[4][0] = "htp://www.google.com";
	   urls[5][0] = "http:/www.google.com";
	   urls[6][0] = "http://wwwgoogle.com";
	   urls[7][0] = "http://www.google.ca:";
	   urls[8][0] = "//www.google.com";
	   urls[9][0] = "www.google.com";
	   
	   urls[0][1] = "true";
	   urls[1][1] = "true";
	   urls[2][1] = "true";
	   urls[3][1] = "true";
	   urls[4][1] = "true";
	   urls[5][1] = "true";
	   urls[6][1] = "true";
	   urls[7][1] = "false";
	   urls[8][1] = "false";
	   urls[9][1] = "true";

	   
	   for (int i = 0; i < 10; i++) {
		   try {
			   if(urlVal.isValid(urls[i][0]) != Boolean.parseBoolean(urls[i][1])) {
				   System.out.println("Test Failed for: " + urls[i][0]);
			   };
			   
		   } catch(Error e)
		   {
			   System.out.println("Error on: " + urls[i][0] + " " + e);
		   }	   
	   } 
	   
	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
