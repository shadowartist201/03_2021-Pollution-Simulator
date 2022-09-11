#pragma once
#include <vector>
#include <string>
using namespace std;

class residential {
public:
	vector<string> main(vector<string> input, int num2, int num3);
	vector<string> copy_paste(vector<string> input);
	char comm_statements(vector<string> thing, int vector_iter, int string_iter, int workers, int goods);
	char res_statements(vector<string> thing, int vector_iter, int string_iter);
	char indus_statements(vector<string> thing, int vector_iter, int string_iter, int workers);
	char poll_statements(vector<string> thing, int vector_iter, int string_iter);
private:
};
