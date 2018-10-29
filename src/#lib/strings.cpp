vector<string> splitString(string &S, char delim) {
	vector<string> lst;
	stringstream ss;
	ss.str(S);
	string str;
	while (getline(ss, str, delim)) {
		lst.push_back(str);
	}
	return lst;
}
