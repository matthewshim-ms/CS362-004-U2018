

import junit.framework.TestCase;
import junit.framework.Random;
//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://www.amazon.com"));

	   assertFalse(urlVal.isValid("http://www.google.com"));
	   assertTrue(urlVal.isValid("http://www.amazon.com"));
	   assertFalse(urlVal.isValid("http://www.maps.google.com"));
	   assertTrue(urlVal.isValid("http://www.oregonstate.edu"));
       assertTrue(urlVal.isValid("http://www.espn.com"));
       assertTrue(urlVal.isValid("https://www.bbc.com"));
       assertTrue(urlVal.isValid("https://www.navy.mil"));
       assertTrue(urlVal.isValid("https://www.energy.gov"));
       assertTrue(urlVal.isValid("http://www.timhortons.ca"));

	   assertFalse(urlVal.isValid("http://www.google.invalidcom"));
       assertFalse(urlVal.isValid(""));

       assertFalse(urlVal.isValid("http://256.256.256.256//"));

   }
   
   public void testYourFirstPartition()
   {
	    UrlValidator urlVal = new UrlValidator();

       assertTrue(urlVal.isValid("https://www.google.com/search?q=google"));
       assertTrue(urlVal.isValid("https://www.reddit.com:800/r/bananas"));
       assertTrue(urlVal.isValid("ftp://www.amazon.com/"));
       assertFalse(urlVal.isValid("tp://134567.123445.12342/123412/1234123"));
       assertFalse(urlVal.isValid("h=[p//reddit800r/bananas"));
       assertFalse(urlVal.isValid("http///test1?action=view"));
   }
   
   public void testYourSecondPartition(){
    	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(urlVal.isValid("http://0.0.0.0"));
        assertTrue(urlVal.isValid("http://amazon.cc"));
        assertTrue(urlVal.isValid("http://amazon.com"));
        assertTrue(urlVal.isValid("http://amazon.com:80"));
        assertTrue(urlVal.isValid("file:///etc"));
        assertTrue(urlVal.isValid("http://www.amazon.com"));
        assertFalse(urlVal.isValid(""));
        assertFalse(urlVal.isValid("4.3.5.2."));
        assertFalse(urlVal.isValid("1.5.7.5.7"));
        assertFalse(urlVal.isValid("3.5.9"));
        assertFalse(urlVal.isValid("am.zn"));
        assertFalse(urlVal.isValid("am.3j"));
        assertTrue(urlVal.isValid("http://amazon.com:0"));
   }
   //You need to create more test cases for your Partitions if you need to 
   
    public void testYourThirdPartition(){
          
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       assertTrue(urlVal.isValid("https://www.google.com/search?q=google"));
       assertTrue(urlVal.isValid("https://www.google.com/search?"));
       assertTrue(urlVal.isValid("https://www.google.com/search?entry=google?mode=poo"));
       assertFalse(urlVal.isValid("https://www.google.com/search??q?::=google"));
       assertFalse(urlVal.isValid("https://www.google.com/search///"));
       assertFalse(urlVal.isValid("https://www.google.com/search.....>>"));
    }

   public void testPathPartition()
   {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(urlVal.isValid("http://www.amazon.com/file"));
        assertTrue(urlVal.isValid("http://www.amazon.com/file/file2"));
        assertTrue(urlVal.isValid("http://www.amazon.com/file/"));
        assertFalse(urlVal.isValid("http://amazon.com/.."));
        assertFalse(urlVal.isValid("http://amazon.com/../file"));
        assertFalse(urlVal.isValid("http://amazon.com/..//file"));
   }

   public void testIsValid()
   {
	   //You can use this function for programming based testing
        System.out.println("****** testIsValid() ********");
        System.out.println("       Programming based testing....");

        String validURL = "";
        String falseURL = "";
        UrlValidator checkTrue;
        UrlValidator checkFalse; 

	   for (int i = 0; i < 10000; i++){

        // random.nextInt() returns random int within specified range (up to the input)
        // source: https://www.geeksforgeeks.org/java-util-random-nextint-java/

        int valid_scheme_num = random.nextInt(5);
        int false_scheme_num = random.nextInt(5);

        int trueAuthorityNum = random.nextInt(7);
        int falseAuthorityNum = random.nextInt(12);

        int validPort = random.nextInt(5);
        int falsePort = random.nextInt(2);

        int truePathNum = random.nextInt(9);
        int false_query_num = random.nextInt(6);
        int valid_query_num = random.nextInt(3);

        // generate Valid URLS
        validURL = validURL_init[valid_scheme_num] + trueTestUrlAuthority[trueAuthorityNum] + validURLport[validPort] + trueTestPath[truePathNum] + trueTestUrlQuery[valid_query_num];

        //generates false urls
        falseURL = falseURL_init[false_scheme_num] + falseTestUrlAuthority[falseAuthorityNum] + falseUrlPort[falsePort] + falseTestPath[false_query_num];

        // Validate if TRUE
        trueValidator = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);

        trueValidator.isValid(trueTestURL);

        // Validate if False 
        falseValidator = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);

        falseValidator.isValid(falseTestURL);

        // test VALID URLS
        System.out.println("=========== VALID URLS =========== ");
        boolean isValidURL = trueValidator.isValid(trueTestURL);

        if (isValidURL) {
            System.out.println("PASS\n");
        } else {
            // if test fails print the count and the particular URL that failed
            System.out.println("*** FAILURE");
            System.out.println("URL: " + trueTestURL);
            System.out.println("Actual: " + trueBugCount + " | Expected: true");
        }

        // test INVALID URLS
        System.out.println("=========== INVALID URLS =========== ");
        boolean isFalseURL = falseValidator.isValid(falseTestURL);
        
        if (!isFalseURL) {
            System.out.println("PASS\n");
        } else {
            System.out.println("URL Fail: " + falseTestURL);
            System.out.println("Actual: " + falseBugCount + " | Expected: false");
        }
    }
	   System.out.println("---------------------------------------------------------");
   }
   
}
