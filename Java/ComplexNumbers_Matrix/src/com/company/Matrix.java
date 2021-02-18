package com.company;

import java.util.Random;

public class Matrix {
    private final int rows, columns;
    private final ComplexNumbers[][] matrix;

    public int getColumns() {
        return columns;
    }

    public int getRows() {
        return rows;
    }

    public Matrix() {
        this.rows = 0;
        this.columns = 0;
        this.matrix = null;
    }

    public Matrix(int r, int c) {
        if (r == 0 || c == 0) {
            throw new ArithmeticException("*** Size must be greater than 0 ***");
        }
        this.rows = r;
        this.columns = c;
        this.matrix = new ComplexNumbers[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                this.matrix[i][j] = new ComplexNumbers();
            }
        }
    }

    public Matrix(Matrix newM) {
        this.rows = newM.rows;
        this.columns = newM.columns;
        this.matrix = new ComplexNumbers[rows][columns];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                this.matrix[i][j] = newM.matrix[i][j];
            }
        }
    }

    public void printMatrix() {
        Matrix matr = this;
        for (int i = 0; i < matr.rows; i++) {
            for (int j = 0; j < matr.columns; j++) {
                assert matr.matrix != null;
                System.out.print(matr.matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void setValue(ComplexNumbers num, int i, int j) {
        if (i > this.rows || i < 0 || j > this.columns || j < 0) {
            throw new ArithmeticException("*** INDEX IS OUT ***");
        }
        assert this.matrix != null;
        this.matrix[i][j] = num;
    }

    public ComplexNumbers getValue(int i, int j) {
        if (i > this.rows || i < 0 || j > this.columns || j < 0) {
            throw new ArithmeticException("*** INDEX IS OUT ***");
        } else {
            assert matrix != null;
            return matrix[i][j];
        }
    }

    public boolean isSymmetric() {
        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                assert this.matrix != null;
                if (this.matrix[i][j] != this.matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean equals(Matrix a) {
        Matrix firstMatrix = this;
        if (firstMatrix.columns != a.rows) {
            return false;
        }
        for (int row = 0; row < this.rows; row++) {
            assert firstMatrix.matrix != null;
            assert a.matrix != null;
            for (int col = 0; col < this.columns; col++)
                if (firstMatrix.matrix[row][col] != a.matrix[row][col])
                    return false;
        }
        return true;
    }

    public void checkMatrix(Matrix m) {
        if (this.columns != m.getColumns() || this.rows != m.getRows()) {
            throw new ArithmeticException("*** Matrices have different dimensions ***");
        }
    }

    public Matrix addMatrix(Matrix a) {
        checkMatrix(a);
        Matrix res = new Matrix(this.getRows(), this.getColumns());
        for (int i = 0; i < this.getRows(); ++i) {
            for (int j = 0; j < this.getColumns(); ++j) {
                ComplexNumbers val1 = a.getValue(i, j);
                ComplexNumbers val2 = this.getValue(i, j);
                ComplexNumbers sum = val1.add(val2);
                res.setValue(sum, i, j);
            }
        }
        return res;
    }

    public Matrix addNumber(ComplexNumbers num) {
        Matrix res = new Matrix(this.getRows(), this.getColumns());
        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                ComplexNumbers val1 = this.getValue(i, j);
                ComplexNumbers sum = val1.add(num);
                res.setValue(sum, i, j);
            }
        }
        return res;
    }

    public Matrix addNumber(float num) {
        Matrix result = new Matrix(this.getRows(), this.getColumns());
        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                result.setValue(this.getValue(i, j).add(new ComplexNumbers(num)), i, j);
            }
        }
        return result;
    }

    public Matrix subtractMatrix(Matrix a) {
        checkMatrix(a);
        Matrix res = new Matrix(a.getRows(), a.getColumns());
        for (int i = 0; i < this.getRows(); ++i) {
            for (int j = 0; j < this.getColumns(); ++j) {
                ComplexNumbers val1 = a.getValue(i, j);
                ComplexNumbers val2 = this.getValue(i, j);
                ComplexNumbers sub = val2.subtract(val1);
                res.setValue(sub, i, j);
            }
        }
        return res;
    }

    public Matrix subtractNumber(ComplexNumbers num) {
        Matrix res = new Matrix(this.getRows(), this.getColumns());
        for (int i = 0; i < this.getRows(); i++) {
            for (int j = 0; j < this.getColumns(); j++) {
                ComplexNumbers val1 = this.getValue(i, j);
                ComplexNumbers sub = val1.subtract(num);
                res.setValue(sub, i, j);
            }
        }
        return res;
    }

    public Matrix multiplyMatrices(Matrix a) {
        if (this.columns != a.rows) {
            throw new ArithmeticException("The matrices have different sizes");
        }
        Matrix res = new Matrix(this.getRows(), a.getColumns());

        for (int i = 0; i < this.rows; ++i) {
            for (int j = 0; j < a.getColumns(); ++j) {
                ComplexNumbers s = new ComplexNumbers();
                for (int k = 0; k < a.getRows(); ++k) {
                    s = s.add(this.getValue(i, k).multiply(a.getValue(k, j)));
                }
                res.setValue(s, i, j);
            }
        }
        return res;
    }

    public Matrix multiplyByNumber(ComplexNumbers num) {
        Matrix result = new Matrix(this.getRows(), this.getColumns());
        for (int i = 0; i < this.getRows(); i++)
            for (int j = 0; j < this.getColumns(); j++)
                result.setValue(this.getValue(i, j).multiply(num), i, j);
        return result;
    }

    public Matrix transpose() {
        Matrix matr = new Matrix(this.getColumns(), this.getRows());
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.columns; j++) {
                assert matr.matrix != null;
                assert this.matrix != null;
                matr.matrix[j][i] = this.matrix[i][j];
            }
        }
        return matr;
    }

    ////////////////////////////////////////////////////////////
    public ComplexNumbers determinant() {
        if (this.getRows() != this.getColumns()) {
            throw new ArithmeticException("*** This matrix is non-square ***");
        }
        assert this.matrix != null;
        return determinant(this.matrix);
    }


    public ComplexNumbers determinant(ComplexNumbers[][] matrix) {
        ComplexNumbers[][] temporary;
        ComplexNumbers result = new ComplexNumbers();

        if (matrix.length == 1) {
            result = matrix[0][0];
            return (result);
        }

        if (matrix.length == 2) {
            result = ((matrix[0][0].multiply(matrix[1][1])).subtract(matrix[0][1].multiply(matrix[1][0])));
            return (result);
        }

        for (int row = 0; row < matrix[0].length; row++) {
            temporary = new ComplexNumbers[matrix.length - 1][matrix[0].length - 1];

            for (int col = 1; col < matrix.length; col++) {
                for (int k = 0; k < matrix[0].length; k++) {
                    if (k < row) {
                        temporary[col - 1][k] = matrix[col][k];
                    } else if (k > row) {
                        temporary[col - 1][k - 1] = matrix[col][k];
                    }
                }
            }

            result.add(matrix[0][row].multiply(Math.pow(-1, (double) row)).multiply(determinant(temporary)));
        }
        return (result);
    }
}
