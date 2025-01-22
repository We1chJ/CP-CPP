// /*
//  * Solution Template for Shoptimality
//  * 
//  * Australian Informatics Olympiad 2023
//  * 
//  * This file is provided to assist with reading and writing of the input
//  * files for the problem. You may modify this file however you wish, or
//  * you may choose not to use this file at all.
//  */

// import java.io.*;
// import java.util.ArrayList;


// class Solution {
//     /* N is the number of houses. */
//     private static int N;

//     /* M is the number of supermarkets. */
//     private static int M;

//     /*
//       * H contains the locations of the houses. Note that here the houses are
//       * numbered starting from 0.
//      */
//     private static int H[] = new int[100005];

//     /*
//       * S contains the locations of the supermarkets. Note that here the
//       * supermarkets are numbered starting from 0.
//      */
//     private static int S[] = new int[100005];

//     /*
//       * P contains the price factors of the supermarkets. Note that here the
//       * supermarkets are numbered starting from 0.
//      */
//     private static int P[] = new int[100005];

//     /*
//       * answers[i] should store the badness of the best supermarket for the i-th
//       * house. Note that here the houses are numbered starting from 0.
//      */
//     private static int answers[] = new int[100005];

//     /*
//       * Read the next token from the input file.
//       * Tokens are separated by whitespace, i.e., spaces, tabs and newlines.
//       * If end-of-file is reached then an empty string is returned.
//      */
//     private static String readToken(BufferedReader in) throws IOException {
//         StringBuffer ans = new StringBuffer();
//         int next;

//         /* Skip any initial whitespace. */
//         next = in.read();
//         while (next >= 0 && Character.isWhitespace((char) next)) {
//             next = in.read();
//         }

//         /* Read the following token. */
//         while (next >= 0 && !Character.isWhitespace((char) next)) {
//             ans.append((char) next);
//             next = in.read();
//         }

//         return ans.toString();
//     }

//     public static void main(String[] args) throws IOException {
//         /* Open the input and output files. */
//         BufferedReader input_file = new BufferedReader(new FileReader(
//                 "shopin.txt"));
//         BufferedWriter output_file = new BufferedWriter(new FileWriter(
//                 "shopout.txt"));

//         /* Read the values of N, M, H, S and P from input file. */
//         N = Integer.parseInt(readToken(input_file));
//         M = Integer.parseInt(readToken(input_file));
//         for (int i = 0; i < N; i++) {
//             H[i] = Integer.parseInt(readToken(input_file));
//         }
//         for (int i = 0; i < M; i++) {
//             S[i] = Integer.parseInt(readToken(input_file));
//         }
//         for (int i = 0; i < M; i++) {
//             P[i] = Integer.parseInt(readToken(input_file));
//         }

//         /*
//           * TODO: This is where you should compute your solution. For each
//           * house, find the badness of the best supermarket, and store these
//           * values into the array answers.
//          */
//         for (int i = 0; i < N; i++) {
//             answers[i] = Integer.MAX_VALUE;
//         }


//         ArrayList<Building> list = new ArrayList<>();
//         for (int i = 0; i < N; i++) {
//             list.add(new Building(H[i], -1));
//         }
//         for (int i = 0; i < M; i++) {
//             list.add(new Building(S[i], P[i]));
//         }

//         list.sort((Building o1, Building o2) -> o1.location - o2.location);

//         Building bad = new Building(Integer.MAX_VALUE, -1);
//         int ind = 0;

//         for (Building b : list) {
//             if (b.priceFactor == -1) {
//                 // when there is no supermarket yet on the left
//                 if (bad.priceFactor == -1) {
//                     ind++;
//                     continue;
//                 }
//                 answers[ind] = Math.min(answers[ind], b.location - bad.location + bad.priceFactor);
//                 ind++;
//             } else {
//                 if (bad.priceFactor == -1) {
//                     bad = b;
//                     continue;
//                 }
//                 if (b.location - bad.location + bad.priceFactor > b.priceFactor) {
//                     bad = b;
//                 }
//             }

//         }

//         // // Reset bad and ind for right to left pass
//         bad = new Building(Integer.MAX_VALUE, -1);
//         ind = N - 1;

//         for (int i = list.size() - 1; i >= 0; i--) {
//             Building b = list.get(i);
//             if (b.priceFactor == -1) {
//                 // when there is no supermarket yet on the right
//                 if (bad.priceFactor == -1) {
//                     ind--;
//                     continue;
//                 }
//                 answers[ind] = Math.min(answers[ind], bad.location - b.location + bad.priceFactor);
//                 ind--;
//             } else {
//                 if (bad.priceFactor == -1) {
//                     bad = b;
//                     continue;
//                 }
//                 if (bad.location - b.location + bad.priceFactor > b.priceFactor) {
//                     bad = b;
//                 }
//             }
//         }


//         /* Write the answers to the output file. */
//         for (int i = 0; i < N; i++) {
//             output_file.write(answers[i] + " ");
//         }

//         /* Finally, close the input/output files. */
//         input_file.close();
//         output_file.close();
//     }
//     static class Building {
    
//         int location;
//         int priceFactor;
    
//         Building(int location, int priceFactor) {
//             this.location = location;
//             this.priceFactor = priceFactor;
//         }
//     }
// }


import java.io.*;
import java.util.Arrays;

class Solution {

    private static int N, M;

    private static int H[] = new int[100005];
    private static int S[] = new int[100005];
    private static int P[] = new int[100005];

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
                "shopin.txt"));
        BufferedWriter output_file = new BufferedWriter(new FileWriter(
                "shopout.txt"));

        /* Read the value of N and K. */
        N = Integer.parseInt(readToken(input_file));
        M = Integer.parseInt(readToken(input_file));
        
        for (int i = 0; i < N; i++) {
            H[i] = Integer.parseInt(readToken(input_file));
        }
        for (int i = 0; i < M; i++) {
            S[i] = Integer.parseInt(readToken(input_file));
        }
        for (int i = 0; i < M; i++) {
            P[i] = Integer.parseInt(readToken(input_file));
        }
        
        Building[] buildings = new Building[N+M];
        int bIndex = 0;
        for (int order = 0; order < N; order++) {
            // order of just houses, no supermarkets included
            buildings[bIndex] = new Building(H[order], order);
            bIndex++;
        }
        
        // ex. if there are 4 houses, bIndex will be 4 when this loop starts
        //     with the supermarket that is in position 0 of supermarket order
        for (int order = 0; order < M; order++) {
            buildings[bIndex] = new Building(S[order], order, P[order]);
            // buildings[4]   = new Building(S[0], 0, P[0])
            
            bIndex++;
        }
        
        Arrays.sort(buildings);
        // only works on Comparable classes (or built-in types that are comparable)
        
        
        // PHASE 1: left->right gathering up "best supermarket" data as we go
        int best = -1;
        // index number of best supermarket so far
        
        for (int i = 0; i < N+M; i++) {
            
            int badness;
            if (best == -1) {
                // use a value that's "always bad" if there is no best supermarket (so far)
                badness = Integer.MAX_VALUE;
            }
            else {   // there actually IS a best supermarket (so far)
                badness = buildings[best].p;
                badness += buildings[i].x - buildings[best].x;
            }
            
            if (buildings[i].isHouse) {
                if (best >= 0) {
                    buildings[i].ans = badness;
                }
                // else there is no best supermarket yet - do nothing for house
            }
            else {
                if (best == -1 || badness > buildings[i].p) {
                //  oldbadness > newbadness
                    best = i;
                    // remember the NEW building as the better one
                }
                // else keep using the previous best supermarket
            }
        }
        
        
        // PHASE 2: right->left same thing
        best = -1;
        // CHANGE: best is now "best market on right", not left
        
        for (int i = N+M-1; i >= 0; i--) {  // CHANGE: loop goes R->L
            
            int badness;
            if (best == -1) {
                badness = Integer.MAX_VALUE;
            }
            else {
                badness = buildings[best].p;
                badness += buildings[best].x - buildings[i].x;
                // CHANGE: now the best market is to the RIGHT (larger x),
                //    so we must subtract FROM it, instead of subtracting it
                //    from the house x
            }
            
            if (buildings[i].isHouse) {
                // CHANGE: condition for if has to check for setting OR updating
                //    an answer IF it's a better answer
                if (best >= 0 && (buildings[i].ans == 0 || buildings[i].ans > badness)) {
                //  answer exist       house had no answer        new answer is better
                    buildings[i].ans = badness;
                }
            }
            else {
                if (best == -1 || badness > buildings[i].p) {
                    best = i;
                }
            }
        }
        
        

        /* Write the answer to the output file. */
        for (int i = 0; i < N+M; i++) {
            if (buildings[i].isHouse) {
                output_file.write( buildings[i].ans + "\n");
            }
        }

        /* Finally, close the input/output files. */
        input_file.close();
        output_file.close();
    }
    
    
        
    static class Building implements Comparable<Building> {
        int x;
        int order;
        int ans;    // used only for Houses
        
        int p;      // used only for Supermarkets
        
        boolean isHouse;   // optional; alternative is something like
                           //   p=-1 for all houses
        
        // House h = new House( sc.nextInt(), i+1 );
        
        // House h = new House();
        // h.x = sc.nextInt();
        // h.order = i+1;
        
        // constructor for houses
        Building(int xx, int oo) {
            x = xx;
            order = oo;
            isHouse = true;
        }
        
        // ex. data sample #1
        // 4 3
        // 1 7 8 9
        // 4 6 10   <-- xs for supermarkets
        // 0 0 0   <-- ps for supermarkets
        
        // constructor for supermarkets
        Building(int xx, int oo, int pp) {
            x = xx;
            order = oo;
            p = pp;
            isHouse = false;
        }
        
        
        // a.compareTo(b)
        
        // a is comparing itself to b
        //    "this" = a
        //    "other" = b
        
        public int compareTo(Building other) {
            // negative result => this goes before other
            // positive        =>           after
            // zero            => this and other are tied
            
            if (this.x < other.x) return -1;
            if (this.x > other.x) return +19284;   // usually +1 works, but any pos is fine
            return 0;
        }
    }

}