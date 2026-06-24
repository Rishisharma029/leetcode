class Solution {
    static constexpr int MOD = 1000000007;
    static constexpr int MAXM = 75;

    struct Matrix {
        long long a[MAXM][MAXM];
        Matrix(bool ident = false) {
            memset(a, 0, sizeof(a));
            if (ident)
                for (int i = 0; i < MAXM; i++)
                    a[i][i] = 1;
        }
    };

    Matrix multiply(const Matrix &A, const Matrix &B, int m) {
        Matrix C;
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < m; k++) {
                if (!A.a[i][k]) continue;
                long long val = A.a[i][k];
                for (int j = 0; j < m; j++) {
                    C.a[i][j] += val * B.a[k][j];
                    if (C.a[i][j] >= (1LL << 62))
                        C.a[i][j] %= MOD;
                }
            }
            for (int j = 0; j < m; j++)
                C.a[i][j] %= MOD;
        }
        return C;
    }

    void matVec(const Matrix &A, long long vec[], int m) {
        static long long tmp[MAXM];
        memset(tmp, 0, sizeof(tmp));

        for (int i = 0; i < m; i++) {
            long long sum = 0;
            for (int j = 0; j < m; j++)
                sum = (sum + A.a[i][j] * vec[j]) % MOD;
            tmp[i] = sum;
        }

        memcpy(vec, tmp, sizeof(tmp));
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        Matrix C;

        // C[i][j] = number of k such that i<k and j<k
        // = (m-1) - max(i,j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                C.a[i][j] = max(0, m - 1 - max(i, j));
            }
        }

        long long vec[MAXM];

        long long exp;
        if (n & 1) {
            // odd n = 2t+1
            exp = (n - 1) / 2;
            for (int i = 0; i < m; i++) vec[i] = 1;
        } else {
            // even n = 2t+2
            exp = (n - 2) / 2;
            for (int i = 0; i < m; i++)
                vec[i] = m - 1 - i;   // A * ones
        }

        Matrix base = C;

        while (exp) {
            if (exp & 1)
                matVec(base, vec, m);

            base = multiply(base, base, m);
            exp >>= 1;
        }

        long long ans = 0;
        for (int i = 0; i < m; i++)
            ans = (ans + vec[i]) % MOD;

        ans = ans * 2 % MOD;

        return (int)ans;
    }
};