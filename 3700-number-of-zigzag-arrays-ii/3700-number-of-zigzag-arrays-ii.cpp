class Solution {
public:
    static constexpr long long MOD = 1000000007LL;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix &A, const Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;
                long long val = A[i][k];
                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + val * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    long long sumAll(const Matrix &M) {
        long long ans = 0;
        int n = M.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = (ans + M[i][j]) % MOD;
        return ans;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        Matrix A(m, vector<long long>(m, 0));
        Matrix B(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                A[i][j] = 1; // up
                B[j][i] = 1; // down
            }
        }

        Matrix C = multiply(A, B);
        Matrix D = multiply(B, A);

        if (n % 2 == 1) {
            long long t = (n - 1) / 2;
            Matrix Ct = power(C, t);
            Matrix Dt = power(D, t);

            long long ans = (sumAll(Ct) + sumAll(Dt)) % MOD;
            return ans;
        } else {
            long long t = (n - 2) / 2;

            Matrix Ct = power(C, t);
            Matrix Dt = power(D, t);

            Matrix X = multiply(Ct, A);
            Matrix Y = multiply(Dt, B);

            long long ans = (sumAll(X) + sumAll(Y)) % MOD;
            return ans;
        }
    }
};