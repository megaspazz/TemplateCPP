template <typename Key>
using hashset = unordered_set<Key, typename Key::Hash, typename Key::Equals>;

template <typename Key, typename T>
using hashmap = unordered_map<Key, T, typename Key::Hash, typename Key::Equals>;
