#include <iostream>

class Matrix{
public:
  double **data;
  int row;
  int col;

  Matrix(){ }

  Matrix(int row, int col) : Matrix(row, col, false){ }

  Matrix(int row, int col, bool ones){
    this->row = row;
    this->col = col;

    this->data = new double*[this->row];
    for(int i = 0; i < this->row; i++){
      this->data[i] = new double[this->col];
      if(ones){
        for(int j = 0; j < this->col; j++){
          this->data[i][j] = 0;
        }
      }
    }
  }

  Matrix(double **data, int row, int col){
    this->data = data;
    this->row = row;
    this->col = col;
  }

  static Matrix * matrix_from_array(double arr[], int n, int r, int c){
    Matrix *m = new Matrix(r, c, true);

    int index = 0;
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
        index = i * c + j;

        if(index < n) m->data[i][j] = arr[index];
        else break;
      }

      if(index >= n) break;
    }

    return m;
  }

  void print(){
    for(int i = 0; i < this->row; i++){
      for(int j = 0; j < this->col; j++){
        std::cout << this->data[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  ~Matrix(){
    for(int i = 0; i < row; i++){
      delete[] this->data[i];
    }
  }
};

class MatrixOperations{
public:
  static Matrix * transpose_matrix(Matrix *m){
    Matrix *transpose = new Matrix(m->col, m->row);

    for(int i = 0; i < m->col; i++){
      for(int j = 0; j < m->row; j++){
        transpose->data[i][j] = m->data[j][i];
      }
    }

    return transpose;
  }

  static Matrix * multiply_matrix(Matrix *m1, Matrix*m2){
    Matrix *prod = new Matrix(m1->row, m2->col);

    for(int i = 0; i < m1->col; i++){
      for(int j = 0; j < m2->col; j++){
        for(int k = 0; k < m1->col; k++){
          prod->data[i][j] += m1->data[i][k] * m2->data[k][j];
        }
      }
    }

    return prod;
  }

  static Matrix * matrix_inverse(Matrix *m){
    Matrix *inverse = new Matrix(m->row, m->col);

    // TODO

    return inverse;
  }
};

int main(){

  double arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  Matrix *m = Matrix::matrix_from_array(arr, 9, 3, 3);
  m = MatrixOperations::transpose_matrix(m);

  m->print();

  return 0;
}
