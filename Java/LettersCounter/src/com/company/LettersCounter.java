package com.company;

import java.io.*;
import java.util.*;


public class LettersCounter {
    public <str> Map<Character, Integer> toCountLetters(FileInputStream file) throws IOException {
        String alphabet = new String("abcdefghijklmnopqrstuvwxyz");
        Map<Character, Integer> alph = new HashMap<Character, Integer>();
        for (int i = 0; i < alphabet.length(); i++) {
            alph.put(Character.toUpperCase(alphabet.charAt(i)), 0);
        }

        int i;
        while ((i = file.read()) != -1) {
            if ((char) i >= 'A' && (char) i <= 'Z' | (char) i >= 'a' && (char) i <= 'z') {
                if (alph.get(Character.toUpperCase((char) i)) == 0) {
                    alph.put(Character.toUpperCase((char) i), 1);
                } else {
                    int size = alph.get(Character.toUpperCase((char) i)) + 1;
                    alph.put(Character.toUpperCase((char) i), size);
                }
            }
        }
        return alph;
    }
}
