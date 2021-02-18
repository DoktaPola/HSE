package com.company;

import static java.lang.Math.atan2;

public class ComplexNumbers {
    /* vars */
    private double realPart, imagPart;

    /* getters & setters */
    public double getRealPart() {
        return realPart;
    }

    public void setRealPart(double realPart) {
        this.realPart = realPart;
    }

    public double getImagPart() {
        return imagPart;
    }

    public void setImagPart(double imagPart) {
        this.imagPart = imagPart;
    }

    /* constructors */
    public ComplexNumbers() {
        this.realPart = 0.0;
        this.imagPart = 0.0;
    }

    public ComplexNumbers(double rP, double iP) {
        this.realPart = rP;
        this.imagPart = iP;
    }

    public ComplexNumbers(double rP) {
        this.realPart = rP;
        this.imagPart = 0.0;
    }

    /* simple additional methods */
    private String symbol() {
        if (imagPart > 0) return " + ";
        else return " - ";
    }

    public String toString() {
        String string;
        if (imagPart == -1.0 || imagPart == 1.0) {
            if (realPart == 0) {
                string = symbol() + "i";
            } else {
                string = realPart + symbol() + "i";
            }
        } else if (imagPart != 0) {
            if (realPart == 0) {
                string = String.format("%.2f", imagPart) + "i";
            } else {
                string = String.format("%.2f", realPart) + symbol()
                        + String.format("%.2f", Math.abs(imagPart)) + "i";
            }
        } else {
            string = String.format("%.2f", realPart) + "";
        }
        return string;
    }

    public boolean equals(ComplexNumbers num) {
        return num != null && this.getRealPart() == num.getRealPart() && this.getImagPart() == num.getImagPart();          /////////////////
    }

    /* methods */
    public ComplexNumbers add(ComplexNumbers n1) {
        return new ComplexNumbers(this.getRealPart() + n1.getRealPart(), this.getImagPart() + n1.getImagPart());
    }

    public ComplexNumbers add(double a) {
        return new ComplexNumbers(this.getRealPart() + a, this.getImagPart());
    }

    public ComplexNumbers subtract(ComplexNumbers n1) {
        return new ComplexNumbers(this.getRealPart() - n1.getRealPart(), this.getImagPart() - n1.getImagPart());
    }

    public ComplexNumbers multiply(ComplexNumbers n1) {
        ComplexNumbers newOne = new ComplexNumbers(0.0, 0.0);
        newOne.realPart = this.getRealPart() * n1.getRealPart() - this.getImagPart() * n1.getImagPart();
        newOne.imagPart = this.getRealPart() * n1.getImagPart() + this.getImagPart() * n1.getRealPart();
        return (newOne);
    }

    public ComplexNumbers multiply(double a) {
        return new ComplexNumbers(this.getRealPart() * a, this.getImagPart() * a);
    }

    public ComplexNumbers divide(ComplexNumbers num) {
        if (num.getRealPart() == 0 && num.getImagPart() == 0) {
            throw new ArithmeticException("!!! DIVISION BY ZERO !!!");
        }
        double real = (this.getRealPart() * num.getRealPart() + this.getImagPart() * num.getImagPart()) /
                (Math.pow(num.getRealPart(), 2) + Math.pow(num.getImagPart(), 2));
        double imaginary = (this.getImagPart() * num.getRealPart() - this.getRealPart() * num.getImagPart()) /
                (Math.pow(num.getRealPart(), 2) + Math.pow(num.getImagPart(), 2));
        return new ComplexNumbers(real, imaginary);
    }

    public double module(ComplexNumbers num) {
        return Math.sqrt(Math.pow(num.getRealPart(), 2) + Math.pow(num.getImagPart(), 2));
    }

    public double argument(ComplexNumbers num) {
        return Math.toDegrees(Math.atan(num.getImagPart() / num.getRealPart()));
    }

    public String fromAlgToTrigForm() {
        double m = module(this);
        double arg = argument(this);
        return String.format("%.2f*(cos(%.2f) + i*sin(%.02f))", m, arg, arg);
    }

    public String fromTrigToAlgForm() {
        if (this.getImagPart() == 0.0) {
            return String.format("z = %.2f", this.getRealPart());
        } else {
            if (this.getImagPart() >= 0.0) {
                return String.format("z = %.2f + %.2f*i", this.getRealPart(), this.getImagPart());
            } else {
                return String.format("z = %.2f - %.2f*i", this.getRealPart(), -this.getImagPart());
            }
        }
    }
}