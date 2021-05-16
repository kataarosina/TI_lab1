#pragma once
#ifndef UNITH
#define UNITH

#include <string>

std::string column_encrypt(std::string, std::string);
std::string column_decrypt(std::string, std::string);

std::string grille_encrypt(std::string, bool **key);
std::string grille_decrypt(std::string, bool **key);

std::string vigener_encrypt(std::string, std::string);
std::string vigener_decrypt(std::string, std::string);

#endif