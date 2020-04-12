/*Copyright 2020 Alex Bieliakov*/

#ifndef NONOGRAM_GAME_NONOGRAM_TEST_MOCKS_INCLUDE_MOCK_NONOGRAM_HPP_
#define NONOGRAM_GAME_NONOGRAM_TEST_MOCKS_INCLUDE_MOCK_NONOGRAM_HPP_

#include "gmock/gmock.h"

#include "i_nonogram.hpp"

class MockNonogram : public INonogram {
  MOCK_CONST_METHOD0(GetField,
                     const std::vector<std::vector<NonogramCellState>> &());
  MOCK_CONST_METHOD0(GetColumns, const uint8_t());
  MOCK_CONST_METHOD0(GetRows, const uint8_t());
  MOCK_CONST_METHOD2(GetNonogramCellState,
                     const NonogramCellState(const uint8_t, const uint8_t));
  MOCK_METHOD3(SetNonogramCellState,
               void(const uint8_t, const uint8_t, const NonogramCellState));
  MOCK_CONST_METHOD1(GetRowNumbers,
                     const std::vector<uint8_t> &(const uint8_t));
  MOCK_CONST_METHOD1(GetColumnNumbers,
                     const std::vector<uint8_t> &(const uint8_t));
};

#endif // NONOGRAM_GAME_NONOGRAM_TEST_MOCKS_INCLUDE_MOCK_NONOGRAM_HPP_
