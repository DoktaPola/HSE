package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static <str> void main(String[] args) throws IOException, FileNotFoundException, EmptyFileException {
        /* interaction with user */
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter, pls, path to the <name>.txt file.\n>>>"); // example: data\input.txt
        String filePath = sc.nextLine();
        sc.close();

        /* if file is empty */
        File isEmpty = new File(filePath);
        if (isEmpty.length() == 0) {
            throw new EmptyFileException("*** File is empty ***");
        }

        try {
            FileInputStream file = new FileInputStream(filePath);

            /*letters counter function*/
            LettersCounter lc = new LettersCounter();
            Map<Character, Integer> alph = lc.toCountLetters(file);

            FileWriter writer = new FileWriter("data" + File.separator +
                    "output.txt", false);
            try {
                for (Map.Entry<Character, Integer> item : alph.entrySet()) {
                    writer.write(item.getKey() + " " + item.getValue() + "\n");
                }
                writer.flush();
            } catch (IOException ex) {
                System.out.println(ex.getMessage());
            }
        } catch (FileNotFoundException ex) {
            System.out.println(ex.getMessage());
        }
    }
}
