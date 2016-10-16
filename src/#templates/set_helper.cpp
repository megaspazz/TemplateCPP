
/**
 * Gets the largest element strictly less than the input element in the set.
 */
template <typename T>
T getLower(const set<T> &s, const T &val) {
    return *(--s.lower_bound(val));
}

/**
 * Gets the smallest element strictly greater than the input element in the set.
 */
template <typename T>
T getUpper(const set<T> &s, const T &val) {
    return *s.upper_bound(val);
}
