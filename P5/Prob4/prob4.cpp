#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

#define READ 0
#define WRITE 1
#define MAX_STR_LEN 1024

string get_token(string to_token, size_t begin, size_t end)
{
  string tokenized;

  for(size_t i = begin; i < end; i++)
    tokenized.push_back(to_token.at(i));

  return tokenized;
}

vector<string> tokenizer (string to_token, string token)
{
  size_t found, last_found = -1;

	vector<string> tokens;

	while ((found = to_token.find(token, last_found + 1)) != to_token.npos)
	{
		tokens.push_back(get_token(to_token, last_found + 1, found));

    last_found = found + token.length() - 1;
	}

	tokens.push_back(get_token(to_token, last_found + 1, to_token.size()));

  return tokens;
}

int main ()
{
  vector<string> cmds;

  string resp;

  cout << "Insira um comando\n";

  getline(cin, resp);

  cmds = tokenizer(resp, " | ");

  for(vector<string>::iterator i = cmds.begin(); i != cmds.end(); i++)
  {
    cout << "Thread: " << *i << endl;
  }

  return 0;
}
