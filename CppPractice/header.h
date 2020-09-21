#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <memory>



class DigitSplitter {
private:
	long long number;
	std::vector<int> digits;
public:
	DigitSplitter(int n) {
		number = n;
		if (n <= 0) {
			return;
		}
		size_t s = static_cast<size_t>(std::log10(n));
		digits.resize(s + 1);
		while (n > 10) {
			digits[s] = n % 10;
			n = n / 10;
			s--;
		}
		digits[0] = n;
	}

	friend std::ostream& operator<<(std::ostream& os, const DigitSplitter& beginer) {
		for (auto& i : beginer.digits) {
			os << i << " ";
		}
		return os;
	}

};

class CurlyBracesBalance
{
private:
	std::unique_ptr<std::ifstream> file;
public:
	CurlyBracesBalance() noexcept {
		this->file = std::make_unique<std::ifstream>();
	}
	~CurlyBracesBalance() noexcept {
		this->file.reset();
	}

	bool open(std::string s) {
		if (this->file->is_open()) {
			this->file->close();
		}

		this->file->open(s);

		return file->is_open() ? true : false;
	}

	bool checkFile() {
		if (!this->file->is_open()) {
			throw std::runtime_error("File is not open!");
		}

		char s;
		int accum = 0;

		while (this->file->get(s)) {
			if (s == '{') {
				accum++;
			}
			else if (s == '}') {
				accum--;
			}
		}


		return !accum;
	}
};

class String {
private:
	char* m_strptr;
	size_t m_MaxStrSize;
	size_t m_length;


	static void strcpy(char* destptr, const char* srcptr, size_t str_size, size_t start = 0) {
		size_t i = start;
		size_t j = 0;
		while (i <= str_size) {
			destptr[i] = srcptr[j];
			if (srcptr[j] == '\0') {
				break;
			}
			i++;
			j++;
		}
	}


public:
	String() {
		this->m_strptr = nullptr;
		this->m_MaxStrSize = 256;
		this->m_length = 0;
	};

	String(const char* chars, const size_t max_size = 256) {
		this->m_MaxStrSize = max_size;
		this->m_length = strlen(chars);
		if (this->m_length > this->m_MaxStrSize) {
			this->m_length = this->m_MaxStrSize;
		}
		this->m_strptr = new char[this->m_length + 1];
		strcpy(this->m_strptr, chars, max_size);
	}

	String(const String& other) {
		this->m_length = other.m_length;
		this->m_MaxStrSize = other.m_MaxStrSize;
		this->m_strptr = new char[this->m_length + 1];
		strcpy(this->m_strptr, other.m_strptr, this->m_length);
		this->m_strptr[this->m_length] = '\0';
	}

	~String() {
		delete[] this->m_strptr;
	}

	String& operator=(const char* chars) {
		if (this->m_strptr != nullptr) {
			delete[] this->m_strptr;
		}
		this->m_length = strlen(chars);
		this->m_MaxStrSize = 256;
		this->m_strptr = new char[this->m_length + 1];
		strcpy(this->m_strptr, chars, this->m_MaxStrSize);
		return *this;
	}

	String& operator=(const String& s) {
		if (this->m_strptr != nullptr) {
			delete[] this->m_strptr;
		}
		this->m_length = s.m_length;
		this->m_MaxStrSize = s.m_MaxStrSize;
		this->m_strptr = new char[this->m_length + 1];
		strcpy(this->m_strptr, s.m_strptr, this->m_length);
		this->m_strptr[this->m_length] = '\0';
		return *this;
	}



	const String operator+(const String& other) {
		String newString;
		size_t oEnd = this->m_length;
		size_t newLen = this->m_length + other.m_length;
		if (newLen > this->m_MaxStrSize) {
			newLen = this->m_MaxStrSize;
		}
		newString.m_length = newLen;
		newString.m_MaxStrSize = this->m_MaxStrSize;
		auto newStr = new char[newLen + 1];
		strcpy(newStr, this->m_strptr, this->m_length - 1);
		strcpy(newStr, other.m_strptr, newLen - 1, oEnd);
		newStr[newLen] = '\0';
		newString.m_strptr = newStr;
		return newString;
	}


	size_t len() {
		return this->m_length;
	}

};