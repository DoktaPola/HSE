package com.company;

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        /* 1ST TASK */
//        ComplexNumbers n1 = new ComplexNumbers(1.5, 8.1);
//        ComplexNumbers n2 = new ComplexNumbers(-2.5, 10.2);
//        ComplexNumbers n3 = new ComplexNumbers(0.0, 0.0);
//        ComplexNumbers n4 = new ComplexNumbers();
//        n4.setRealPart(1);
//        n4.setImagPart(5);
//        double d1 = 3.3;
//
//        System.out.println("Add: " + n2.add(n1).toString());
//        System.out.println("Add (double) : " + n2.add(d1).toString());
//        System.out.println("Subtract : " + n1.subtract(n2).toString());
//        System.out.println("Multiply : " + n1.multiply(n2).toString());
//        System.out.println("Multiply (double) : " + n1.multiply(d1).toString());
//        System.out.println("Divide : " + n1.divide(n2).toString());
//        System.out.println("From Algebraic to Trigonometric form: " + n4.fromAlgToTrigForm() +
//                "\nFrom Trigonometric to Algebraic form: " + n4.fromTrigToAlgForm());

        /* 2ND TASK */
        // matrix 1
        Matrix m1 = new Matrix(2, 4);
        double num = 0.0;
        m1.setValue(new ComplexNumbers(++num), 0, 0);
        m1.setValue(new ComplexNumbers(++num), 0, 1);
        m1.setValue(new ComplexNumbers(++num), 0, 2);
        m1.setValue(new ComplexNumbers(++num), 0, 3);
        m1.setValue(new ComplexNumbers(++num), 1, 0);
        m1.setValue(new ComplexNumbers(++num), 1, 1);
        m1.setValue(new ComplexNumbers(++num), 1, 2);
        m1.setValue(new ComplexNumbers(++num), 1, 3);
        // matrix 2
        Matrix m2 = new Matrix(4, 2);
        Random random = new Random();
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 2; col++) {
                m2.setValue(new ComplexNumbers(random.nextDouble()), row, col);
            }
        }
        // matrix 3
        double num2 = 0.0;
        Matrix m3 = new Matrix(2, 4);
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 4; col++) {
                m3.setValue(new ComplexNumbers(num2++), row, col);
            }
        }

        ComplexNumbers cn1 = new ComplexNumbers(1, 3);
        ///////////////////////////
        System.out.println("\n");
        System.out.println(">> MATRIX 1: ");
        m1.printMatrix();
        System.out.println(">> MATRIX 2: ");
        m2.printMatrix();
        System.out.println(">> MATRIX 3: ");
        m3.printMatrix();
        System.out.println("\n");
        System.out.println(">> TRANSPOSE MATRIX 1: ");
        m1.transpose().printMatrix();
        System.out.println(">> TRANSPOSE MATRIX 2: ");
        m2.transpose().printMatrix();
        System.out.println("\n");
        System.out.println(">> MATRIX 1 + MATRIX 2: ");
        try {
            m1.addMatrix(m2).printMatrix();
        } catch (ArithmeticException ae) {
            System.out.println("*** Dimensions of these matrix's are different ***");
        }
        System.out.println("\n");
        System.out.println(">> MATRIX 1 + 5: ");
        m1.addNumber(5).printMatrix();
        System.out.println("\n");
        System.out.println(">> MATRIX 1 + (1 + 3*i): ");
        m1.addNumber(cn1).printMatrix();
        System.out.println("\n");
        System.out.println(">> MATRIX 1 - MATRIX 3: ");
        try {
            m1.subtractMatrix(m3).printMatrix();
        } catch (ArithmeticException ae) {
            System.out.println("*** Dimensions of these matrix's are different ***");
        }
        System.out.println("\n");
        System.out.println(">> MATRIX 1 - (1 + 3*i): ");
        m1.subtractNumber(cn1).printMatrix();
        System.out.println("\n");
        System.out.println(">> MATRIX 1 * MATRIX 2: ");
        try {
            m1.multiplyMatrices(m2).printMatrix();
        } catch (ArithmeticException ae) {
            System.out.println("*** Dimensions of these matrix's are different ***");
        }
        System.out.println("\n");
        System.out.println(">> MATRIX 1 * (1 + 3*i): ");
        m1.multiplyByNumber(cn1).printMatrix();
        System.out.println("\n");
        // matrix 4
        Matrix m4 = new Matrix(2, 2);
        double num4 = 1.0;
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 2; col++) {
                m4.setValue(new ComplexNumbers(num4++), row, col);
            }
        }
        System.out.println(">> MATRIX 4: ");
        m4.printMatrix();
        System.out.println("\n");
        try {
            System.out.println("Determinant -> Matrix 4: " + m4.determinant());
        }catch (ArithmeticException ae){
            System.out.println( "*** This matrix is non-square ***");
        }
    }
}
