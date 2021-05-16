#include "Ciphers.h"
#include <algorithm>
#include <string>

#define GRSIZE 4
#define RMIN 'A'
#define RRAN 26
#define RUSLEN 32

using namespace std;

int *column_generate_key(string wkey) {

	int keylen = wkey.size();

	char *ckey = new char[keylen];
	for (int i = 0; i < keylen; ++i) {
		ckey[i] = wkey[i];
	}
	sort(ckey, ckey + keylen);

	int *key = new int[keylen];
	int cnt = 0;

	for (int i = 0; i < keylen; ++i)
		for (int j = 0; j < keylen; ++j)
			if (ckey[i] == wkey[j]) {
				wkey[j] = 1;
				key[j] = ++cnt;
				break;
			}
	delete[] ckey;

	return key;

}

string column_encrypt(string srcmessage, string wkey) {

	string message = "";
	for (int i = 0; i < srcmessage.size(); ++i)
		if ('A' <= srcmessage[i] && srcmessage[i] <= 'z')
			message += srcmessage[i];

	int keylen = wkey.size();
	int *key = column_generate_key(wkey);

	int cnt = 0;
	int mheight = (message.size() % keylen == 0) ? message.size() / keylen : message.size() / keylen + 1;
	char **matr = new char *[mheight];
	for (int i = 0; i < mheight; ++i) {
		matr[i] = new char[keylen];
		for (int j = 0; j < keylen; ++j)
			matr[i][j] = (cnt < message.size()) ? message[cnt++] : 0;
	}

	string ans = "";
	cnt = 1;

	for (int k = 0; k < keylen; ++k)
		for (int i = 0; i < keylen; ++i)
			if (key[i] == cnt) {
				for (int j = 0; j < mheight; ++j)
					if (matr[j][i] != 0)
						ans += matr[j][i];
				++cnt;
			}

	delete[] key, matr;

	string res = "";
	cnt = 0;

	for (int i = 0; i < srcmessage.size(); ++i)
		if ('A' <= srcmessage[i] && srcmessage[i] <= 'z')
			res += ans[cnt++];
		else
			res += srcmessage[i];

	return res;
}

string column_decrypt(string srcmessage, string wkey) {

	string message = "";
	for (int i = 0; i < srcmessage.size(); ++i)
		if ('A' <= srcmessage[i] && srcmessage[i] <= 'z')
			message += srcmessage[i];

	int keylen = wkey.size();
	int *key = column_generate_key(wkey);

	int mheight = (message.size() % keylen == 0) ? message.size() / keylen : message.size() / keylen + 1;
	char **matr = new char *[mheight];
	for (int i = 0; i < mheight; ++i)
		matr[i] = new char[keylen];

	int cnt = 1, cnt_mes = 0;

	for (int k = 0; k < keylen; ++k)
		for (int i = 0; i < keylen; ++i)
			if (key[i] == cnt) {
				for (int j = 0; j < mheight; ++j)
					if ((j)* keylen + i + 1 <= message.size())
						matr[j][i] = message[cnt_mes++];
					else matr[j][i] = 0;
					++cnt;
			}

	string ans = "";

	for (int i = 0; i < mheight; ++i) {
		for (int j = 0; j < keylen; ++j)
			if (matr[i][j])
				ans += matr[i][j];
			else break;
	}

	delete[] matr, key;

	string res = "";
	cnt = 0;

	for (int i = 0; i < srcmessage.size(); ++i)
		if ('A' <= srcmessage[i] && srcmessage[i] <= 'z')
			res += ans[cnt++];
		else
			res += srcmessage[i];

	return res;
}

bool **rotate_matr(bool **matr, int n) {

	for (int i = 0; i < n / 2; ++i)
		for (int j = i; j < n - i - 1; ++j) {
			bool tmp = matr[i][j];
			matr[i][j] = matr[n - j - 1][i];
			matr[n - j - 1][i] = matr[n - i - 1][n - j - 1];
			matr[n - i - 1][n - j - 1] = matr[j][n - i - 1];
			matr[j][n - i - 1] = tmp;
		}

	return matr;
}


string grille_encrypt(string message, bool **key) {

	int n = GRSIZE;
	char **matr = new char *[n];
	for (int i = 0; i < n; ++i)
		matr[i] = new char[n];
	int cnt = 0, alph_cnt = 0;

	for (int n_rot = 0; n_rot < 4; ++n_rot) {

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (key[i][j]) matr[i][j] = (cnt < message.size()) ? message[cnt++] : RMIN + (alph_cnt++ % RRAN);
			}

		key = rotate_matr(key, n);
	}

	string ans = "";

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans += matr[i][j];

	delete[] matr;
	return ans;
}

string grille_decrypt(string message, bool **key) {

	int n = GRSIZE;
	int cnt = 0;
	char **matr = new char *[n];
	for (int i = 0; i < n; ++i) {
		matr[i] = new char[n];
		for (int j = 0; j < n; ++j)
			matr[i][j] = message[cnt++];
	}

	string ans = "";
	for (int n_rot = 0; n_rot < 4; ++n_rot) {

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (key[i][j])
					ans += matr[i][j];

		key = rotate_matr(key, n);
	}

	delete[] matr;

	int ind_beg = ans.size();
	for (int i = ans.size() - 1; i > 0; --i) {
		if (ans[i] - ans[i - 1] != 1) {
			break;
		}
		ind_beg = i - 1;
	}
	ans = ans.substr(0, ind_beg);
	return ans;

}

string vigener_encrypt(string srcmessage, string key) {

	string ALPHABET = "À";
	for (int i = 1; i < 32; ++i) {
		ALPHABET += ALPHABET[i - 1] + 1;
	}

	ALPHABET.insert(6, "¨");

	string message = "";
	for (int i = 0; i < srcmessage.size(); ++i) {
		if ('À' <= srcmessage[i] && srcmessage[i] <= 'ÿ'\
			|| srcmessage[i] == '¨' || srcmessage[i] == '¸')
			message += toupper(srcmessage[i]);
	}

	key += message.substr(0, message.size() - key.size());

	string ans = "";
	for (int i = 0; i < message.size(); ++i) {

		int ans_pos = (ALPHABET.find(message[i]) + ALPHABET.find(key[i])) % ALPHABET.size();
		ans += ALPHABET[ans_pos];
	}

	string res = "";
	int cnt = 0;

	for (int i = 0; i < srcmessage.size(); ++i) {
		if ('à' <= srcmessage[i] && srcmessage[i] <= 'ÿ' || srcmessage[i] == '¸') {
			res += tolower(ans[cnt++]);
		}
		else if ('À' <= srcmessage[i] && srcmessage[i] <= 'ß' || srcmessage[i] == '¨') {
			res += ans[cnt++];
		}
		else
			res += srcmessage[i];
	}

	return res;
}

string vigener_decrypt(string srcmessage, string key) {

	string ALPHABET = "À";
	for (int i = 1; i < 32; ++i) {
		ALPHABET += ALPHABET[i - 1] + 1;
	}

	ALPHABET.insert(6, "¨");

	string message = "";
	for (int i = 0; i < srcmessage.size(); ++i)
		if ('À' <= srcmessage[i] && srcmessage[i] <= 'ÿ' || srcmessage[i] == '¸' || srcmessage[i] == '¨')
			message += toupper(srcmessage[i]);

	string ans = "";

	for (int i = 0; i < message.size(); ++i) {
		int ans_pos = (ALPHABET.find(message[i]) + ALPHABET.size() - ALPHABET.find(key[i])) % ALPHABET.size();
		ans += ALPHABET[ans_pos];
		if (key.size() < message.size())
			key += ans.back();
	}

	string res = "";
	int cnt = 0;

	for (int i = 0; i < srcmessage.size(); ++i) {
		if ('à' <= srcmessage[i] && srcmessage[i] <= 'ÿ' || srcmessage[i] == '¸') {
			res += tolower(ans[cnt++]);
		}
		else if ('À' <= srcmessage[i] && srcmessage[i] <= 'ß' || srcmessage[i] == '¨') {
			res += ans[cnt++];
		}
		else
			res += srcmessage[i];
	}

	return res;
}


#undef GRSIZE
#undef RMIN
#undef RRAN
#undef RUSLEN
