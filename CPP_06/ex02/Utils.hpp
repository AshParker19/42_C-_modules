#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Wrong.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif