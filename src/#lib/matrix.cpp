template <typename T>
using matrix = vector<vector<T>>;

template <typename T>
static vector<vector<T>> MakeMatrix(int rows, int cols) {
	return vector<vector<T>>(rows, vector<T>(cols));
}

template <typename T>
static vector<vector<T>> MakeDataMatrix(int rows, int cols, T init) {
	return vector<vector<T>>(rows, vector<T>(cols, init));
}

template <typename T, typename Gen>
static vector<vector<T>> MakeGeneratedMatrix(int rows, int cols) {
	Gen initFn;
	matrix<T> m = MakeMatrix<T>(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			m[i][j] = initFn();
		}
	}
	return m;
}

template <typename T>
struct Matrix {
	int N, M;
	vector<vector<int>> A;

	Matrix(int rows, int cols) {
		N = rows;
		M = cols;
		A.resize(N);
		for (int i = 0; i < N; i++) {
			A[i].resize(M);
		}
	}

	int *operator[](int idx) {
		return &A[idx][0];
	}
};
