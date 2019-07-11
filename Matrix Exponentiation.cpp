struct Matrix {
        int n, m;
        vector <vector <int>> mat;

        Matrix() {}

        Matrix(int _n, int _m) {
                n = _n, m = _m;
                mat = vector <vector <int>> (n, vector <int> (m));
        }

        void print() {
                for(int i = 0; i < n; i++) {
                        for(int j = 0; j < m; j++) {
                                printf("%d", mat[i][j]);
                                if(j == m - 1) {
                                        printf("\n");
                                }
                                else {
                                        printf(" ");
                                }
                        }
                }
        }
};

Matrix Multiply(Matrix a, Matrix b, int Mod) {
        Matrix c = Matrix(a.n, b.m);
        for(int i = 0; i < a.n; i++) {
                for(int j = 0; j < b.m; j++) {
                        c.mat[i][j] = 0;
                        for(int k = 0; k < a.m; k++) {
                                c.mat[i][j] += (1LL * a.mat[i][k] * b.mat[k][j]) % Mod;
                                c.mat[i][j] %= Mod;
                        }
                }
        }
        return c;
}

Matrix Add(Matrix a, Matrix b, int Mod) {
        Matrix c = Matrix(a.n, a.n);
        for(int i = 0; i < a.n; i++) {
                for(int j = 0; j < a.n; j++) {
                        c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
                        c.mat[i][j] %= Mod;
                }
        }
        return c;
}

Matrix Pow(Matrix a, ll p, int Mod) {
        if(p == 1) {
                return a;
        }
        Matrix x = Pow(a, p / 2, Mod);
        x = Multiply(x, x, Mod);
        if(p & 1) {
                x = Multiply(x, a, Mod);
        }
        return x;
}
