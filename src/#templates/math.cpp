
template <typename T>
T abs(const T &val) {
    return (val < 0) ? -val : val;
}

long long modPow(long long b, long long e, long long m) {
    long long ans = 1;
    while (e) {
        if (e & 1) {
            ans = (ans * b) % m;
        }
        b = (b * b) % m;
        e >>= 1;
    }
    return ans;
}

long long gcd (long long a, long long b)
{
    long long c;
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}
