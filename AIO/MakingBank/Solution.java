/*
 * Solution Template for Making Bank
 * 
 * Australian Informatics Olympiad 2023
 * 
 * This file is provided to assist with reading and writing of the input
 * files for the problem. You may modify this file however you wish, or
 * you may choose not to use this file at all.
 */

 import java.io.*;

 class Solution {
 
     /* N is the number of days. */
     private static int N;
 
     /* days contains the type of each day. */
     private static char days[] = new char[100005];
 
     private static int answer;
     /*
      * Read the next token from the input file.
      * Tokens are separated by whitespace, i.e., spaces, tabs and newlines.
      * If end-of-file is reached then an empty string is returned.
      */
     private static String readToken(BufferedReader in) throws IOException {
         StringBuffer ans = new StringBuffer();
         int next;
 
         /* Skip any initial whitespace. */
         next = in.read();
         while (next >= 0 && Character.isWhitespace((char)next))
             next = in.read();
 
         /* Read the following token. */
         while (next >= 0 && ! Character.isWhitespace((char)next)) {
             ans.append((char)next);
             next = in.read();
         }
 
         return ans.toString();
     }
 
     public static void main(String[] args) throws IOException {
         /* Open the input and output files. */
         BufferedReader input_file = new BufferedReader(new FileReader(
                 "bankin.txt"));
         BufferedWriter output_file = new BufferedWriter(new FileWriter(
                 "bankout.txt"));
 
         /*
          * Read the value of N and the string of characters from the input file.
          */
         N = Integer.parseInt(readToken(input_file));
         days = readToken(input_file).toCharArray();
 
         /*
          * TODO: This is where you should compute your solution. Store the most
          * money that you can retire with into the variable answer.
          */
        
          int skill = 1;
          int curBank = 0;
        for(int i = 0; i < N; i++){
            if(days[i] == 'C'){
                skill++;
            }else{
                curBank += skill;
            }
            answer = Math.max(answer, curBank + (N-i-1)*skill);
        }

 
         /* Write the answer to the output file. */
         output_file.write(answer + "\n");
 
         /* Finally, close the input/output files. */
         input_file.close();
         output_file.close();
     }
 }