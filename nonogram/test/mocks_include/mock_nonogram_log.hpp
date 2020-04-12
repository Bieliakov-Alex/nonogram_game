/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_TEST_MOCKS_INCLUDE_MOCK_NONOGRAM_HPP_
#define NONOGRAM_GAME_NONOGRAM_TEST_MOCKS_INCLUDE_MOCK_NONOGRAM_HPP_

#include <string>

#include "gmock/gmock.h"

#include "i_nonogram_log.hpp"

class MockNonogramLog : public INonogramLog {
  MOCK_CONST_METHOD1(LogInfo, void(const std::string &));
};

#endif // NONOGRAM_GAME_NONOGRAM_TEST_MOCKS_INCLUDE_MOCK_NONOGRAM_HPP_
